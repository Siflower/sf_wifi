#include "siwifi_tdls.h"
#include "siwifi_compat.h"
static u16
siwifi_get_tdls_sta_capab(struct siwifi_vif *siwifi_vif, u16 status_code)
{
    u16 capab = 0;
    if (status_code != 0)
        return capab;
    if (siwifi_vif->sta.ap->band != NL80211_BAND_2GHZ)
        return capab;
    capab |= WLAN_CAPABILITY_SHORT_SLOT_TIME;
    capab |= WLAN_CAPABILITY_SHORT_PREAMBLE;
    return capab;
}
static int
siwifi_tdls_prepare_encap_data(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                                 const u8 *peer, u8 action_code, u8 dialog_token,
                                 u16 status_code, struct sk_buff *skb)
{
    struct ieee80211_tdls_data *tf;
    tf = (void *)skb_put(skb, sizeof(struct ieee80211_tdls_data) - sizeof(tf->u));
    memcpy(tf->da, peer, ETH_ALEN);
    memcpy(tf->sa, siwifi_hw->wiphy->perm_addr, ETH_ALEN);
    tf->ether_type = cpu_to_be16(ETH_P_TDLS);
    tf->payload_type = WLAN_TDLS_SNAP_RFTYPE;
    tf->category = WLAN_CATEGORY_TDLS;
    tf->action_code = action_code;
    switch (action_code) {
    case WLAN_TDLS_SETUP_REQUEST:
        skb_put(skb, sizeof(tf->u.setup_req));
        tf->u.setup_req.dialog_token = dialog_token;
        tf->u.setup_req.capability =
                cpu_to_le16(siwifi_get_tdls_sta_capab(siwifi_vif, status_code));
        break;
    case WLAN_TDLS_SETUP_RESPONSE:
        skb_put(skb, sizeof(tf->u.setup_resp));
        tf->u.setup_resp.status_code = cpu_to_le16(status_code);
        tf->u.setup_resp.dialog_token = dialog_token;
        tf->u.setup_resp.capability =
                cpu_to_le16(siwifi_get_tdls_sta_capab(siwifi_vif, status_code));
        break;
    case WLAN_TDLS_SETUP_CONFIRM:
        skb_put(skb, sizeof(tf->u.setup_cfm));
        tf->u.setup_cfm.status_code = cpu_to_le16(status_code);
        tf->u.setup_cfm.dialog_token = dialog_token;
        break;
    case WLAN_TDLS_TEARDOWN:
        skb_put(skb, sizeof(tf->u.teardown));
        tf->u.teardown.reason_code = cpu_to_le16(status_code);
        break;
    case WLAN_TDLS_DISCOVERY_REQUEST:
        skb_put(skb, sizeof(tf->u.discover_req));
        tf->u.discover_req.dialog_token = dialog_token;
        break;
    default:
        return -EINVAL;
    }
    return 0;
}
static int
siwifi_prep_tdls_direct(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                      const u8 *peer, u8 action_code, u8 dialog_token,
                      u16 status_code, struct sk_buff *skb)
{
    struct ieee80211_mgmt *mgmt;
    mgmt = (void *)skb_put(skb, 24);
    memset(mgmt, 0, 24);
    memcpy(mgmt->da, peer, ETH_ALEN);
    memcpy(mgmt->sa, siwifi_hw->wiphy->perm_addr, ETH_ALEN);
    memcpy(mgmt->bssid, siwifi_vif->sta.ap->mac_addr, ETH_ALEN);
    mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
                      IEEE80211_STYPE_ACTION);
    switch (action_code) {
    case WLAN_PUB_ACTION_TDLS_DISCOVER_RES:
        skb_put(skb, 1 + sizeof(mgmt->u.action.u.tdls_discover_resp));
        mgmt->u.action.category = WLAN_CATEGORY_PUBLIC;
        mgmt->u.action.u.tdls_discover_resp.action_code = WLAN_PUB_ACTION_TDLS_DISCOVER_RES;
        mgmt->u.action.u.tdls_discover_resp.dialog_token = dialog_token;
        mgmt->u.action.u.tdls_discover_resp.capability =
            cpu_to_le16(siwifi_get_tdls_sta_capab(siwifi_vif, status_code));
        break;
    default:
        return -EINVAL;
    }
    return 0;
}
static int
siwifi_add_srates_ie(struct siwifi_hw *siwifi_hw, struct sk_buff *skb)
{
    u8 i, rates, *pos;
    int rate;
    struct ieee80211_supported_band *siwifi_band_2GHz = siwifi_hw->wiphy->bands[NL80211_BAND_2GHZ];
    rates = 8;
    if (skb_tailroom(skb) < rates + 2)
        return -ENOMEM;
    pos = skb_put(skb, rates + 2);
    *pos++ = WLAN_EID_SUPP_RATES;
    *pos++ = rates;
    for (i = 0; i < rates; i++) {
        rate = siwifi_band_2GHz->bitrates[i].bitrate;
        rate = DIV_ROUND_UP(rate, 5);
        *pos++ = (u8)rate;
    }
    return 0;
}
static int
siwifi_add_ext_srates_ie(struct siwifi_hw *siwifi_hw, struct sk_buff *skb)
{
    u8 i, exrates, *pos;
    int rate;
    struct ieee80211_supported_band *siwifi_band_2GHz = siwifi_hw->wiphy->bands[NL80211_BAND_2GHZ];
    exrates = siwifi_band_2GHz->n_bitrates - 8;
    if (skb_tailroom(skb) < exrates + 2)
        return -ENOMEM;
    pos = skb_put(skb, exrates + 2);
    *pos++ = WLAN_EID_EXT_SUPP_RATES;
    *pos++ = exrates;
    for (i = 8; i < (8+exrates); i++) {
        rate = siwifi_band_2GHz->bitrates[i].bitrate;
        rate = DIV_ROUND_UP(rate, 5);
        *pos++ = (u8)rate;
    }
    return 0;
}
static void
siwifi_tdls_add_supp_channels(struct siwifi_hw *siwifi_hw, struct sk_buff *skb)
{
    u8 subband_cnt = 0;
    u8 *pos_subband;
    u8 *pos = skb_put(skb, 2);
    struct ieee80211_supported_band *siwifi_band_2GHz = siwifi_hw->wiphy->bands[NL80211_BAND_2GHZ];
    struct ieee80211_supported_band *siwifi_band_5GHz = siwifi_hw->wiphy->bands[NL80211_BAND_5GHZ];
    *pos++ = WLAN_EID_SUPPORTED_CHANNELS;
    pos_subband = skb_put(skb, 2);
    if (siwifi_band_2GHz->n_channels > 0)
    {
        *pos_subband++ = ieee80211_frequency_to_channel(siwifi_band_2GHz->channels[0].center_freq);
        *pos_subband++ = siwifi_band_2GHz->n_channels;
        subband_cnt++;
    }
    pos_subband = skb_put(skb, 2);
    if (siwifi_band_5GHz->n_channels > 0)
    {
        *pos_subband++ = ieee80211_frequency_to_channel(siwifi_band_5GHz->channels[0].center_freq);
        *pos_subband++ = siwifi_band_5GHz->n_channels;
        subband_cnt++;
    }
    *pos = 2 * subband_cnt;
}
static void
siwifi_tdls_add_ext_capab(struct siwifi_hw *siwifi_hw, struct sk_buff *skb)
{
    u8 *pos = (void *)skb_put(skb, 7);
    bool chan_switch = siwifi_hw->wiphy->features &
               NL80211_FEATURE_TDLS_CHANNEL_SWITCH;
    *pos++ = WLAN_EID_EXT_CAPABILITY;
    *pos++ = 5;
    *pos++ = 0x0;
    *pos++ = 0x0;
    *pos++ = 0x0;
    *pos++ = WLAN_EXT_CAPA4_TDLS_BUFFER_STA |
             (chan_switch ? WLAN_EXT_CAPA4_TDLS_CHAN_SWITCH : 0);
    *pos++ = WLAN_EXT_CAPA5_TDLS_ENABLED;
}
static void
siwifi_add_wmm_info_ie(struct sk_buff *skb, u8 qosinfo)
{
    u8 *pos = (void *)skb_put(skb, 9);
    *pos++ = WLAN_EID_VENDOR_SPECIFIC;
    *pos++ = 7;
    *pos++ = 0x00;
    *pos++ = 0x50;
    *pos++ = 0xf2;
    *pos++ = 2;
    *pos++ = 0;
    *pos++ = 1;
    *pos++ = qosinfo;
}
static u8 siwifi_ac_from_wmm(int ac)
{
 switch (ac) {
 default:
  WARN_ON_ONCE(1);
 case 0:
  return AC_BE;
 case 1:
  return AC_BK;
 case 2:
  return AC_VI;
 case 3:
  return AC_VO;
 }
}
static void
siwifi_add_wmm_param_ie(struct sk_buff *skb, u8 acm_bits, u32 *ac_params)
{
    struct ieee80211_wmm_param_ie *wmm;
    int i, j;
    u8 cw_min, cw_max;
    bool acm;
    wmm = (void *)skb_put(skb, sizeof(struct ieee80211_wmm_param_ie));
    memset(wmm, 0, sizeof(*wmm));
    wmm->element_id = WLAN_EID_VENDOR_SPECIFIC;
    wmm->len = sizeof(*wmm) - 2;
    wmm->oui[0] = 0x00;
    wmm->oui[1] = 0x50;
    wmm->oui[2] = 0xf2;
    wmm->oui_type = 2;
    wmm->oui_subtype = 1;
    wmm->version = 1;
    wmm->qos_info = 0;
    for (i = 0; i < AC_MAX; i++) {
        j = siwifi_ac_from_wmm(i);
        cw_min = (ac_params[j] & 0xF0 ) >> 4;
        cw_max = (ac_params[j] & 0xF00 ) >> 8;
        acm = (acm_bits & (1 << j)) != 0;
        wmm->ac[i].aci_aifsn = (i << 5) | (acm << 4) | (ac_params[j] & 0xF);
        wmm->ac[i].cw = (cw_max << 4) | cw_min;
        wmm->ac[i].txop_limit = (ac_params[j] & 0x0FFFF000 ) >> 12;
    }
}
static void
siwifi_tdls_add_oper_classes(struct siwifi_vif *siwifi_vif, struct sk_buff *skb)
{
    u8 *pos;
    u8 op_class;
    struct cfg80211_chan_def chan_def;
    struct ieee80211_channel chan;
    chan.band = siwifi_vif->sta.ap->band;
    chan.center_freq = siwifi_vif->sta.ap->center_freq;
    chan_def.chan = &chan;
    chan_def.width = siwifi_vif->sta.ap->width;
    chan_def.center_freq1 = siwifi_vif->sta.ap->center_freq1;
    chan_def.center_freq2 = siwifi_vif->sta.ap->center_freq2;
    if (!ieee80211_chandef_to_operating_class(&chan_def, &op_class))
        return;
    pos = skb_put(skb, 4);
    *pos++ = WLAN_EID_SUPPORTED_REGULATORY_CLASSES;
    *pos++ = 2;
    *pos++ = op_class;
    *pos++ = op_class;
}
static void
siwifi_ie_build_ht_cap(struct sk_buff *skb, struct ieee80211_sta_ht_cap *ht_cap,
                  u16 cap)
{
    u8 *pos;
    __le16 tmp;
    pos = skb_put(skb, sizeof(struct ieee80211_ht_cap) + 2);
    *pos++ = WLAN_EID_HT_CAPABILITY;
    *pos++ = sizeof(struct ieee80211_ht_cap);
    memset(pos, 0, sizeof(struct ieee80211_ht_cap));
    tmp = cpu_to_le16(cap);
    memcpy(pos, &tmp, sizeof(u16));
    pos += sizeof(u16);
    *pos++ = ht_cap->ampdu_factor |
         (ht_cap->ampdu_density <<
            IEEE80211_HT_AMPDU_PARM_DENSITY_SHIFT);
    memcpy(pos, &ht_cap->mcs, sizeof(ht_cap->mcs));
    pos += sizeof(ht_cap->mcs);
    pos += sizeof(__le16);
    pos += sizeof(__le32);
    pos += sizeof(u8);
}
static void
siwifi_ie_build_vht_cap(struct sk_buff *skb, struct ieee80211_sta_vht_cap *vht_cap,
                   u32 cap)
{
    u8 *pos;
    __le32 tmp;
    pos = skb_put(skb, 14);
    *pos++ = WLAN_EID_VHT_CAPABILITY;
    *pos++ = sizeof(struct ieee80211_vht_cap);
    memset(pos, 0, sizeof(struct ieee80211_vht_cap));
    tmp = cpu_to_le32(cap);
    memcpy(pos, &tmp, sizeof(u32));
    pos += sizeof(u32);
    memcpy(pos, &vht_cap->vht_mcs, sizeof(vht_cap->vht_mcs));
    pos += sizeof(vht_cap->vht_mcs);
}
static void
siwifi_tdls_add_bss_coex_ie(struct sk_buff *skb)
{
    u8 *pos = (void *)skb_put(skb, 3);
    *pos++ = WLAN_EID_BSS_COEX_2040;
    *pos++ = 1;
    *pos++ = WLAN_BSS_COEX_INFORMATION_REQUEST;
}
static void
siwifi_tdls_add_link_ie(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                       struct sk_buff *skb, const u8 *peer,
                       bool initiator)
{
    struct ieee80211_tdls_lnkie *lnkid;
    const u8 *init_addr, *rsp_addr;
    if (initiator) {
        init_addr = siwifi_hw->wiphy->perm_addr;
        rsp_addr = peer;
    } else {
        init_addr = peer;
        rsp_addr = siwifi_hw->wiphy->perm_addr;
    }
    lnkid = (void *)skb_put(skb, sizeof(struct ieee80211_tdls_lnkie));
    lnkid->ie_type = WLAN_EID_LINK_ID;
    lnkid->ie_len = sizeof(struct ieee80211_tdls_lnkie) - 2;
    memcpy(lnkid->bssid, siwifi_vif->sta.ap->mac_addr, ETH_ALEN);
    memcpy(lnkid->init_sta, init_addr, ETH_ALEN);
    memcpy(lnkid->resp_sta, rsp_addr, ETH_ALEN);
}
static void
siwifi_tdls_add_aid_ie(struct siwifi_vif *siwifi_vif, struct sk_buff *skb)
{
    u8 *pos = (void *)skb_put(skb, 4);
    *pos++ = WLAN_EID_AID;
    *pos++ = 2;
    *pos++ = siwifi_vif->sta.ap->aid;
}
static u8 *
siwifi_ie_build_ht_oper(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                          u8 *pos, struct ieee80211_sta_ht_cap *ht_cap,
                          u16 prot_mode)
{
    struct ieee80211_ht_operation *ht_oper;
    *pos++ = WLAN_EID_HT_OPERATION;
    *pos++ = sizeof(struct ieee80211_ht_operation);
    ht_oper = (struct ieee80211_ht_operation *)pos;
    ht_oper->primary_chan = ieee80211_frequency_to_channel(
                    siwifi_vif->sta.ap->center_freq);
    switch (siwifi_vif->sta.ap->width) {
    case NL80211_CHAN_WIDTH_160:
    case NL80211_CHAN_WIDTH_80P80:
    case NL80211_CHAN_WIDTH_80:
    case NL80211_CHAN_WIDTH_40:
        if (siwifi_vif->sta.ap->center_freq1 > siwifi_vif->sta.ap->center_freq)
            ht_oper->ht_param = IEEE80211_HT_PARAM_CHA_SEC_ABOVE;
        else
            ht_oper->ht_param = IEEE80211_HT_PARAM_CHA_SEC_BELOW;
        break;
    default:
        ht_oper->ht_param = IEEE80211_HT_PARAM_CHA_SEC_NONE;
        break;
    }
    if (ht_cap->cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40 &&
        siwifi_vif->sta.ap->width != NL80211_CHAN_WIDTH_20_NOHT &&
        siwifi_vif->sta.ap->width != NL80211_CHAN_WIDTH_20)
        ht_oper->ht_param |= IEEE80211_HT_PARAM_CHAN_WIDTH_ANY;
    ht_oper->operation_mode = cpu_to_le16(prot_mode);
    ht_oper->stbc_param = 0x0000;
    memset(&ht_oper->basic_set, 0, 16);
    memcpy(&ht_oper->basic_set, &ht_cap->mcs, 10);
    return pos + sizeof(struct ieee80211_ht_operation);
}
static u8 *
siwifi_ie_build_vht_oper(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                          u8 *pos, struct ieee80211_sta_ht_cap *ht_cap,
                          u16 prot_mode)
{
    struct ieee80211_vht_operation *vht_oper;
    *pos++ = WLAN_EID_VHT_OPERATION;
    *pos++ = sizeof(struct ieee80211_vht_operation);
    vht_oper = (struct ieee80211_vht_operation *)pos;
    switch (siwifi_vif->sta.ap->width) {
    case NL80211_CHAN_WIDTH_80:
        vht_oper->chan_width = IEEE80211_VHT_CHANWIDTH_80MHZ;
        CCFS0(vht_oper) =
                ieee80211_frequency_to_channel(siwifi_vif->sta.ap->center_freq);
        CCFS1(vht_oper) = 0;
        break;
    case NL80211_CHAN_WIDTH_160:
        vht_oper->chan_width = IEEE80211_VHT_CHANWIDTH_160MHZ;
        CCFS0(vht_oper) =
                ieee80211_frequency_to_channel(siwifi_vif->sta.ap->center_freq);
        CCFS1(vht_oper) = 0;
        break;
    case NL80211_CHAN_WIDTH_80P80:
        vht_oper->chan_width = IEEE80211_VHT_CHANWIDTH_80P80MHZ;
        CCFS0(vht_oper) =
                ieee80211_frequency_to_channel(siwifi_vif->sta.ap->center_freq1);
        CCFS1(vht_oper) =
                ieee80211_frequency_to_channel(siwifi_vif->sta.ap->center_freq2);
        break;
    default:
        vht_oper->chan_width = IEEE80211_VHT_CHANWIDTH_USE_HT;
        CCFS0(vht_oper) = 0;
        CCFS1(vht_oper) = 0;
        break;
    }
    vht_oper->basic_mcs_set = cpu_to_le16(siwifi_hw->mod_params->mcs_map);
    return pos + sizeof(struct ieee80211_vht_operation);
}
static void
siwifi_tdls_add_setup_start_ies(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                              struct sk_buff *skb, const u8 *peer,
                              u8 action_code, bool initiator,
                              const u8 *extra_ies, size_t extra_ies_len)
{
    enum nl80211_band band = siwifi_vif->sta.ap->band;
    struct ieee80211_supported_band *sband;
    struct ieee80211_sta_ht_cap ht_cap;
    struct ieee80211_sta_vht_cap vht_cap;
    size_t offset = 0, noffset;
    u8 *pos;
    rcu_read_lock();
    siwifi_add_srates_ie(siwifi_hw, skb);
    siwifi_add_ext_srates_ie(siwifi_hw, skb);
    siwifi_tdls_add_supp_channels(siwifi_hw, skb);
    siwifi_tdls_add_ext_capab(siwifi_hw, skb);
    if (
        action_code != WLAN_PUB_ACTION_TDLS_DISCOVER_RES)
        siwifi_add_wmm_info_ie(skb, 0);
    siwifi_tdls_add_oper_classes(siwifi_vif, skb);
    sband = siwifi_hw->wiphy->bands[band];
    memcpy(&ht_cap, &sband->ht_cap, sizeof(ht_cap));
    if (((action_code == WLAN_TDLS_SETUP_REQUEST) ||
         (action_code == WLAN_TDLS_SETUP_RESPONSE) ||
         (action_code == WLAN_PUB_ACTION_TDLS_DISCOVER_RES)) &&
         ht_cap.ht_supported ) {
        siwifi_ie_build_ht_cap(skb, &ht_cap, ht_cap.cap);
    }
    if (ht_cap.ht_supported &&
        (ht_cap.cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40))
        siwifi_tdls_add_bss_coex_ie(skb);
    siwifi_tdls_add_link_ie(siwifi_hw, siwifi_vif, skb, peer, initiator);
    memcpy(&vht_cap, &sband->vht_cap, sizeof(vht_cap));
    if (vht_cap.vht_supported) {
        siwifi_tdls_add_aid_ie(siwifi_vif, skb);
        siwifi_ie_build_vht_cap(skb, &vht_cap, vht_cap.cap);
    }
    if (extra_ies_len) {
        noffset = extra_ies_len;
        pos = skb_put(skb, noffset - offset);
        memcpy(pos, extra_ies + offset, noffset - offset);
    }
    rcu_read_unlock();
}
static void
siwifi_tdls_add_setup_cfm_ies(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                              struct sk_buff *skb, const u8 *peer, bool initiator,
                              const u8 *extra_ies, size_t extra_ies_len)
{
    struct ieee80211_supported_band *sband;
    enum nl80211_band band = siwifi_vif->sta.ap->band;
    struct ieee80211_sta_ht_cap ht_cap;
    struct ieee80211_sta_vht_cap vht_cap;
    size_t offset = 0, noffset;
    struct siwifi_sta *sta, *ap_sta;
    u8 *pos;
    rcu_read_lock();
    sta = siwifi_get_sta(siwifi_hw, peer);
    ap_sta = siwifi_vif->sta.ap;
    if (WARN_ON_ONCE(!sta || !ap_sta)) {
        rcu_read_unlock();
        return;
    }
    if (sta->qos)
     siwifi_add_wmm_param_ie(skb, ap_sta->acm, ap_sta->ac_param);
    sband = siwifi_hw->wiphy->bands[band];
    memcpy(&ht_cap, &sband->ht_cap, sizeof(ht_cap));
    if (ht_cap.ht_supported && !ap_sta->ht && sta->ht) {
        pos = skb_put(skb, 2 + sizeof(struct ieee80211_ht_operation));
        siwifi_ie_build_ht_oper(siwifi_hw, siwifi_vif, pos, &ht_cap, 0);
    }
    siwifi_tdls_add_link_ie(siwifi_hw, siwifi_vif, skb, peer, initiator);
    memcpy(&vht_cap, &sband->vht_cap, sizeof(vht_cap));
    if (vht_cap.vht_supported && !ap_sta->vht && sta->vht) {
        pos = skb_put(skb, 2 + sizeof(struct ieee80211_vht_operation));
        siwifi_ie_build_vht_oper(siwifi_hw, siwifi_vif, pos, &ht_cap, 0);
    }
    if (extra_ies_len) {
        noffset = extra_ies_len;
        pos = skb_put(skb, noffset - offset);
        memcpy(pos, extra_ies + offset, noffset - offset);
    }
    rcu_read_unlock();
}
static void
siwifi_tdls_add_ies(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                                   struct sk_buff *skb, const u8 *peer,
                                   u8 action_code, u16 status_code,
                                   bool initiator, const u8 *extra_ies,
                                   size_t extra_ies_len, u8 oper_class,
                                   struct cfg80211_chan_def *chandef)
{
    switch (action_code) {
    case WLAN_TDLS_SETUP_REQUEST:
    case WLAN_TDLS_SETUP_RESPONSE:
    case WLAN_PUB_ACTION_TDLS_DISCOVER_RES:
        if (status_code == 0)
            siwifi_tdls_add_setup_start_ies(siwifi_hw, siwifi_vif, skb, peer, action_code,
                                          initiator, extra_ies, extra_ies_len);
        break;
    case WLAN_TDLS_SETUP_CONFIRM:
        if (status_code == 0)
            siwifi_tdls_add_setup_cfm_ies(siwifi_hw, siwifi_vif, skb, peer, initiator,
                                        extra_ies, extra_ies_len);
        break;
    case WLAN_TDLS_TEARDOWN:
    case WLAN_TDLS_DISCOVERY_REQUEST:
        if (extra_ies_len)
            memcpy(skb_put(skb, extra_ies_len), extra_ies,
                   extra_ies_len);
        if (status_code == 0 || action_code == WLAN_TDLS_TEARDOWN)
            siwifi_tdls_add_link_ie(siwifi_hw, siwifi_vif, skb, peer, initiator);
        break;
    }
}
int
siwifi_tdls_send_mgmt_packet_data(struct siwifi_hw *siwifi_hw, struct siwifi_vif *siwifi_vif,
                         const u8 *peer, u8 action_code, u8 dialog_token,
                         u16 status_code, u32 peer_capability, bool initiator,
                         const u8 *extra_ies, size_t extra_ies_len, u8 oper_class,
                         struct cfg80211_chan_def *chandef)
{
    struct sk_buff *skb;
    int ret = 0;
    struct ieee80211_supported_band *siwifi_band_2GHz = siwifi_hw->wiphy->bands[NL80211_BAND_2GHZ];
    struct ieee80211_supported_band *siwifi_band_5GHz = siwifi_hw->wiphy->bands[NL80211_BAND_5GHZ];
    skb = netdev_alloc_skb(siwifi_vif->ndev,
              sizeof(struct ieee80211_tdls_data) +
              10 +
              6 +
              (2 + siwifi_band_2GHz->n_channels + siwifi_band_5GHz->n_channels) +
              sizeof(struct ieee_types_extcap) +
              sizeof(struct ieee80211_wmm_param_ie) +
              4 +
              28 +
              sizeof(struct ieee_types_bss_co_2040) +
              sizeof(struct ieee80211_tdls_lnkie) +
              (2 + sizeof(struct ieee80211_vht_cap)) +
              4 +
              (2 + sizeof(struct ieee80211_ht_operation)) +
              extra_ies_len);
    if (!skb)
        return 0;
    switch (action_code) {
    case WLAN_TDLS_SETUP_REQUEST:
    case WLAN_TDLS_SETUP_RESPONSE:
    case WLAN_TDLS_SETUP_CONFIRM:
    case WLAN_TDLS_TEARDOWN:
    case WLAN_TDLS_DISCOVERY_REQUEST:
        ret = siwifi_tdls_prepare_encap_data(siwifi_hw, siwifi_vif, peer, action_code,
                                           dialog_token, status_code, skb);
        break;
    case WLAN_PUB_ACTION_TDLS_DISCOVER_RES:
        ret = siwifi_prep_tdls_direct(siwifi_hw, siwifi_vif, peer, action_code,
                                    dialog_token, status_code, skb);
        break;
    default:
        ret = -ENOTSUPP;
        break;
    }
    if (ret < 0)
        goto fail;
    siwifi_tdls_add_ies(siwifi_hw, siwifi_vif, skb, peer, action_code, status_code,
                      initiator, extra_ies, extra_ies_len, oper_class, chandef);
    if (action_code == WLAN_PUB_ACTION_TDLS_DISCOVER_RES) {
        u64 cookie;
        struct cfg80211_mgmt_tx_params params;
        params.len = skb->len;
        params.buf = skb->data;
        ret = siwifi_start_mgmt_xmit(siwifi_vif, NULL, &params, false, &cookie);
        return ret;
    }
    switch (action_code) {
    case WLAN_TDLS_SETUP_REQUEST:
    case WLAN_TDLS_SETUP_RESPONSE:
    case WLAN_TDLS_SETUP_CONFIRM:
        skb->priority = 2;
        break;
    default:
        skb->priority = 5;
        break;
    }
    ret = siwifi_select_txq(siwifi_vif, skb);
    ret = siwifi_start_xmit(skb, siwifi_vif->ndev);
   return ret;
fail:
    dev_kfree_skb(skb);
    return ret;
}
