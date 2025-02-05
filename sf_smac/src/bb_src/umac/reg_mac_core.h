#ifndef _REG_MAC_CORE_H_
#define _REG_MAC_CORE_H_ 
#ifndef __KERNEL__
#include <stdint.h>
#include "_reg_mac_core.h"
#include "compiler.h"
#include "arch.h"
#else
#include "ipc_compat.h"
#endif
#include "reg_access.h"
#define REG_MAC_CORE_COUNT 344
#define REG_MAC_CORE_DECODING_MASK 0x000007FF
#define NXMAC_SIGNATURE_ADDR REG_MAC_CORE_BASE_ADDR + 0x0000
#define NXMAC_SIGNATURE_OFFSET 0x00000000
#define NXMAC_SIGNATURE_INDEX 0x00000000
#define NXMAC_SIGNATURE_RESET 0x00000000
__INLINE uint32_t nxmac_signature_get(void)
{
    return REG_PL_RD(NXMAC_SIGNATURE_ADDR);
}
#define NXMAC_SIGNATURE_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_SIGNATURE_LSB 0
#define NXMAC_SIGNATURE_WIDTH ((uint32_t)0x00000020)
#define NXMAC_SIGNATURE_RST 0x0
__INLINE uint32_t nxmac_signature_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_SIGNATURE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_VERSION_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0004
#define NXMAC_VERSION_1_OFFSET 0x00000004
#define NXMAC_VERSION_1_INDEX 0x00000001
#define NXMAC_VERSION_1_RESET 0x00001C03
__INLINE uint32_t nxmac_version_1_get(void)
{
    return REG_PL_RD(NXMAC_VERSION_1_ADDR);
}
#define NXMAC_MU_MIMO_TX_BIT ((uint32_t)0x00080000)
#define NXMAC_MU_MIMO_TX_POS 19
#define NXMAC_BFMER_BIT ((uint32_t)0x00040000)
#define NXMAC_BFMER_POS 18
#define NXMAC_BFMEE_BIT ((uint32_t)0x00020000)
#define NXMAC_BFMEE_POS 17
#define NXMAC_MAC_80211MH_FORMAT_BIT ((uint32_t)0x00010000)
#define NXMAC_MAC_80211MH_FORMAT_POS 16
#define NXMAC_COEX_BIT ((uint32_t)0x00004000)
#define NXMAC_COEX_POS 14
#define NXMAC_WAPI_BIT ((uint32_t)0x00002000)
#define NXMAC_WAPI_POS 13
#define NXMAC_TPC_BIT ((uint32_t)0x00001000)
#define NXMAC_TPC_POS 12
#define NXMAC_VHT_BIT ((uint32_t)0x00000800)
#define NXMAC_VHT_POS 11
#define NXMAC_HT_BIT ((uint32_t)0x00000400)
#define NXMAC_HT_POS 10
#define NXMAC_RCE_BIT ((uint32_t)0x00000100)
#define NXMAC_RCE_POS 8
#define NXMAC_CCMP_BIT ((uint32_t)0x00000080)
#define NXMAC_CCMP_POS 7
#define NXMAC_TKIP_BIT ((uint32_t)0x00000040)
#define NXMAC_TKIP_POS 6
#define NXMAC_WEP_BIT ((uint32_t)0x00000020)
#define NXMAC_WEP_POS 5
#define NXMAC_SECURITY_BIT ((uint32_t)0x00000010)
#define NXMAC_SECURITY_POS 4
#define NXMAC_SME_BIT ((uint32_t)0x00000008)
#define NXMAC_SME_POS 3
#define NXMAC_HCCA_BIT ((uint32_t)0x00000004)
#define NXMAC_HCCA_POS 2
#define NXMAC_EDCA_BIT ((uint32_t)0x00000002)
#define NXMAC_EDCA_POS 1
#define NXMAC_QOS_BIT ((uint32_t)0x00000001)
#define NXMAC_QOS_POS 0
#define NXMAC_MAC_80211MH_FORMAT_RST 0x0
#define NXMAC_COEX_RST 0x0
#define NXMAC_WAPI_RST 0x0
#define NXMAC_TPC_RST 0x1
#define NXMAC_VHT_RST 0x1
#define NXMAC_HT_RST 0x1
#define NXMAC_RCE_RST 0x0
#define NXMAC_CCMP_RST 0x0
#define NXMAC_TKIP_RST 0x0
#define NXMAC_WEP_RST 0x0
#define NXMAC_SECURITY_RST 0x0
#define NXMAC_SME_RST 0x0
#define NXMAC_HCCA_RST 0x0
#define NXMAC_EDCA_RST 0x1
#define NXMAC_QOS_RST 0x1
__INLINE void nxmac_version_1_unpack(uint8_t* mac80211mhformat, uint8_t* coex, uint8_t* wapi, uint8_t* tpc, uint8_t* vht, uint8_t* ht, uint8_t* rce, uint8_t* ccmp, uint8_t* tkip, uint8_t* wep, uint8_t* security, uint8_t* sme, uint8_t* hcca, uint8_t* edca, uint8_t* qos)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    *mac80211mhformat = (localVal & ((uint32_t)0x00010000)) >> 16;
    *coex = (localVal & ((uint32_t)0x00004000)) >> 14;
    *wapi = (localVal & ((uint32_t)0x00002000)) >> 13;
    *tpc = (localVal & ((uint32_t)0x00001000)) >> 12;
    *vht = (localVal & ((uint32_t)0x00000800)) >> 11;
    *ht = (localVal & ((uint32_t)0x00000400)) >> 10;
    *rce = (localVal & ((uint32_t)0x00000100)) >> 8;
    *ccmp = (localVal & ((uint32_t)0x00000080)) >> 7;
    *tkip = (localVal & ((uint32_t)0x00000040)) >> 6;
    *wep = (localVal & ((uint32_t)0x00000020)) >> 5;
    *security = (localVal & ((uint32_t)0x00000010)) >> 4;
    *sme = (localVal & ((uint32_t)0x00000008)) >> 3;
    *hcca = (localVal & ((uint32_t)0x00000004)) >> 2;
    *edca = (localVal & ((uint32_t)0x00000002)) >> 1;
    *qos = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_mac_80211mh_format_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t nxmac_coex_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t nxmac_wapi_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t nxmac_tpc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t nxmac_vht_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t nxmac_ht_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t nxmac_rce_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t nxmac_ccmp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t nxmac_tkip_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t nxmac_wep_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t nxmac_security_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t nxmac_sme_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t nxmac_hcca_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t nxmac_edca_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t nxmac_qos_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
#define NXMAC_VERSION_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0008
#define NXMAC_VERSION_2_OFFSET 0x00000008
#define NXMAC_VERSION_2_INDEX 0x00000002
#define NXMAC_VERSION_2_RESET 0x00000000
__INLINE uint32_t nxmac_version_2_get(void)
{
    return REG_PL_RD(NXMAC_VERSION_2_ADDR);
}
#define NXMAC_PHASE_NUMBER_MASK ((uint32_t)0x0001C000)
#define NXMAC_PHASE_NUMBER_LSB 14
#define NXMAC_PHASE_NUMBER_WIDTH ((uint32_t)0x00000003)
#define NXMAC_RELEASE_NUMBER_MASK ((uint32_t)0x00003F00)
#define NXMAC_RELEASE_NUMBER_LSB 8
#define NXMAC_RELEASE_NUMBER_WIDTH ((uint32_t)0x00000006)
#define NXMAC_IE_RELEASE_BIT ((uint32_t)0x00000080)
#define NXMAC_IE_RELEASE_POS 7
#define NXMAC_UM_VERSION_MASK ((uint32_t)0x0000007F)
#define NXMAC_UM_VERSION_LSB 0
#define NXMAC_UM_VERSION_WIDTH ((uint32_t)0x00000007)
#define NXMAC_PHASE_NUMBER_RST 0x0
#define NXMAC_RELEASE_NUMBER_RST 0x0
#define NXMAC_IE_RELEASE_RST 0x0
#define NXMAC_UM_VERSION_RST 0x0
__INLINE void nxmac_version_2_unpack(uint8_t* phasenumber, uint8_t* releasenumber, uint8_t* ierelease, uint8_t* umversion)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_2_ADDR);
    *phasenumber = (localVal & ((uint32_t)0x0001C000)) >> 14;
    *releasenumber = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *ierelease = (localVal & ((uint32_t)0x00000080)) >> 7;
    *umversion = (localVal & ((uint32_t)0x0000007F)) >> 0;
}
__INLINE uint8_t nxmac_phase_number_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_2_ADDR);
    return ((localVal & ((uint32_t)0x0001C000)) >> 14);
}
__INLINE uint8_t nxmac_release_number_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_2_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE uint8_t nxmac_ie_release_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_2_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t nxmac_um_version_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VERSION_2_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}
#define NXMAC_BITMAP_CNT_ADDR REG_MAC_CORE_BASE_ADDR + 0x000C
#define NXMAC_BITMAP_CNT_OFFSET 0x0000000C
#define NXMAC_BITMAP_CNT_INDEX 0x00000003
#define NXMAC_BITMAP_CNT_RESET 0x00000000
__INLINE uint32_t nxmac_bitmap_cnt_get(void)
{
    return REG_PL_RD(NXMAC_BITMAP_CNT_ADDR);
}
#define NXMAC_BITMAP_CNT_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BITMAP_CNT_LSB 0
#define NXMAC_BITMAP_CNT_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BITMAP_CNT_RST 0x0
__INLINE uint16_t nxmac_bitmap_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BITMAP_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_MAC_ADDR_LOW_ADDR REG_MAC_CORE_BASE_ADDR + 0x0010
#define NXMAC_MAC_ADDR_LOW_OFFSET 0x00000010
#define NXMAC_MAC_ADDR_LOW_INDEX 0x00000004
#define NXMAC_MAC_ADDR_LOW_RESET 0x00000000
__INLINE uint32_t nxmac_mac_addr_low_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ADDR_LOW_ADDR);
}
__INLINE void nxmac_mac_addr_low_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ADDR_LOW_ADDR, value);
}
#define NXMAC_MAC_ADDR_LOW_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_MAC_ADDR_LOW_LSB 0
#define NXMAC_MAC_ADDR_LOW_WIDTH ((uint32_t)0x00000020)
#define NXMAC_MAC_ADDR_LOW_RST 0x0
__INLINE uint32_t nxmac_mac_addr_low_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ADDR_LOW_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_low_setf(uint32_t macaddrlow)
{
    ASSERT_ERR((((uint32_t)macaddrlow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_MAC_ADDR_LOW_ADDR, (uint32_t)macaddrlow << 0);
}
#define NXMAC_MAC_ADDR_HI_ADDR REG_MAC_CORE_BASE_ADDR + 0x0014
#define NXMAC_MAC_ADDR_HI_OFFSET 0x00000014
#define NXMAC_MAC_ADDR_HI_INDEX 0x00000005
#define NXMAC_MAC_ADDR_HI_RESET 0x00000000
__INLINE uint32_t nxmac_mac_addr_hi_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ADDR_HI_ADDR);
}
__INLINE void nxmac_mac_addr_hi_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ADDR_HI_ADDR, value);
}
#define NXMAC_MAC_ADDR_HIGH_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_MAC_ADDR_HIGH_LSB 0
#define NXMAC_MAC_ADDR_HIGH_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MAC_ADDR_HIGH_RST 0x0
__INLINE uint16_t nxmac_mac_addr_high_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ADDR_HI_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_high_setf(uint16_t macaddrhigh)
{
    ASSERT_ERR((((uint32_t)macaddrhigh << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_MAC_ADDR_HI_ADDR, (uint32_t)macaddrhigh << 0);
}
#define NXMAC_MAC_ADDR_LOW_MASK_ADDR REG_MAC_CORE_BASE_ADDR + 0x0018
#define NXMAC_MAC_ADDR_LOW_MASK_OFFSET 0x00000018
#define NXMAC_MAC_ADDR_LOW_MASK_INDEX 0x00000006
#define NXMAC_MAC_ADDR_LOW_MASK_RESET 0x00000000
__INLINE uint32_t nxmac_mac_addr_low_mask_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ADDR_LOW_MASK_ADDR);
}
__INLINE void nxmac_mac_addr_low_mask_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ADDR_LOW_MASK_ADDR, value);
}
#define NXMAC_MAC_ADDR_LOW_MASK_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_MAC_ADDR_LOW_MASK_LSB 0
#define NXMAC_MAC_ADDR_LOW_MASK_WIDTH ((uint32_t)0x00000020)
#define NXMAC_MAC_ADDR_LOW_MASK_RST 0x0
__INLINE uint32_t nxmac_mac_addr_low_mask_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ADDR_LOW_MASK_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_low_mask_setf(uint32_t macaddrlowmask)
{
    ASSERT_ERR((((uint32_t)macaddrlowmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_MAC_ADDR_LOW_MASK_ADDR, (uint32_t)macaddrlowmask << 0);
}
#define NXMAC_MAC_ADDR_HI_MASK_ADDR REG_MAC_CORE_BASE_ADDR + 0x001C
#define NXMAC_MAC_ADDR_HI_MASK_OFFSET 0x0000001C
#define NXMAC_MAC_ADDR_HI_MASK_INDEX 0x00000007
#define NXMAC_MAC_ADDR_HI_MASK_RESET 0x00000000
__INLINE uint32_t nxmac_mac_addr_hi_mask_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ADDR_HI_MASK_ADDR);
}
__INLINE void nxmac_mac_addr_hi_mask_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ADDR_HI_MASK_ADDR, value);
}
#define NXMAC_MAC_ADDR_HIGH_MASK_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_MAC_ADDR_HIGH_MASK_LSB 0
#define NXMAC_MAC_ADDR_HIGH_MASK_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MAC_ADDR_HIGH_MASK_RST 0x0
__INLINE uint16_t nxmac_mac_addr_high_mask_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ADDR_HI_MASK_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_high_mask_setf(uint16_t macaddrhighmask)
{
    ASSERT_ERR((((uint32_t)macaddrhighmask << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_MAC_ADDR_HI_MASK_ADDR, (uint32_t)macaddrhighmask << 0);
}
#define NXMAC_BSS_ID_LOW_ADDR REG_MAC_CORE_BASE_ADDR + 0x0020
#define NXMAC_BSS_ID_LOW_OFFSET 0x00000020
#define NXMAC_BSS_ID_LOW_INDEX 0x00000008
#define NXMAC_BSS_ID_LOW_RESET 0x00000000
__INLINE uint32_t nxmac_bss_id_low_get(void)
{
    return REG_PL_RD(NXMAC_BSS_ID_LOW_ADDR);
}
__INLINE void nxmac_bss_id_low_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BSS_ID_LOW_ADDR, value);
}
#define NXMAC_BSS_ID_LOW_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_BSS_ID_LOW_LSB 0
#define NXMAC_BSS_ID_LOW_WIDTH ((uint32_t)0x00000020)
#define NXMAC_BSS_ID_LOW_RST 0x0
__INLINE uint32_t nxmac_bss_id_low_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BSS_ID_LOW_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_id_low_setf(uint32_t bssidlow)
{
    ASSERT_ERR((((uint32_t)bssidlow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_BSS_ID_LOW_ADDR, (uint32_t)bssidlow << 0);
}
#define NXMAC_BSS_ID_HI_ADDR REG_MAC_CORE_BASE_ADDR + 0x0024
#define NXMAC_BSS_ID_HI_OFFSET 0x00000024
#define NXMAC_BSS_ID_HI_INDEX 0x00000009
#define NXMAC_BSS_ID_HI_RESET 0x00000000
__INLINE uint32_t nxmac_bss_id_hi_get(void)
{
    return REG_PL_RD(NXMAC_BSS_ID_HI_ADDR);
}
__INLINE void nxmac_bss_id_hi_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BSS_ID_HI_ADDR, value);
}
#define NXMAC_BSS_ID_HIGH_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BSS_ID_HIGH_LSB 0
#define NXMAC_BSS_ID_HIGH_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BSS_ID_HIGH_RST 0x0
__INLINE uint16_t nxmac_bss_id_high_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BSS_ID_HI_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_id_high_setf(uint16_t bssidhigh)
{
    ASSERT_ERR((((uint32_t)bssidhigh << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BSS_ID_HI_ADDR, (uint32_t)bssidhigh << 0);
}
#define NXMAC_BSS_ID_LOW_MASK_ADDR REG_MAC_CORE_BASE_ADDR + 0x0028
#define NXMAC_BSS_ID_LOW_MASK_OFFSET 0x00000028
#define NXMAC_BSS_ID_LOW_MASK_INDEX 0x0000000A
#define NXMAC_BSS_ID_LOW_MASK_RESET 0x00000000
__INLINE uint32_t nxmac_bss_id_low_mask_get(void)
{
    return REG_PL_RD(NXMAC_BSS_ID_LOW_MASK_ADDR);
}
__INLINE void nxmac_bss_id_low_mask_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BSS_ID_LOW_MASK_ADDR, value);
}
#define NXMAC_BSS_ID_LOW_MASK_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_BSS_ID_LOW_MASK_LSB 0
#define NXMAC_BSS_ID_LOW_MASK_WIDTH ((uint32_t)0x00000020)
#define NXMAC_BSS_ID_LOW_MASK_RST 0x0
__INLINE uint32_t nxmac_bss_id_low_mask_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BSS_ID_LOW_MASK_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_id_low_mask_setf(uint32_t bssidlowmask)
{
    ASSERT_ERR((((uint32_t)bssidlowmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_BSS_ID_LOW_MASK_ADDR, (uint32_t)bssidlowmask << 0);
}
#define NXMAC_BSS_ID_HI_MASK_ADDR REG_MAC_CORE_BASE_ADDR + 0x002C
#define NXMAC_BSS_ID_HI_MASK_OFFSET 0x0000002C
#define NXMAC_BSS_ID_HI_MASK_INDEX 0x0000000B
#define NXMAC_BSS_ID_HI_MASK_RESET 0x00000000
__INLINE uint32_t nxmac_bss_id_hi_mask_get(void)
{
    return REG_PL_RD(NXMAC_BSS_ID_HI_MASK_ADDR);
}
__INLINE void nxmac_bss_id_hi_mask_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BSS_ID_HI_MASK_ADDR, value);
}
#define NXMAC_BSS_ID_HIGH_MASK_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BSS_ID_HIGH_MASK_LSB 0
#define NXMAC_BSS_ID_HIGH_MASK_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BSS_ID_HIGH_MASK_RST 0x0
__INLINE uint16_t nxmac_bss_id_high_mask_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BSS_ID_HI_MASK_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_id_high_mask_setf(uint16_t bssidhighmask)
{
    ASSERT_ERR((((uint32_t)bssidhighmask << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BSS_ID_HI_MASK_ADDR, (uint32_t)bssidhighmask << 0);
}
#define NXMAC_STATE_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0038
#define NXMAC_STATE_CNTRL_OFFSET 0x00000038
#define NXMAC_STATE_CNTRL_INDEX 0x0000000E
#define NXMAC_STATE_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_state_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_STATE_CNTRL_ADDR);
}
__INLINE void nxmac_state_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_STATE_CNTRL_ADDR, value);
}
#define NXMAC_NEXT_STATE_MASK ((uint32_t)0x000000F0)
#define NXMAC_NEXT_STATE_LSB 4
#define NXMAC_NEXT_STATE_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CURRENT_STATE_MASK ((uint32_t)0x0000000F)
#define NXMAC_CURRENT_STATE_LSB 0
#define NXMAC_CURRENT_STATE_WIDTH ((uint32_t)0x00000004)
#define NXMAC_NEXT_STATE_RST 0x0
#define NXMAC_CURRENT_STATE_RST 0x0
__INLINE void nxmac_state_cntrl_unpack(uint8_t* nextstate, uint8_t* currentstate)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STATE_CNTRL_ADDR);
    *nextstate = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *currentstate = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint8_t nxmac_next_state_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STATE_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_next_state_setf(uint8_t nextstate)
{
    ASSERT_ERR((((uint32_t)nextstate << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_STATE_CNTRL_ADDR, (uint32_t)nextstate << 4);
}
__INLINE uint8_t nxmac_current_state_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STATE_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
#define NXMAC_SCAN_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x003C
#define NXMAC_SCAN_CNTRL_OFFSET 0x0000003C
#define NXMAC_SCAN_CNTRL_INDEX 0x0000000F
#define NXMAC_SCAN_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_scan_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_SCAN_CNTRL_ADDR);
}
__INLINE void nxmac_scan_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_SCAN_CNTRL_ADDR, value);
}
#define NXMAC_PROBE_DELAY_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_PROBE_DELAY_LSB 0
#define NXMAC_PROBE_DELAY_WIDTH ((uint32_t)0x00000010)
#define NXMAC_PROBE_DELAY_RST 0x0
__INLINE uint16_t nxmac_probe_delay_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_SCAN_CNTRL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_probe_delay_setf(uint16_t probedelay)
{
    ASSERT_ERR((((uint32_t)probedelay << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_SCAN_CNTRL_ADDR, (uint32_t)probedelay << 0);
}
#define NXMAC_DOZE_CNTRL_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0044
#define NXMAC_DOZE_CNTRL_1_OFFSET 0x00000044
#define NXMAC_DOZE_CNTRL_1_INDEX 0x00000011
#define NXMAC_DOZE_CNTRL_1_RESET 0x00000000
__INLINE uint32_t nxmac_doze_cntrl_1_get(void)
{
    return REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR);
}
__INLINE void nxmac_doze_cntrl_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DOZE_CNTRL_1_ADDR, value);
}
#define NXMAC_ATIM_W_MASK ((uint32_t)0xFFFE0000)
#define NXMAC_ATIM_W_LSB 17
#define NXMAC_ATIM_W_WIDTH ((uint32_t)0x0000000F)
#define NXMAC_WAKEUP_DTIM_BIT ((uint32_t)0x00010000)
#define NXMAC_WAKEUP_DTIM_POS 16
#define NXMAC_LISTEN_INTERVAL_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_LISTEN_INTERVAL_LSB 0
#define NXMAC_LISTEN_INTERVAL_WIDTH ((uint32_t)0x00000010)
#define NXMAC_ATIM_W_RST 0x0
#define NXMAC_WAKEUP_DTIM_RST 0x0
#define NXMAC_LISTEN_INTERVAL_RST 0x0
__INLINE void nxmac_doze_cntrl_1_pack(uint16_t atimw, uint8_t wakeupdtim, uint16_t listeninterval)
{
    ASSERT_ERR((((uint32_t)atimw << 17) & ~((uint32_t)0xFFFE0000)) == 0);
    ASSERT_ERR((((uint32_t)wakeupdtim << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)listeninterval << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_DOZE_CNTRL_1_ADDR, ((uint32_t)atimw << 17) | ((uint32_t)wakeupdtim << 16) | ((uint32_t)listeninterval << 0));
}
__INLINE void nxmac_doze_cntrl_1_unpack(uint16_t* atimw, uint8_t* wakeupdtim, uint16_t* listeninterval)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR);
    *atimw = (localVal & ((uint32_t)0xFFFE0000)) >> 17;
    *wakeupdtim = (localVal & ((uint32_t)0x00010000)) >> 16;
    *listeninterval = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint16_t nxmac_atim_w_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0xFFFE0000)) >> 17);
}
__INLINE void nxmac_atim_w_setf(uint16_t atimw)
{
    ASSERT_ERR((((uint32_t)atimw << 17) & ~((uint32_t)0xFFFE0000)) == 0);
    REG_PL_WR(NXMAC_DOZE_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR) & ~((uint32_t)0xFFFE0000)) | ((uint32_t)atimw << 17));
}
__INLINE uint8_t nxmac_wakeup_dtim_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void nxmac_wakeup_dtim_setf(uint8_t wakeupdtim)
{
    ASSERT_ERR((((uint32_t)wakeupdtim << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(NXMAC_DOZE_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)wakeupdtim << 16));
}
__INLINE uint16_t nxmac_listen_interval_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_listen_interval_setf(uint16_t listeninterval)
{
    ASSERT_ERR((((uint32_t)listeninterval << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_DOZE_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_DOZE_CNTRL_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)listeninterval << 0));
}
#define NXMAC_MAC_CNTRL_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x004C
#define NXMAC_MAC_CNTRL_1_OFFSET 0x0000004C
#define NXMAC_MAC_CNTRL_1_INDEX 0x00000013
#define NXMAC_MAC_CNTRL_1_RESET 0x0000C881
__INLINE uint32_t nxmac_mac_cntrl_1_get(void)
{
    return REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
}
__INLINE void nxmac_mac_cntrl_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, value);
}
#define NXMAC_RX_RIFS_EN_BIT ((uint32_t)0x04000000)
#define NXMAC_RX_RIFS_EN_POS 26
#define NXMAC_TSF_MGT_DISABLE_BIT ((uint32_t)0x02000000)
#define NXMAC_TSF_MGT_DISABLE_POS 25
#define NXMAC_TSF_UPDATED_BY_SW_BIT ((uint32_t)0x01000000)
#define NXMAC_TSF_UPDATED_BY_SW_POS 24
#define NXMAC_ABGN_MODE_MASK ((uint32_t)0x0001C000)
#define NXMAC_ABGN_MODE_LSB 14
#define NXMAC_ABGN_MODE_WIDTH ((uint32_t)0x00000003)
#define NXMAC_KEY_STO_RAM_RESET_BIT ((uint32_t)0x00002000)
#define NXMAC_KEY_STO_RAM_RESET_POS 13
#define NXMAC_MIB_TABLE_RESET_BIT ((uint32_t)0x00001000)
#define NXMAC_MIB_TABLE_RESET_POS 12
#define NXMAC_RATE_CONTROLLER_MPIF_BIT ((uint32_t)0x00000800)
#define NXMAC_RATE_CONTROLLER_MPIF_POS 11
#define NXMAC_DISABLE_BA_RESP_BIT ((uint32_t)0x00000400)
#define NXMAC_DISABLE_BA_RESP_POS 10
#define NXMAC_DISABLE_CTS_RESP_BIT ((uint32_t)0x00000200)
#define NXMAC_DISABLE_CTS_RESP_POS 9
#define NXMAC_DISABLE_ACK_RESP_BIT ((uint32_t)0x00000100)
#define NXMAC_DISABLE_ACK_RESP_POS 8
#define NXMAC_ACTIVE_CLK_GATING_BIT ((uint32_t)0x00000080)
#define NXMAC_ACTIVE_CLK_GATING_POS 7
#define NXMAC_ENABLE_LP_CLK_SWITCH_BIT ((uint32_t)0x00000040)
#define NXMAC_ENABLE_LP_CLK_SWITCH_POS 6
#define NXMAC_CFP_AWARE_BIT ((uint32_t)0x00000008)
#define NXMAC_CFP_AWARE_POS 3
#define NXMAC_PWR_MGT_BIT ((uint32_t)0x00000004)
#define NXMAC_PWR_MGT_POS 2
#define NXMAC_AP_BIT ((uint32_t)0x00000002)
#define NXMAC_AP_POS 1
#define NXMAC_BSS_TYPE_BIT ((uint32_t)0x00000001)
#define NXMAC_BSS_TYPE_POS 0
#define NXMAC_RX_RIFS_EN_RST 0x0
#define NXMAC_TSF_MGT_DISABLE_RST 0x0
#define NXMAC_TSF_UPDATED_BY_SW_RST 0x0
#define NXMAC_ABGN_MODE_RST 0x3
#define NXMAC_KEY_STO_RAM_RESET_RST 0x0
#define NXMAC_MIB_TABLE_RESET_RST 0x0
#define NXMAC_RATE_CONTROLLER_MPIF_RST 0x1
#define NXMAC_DISABLE_BA_RESP_RST 0x0
#define NXMAC_DISABLE_CTS_RESP_RST 0x0
#define NXMAC_DISABLE_ACK_RESP_RST 0x0
#define NXMAC_ACTIVE_CLK_GATING_RST 0x1
#define NXMAC_ENABLE_LP_CLK_SWITCH_RST 0x0
#define NXMAC_CFP_AWARE_RST 0x0
#define NXMAC_PWR_MGT_RST 0x0
#define NXMAC_AP_RST 0x0
#define NXMAC_BSS_TYPE_RST 0x1
__INLINE void nxmac_mac_cntrl_1_pack(uint8_t rxrifsen, uint8_t tsfmgtdisable, uint8_t tsfupdatedbysw, uint8_t abgnmode, uint8_t keystoramreset, uint8_t mibtablereset, uint8_t ratecontrollermpif, uint8_t disablebaresp, uint8_t disablectsresp, uint8_t disableackresp, uint8_t activeclkgating, uint8_t enablelpclkswitch, uint8_t cfpaware, uint8_t pwrmgt, uint8_t ap, uint8_t bsstype)
{
    ASSERT_ERR((((uint32_t)rxrifsen << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)tsfmgtdisable << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)tsfupdatedbysw << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)abgnmode << 14) & ~((uint32_t)0x0001C000)) == 0);
    ASSERT_ERR((((uint32_t)keystoramreset << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)mibtablereset << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)ratecontrollermpif << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)disablebaresp << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)disablectsresp << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)disableackresp << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)activeclkgating << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)enablelpclkswitch << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)cfpaware << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)pwrmgt << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)ap << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)bsstype << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, ((uint32_t)rxrifsen << 26) | ((uint32_t)tsfmgtdisable << 25) | ((uint32_t)tsfupdatedbysw << 24) | ((uint32_t)abgnmode << 14) | ((uint32_t)keystoramreset << 13) | ((uint32_t)mibtablereset << 12) | ((uint32_t)ratecontrollermpif << 11) | ((uint32_t)disablebaresp << 10) | ((uint32_t)disablectsresp << 9) | ((uint32_t)disableackresp << 8) | ((uint32_t)activeclkgating << 7) | ((uint32_t)enablelpclkswitch << 6) | ((uint32_t)cfpaware << 3) | ((uint32_t)pwrmgt << 2) | ((uint32_t)ap << 1) | ((uint32_t)bsstype << 0));
}
__INLINE void nxmac_mac_cntrl_1_unpack(uint8_t* rxrifsen, uint8_t* tsfmgtdisable, uint8_t* tsfupdatedbysw, uint8_t* abgnmode, uint8_t* keystoramreset, uint8_t* mibtablereset, uint8_t* ratecontrollermpif, uint8_t* disablebaresp, uint8_t* disablectsresp, uint8_t* disableackresp, uint8_t* activeclkgating, uint8_t* enablelpclkswitch, uint8_t* cfpaware, uint8_t* pwrmgt, uint8_t* ap, uint8_t* bsstype)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    *rxrifsen = (localVal & ((uint32_t)0x04000000)) >> 26;
    *tsfmgtdisable = (localVal & ((uint32_t)0x02000000)) >> 25;
    *tsfupdatedbysw = (localVal & ((uint32_t)0x01000000)) >> 24;
    *abgnmode = (localVal & ((uint32_t)0x0001C000)) >> 14;
    *keystoramreset = (localVal & ((uint32_t)0x00002000)) >> 13;
    *mibtablereset = (localVal & ((uint32_t)0x00001000)) >> 12;
    *ratecontrollermpif = (localVal & ((uint32_t)0x00000800)) >> 11;
    *disablebaresp = (localVal & ((uint32_t)0x00000400)) >> 10;
    *disablectsresp = (localVal & ((uint32_t)0x00000200)) >> 9;
    *disableackresp = (localVal & ((uint32_t)0x00000100)) >> 8;
    *activeclkgating = (localVal & ((uint32_t)0x00000080)) >> 7;
    *enablelpclkswitch = (localVal & ((uint32_t)0x00000040)) >> 6;
    *cfpaware = (localVal & ((uint32_t)0x00000008)) >> 3;
    *pwrmgt = (localVal & ((uint32_t)0x00000004)) >> 2;
    *ap = (localVal & ((uint32_t)0x00000002)) >> 1;
    *bsstype = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_rx_rifs_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void nxmac_rx_rifs_en_setf(uint8_t rxrifsen)
{
    ASSERT_ERR((((uint32_t)rxrifsen << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rxrifsen << 26));
}
__INLINE uint8_t nxmac_tsf_mgt_disable_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void nxmac_tsf_mgt_disable_setf(uint8_t tsfmgtdisable)
{
    ASSERT_ERR((((uint32_t)tsfmgtdisable << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)tsfmgtdisable << 25));
}
__INLINE uint8_t nxmac_tsf_updated_by_sw_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void nxmac_tsf_updated_by_sw_setf(uint8_t tsfupdatedbysw)
{
    ASSERT_ERR((((uint32_t)tsfupdatedbysw << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)tsfupdatedbysw << 24));
}
__INLINE uint8_t nxmac_abgn_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x0001C000)) >> 14);
}
__INLINE void nxmac_abgn_mode_setf(uint8_t abgnmode)
{
    ASSERT_ERR((((uint32_t)abgnmode << 14) & ~((uint32_t)0x0001C000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x0001C000)) | ((uint32_t)abgnmode << 14));
}
__INLINE uint8_t nxmac_key_sto_ram_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void nxmac_key_sto_ram_reset_setf(uint8_t keystoramreset)
{
    ASSERT_ERR((((uint32_t)keystoramreset << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)keystoramreset << 13));
}
__INLINE uint8_t nxmac_mib_table_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void nxmac_mib_table_reset_setf(uint8_t mibtablereset)
{
    ASSERT_ERR((((uint32_t)mibtablereset << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)mibtablereset << 12));
}
__INLINE uint8_t nxmac_rate_controller_mpif_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void nxmac_rate_controller_mpif_setf(uint8_t ratecontrollermpif)
{
    ASSERT_ERR((((uint32_t)ratecontrollermpif << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)ratecontrollermpif << 11));
}
__INLINE uint8_t nxmac_disable_ba_resp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void nxmac_disable_ba_resp_setf(uint8_t disablebaresp)
{
    ASSERT_ERR((((uint32_t)disablebaresp << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)disablebaresp << 10));
}
__INLINE uint8_t nxmac_disable_cts_resp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void nxmac_disable_cts_resp_setf(uint8_t disablectsresp)
{
    ASSERT_ERR((((uint32_t)disablectsresp << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)disablectsresp << 9));
}
__INLINE uint8_t nxmac_disable_ack_resp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void nxmac_disable_ack_resp_setf(uint8_t disableackresp)
{
    ASSERT_ERR((((uint32_t)disableackresp << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)disableackresp << 8));
}
__INLINE uint8_t nxmac_active_clk_gating_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void nxmac_active_clk_gating_setf(uint8_t activeclkgating)
{
    ASSERT_ERR((((uint32_t)activeclkgating << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)activeclkgating << 7));
}
__INLINE uint8_t nxmac_enable_lp_clk_switch_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void nxmac_enable_lp_clk_switch_setf(uint8_t enablelpclkswitch)
{
    ASSERT_ERR((((uint32_t)enablelpclkswitch << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)enablelpclkswitch << 6));
}
__INLINE uint8_t nxmac_cfp_aware_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_cfp_aware_setf(uint8_t cfpaware)
{
    ASSERT_ERR((((uint32_t)cfpaware << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)cfpaware << 3));
}
__INLINE uint8_t nxmac_pwr_mgt_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void nxmac_pwr_mgt_setf(uint8_t pwrmgt)
{
    ASSERT_ERR((((uint32_t)pwrmgt << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)pwrmgt << 2));
}
__INLINE uint8_t nxmac_ap_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_ap_setf(uint8_t ap)
{
    ASSERT_ERR((((uint32_t)ap << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ap << 1));
}
__INLINE uint8_t nxmac_bss_type_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_bss_type_setf(uint8_t bsstype)
{
    ASSERT_ERR((((uint32_t)bsstype << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_MAC_CNTRL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)bsstype << 0));
}
#define NXMAC_MAC_ERR_REC_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0054
#define NXMAC_MAC_ERR_REC_CNTRL_OFFSET 0x00000054
#define NXMAC_MAC_ERR_REC_CNTRL_INDEX 0x00000015
#define NXMAC_MAC_ERR_REC_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_mac_err_rec_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
}
__INLINE void nxmac_mac_err_rec_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, value);
}
#define NXMAC_RX_FLOW_CNTRL_EN_BIT ((uint32_t)0x00010000)
#define NXMAC_RX_FLOW_CNTRL_EN_POS 16
#define NXMAC_BA_PS_BITMAP_RESET_BIT ((uint32_t)0x00000080)
#define NXMAC_BA_PS_BITMAP_RESET_POS 7
#define NXMAC_ENCR_RX_FIFO_RESET_BIT ((uint32_t)0x00000040)
#define NXMAC_ENCR_RX_FIFO_RESET_POS 6
#define NXMAC_MAC_PHYIFFIFO_RESET_BIT ((uint32_t)0x00000020)
#define NXMAC_MAC_PHYIFFIFO_RESET_POS 5
#define NXMAC_TX_FIFO_RESET_BIT ((uint32_t)0x00000010)
#define NXMAC_TX_FIFO_RESET_POS 4
#define NXMAC_RX_FIFO_RESET_BIT ((uint32_t)0x00000008)
#define NXMAC_RX_FIFO_RESET_POS 3
#define NXMAC_HW_FSM_RESET_BIT ((uint32_t)0x00000004)
#define NXMAC_HW_FSM_RESET_POS 2
#define NXMAC_USE_ERR_DET_BIT ((uint32_t)0x00000002)
#define NXMAC_USE_ERR_DET_POS 1
#define NXMAC_USE_ERR_REC_BIT ((uint32_t)0x00000001)
#define NXMAC_USE_ERR_REC_POS 0
#define NXMAC_RX_FLOW_CNTRL_EN_RST 0x0
#define NXMAC_BA_PS_BITMAP_RESET_RST 0x0
#define NXMAC_ENCR_RX_FIFO_RESET_RST 0x0
#define NXMAC_MAC_PHYIFFIFO_RESET_RST 0x0
#define NXMAC_TX_FIFO_RESET_RST 0x0
#define NXMAC_RX_FIFO_RESET_RST 0x0
#define NXMAC_HW_FSM_RESET_RST 0x0
#define NXMAC_USE_ERR_DET_RST 0x0
#define NXMAC_USE_ERR_REC_RST 0x0
__INLINE void nxmac_mac_err_rec_cntrl_pack(uint8_t rxflowcntrlen, uint8_t bapsbitmapreset, uint8_t encrrxfiforeset, uint8_t macphyiffiforeset, uint8_t txfiforeset, uint8_t rxfiforeset, uint8_t hwfsmreset, uint8_t useerrdet)
{
    ASSERT_ERR((((uint32_t)rxflowcntrlen << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)bapsbitmapreset << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)encrrxfiforeset << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)macphyiffiforeset << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)txfiforeset << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)rxfiforeset << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)hwfsmreset << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)useerrdet << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, ((uint32_t)rxflowcntrlen << 16) | ((uint32_t)bapsbitmapreset << 7) | ((uint32_t)encrrxfiforeset << 6) | ((uint32_t)macphyiffiforeset << 5) | ((uint32_t)txfiforeset << 4) | ((uint32_t)rxfiforeset << 3) | ((uint32_t)hwfsmreset << 2) | ((uint32_t)useerrdet << 1));
}
__INLINE void nxmac_mac_err_rec_cntrl_unpack(uint8_t* rxflowcntrlen, uint8_t* bapsbitmapreset, uint8_t* encrrxfiforeset, uint8_t* macphyiffiforeset, uint8_t* txfiforeset, uint8_t* rxfiforeset, uint8_t* hwfsmreset, uint8_t* useerrdet, uint8_t* useerrrec)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    *rxflowcntrlen = (localVal & ((uint32_t)0x00010000)) >> 16;
    *bapsbitmapreset = (localVal & ((uint32_t)0x00000080)) >> 7;
    *encrrxfiforeset = (localVal & ((uint32_t)0x00000040)) >> 6;
    *macphyiffiforeset = (localVal & ((uint32_t)0x00000020)) >> 5;
    *txfiforeset = (localVal & ((uint32_t)0x00000010)) >> 4;
    *rxfiforeset = (localVal & ((uint32_t)0x00000008)) >> 3;
    *hwfsmreset = (localVal & ((uint32_t)0x00000004)) >> 2;
    *useerrdet = (localVal & ((uint32_t)0x00000002)) >> 1;
    *useerrrec = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_rx_flow_cntrl_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void nxmac_rx_flow_cntrl_en_setf(uint8_t rxflowcntrlen)
{
    ASSERT_ERR((((uint32_t)rxflowcntrlen << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rxflowcntrlen << 16));
}
__INLINE uint8_t nxmac_ba_ps_bitmap_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void nxmac_ba_ps_bitmap_reset_setf(uint8_t bapsbitmapreset)
{
    ASSERT_ERR((((uint32_t)bapsbitmapreset << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)bapsbitmapreset << 7));
}
__INLINE uint8_t nxmac_encr_rx_fifo_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void nxmac_encr_rx_fifo_reset_setf(uint8_t encrrxfiforeset)
{
    ASSERT_ERR((((uint32_t)encrrxfiforeset << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)encrrxfiforeset << 6));
}
__INLINE uint8_t nxmac_mac_phyiffifo_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void nxmac_mac_phyiffifo_reset_setf(uint8_t macphyiffiforeset)
{
    ASSERT_ERR((((uint32_t)macphyiffiforeset << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)macphyiffiforeset << 5));
}
__INLINE uint8_t nxmac_tx_fifo_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void nxmac_tx_fifo_reset_setf(uint8_t txfiforeset)
{
    ASSERT_ERR((((uint32_t)txfiforeset << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txfiforeset << 4));
}
__INLINE uint8_t nxmac_rx_fifo_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_rx_fifo_reset_setf(uint8_t rxfiforeset)
{
    ASSERT_ERR((((uint32_t)rxfiforeset << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)rxfiforeset << 3));
}
__INLINE uint8_t nxmac_hw_fsm_reset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void nxmac_hw_fsm_reset_setf(uint8_t hwfsmreset)
{
    ASSERT_ERR((((uint32_t)hwfsmreset << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)hwfsmreset << 2));
}
__INLINE uint8_t nxmac_use_err_det_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_use_err_det_setf(uint8_t useerrdet)
{
    ASSERT_ERR((((uint32_t)useerrdet << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_REC_CNTRL_ADDR, (REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)useerrdet << 1));
}
__INLINE uint8_t nxmac_use_err_rec_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_REC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
#define NXMAC_MAC_ERR_SET_STATUS_ADDR REG_MAC_CORE_BASE_ADDR + 0x0058
#define NXMAC_MAC_ERR_SET_STATUS_OFFSET 0x00000058
#define NXMAC_MAC_ERR_SET_STATUS_INDEX 0x00000016
#define NXMAC_MAC_ERR_SET_STATUS_RESET 0x00000000
__INLINE uint32_t nxmac_mac_err_set_status_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
}
__INLINE void nxmac_mac_err_set_status_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, value);
}
#define NXMAC_ERR_IN_HW_LEVEL_3_BIT ((uint32_t)0x00000008)
#define NXMAC_ERR_IN_HW_LEVEL_3_POS 3
#define NXMAC_ERR_IN_TX_RX_LEVEL_2_BIT ((uint32_t)0x00000004)
#define NXMAC_ERR_IN_TX_RX_LEVEL_2_POS 2
#define NXMAC_ERR_IN_RX_LEVEL_1_BIT ((uint32_t)0x00000002)
#define NXMAC_ERR_IN_RX_LEVEL_1_POS 1
#define NXMAC_ERR_IN_TX_LEVEL_1_BIT ((uint32_t)0x00000001)
#define NXMAC_ERR_IN_TX_LEVEL_1_POS 0
#define NXMAC_ERR_IN_HW_LEVEL_3_RST 0x0
#define NXMAC_ERR_IN_TX_RX_LEVEL_2_RST 0x0
#define NXMAC_ERR_IN_RX_LEVEL_1_RST 0x0
#define NXMAC_ERR_IN_TX_LEVEL_1_RST 0x0
__INLINE void nxmac_mac_err_set_status_pack(uint8_t errinhwlevel3, uint8_t errintxrxlevel2, uint8_t errinrxlevel1, uint8_t errintxlevel1)
{
    ASSERT_ERR((((uint32_t)errinhwlevel3 << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)errintxrxlevel2 << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)errinrxlevel1 << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)errintxlevel1 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, ((uint32_t)errinhwlevel3 << 3) | ((uint32_t)errintxrxlevel2 << 2) | ((uint32_t)errinrxlevel1 << 1) | ((uint32_t)errintxlevel1 << 0));
}
__INLINE void nxmac_mac_err_set_status_unpack(uint8_t* errinhwlevel3, uint8_t* errintxrxlevel2, uint8_t* errinrxlevel1, uint8_t* errintxlevel1)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
    *errinhwlevel3 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *errintxrxlevel2 = (localVal & ((uint32_t)0x00000004)) >> 2;
    *errinrxlevel1 = (localVal & ((uint32_t)0x00000002)) >> 1;
    *errintxlevel1 = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_err_in_hw_level_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_err_in_hw_level_3_setf(uint8_t errinhwlevel3)
{
    ASSERT_ERR((((uint32_t)errinhwlevel3 << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, (uint32_t)errinhwlevel3 << 3);
}
__INLINE uint8_t nxmac_err_in_tx_rx_level_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void nxmac_err_in_tx_rx_level_2_setf(uint8_t errintxrxlevel2)
{
    ASSERT_ERR((((uint32_t)errintxrxlevel2 << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, (uint32_t)errintxrxlevel2 << 2);
}
__INLINE uint8_t nxmac_err_in_rx_level_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_err_in_rx_level_1_setf(uint8_t errinrxlevel1)
{
    ASSERT_ERR((((uint32_t)errinrxlevel1 << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, (uint32_t)errinrxlevel1 << 1);
}
__INLINE uint8_t nxmac_err_in_tx_level_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_SET_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_err_in_tx_level_1_setf(uint8_t errintxlevel1)
{
    ASSERT_ERR((((uint32_t)errintxlevel1 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_SET_STATUS_ADDR, (uint32_t)errintxlevel1 << 0);
}
#define NXMAC_MAC_ERR_CLEAR_STATUS_ADDR REG_MAC_CORE_BASE_ADDR + 0x005C
#define NXMAC_MAC_ERR_CLEAR_STATUS_OFFSET 0x0000005C
#define NXMAC_MAC_ERR_CLEAR_STATUS_INDEX 0x00000017
#define NXMAC_MAC_ERR_CLEAR_STATUS_RESET 0x00000000
__INLINE uint32_t nxmac_mac_err_clear_status_get(void)
{
    return REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
}
__INLINE void nxmac_mac_err_clear_status_clear(uint32_t value)
{
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, value);
}
#define NXMAC_CLEAR_ERR_IN_HW_LEVEL_3_BIT ((uint32_t)0x00000008)
#define NXMAC_CLEAR_ERR_IN_HW_LEVEL_3_POS 3
#define NXMAC_CLEAR_ERR_IN_TX_RX_LEVEL_2_BIT ((uint32_t)0x00000004)
#define NXMAC_CLEAR_ERR_IN_TX_RX_LEVEL_2_POS 2
#define NXMAC_CLEAR_ERR_IN_RX_LEVEL_1_BIT ((uint32_t)0x00000002)
#define NXMAC_CLEAR_ERR_IN_RX_LEVEL_1_POS 1
#define NXMAC_CLEAR_ERR_IN_TX_LEVEL_1_BIT ((uint32_t)0x00000001)
#define NXMAC_CLEAR_ERR_IN_TX_LEVEL_1_POS 0
#define NXMAC_CLEAR_ERR_IN_HW_LEVEL_3_RST 0x0
#define NXMAC_CLEAR_ERR_IN_TX_RX_LEVEL_2_RST 0x0
#define NXMAC_CLEAR_ERR_IN_RX_LEVEL_1_RST 0x0
#define NXMAC_CLEAR_ERR_IN_TX_LEVEL_1_RST 0x0
__INLINE void nxmac_mac_err_clear_status_pack(uint8_t clearerrinhwlevel3, uint8_t clearerrintxrxlevel2, uint8_t clearerrinrxlevel1, uint8_t clearerrintxlevel1)
{
    ASSERT_ERR((((uint32_t)clearerrinhwlevel3 << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)clearerrintxrxlevel2 << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)clearerrinrxlevel1 << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)clearerrintxlevel1 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, ((uint32_t)clearerrinhwlevel3 << 3) | ((uint32_t)clearerrintxrxlevel2 << 2) | ((uint32_t)clearerrinrxlevel1 << 1) | ((uint32_t)clearerrintxlevel1 << 0));
}
__INLINE void nxmac_mac_err_clear_status_unpack(uint8_t* clearerrinhwlevel3, uint8_t* clearerrintxrxlevel2, uint8_t* clearerrinrxlevel1, uint8_t* clearerrintxlevel1)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
    *clearerrinhwlevel3 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *clearerrintxrxlevel2 = (localVal & ((uint32_t)0x00000004)) >> 2;
    *clearerrinrxlevel1 = (localVal & ((uint32_t)0x00000002)) >> 1;
    *clearerrintxlevel1 = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_clear_err_in_hw_level_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_clear_err_in_hw_level_3_clearf(uint8_t clearerrinhwlevel3)
{
    ASSERT_ERR((((uint32_t)clearerrinhwlevel3 << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, (uint32_t)clearerrinhwlevel3 << 3);
}
__INLINE uint8_t nxmac_clear_err_in_tx_rx_level_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void nxmac_clear_err_in_tx_rx_level_2_clearf(uint8_t clearerrintxrxlevel2)
{
    ASSERT_ERR((((uint32_t)clearerrintxrxlevel2 << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, (uint32_t)clearerrintxrxlevel2 << 2);
}
__INLINE uint8_t nxmac_clear_err_in_rx_level_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_clear_err_in_rx_level_1_clearf(uint8_t clearerrinrxlevel1)
{
    ASSERT_ERR((((uint32_t)clearerrinrxlevel1 << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, (uint32_t)clearerrinrxlevel1 << 1);
}
__INLINE uint8_t nxmac_clear_err_in_tx_level_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_clear_err_in_tx_level_1_clearf(uint8_t clearerrintxlevel1)
{
    ASSERT_ERR((((uint32_t)clearerrintxlevel1 << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_MAC_ERR_CLEAR_STATUS_ADDR, (uint32_t)clearerrintxlevel1 << 0);
}
#define NXMAC_RX_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0060
#define NXMAC_RX_CNTRL_OFFSET 0x00000060
#define NXMAC_RX_CNTRL_INDEX 0x00000018
#define NXMAC_RX_CNTRL_RESET 0x15078788
__INLINE uint32_t nxmac_rx_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
}
__INLINE void nxmac_rx_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, value);
}
#define NXMAC_EN_DUPLICATE_DETECTION_BIT ((uint32_t)0x80000000)
#define NXMAC_EN_DUPLICATE_DETECTION_POS 31
#define NXMAC_ACCEPT_UNKNOWN_BIT ((uint32_t)0x40000000)
#define NXMAC_ACCEPT_UNKNOWN_POS 30
#define NXMAC_ACCEPT_OTHER_DATA_FRAMES_BIT ((uint32_t)0x20000000)
#define NXMAC_ACCEPT_OTHER_DATA_FRAMES_POS 29
#define NXMAC_ACCEPT_QO_S_NULL_BIT ((uint32_t)0x10000000)
#define NXMAC_ACCEPT_QO_S_NULL_POS 28
#define NXMAC_ACCEPT_QCFWO_DATA_BIT ((uint32_t)0x08000000)
#define NXMAC_ACCEPT_QCFWO_DATA_POS 27
#define NXMAC_ACCEPT_Q_DATA_BIT ((uint32_t)0x04000000)
#define NXMAC_ACCEPT_Q_DATA_POS 26
#define NXMAC_ACCEPT_CFWO_DATA_BIT ((uint32_t)0x02000000)
#define NXMAC_ACCEPT_CFWO_DATA_POS 25
#define NXMAC_ACCEPT_DATA_BIT ((uint32_t)0x01000000)
#define NXMAC_ACCEPT_DATA_POS 24
#define NXMAC_ACCEPT_OTHER_CNTRL_FRAMES_BIT ((uint32_t)0x00800000)
#define NXMAC_ACCEPT_OTHER_CNTRL_FRAMES_POS 23
#define NXMAC_ACCEPT_CF_END_BIT ((uint32_t)0x00400000)
#define NXMAC_ACCEPT_CF_END_POS 22
#define NXMAC_ACCEPT_ACK_BIT ((uint32_t)0x00200000)
#define NXMAC_ACCEPT_ACK_POS 21
#define NXMAC_ACCEPT_CTS_BIT ((uint32_t)0x00100000)
#define NXMAC_ACCEPT_CTS_POS 20
#define NXMAC_ACCEPT_RTS_BIT ((uint32_t)0x00080000)
#define NXMAC_ACCEPT_RTS_POS 19
#define NXMAC_ACCEPT_PS_POLL_BIT ((uint32_t)0x00040000)
#define NXMAC_ACCEPT_PS_POLL_POS 18
#define NXMAC_ACCEPT_BA_BIT ((uint32_t)0x00020000)
#define NXMAC_ACCEPT_BA_POS 17
#define NXMAC_ACCEPT_BAR_BIT ((uint32_t)0x00010000)
#define NXMAC_ACCEPT_BAR_POS 16
#define NXMAC_ACCEPT_OTHER_MGMT_FRAMES_BIT ((uint32_t)0x00008000)
#define NXMAC_ACCEPT_OTHER_MGMT_FRAMES_POS 15
#define NXMAC_ACCEPT_ALL_BEACON_BIT ((uint32_t)0x00002000)
#define NXMAC_ACCEPT_ALL_BEACON_POS 13
#define NXMAC_ACCEPT_NOT_EXPECTED_BA_BIT ((uint32_t)0x00001000)
#define NXMAC_ACCEPT_NOT_EXPECTED_BA_POS 12
#define NXMAC_ACCEPT_DECRYPT_ERROR_FRAMES_BIT ((uint32_t)0x00000800)
#define NXMAC_ACCEPT_DECRYPT_ERROR_FRAMES_POS 11
#define NXMAC_ACCEPT_BEACON_BIT ((uint32_t)0x00000400)
#define NXMAC_ACCEPT_BEACON_POS 10
#define NXMAC_ACCEPT_PROBE_RESP_BIT ((uint32_t)0x00000200)
#define NXMAC_ACCEPT_PROBE_RESP_POS 9
#define NXMAC_ACCEPT_PROBE_REQ_BIT ((uint32_t)0x00000100)
#define NXMAC_ACCEPT_PROBE_REQ_POS 8
#define NXMAC_ACCEPT_MY_UNICAST_BIT ((uint32_t)0x00000080)
#define NXMAC_ACCEPT_MY_UNICAST_POS 7
#define NXMAC_ACCEPT_UNICAST_BIT ((uint32_t)0x00000040)
#define NXMAC_ACCEPT_UNICAST_POS 6
#define NXMAC_ACCEPT_ERROR_FRAMES_BIT ((uint32_t)0x00000020)
#define NXMAC_ACCEPT_ERROR_FRAMES_POS 5
#define NXMAC_ACCEPT_OTHER_BSSID_BIT ((uint32_t)0x00000010)
#define NXMAC_ACCEPT_OTHER_BSSID_POS 4
#define NXMAC_ACCEPT_BROADCAST_BIT ((uint32_t)0x00000008)
#define NXMAC_ACCEPT_BROADCAST_POS 3
#define NXMAC_ACCEPT_MULTICAST_BIT ((uint32_t)0x00000004)
#define NXMAC_ACCEPT_MULTICAST_POS 2
#define NXMAC_DONT_DECRYPT_BIT ((uint32_t)0x00000002)
#define NXMAC_DONT_DECRYPT_POS 1
#define NXMAC_EXC_UNENCRYPTED_BIT ((uint32_t)0x00000001)
#define NXMAC_EXC_UNENCRYPTED_POS 0
#define NXMAC_EN_DUPLICATE_DETECTION_RST 0x0
#define NXMAC_ACCEPT_UNKNOWN_RST 0x0
#define NXMAC_ACCEPT_OTHER_DATA_FRAMES_RST 0x0
#define NXMAC_ACCEPT_QO_S_NULL_RST 0x1
#define NXMAC_ACCEPT_QCFWO_DATA_RST 0x0
#define NXMAC_ACCEPT_Q_DATA_RST 0x1
#define NXMAC_ACCEPT_CFWO_DATA_RST 0x0
#define NXMAC_ACCEPT_DATA_RST 0x1
#define NXMAC_ACCEPT_OTHER_CNTRL_FRAMES_RST 0x0
#define NXMAC_ACCEPT_CF_END_RST 0x0
#define NXMAC_ACCEPT_ACK_RST 0x0
#define NXMAC_ACCEPT_CTS_RST 0x0
#define NXMAC_ACCEPT_RTS_RST 0x0
#define NXMAC_ACCEPT_PS_POLL_RST 0x1
#define NXMAC_ACCEPT_BA_RST 0x1
#define NXMAC_ACCEPT_BAR_RST 0x1
#define NXMAC_ACCEPT_OTHER_MGMT_FRAMES_RST 0x1
#define NXMAC_ACCEPT_ALL_BEACON_RST 0x0
#define NXMAC_ACCEPT_NOT_EXPECTED_BA_RST 0x0
#define NXMAC_ACCEPT_DECRYPT_ERROR_FRAMES_RST 0x0
#define NXMAC_ACCEPT_BEACON_RST 0x1
#define NXMAC_ACCEPT_PROBE_RESP_RST 0x1
#define NXMAC_ACCEPT_PROBE_REQ_RST 0x1
#define NXMAC_ACCEPT_MY_UNICAST_RST 0x1
#define NXMAC_ACCEPT_UNICAST_RST 0x0
#define NXMAC_ACCEPT_ERROR_FRAMES_RST 0x0
#define NXMAC_ACCEPT_OTHER_BSSID_RST 0x0
#define NXMAC_ACCEPT_BROADCAST_RST 0x1
#define NXMAC_ACCEPT_MULTICAST_RST 0x0
#define NXMAC_DONT_DECRYPT_RST 0x0
#define NXMAC_EXC_UNENCRYPTED_RST 0x0
__INLINE void nxmac_rx_cntrl_pack(uint8_t acceptunknown, uint8_t acceptotherdataframes, uint8_t acceptqosnull, uint8_t acceptqcfwodata, uint8_t acceptqdata, uint8_t acceptcfwodata, uint8_t acceptdata, uint8_t acceptothercntrlframes, uint8_t acceptcfend, uint8_t acceptack, uint8_t acceptcts, uint8_t acceptrts, uint8_t acceptpspoll, uint8_t acceptba, uint8_t acceptbar, uint8_t acceptothermgmtframes, uint8_t acceptallbeacon, uint8_t acceptnotexpectedba, uint8_t acceptdecrypterrorframes, uint8_t acceptbeacon, uint8_t acceptproberesp, uint8_t acceptprobereq, uint8_t acceptmyunicast, uint8_t acceptunicast, uint8_t accepterrorframes, uint8_t acceptotherbssid, uint8_t acceptbroadcast, uint8_t acceptmulticast, uint8_t dontdecrypt, uint8_t excunencrypted)
{
    ASSERT_ERR((((uint32_t)acceptunknown << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptotherdataframes << 29) & ~((uint32_t)0x20000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptqosnull << 28) & ~((uint32_t)0x10000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptqcfwodata << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptqdata << 26) & ~((uint32_t)0x04000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptcfwodata << 25) & ~((uint32_t)0x02000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptdata << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)acceptothercntrlframes << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)acceptcfend << 22) & ~((uint32_t)0x00400000)) == 0);
    ASSERT_ERR((((uint32_t)acceptack << 21) & ~((uint32_t)0x00200000)) == 0);
    ASSERT_ERR((((uint32_t)acceptcts << 20) & ~((uint32_t)0x00100000)) == 0);
    ASSERT_ERR((((uint32_t)acceptrts << 19) & ~((uint32_t)0x00080000)) == 0);
    ASSERT_ERR((((uint32_t)acceptpspoll << 18) & ~((uint32_t)0x00040000)) == 0);
    ASSERT_ERR((((uint32_t)acceptba << 17) & ~((uint32_t)0x00020000)) == 0);
    ASSERT_ERR((((uint32_t)acceptbar << 16) & ~((uint32_t)0x00010000)) == 0);
    ASSERT_ERR((((uint32_t)acceptothermgmtframes << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)acceptallbeacon << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)acceptnotexpectedba << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)acceptdecrypterrorframes << 11) & ~((uint32_t)0x00000800)) == 0);
    ASSERT_ERR((((uint32_t)acceptbeacon << 10) & ~((uint32_t)0x00000400)) == 0);
    ASSERT_ERR((((uint32_t)acceptproberesp << 9) & ~((uint32_t)0x00000200)) == 0);
    ASSERT_ERR((((uint32_t)acceptprobereq << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)acceptmyunicast << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)acceptunicast << 6) & ~((uint32_t)0x00000040)) == 0);
    ASSERT_ERR((((uint32_t)accepterrorframes << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)acceptotherbssid << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)acceptbroadcast << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)acceptmulticast << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)dontdecrypt << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)excunencrypted << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, ((uint32_t)acceptunknown << 30) | ((uint32_t)acceptotherdataframes << 29) | ((uint32_t)acceptqosnull << 28) | ((uint32_t)acceptqcfwodata << 27) | ((uint32_t)acceptqdata << 26) | ((uint32_t)acceptcfwodata << 25) | ((uint32_t)acceptdata << 24) | ((uint32_t)acceptothercntrlframes << 23) | ((uint32_t)acceptcfend << 22) | ((uint32_t)acceptack << 21) | ((uint32_t)acceptcts << 20) | ((uint32_t)acceptrts << 19) | ((uint32_t)acceptpspoll << 18) | ((uint32_t)acceptba << 17) | ((uint32_t)acceptbar << 16) | ((uint32_t)acceptothermgmtframes << 15) | ((uint32_t)acceptallbeacon << 13) | ((uint32_t)acceptnotexpectedba << 12) | ((uint32_t)acceptdecrypterrorframes << 11) | ((uint32_t)acceptbeacon << 10) | ((uint32_t)acceptproberesp << 9) | ((uint32_t)acceptprobereq << 8) | ((uint32_t)acceptmyunicast << 7) | ((uint32_t)acceptunicast << 6) | ((uint32_t)accepterrorframes << 5) | ((uint32_t)acceptotherbssid << 4) | ((uint32_t)acceptbroadcast << 3) | ((uint32_t)acceptmulticast << 2) | ((uint32_t)dontdecrypt << 1) | ((uint32_t)excunencrypted << 0));
}
__INLINE void nxmac_rx_cntrl_unpack(uint8_t* enduplicatedetection, uint8_t* acceptunknown, uint8_t* acceptotherdataframes, uint8_t* acceptqosnull, uint8_t* acceptqcfwodata, uint8_t* acceptqdata, uint8_t* acceptcfwodata, uint8_t* acceptdata, uint8_t* acceptothercntrlframes, uint8_t* acceptcfend, uint8_t* acceptack, uint8_t* acceptcts, uint8_t* acceptrts, uint8_t* acceptpspoll, uint8_t* acceptba, uint8_t* acceptbar, uint8_t* acceptothermgmtframes, uint8_t* acceptallbeacon, uint8_t* acceptnotexpectedba, uint8_t* acceptdecrypterrorframes, uint8_t* acceptbeacon, uint8_t* acceptproberesp, uint8_t* acceptprobereq, uint8_t* acceptmyunicast, uint8_t* acceptunicast, uint8_t* accepterrorframes, uint8_t* acceptotherbssid, uint8_t* acceptbroadcast, uint8_t* acceptmulticast, uint8_t* dontdecrypt, uint8_t* excunencrypted)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    *enduplicatedetection = (localVal & ((uint32_t)0x80000000)) >> 31;
    *acceptunknown = (localVal & ((uint32_t)0x40000000)) >> 30;
    *acceptotherdataframes = (localVal & ((uint32_t)0x20000000)) >> 29;
    *acceptqosnull = (localVal & ((uint32_t)0x10000000)) >> 28;
    *acceptqcfwodata = (localVal & ((uint32_t)0x08000000)) >> 27;
    *acceptqdata = (localVal & ((uint32_t)0x04000000)) >> 26;
    *acceptcfwodata = (localVal & ((uint32_t)0x02000000)) >> 25;
    *acceptdata = (localVal & ((uint32_t)0x01000000)) >> 24;
    *acceptothercntrlframes = (localVal & ((uint32_t)0x00800000)) >> 23;
    *acceptcfend = (localVal & ((uint32_t)0x00400000)) >> 22;
    *acceptack = (localVal & ((uint32_t)0x00200000)) >> 21;
    *acceptcts = (localVal & ((uint32_t)0x00100000)) >> 20;
    *acceptrts = (localVal & ((uint32_t)0x00080000)) >> 19;
    *acceptpspoll = (localVal & ((uint32_t)0x00040000)) >> 18;
    *acceptba = (localVal & ((uint32_t)0x00020000)) >> 17;
    *acceptbar = (localVal & ((uint32_t)0x00010000)) >> 16;
    *acceptothermgmtframes = (localVal & ((uint32_t)0x00008000)) >> 15;
    *acceptallbeacon = (localVal & ((uint32_t)0x00002000)) >> 13;
    *acceptnotexpectedba = (localVal & ((uint32_t)0x00001000)) >> 12;
    *acceptdecrypterrorframes = (localVal & ((uint32_t)0x00000800)) >> 11;
    *acceptbeacon = (localVal & ((uint32_t)0x00000400)) >> 10;
    *acceptproberesp = (localVal & ((uint32_t)0x00000200)) >> 9;
    *acceptprobereq = (localVal & ((uint32_t)0x00000100)) >> 8;
    *acceptmyunicast = (localVal & ((uint32_t)0x00000080)) >> 7;
    *acceptunicast = (localVal & ((uint32_t)0x00000040)) >> 6;
    *accepterrorframes = (localVal & ((uint32_t)0x00000020)) >> 5;
    *acceptotherbssid = (localVal & ((uint32_t)0x00000010)) >> 4;
    *acceptbroadcast = (localVal & ((uint32_t)0x00000008)) >> 3;
    *acceptmulticast = (localVal & ((uint32_t)0x00000004)) >> 2;
    *dontdecrypt = (localVal & ((uint32_t)0x00000002)) >> 1;
    *excunencrypted = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_en_duplicate_detection_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t nxmac_accept_unknown_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void nxmac_accept_unknown_setf(uint8_t acceptunknown)
{
    ASSERT_ERR((((uint32_t)acceptunknown << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)acceptunknown << 30));
}
__INLINE uint8_t nxmac_accept_other_data_frames_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void nxmac_accept_other_data_frames_setf(uint8_t acceptotherdataframes)
{
    ASSERT_ERR((((uint32_t)acceptotherdataframes << 29) & ~((uint32_t)0x20000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)acceptotherdataframes << 29));
}
__INLINE uint8_t nxmac_accept_qo_s_null_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void nxmac_accept_qo_s_null_setf(uint8_t acceptqosnull)
{
    ASSERT_ERR((((uint32_t)acceptqosnull << 28) & ~((uint32_t)0x10000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)acceptqosnull << 28));
}
__INLINE uint8_t nxmac_accept_qcfwo_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void nxmac_accept_qcfwo_data_setf(uint8_t acceptqcfwodata)
{
    ASSERT_ERR((((uint32_t)acceptqcfwodata << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)acceptqcfwodata << 27));
}
__INLINE uint8_t nxmac_accept_q_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void nxmac_accept_q_data_setf(uint8_t acceptqdata)
{
    ASSERT_ERR((((uint32_t)acceptqdata << 26) & ~((uint32_t)0x04000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)acceptqdata << 26));
}
__INLINE uint8_t nxmac_accept_cfwo_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void nxmac_accept_cfwo_data_setf(uint8_t acceptcfwodata)
{
    ASSERT_ERR((((uint32_t)acceptcfwodata << 25) & ~((uint32_t)0x02000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)acceptcfwodata << 25));
}
__INLINE uint8_t nxmac_accept_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void nxmac_accept_data_setf(uint8_t acceptdata)
{
    ASSERT_ERR((((uint32_t)acceptdata << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)acceptdata << 24));
}
__INLINE uint8_t nxmac_accept_other_cntrl_frames_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void nxmac_accept_other_cntrl_frames_setf(uint8_t acceptothercntrlframes)
{
    ASSERT_ERR((((uint32_t)acceptothercntrlframes << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)acceptothercntrlframes << 23));
}
__INLINE uint8_t nxmac_accept_cf_end_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void nxmac_accept_cf_end_setf(uint8_t acceptcfend)
{
    ASSERT_ERR((((uint32_t)acceptcfend << 22) & ~((uint32_t)0x00400000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)acceptcfend << 22));
}
__INLINE uint8_t nxmac_accept_ack_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void nxmac_accept_ack_setf(uint8_t acceptack)
{
    ASSERT_ERR((((uint32_t)acceptack << 21) & ~((uint32_t)0x00200000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)acceptack << 21));
}
__INLINE uint8_t nxmac_accept_cts_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void nxmac_accept_cts_setf(uint8_t acceptcts)
{
    ASSERT_ERR((((uint32_t)acceptcts << 20) & ~((uint32_t)0x00100000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)acceptcts << 20));
}
__INLINE uint8_t nxmac_accept_rts_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void nxmac_accept_rts_setf(uint8_t acceptrts)
{
    ASSERT_ERR((((uint32_t)acceptrts << 19) & ~((uint32_t)0x00080000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)acceptrts << 19));
}
__INLINE uint8_t nxmac_accept_ps_poll_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void nxmac_accept_ps_poll_setf(uint8_t acceptpspoll)
{
    ASSERT_ERR((((uint32_t)acceptpspoll << 18) & ~((uint32_t)0x00040000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)acceptpspoll << 18));
}
__INLINE uint8_t nxmac_accept_ba_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void nxmac_accept_ba_setf(uint8_t acceptba)
{
    ASSERT_ERR((((uint32_t)acceptba << 17) & ~((uint32_t)0x00020000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)acceptba << 17));
}
__INLINE uint8_t nxmac_accept_bar_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void nxmac_accept_bar_setf(uint8_t acceptbar)
{
    ASSERT_ERR((((uint32_t)acceptbar << 16) & ~((uint32_t)0x00010000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)acceptbar << 16));
}
__INLINE uint8_t nxmac_accept_other_mgmt_frames_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void nxmac_accept_other_mgmt_frames_setf(uint8_t acceptothermgmtframes)
{
    ASSERT_ERR((((uint32_t)acceptothermgmtframes << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)acceptothermgmtframes << 15));
}
__INLINE uint8_t nxmac_accept_all_beacon_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void nxmac_accept_all_beacon_setf(uint8_t acceptallbeacon)
{
    ASSERT_ERR((((uint32_t)acceptallbeacon << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)acceptallbeacon << 13));
}
__INLINE uint8_t nxmac_accept_not_expected_ba_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void nxmac_accept_not_expected_ba_setf(uint8_t acceptnotexpectedba)
{
    ASSERT_ERR((((uint32_t)acceptnotexpectedba << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)acceptnotexpectedba << 12));
}
__INLINE uint8_t nxmac_accept_decrypt_error_frames_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void nxmac_accept_decrypt_error_frames_setf(uint8_t acceptdecrypterrorframes)
{
    ASSERT_ERR((((uint32_t)acceptdecrypterrorframes << 11) & ~((uint32_t)0x00000800)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)acceptdecrypterrorframes << 11));
}
__INLINE uint8_t nxmac_accept_beacon_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void nxmac_accept_beacon_setf(uint8_t acceptbeacon)
{
    ASSERT_ERR((((uint32_t)acceptbeacon << 10) & ~((uint32_t)0x00000400)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)acceptbeacon << 10));
}
__INLINE uint8_t nxmac_accept_probe_resp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void nxmac_accept_probe_resp_setf(uint8_t acceptproberesp)
{
    ASSERT_ERR((((uint32_t)acceptproberesp << 9) & ~((uint32_t)0x00000200)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)acceptproberesp << 9));
}
__INLINE uint8_t nxmac_accept_probe_req_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void nxmac_accept_probe_req_setf(uint8_t acceptprobereq)
{
    ASSERT_ERR((((uint32_t)acceptprobereq << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)acceptprobereq << 8));
}
__INLINE uint8_t nxmac_accept_my_unicast_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void nxmac_accept_my_unicast_setf(uint8_t acceptmyunicast)
{
    ASSERT_ERR((((uint32_t)acceptmyunicast << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)acceptmyunicast << 7));
}
__INLINE uint8_t nxmac_accept_unicast_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void nxmac_accept_unicast_setf(uint8_t acceptunicast)
{
    ASSERT_ERR((((uint32_t)acceptunicast << 6) & ~((uint32_t)0x00000040)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)acceptunicast << 6));
}
__INLINE uint8_t nxmac_accept_error_frames_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void nxmac_accept_error_frames_setf(uint8_t accepterrorframes)
{
    ASSERT_ERR((((uint32_t)accepterrorframes << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)accepterrorframes << 5));
}
__INLINE uint8_t nxmac_accept_other_bssid_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void nxmac_accept_other_bssid_setf(uint8_t acceptotherbssid)
{
    ASSERT_ERR((((uint32_t)acceptotherbssid << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)acceptotherbssid << 4));
}
__INLINE uint8_t nxmac_accept_broadcast_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_accept_broadcast_setf(uint8_t acceptbroadcast)
{
    ASSERT_ERR((((uint32_t)acceptbroadcast << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)acceptbroadcast << 3));
}
__INLINE uint8_t nxmac_accept_multicast_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void nxmac_accept_multicast_setf(uint8_t acceptmulticast)
{
    ASSERT_ERR((((uint32_t)acceptmulticast << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)acceptmulticast << 2));
}
__INLINE uint8_t nxmac_dont_decrypt_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_dont_decrypt_setf(uint8_t dontdecrypt)
{
    ASSERT_ERR((((uint32_t)dontdecrypt << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dontdecrypt << 1));
}
__INLINE uint8_t nxmac_exc_unencrypted_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_exc_unencrypted_setf(uint8_t excunencrypted)
{
    ASSERT_ERR((((uint32_t)excunencrypted << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_RX_CNTRL_ADDR, (REG_PL_RD(NXMAC_RX_CNTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)excunencrypted << 0));
}
#define NXMAC_BCN_CNTRL_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0064
#define NXMAC_BCN_CNTRL_1_OFFSET 0x00000064
#define NXMAC_BCN_CNTRL_1_INDEX 0x00000019
#define NXMAC_BCN_CNTRL_1_RESET 0x00000000
__INLINE uint32_t nxmac_bcn_cntrl_1_get(void)
{
    return REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
}
__INLINE void nxmac_bcn_cntrl_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, value);
}
#define NXMAC_NO_BCN_TX_TIME_MASK ((uint32_t)0xFF000000)
#define NXMAC_NO_BCN_TX_TIME_LSB 24
#define NXMAC_NO_BCN_TX_TIME_WIDTH ((uint32_t)0x00000008)
#define NXMAC_IMP_TBTT_IN_128_US_BIT ((uint32_t)0x00800000)
#define NXMAC_IMP_TBTT_IN_128_US_POS 23
#define NXMAC_IMP_TBTT_PERIOD_MASK ((uint32_t)0x007F0000)
#define NXMAC_IMP_TBTT_PERIOD_LSB 16
#define NXMAC_IMP_TBTT_PERIOD_WIDTH ((uint32_t)0x00000007)
#define NXMAC_BEACON_INT_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BEACON_INT_LSB 0
#define NXMAC_BEACON_INT_WIDTH ((uint32_t)0x00000010)
#define NXMAC_NO_BCN_TX_TIME_RST 0x0
#define NXMAC_IMP_TBTT_IN_128_US_RST 0x0
#define NXMAC_IMP_TBTT_PERIOD_RST 0x0
#define NXMAC_BEACON_INT_RST 0x0
__INLINE void nxmac_bcn_cntrl_1_pack(uint8_t nobcntxtime, uint8_t imptbttin128us, uint8_t imptbttperiod, uint16_t beaconint)
{
    ASSERT_ERR((((uint32_t)nobcntxtime << 24) & ~((uint32_t)0xFF000000)) == 0);
    ASSERT_ERR((((uint32_t)imptbttin128us << 23) & ~((uint32_t)0x00800000)) == 0);
    ASSERT_ERR((((uint32_t)imptbttperiod << 16) & ~((uint32_t)0x007F0000)) == 0);
    ASSERT_ERR((((uint32_t)beaconint << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, ((uint32_t)nobcntxtime << 24) | ((uint32_t)imptbttin128us << 23) | ((uint32_t)imptbttperiod << 16) | ((uint32_t)beaconint << 0));
}
__INLINE void nxmac_bcn_cntrl_1_unpack(uint8_t* nobcntxtime, uint8_t* imptbttin128us, uint8_t* imptbttperiod, uint16_t* beaconint)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
    *nobcntxtime = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *imptbttin128us = (localVal & ((uint32_t)0x00800000)) >> 23;
    *imptbttperiod = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *beaconint = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint8_t nxmac_no_bcn_tx_time_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void nxmac_no_bcn_tx_time_setf(uint8_t nobcntxtime)
{
    ASSERT_ERR((((uint32_t)nobcntxtime << 24) & ~((uint32_t)0xFF000000)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)nobcntxtime << 24));
}
__INLINE uint8_t nxmac_imp_tbtt_in_128_us_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void nxmac_imp_tbtt_in_128_us_setf(uint8_t imptbttin128us)
{
    ASSERT_ERR((((uint32_t)imptbttin128us << 23) & ~((uint32_t)0x00800000)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)imptbttin128us << 23));
}
__INLINE uint8_t nxmac_imp_tbtt_period_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void nxmac_imp_tbtt_period_setf(uint8_t imptbttperiod)
{
    ASSERT_ERR((((uint32_t)imptbttperiod << 16) & ~((uint32_t)0x007F0000)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)imptbttperiod << 16));
}
__INLINE uint16_t nxmac_beacon_int_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_beacon_int_setf(uint16_t beaconint)
{
    ASSERT_ERR((((uint32_t)beaconint << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_1_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)beaconint << 0));
}
#define NXMAC_BCN_CNTRL_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0068
#define NXMAC_BCN_CNTRL_2_OFFSET 0x00000068
#define NXMAC_BCN_CNTRL_2_INDEX 0x0000001A
#define NXMAC_BCN_CNTRL_2_RESET 0x00000000
__INLINE uint32_t nxmac_bcn_cntrl_2_get(void)
{
    return REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR);
}
__INLINE void nxmac_bcn_cntrl_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BCN_CNTRL_2_ADDR, value);
}
#define NXMAC_AID_MASK ((uint32_t)0x0FFF0000)
#define NXMAC_AID_LSB 16
#define NXMAC_AID_WIDTH ((uint32_t)0x0000000C)
#define NXMAC_TIM_OFFSET_MASK ((uint32_t)0x0000FF00)
#define NXMAC_TIM_OFFSET_LSB 8
#define NXMAC_TIM_OFFSET_WIDTH ((uint32_t)0x00000008)
#define NXMAC_BCN_UPDATE_OFFSET_MASK ((uint32_t)0x000000FF)
#define NXMAC_BCN_UPDATE_OFFSET_LSB 0
#define NXMAC_BCN_UPDATE_OFFSET_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AID_RST 0x0
#define NXMAC_TIM_OFFSET_RST 0x0
#define NXMAC_BCN_UPDATE_OFFSET_RST 0x0
__INLINE void nxmac_bcn_cntrl_2_pack(uint16_t aid, uint8_t timoffset, uint8_t bcnupdateoffset)
{
    ASSERT_ERR((((uint32_t)aid << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    ASSERT_ERR((((uint32_t)timoffset << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)bcnupdateoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_2_ADDR, ((uint32_t)aid << 16) | ((uint32_t)timoffset << 8) | ((uint32_t)bcnupdateoffset << 0));
}
__INLINE void nxmac_bcn_cntrl_2_unpack(uint16_t* aid, uint8_t* timoffset, uint8_t* bcnupdateoffset)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR);
    *aid = (localVal & ((uint32_t)0x0FFF0000)) >> 16;
    *timoffset = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *bcnupdateoffset = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_aid_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR);
    return ((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void nxmac_aid_setf(uint16_t aid)
{
    ASSERT_ERR((((uint32_t)aid << 16) & ~((uint32_t)0x0FFF0000)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_2_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)aid << 16));
}
__INLINE uint8_t nxmac_tim_offset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_tim_offset_setf(uint8_t timoffset)
{
    ASSERT_ERR((((uint32_t)timoffset << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_2_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)timoffset << 8));
}
__INLINE uint8_t nxmac_bcn_update_offset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_bcn_update_offset_setf(uint8_t bcnupdateoffset)
{
    ASSERT_ERR((((uint32_t)bcnupdateoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_BCN_CNTRL_2_ADDR, (REG_PL_RD(NXMAC_BCN_CNTRL_2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bcnupdateoffset << 0));
}
#define NXMAC_DTIM_CFP_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0090
#define NXMAC_DTIM_CFP_1_OFFSET 0x00000090
#define NXMAC_DTIM_CFP_1_INDEX 0x00000024
#define NXMAC_DTIM_CFP_1_RESET 0x00000000
__INLINE uint32_t nxmac_dtim_cfp_1_get(void)
{
    return REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR);
}
__INLINE void nxmac_dtim_cfp_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DTIM_CFP_1_ADDR, value);
}
#define NXMAC_DTIM_UPDATED_BY_SW_BIT ((uint32_t)0x80000000)
#define NXMAC_DTIM_UPDATED_BY_SW_POS 31
#define NXMAC_CFP_PERIOD_MASK ((uint32_t)0x0000FF00)
#define NXMAC_CFP_PERIOD_LSB 8
#define NXMAC_CFP_PERIOD_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DTIM_PERIOD_MASK ((uint32_t)0x000000FF)
#define NXMAC_DTIM_PERIOD_LSB 0
#define NXMAC_DTIM_PERIOD_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DTIM_UPDATED_BY_SW_RST 0x0
#define NXMAC_CFP_PERIOD_RST 0x0
#define NXMAC_DTIM_PERIOD_RST 0x0
__INLINE void nxmac_dtim_cfp_1_pack(uint8_t dtimupdatedbysw, uint8_t cfpperiod, uint8_t dtimperiod)
{
    ASSERT_ERR((((uint32_t)dtimupdatedbysw << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)cfpperiod << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)dtimperiod << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_DTIM_CFP_1_ADDR, ((uint32_t)dtimupdatedbysw << 31) | ((uint32_t)cfpperiod << 8) | ((uint32_t)dtimperiod << 0));
}
__INLINE void nxmac_dtim_cfp_1_unpack(uint8_t* dtimupdatedbysw, uint8_t* cfpperiod, uint8_t* dtimperiod)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR);
    *dtimupdatedbysw = (localVal & ((uint32_t)0x80000000)) >> 31;
    *cfpperiod = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *dtimperiod = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_dtim_updated_by_sw_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void nxmac_dtim_updated_by_sw_setf(uint8_t dtimupdatedbysw)
{
    ASSERT_ERR((((uint32_t)dtimupdatedbysw << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(NXMAC_DTIM_CFP_1_ADDR, (REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)dtimupdatedbysw << 31));
}
__INLINE uint8_t nxmac_cfp_period_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_cfp_period_setf(uint8_t cfpperiod)
{
    ASSERT_ERR((((uint32_t)cfpperiod << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_DTIM_CFP_1_ADDR, (REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)cfpperiod << 8));
}
__INLINE uint8_t nxmac_dtim_period_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_dtim_period_setf(uint8_t dtimperiod)
{
    ASSERT_ERR((((uint32_t)dtimperiod << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_DTIM_CFP_1_ADDR, (REG_PL_RD(NXMAC_DTIM_CFP_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)dtimperiod << 0));
}
#define NXMAC_DTIM_CFP_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0094
#define NXMAC_DTIM_CFP_2_OFFSET 0x00000094
#define NXMAC_DTIM_CFP_2_INDEX 0x00000025
#define NXMAC_DTIM_CFP_2_RESET 0x00000000
__INLINE uint32_t nxmac_dtim_cfp_2_get(void)
{
    return REG_PL_RD(NXMAC_DTIM_CFP_2_ADDR);
}
__INLINE void nxmac_dtim_cfp_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DTIM_CFP_2_ADDR, value);
}
#define NXMAC_CFP_MAX_DURATION_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_CFP_MAX_DURATION_LSB 0
#define NXMAC_CFP_MAX_DURATION_WIDTH ((uint32_t)0x00000010)
#define NXMAC_CFP_MAX_DURATION_RST 0x0
__INLINE uint16_t nxmac_cfp_max_duration_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DTIM_CFP_2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_cfp_max_duration_setf(uint16_t cfpmaxduration)
{
    ASSERT_ERR((((uint32_t)cfpmaxduration << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_DTIM_CFP_2_ADDR, (uint32_t)cfpmaxduration << 0);
}
#define NXMAC_RETRY_LIMITS_ADDR REG_MAC_CORE_BASE_ADDR + 0x0098
#define NXMAC_RETRY_LIMITS_OFFSET 0x00000098
#define NXMAC_RETRY_LIMITS_INDEX 0x00000026
#define NXMAC_RETRY_LIMITS_RESET 0x00000407
__INLINE uint32_t nxmac_retry_limits_get(void)
{
    return REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR);
}
__INLINE void nxmac_retry_limits_set(uint32_t value)
{
    REG_PL_WR(NXMAC_RETRY_LIMITS_ADDR, value);
}
#define NXMAC_DOT_11_LONG_RETRY_LIMIT_MASK ((uint32_t)0x0000FF00)
#define NXMAC_DOT_11_LONG_RETRY_LIMIT_LSB 8
#define NXMAC_DOT_11_LONG_RETRY_LIMIT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DOT_11_SHORT_RETRY_LIMIT_MASK ((uint32_t)0x000000FF)
#define NXMAC_DOT_11_SHORT_RETRY_LIMIT_LSB 0
#define NXMAC_DOT_11_SHORT_RETRY_LIMIT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DOT_11_LONG_RETRY_LIMIT_RST 0x4
#define NXMAC_DOT_11_SHORT_RETRY_LIMIT_RST 0x7
__INLINE void nxmac_retry_limits_pack(uint8_t dot11longretrylimit, uint8_t dot11shortretrylimit)
{
    ASSERT_ERR((((uint32_t)dot11longretrylimit << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)dot11shortretrylimit << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_RETRY_LIMITS_ADDR, ((uint32_t)dot11longretrylimit << 8) | ((uint32_t)dot11shortretrylimit << 0));
}
__INLINE void nxmac_retry_limits_unpack(uint8_t* dot11longretrylimit, uint8_t* dot11shortretrylimit)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR);
    *dot11longretrylimit = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *dot11shortretrylimit = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_dot_11_long_retry_limit_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_dot_11_long_retry_limit_setf(uint8_t dot11longretrylimit)
{
    ASSERT_ERR((((uint32_t)dot11longretrylimit << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_RETRY_LIMITS_ADDR, (REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)dot11longretrylimit << 8));
}
__INLINE uint8_t nxmac_dot_11_short_retry_limit_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_dot_11_short_retry_limit_setf(uint8_t dot11shortretrylimit)
{
    ASSERT_ERR((((uint32_t)dot11shortretrylimit << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_RETRY_LIMITS_ADDR, (REG_PL_RD(NXMAC_RETRY_LIMITS_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)dot11shortretrylimit << 0));
}
#define NXMAC_BB_SERVICE_ADDR REG_MAC_CORE_BASE_ADDR + 0x009C
#define NXMAC_BB_SERVICE_OFFSET 0x0000009C
#define NXMAC_BB_SERVICE_INDEX 0x00000027
#define NXMAC_BB_SERVICE_RESET 0x08000000
__INLINE uint32_t nxmac_bb_service_get(void)
{
    return REG_PL_RD(NXMAC_BB_SERVICE_ADDR);
}
__INLINE void nxmac_bb_service_set(uint32_t value)
{
    REG_PL_WR(NXMAC_BB_SERVICE_ADDR, value);
}
#define NXMAC_MAX_PHY_NTX_MASK ((uint32_t)0x1C000000)
#define NXMAC_MAX_PHY_NTX_LSB 26
#define NXMAC_MAX_PHY_NTX_WIDTH ((uint32_t)0x00000003)
#define NXMAC_BB_SERVICE_B_MASK ((uint32_t)0x00FF0000)
#define NXMAC_BB_SERVICE_B_LSB 16
#define NXMAC_BB_SERVICE_B_WIDTH ((uint32_t)0x00000008)
#define NXMAC_BB_SERVICE_A_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BB_SERVICE_A_LSB 0
#define NXMAC_BB_SERVICE_A_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MAX_PHY_NTX_RST 0x2
#define NXMAC_BB_SERVICE_B_RST 0x0
#define NXMAC_BB_SERVICE_A_RST 0x0
__INLINE void nxmac_bb_service_pack(uint8_t maxphyntx, uint8_t bbserviceb, uint16_t bbservicea)
{
    ASSERT_ERR((((uint32_t)maxphyntx << 26) & ~((uint32_t)0x1C000000)) == 0);
    ASSERT_ERR((((uint32_t)bbserviceb << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)bbservicea << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BB_SERVICE_ADDR, ((uint32_t)maxphyntx << 26) | ((uint32_t)bbserviceb << 16) | ((uint32_t)bbservicea << 0));
}
__INLINE void nxmac_bb_service_unpack(uint8_t* maxphyntx, uint8_t* bbserviceb, uint16_t* bbservicea)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BB_SERVICE_ADDR);
    *maxphyntx = (localVal & ((uint32_t)0x1C000000)) >> 26;
    *bbserviceb = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *bbservicea = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint8_t nxmac_max_phy_ntx_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BB_SERVICE_ADDR);
    return ((localVal & ((uint32_t)0x1C000000)) >> 26);
}
__INLINE void nxmac_max_phy_ntx_setf(uint8_t maxphyntx)
{
    ASSERT_ERR((((uint32_t)maxphyntx << 26) & ~((uint32_t)0x1C000000)) == 0);
    REG_PL_WR(NXMAC_BB_SERVICE_ADDR, (REG_PL_RD(NXMAC_BB_SERVICE_ADDR) & ~((uint32_t)0x1C000000)) | ((uint32_t)maxphyntx << 26));
}
__INLINE uint8_t nxmac_bb_service_b_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BB_SERVICE_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_bb_service_b_setf(uint8_t bbserviceb)
{
    ASSERT_ERR((((uint32_t)bbserviceb << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_BB_SERVICE_ADDR, (REG_PL_RD(NXMAC_BB_SERVICE_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)bbserviceb << 16));
}
__INLINE uint16_t nxmac_bb_service_a_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_BB_SERVICE_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_bb_service_a_setf(uint16_t bbservicea)
{
    ASSERT_ERR((((uint32_t)bbservicea << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_BB_SERVICE_ADDR, (REG_PL_RD(NXMAC_BB_SERVICE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)bbservicea << 0));
}
#define NXMAC_MAX_POWER_LEVEL_ADDR REG_MAC_CORE_BASE_ADDR + 0x00A0
#define NXMAC_MAX_POWER_LEVEL_OFFSET 0x000000A0
#define NXMAC_MAX_POWER_LEVEL_INDEX 0x00000028
#define NXMAC_MAX_POWER_LEVEL_RESET 0x00000404
__INLINE uint32_t nxmac_max_power_level_get(void)
{
    return REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR);
}
__INLINE void nxmac_max_power_level_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAX_POWER_LEVEL_ADDR, value);
}
#define NXMAC_DSSS_MAX_PWR_LEVEL_MASK ((uint32_t)0x0000FF00)
#define NXMAC_DSSS_MAX_PWR_LEVEL_LSB 8
#define NXMAC_DSSS_MAX_PWR_LEVEL_WIDTH ((uint32_t)0x00000008)
#define NXMAC_OFDM_MAX_PWR_LEVEL_MASK ((uint32_t)0x000000FF)
#define NXMAC_OFDM_MAX_PWR_LEVEL_LSB 0
#define NXMAC_OFDM_MAX_PWR_LEVEL_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DSSS_MAX_PWR_LEVEL_RST 0x4
#define NXMAC_OFDM_MAX_PWR_LEVEL_RST 0x4
__INLINE void nxmac_max_power_level_pack(uint8_t dsssmaxpwrlevel, uint8_t ofdmmaxpwrlevel)
{
    ASSERT_ERR((((uint32_t)dsssmaxpwrlevel << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)ofdmmaxpwrlevel << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_MAX_POWER_LEVEL_ADDR, ((uint32_t)dsssmaxpwrlevel << 8) | ((uint32_t)ofdmmaxpwrlevel << 0));
}
__INLINE void nxmac_max_power_level_unpack(uint8_t* dsssmaxpwrlevel, uint8_t* ofdmmaxpwrlevel)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR);
    *dsssmaxpwrlevel = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *ofdmmaxpwrlevel = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_dsss_max_pwr_level_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_dsss_max_pwr_level_setf(uint8_t dsssmaxpwrlevel)
{
    ASSERT_ERR((((uint32_t)dsssmaxpwrlevel << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_MAX_POWER_LEVEL_ADDR, (REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)dsssmaxpwrlevel << 8));
}
__INLINE uint8_t nxmac_ofdm_max_pwr_level_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_ofdm_max_pwr_level_setf(uint8_t ofdmmaxpwrlevel)
{
    ASSERT_ERR((((uint32_t)ofdmmaxpwrlevel << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_MAX_POWER_LEVEL_ADDR, (REG_PL_RD(NXMAC_MAX_POWER_LEVEL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)ofdmmaxpwrlevel << 0));
}
#define NXMAC_ENCR_KEY_0_ADDR REG_MAC_CORE_BASE_ADDR + 0x00AC
#define NXMAC_ENCR_KEY_0_OFFSET 0x000000AC
#define NXMAC_ENCR_KEY_0_INDEX 0x0000002B
#define NXMAC_ENCR_KEY_0_RESET 0x00000000
__INLINE uint32_t nxmac_encr_key_0_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_KEY_0_ADDR);
}
__INLINE void nxmac_encr_key_0_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_KEY_0_ADDR, value);
}
#define NXMAC_ENCR_KEY_RAM_WORD_0_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_KEY_RAM_WORD_0_LSB 0
#define NXMAC_ENCR_KEY_RAM_WORD_0_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_KEY_RAM_WORD_0_RST 0x0
__INLINE uint32_t nxmac_encr_key_ram_word_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_KEY_0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_key_ram_word_0_setf(uint32_t encrkeyramword0)
{
    ASSERT_ERR((((uint32_t)encrkeyramword0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_KEY_0_ADDR, (uint32_t)encrkeyramword0 << 0);
}
#define NXMAC_ENCR_KEY_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x00B0
#define NXMAC_ENCR_KEY_1_OFFSET 0x000000B0
#define NXMAC_ENCR_KEY_1_INDEX 0x0000002C
#define NXMAC_ENCR_KEY_1_RESET 0x00000000
__INLINE uint32_t nxmac_encr_key_1_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_KEY_1_ADDR);
}
__INLINE void nxmac_encr_key_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_KEY_1_ADDR, value);
}
#define NXMAC_ENCR_KEY_RAM_WORD_1_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_KEY_RAM_WORD_1_LSB 0
#define NXMAC_ENCR_KEY_RAM_WORD_1_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_KEY_RAM_WORD_1_RST 0x0
__INLINE uint32_t nxmac_encr_key_ram_word_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_KEY_1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_key_ram_word_1_setf(uint32_t encrkeyramword1)
{
    ASSERT_ERR((((uint32_t)encrkeyramword1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_KEY_1_ADDR, (uint32_t)encrkeyramword1 << 0);
}
#define NXMAC_ENCR_KEY_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x00B4
#define NXMAC_ENCR_KEY_2_OFFSET 0x000000B4
#define NXMAC_ENCR_KEY_2_INDEX 0x0000002D
#define NXMAC_ENCR_KEY_2_RESET 0x00000000
__INLINE uint32_t nxmac_encr_key_2_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_KEY_2_ADDR);
}
__INLINE void nxmac_encr_key_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_KEY_2_ADDR, value);
}
#define NXMAC_ENCR_KEY_RAM_WORD_2_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_KEY_RAM_WORD_2_LSB 0
#define NXMAC_ENCR_KEY_RAM_WORD_2_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_KEY_RAM_WORD_2_RST 0x0
__INLINE uint32_t nxmac_encr_key_ram_word_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_KEY_2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_key_ram_word_2_setf(uint32_t encrkeyramword2)
{
    ASSERT_ERR((((uint32_t)encrkeyramword2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_KEY_2_ADDR, (uint32_t)encrkeyramword2 << 0);
}
#define NXMAC_ENCR_KEY_3_ADDR REG_MAC_CORE_BASE_ADDR + 0x00B8
#define NXMAC_ENCR_KEY_3_OFFSET 0x000000B8
#define NXMAC_ENCR_KEY_3_INDEX 0x0000002E
#define NXMAC_ENCR_KEY_3_RESET 0x00000000
__INLINE uint32_t nxmac_encr_key_3_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_KEY_3_ADDR);
}
__INLINE void nxmac_encr_key_3_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_KEY_3_ADDR, value);
}
#define NXMAC_ENCR_KEY_RAM_WORD_3_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_KEY_RAM_WORD_3_LSB 0
#define NXMAC_ENCR_KEY_RAM_WORD_3_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_KEY_RAM_WORD_3_RST 0x0
__INLINE uint32_t nxmac_encr_key_ram_word_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_KEY_3_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_key_ram_word_3_setf(uint32_t encrkeyramword3)
{
    ASSERT_ERR((((uint32_t)encrkeyramword3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_KEY_3_ADDR, (uint32_t)encrkeyramword3 << 0);
}
#define NXMAC_ENCR_MAC_ADDR_LOW_ADDR REG_MAC_CORE_BASE_ADDR + 0x00BC
#define NXMAC_ENCR_MAC_ADDR_LOW_OFFSET 0x000000BC
#define NXMAC_ENCR_MAC_ADDR_LOW_INDEX 0x0000002F
#define NXMAC_ENCR_MAC_ADDR_LOW_RESET 0xFFFFFFFF
__INLINE uint32_t nxmac_encr_mac_addr_low_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_MAC_ADDR_LOW_ADDR);
}
__INLINE void nxmac_encr_mac_addr_low_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_MAC_ADDR_LOW_ADDR, value);
}
#define NXMAC_MAC_ADDR_RAM_LOW_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_MAC_ADDR_RAM_LOW_LSB 0
#define NXMAC_MAC_ADDR_RAM_LOW_WIDTH ((uint32_t)0x00000020)
#define NXMAC_MAC_ADDR_RAM_LOW_RST 0xFFFFFFFF
__INLINE uint32_t nxmac_mac_addr_ram_low_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_MAC_ADDR_LOW_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_ram_low_setf(uint32_t macaddrramlow)
{
    ASSERT_ERR((((uint32_t)macaddrramlow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_MAC_ADDR_LOW_ADDR, (uint32_t)macaddrramlow << 0);
}
#define NXMAC_ENCR_MAC_ADDR_HIGH_ADDR REG_MAC_CORE_BASE_ADDR + 0x00C0
#define NXMAC_ENCR_MAC_ADDR_HIGH_OFFSET 0x000000C0
#define NXMAC_ENCR_MAC_ADDR_HIGH_INDEX 0x00000030
#define NXMAC_ENCR_MAC_ADDR_HIGH_RESET 0x0000FFFF
__INLINE uint32_t nxmac_encr_mac_addr_high_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_MAC_ADDR_HIGH_ADDR);
}
__INLINE void nxmac_encr_mac_addr_high_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_MAC_ADDR_HIGH_ADDR, value);
}
#define NXMAC_MAC_ADDR_RAM_HIGH_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_MAC_ADDR_RAM_HIGH_LSB 0
#define NXMAC_MAC_ADDR_RAM_HIGH_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MAC_ADDR_RAM_HIGH_RST 0xFFFF
__INLINE uint16_t nxmac_mac_addr_ram_high_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_MAC_ADDR_HIGH_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_mac_addr_ram_high_setf(uint16_t macaddrramhigh)
{
    ASSERT_ERR((((uint32_t)macaddrramhigh << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_MAC_ADDR_HIGH_ADDR, (uint32_t)macaddrramhigh << 0);
}
#define NXMAC_ENCR_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x00C4
#define NXMAC_ENCR_CNTRL_OFFSET 0x000000C4
#define NXMAC_ENCR_CNTRL_INDEX 0x00000031
#define NXMAC_ENCR_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_encr_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
}
__INLINE void nxmac_encr_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, value);
}
#define NXMAC_NEW_READ_BIT ((uint32_t)0x80000000)
#define NXMAC_NEW_READ_POS 31
#define NXMAC_NEW_WRITE_BIT ((uint32_t)0x40000000)
#define NXMAC_NEW_WRITE_POS 30
#define NXMAC_KEY_INDEX_RAM_MASK ((uint32_t)0x03FF0000)
#define NXMAC_KEY_INDEX_RAM_LSB 16
#define NXMAC_KEY_INDEX_RAM_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_C_TYPE_RAM_MASK ((uint32_t)0x00000700)
#define NXMAC_C_TYPE_RAM_LSB 8
#define NXMAC_C_TYPE_RAM_WIDTH ((uint32_t)0x00000003)
#define NXMAC_VLAN_IDRAM_MASK ((uint32_t)0x000000F0)
#define NXMAC_VLAN_IDRAM_LSB 4
#define NXMAC_VLAN_IDRAM_WIDTH ((uint32_t)0x00000004)
#define NXMAC_SPP_RAM_MASK ((uint32_t)0x0000000C)
#define NXMAC_SPP_RAM_LSB 2
#define NXMAC_SPP_RAM_WIDTH ((uint32_t)0x00000002)
#define NXMAC_USE_DEF_KEY_RAM_BIT ((uint32_t)0x00000002)
#define NXMAC_USE_DEF_KEY_RAM_POS 1
#define NXMAC_C_LEN_RAM_BIT ((uint32_t)0x00000001)
#define NXMAC_C_LEN_RAM_POS 0
#define NXMAC_NEW_READ_RST 0x0
#define NXMAC_NEW_WRITE_RST 0x0
#define NXMAC_KEY_INDEX_RAM_RST 0x0
#define NXMAC_C_TYPE_RAM_RST 0x0
#define NXMAC_VLAN_IDRAM_RST 0x0
#define NXMAC_SPP_RAM_RST 0x0
#define NXMAC_USE_DEF_KEY_RAM_RST 0x0
#define NXMAC_C_LEN_RAM_RST 0x0
__INLINE void nxmac_encr_cntrl_pack(uint8_t newread, uint8_t newwrite, uint16_t keyindexram, uint8_t ctyperam, uint8_t vlanidram, uint8_t sppram, uint8_t usedefkeyram, uint8_t clenram)
{
    ASSERT_ERR((((uint32_t)newread << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)newwrite << 30) & ~((uint32_t)0x40000000)) == 0);
    ASSERT_ERR((((uint32_t)keyindexram << 16) & ~((uint32_t)0x03FF0000)) == 0);
    ASSERT_ERR((((uint32_t)ctyperam << 8) & ~((uint32_t)0x00000700)) == 0);
    ASSERT_ERR((((uint32_t)vlanidram << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)sppram << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)usedefkeyram << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)clenram << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, ((uint32_t)newread << 31) | ((uint32_t)newwrite << 30) | ((uint32_t)keyindexram << 16) | ((uint32_t)ctyperam << 8) | ((uint32_t)vlanidram << 4) | ((uint32_t)sppram << 2) | ((uint32_t)usedefkeyram << 1) | ((uint32_t)clenram << 0));
}
__INLINE void nxmac_encr_cntrl_unpack(uint8_t* newread, uint8_t* newwrite, uint16_t* keyindexram, uint8_t* ctyperam, uint8_t* vlanidram, uint8_t* sppram, uint8_t* usedefkeyram, uint8_t* clenram)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    *newread = (localVal & ((uint32_t)0x80000000)) >> 31;
    *newwrite = (localVal & ((uint32_t)0x40000000)) >> 30;
    *keyindexram = (localVal & ((uint32_t)0x03FF0000)) >> 16;
    *ctyperam = (localVal & ((uint32_t)0x00000700)) >> 8;
    *vlanidram = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *sppram = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *usedefkeyram = (localVal & ((uint32_t)0x00000002)) >> 1;
    *clenram = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_new_read_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void nxmac_new_read_setf(uint8_t newread)
{
    ASSERT_ERR((((uint32_t)newread << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)newread << 31));
}
__INLINE uint8_t nxmac_new_write_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void nxmac_new_write_setf(uint8_t newwrite)
{
    ASSERT_ERR((((uint32_t)newwrite << 30) & ~((uint32_t)0x40000000)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)newwrite << 30));
}
__INLINE uint16_t nxmac_key_index_ram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x03FF0000)) >> 16);
}
__INLINE void nxmac_key_index_ram_setf(uint16_t keyindexram)
{
    ASSERT_ERR((((uint32_t)keyindexram << 16) & ~((uint32_t)0x03FF0000)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)keyindexram << 16));
}
__INLINE uint8_t nxmac_c_type_ram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void nxmac_c_type_ram_setf(uint8_t ctyperam)
{
    ASSERT_ERR((((uint32_t)ctyperam << 8) & ~((uint32_t)0x00000700)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ctyperam << 8));
}
__INLINE uint8_t nxmac_vlan_idram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_vlan_idram_setf(uint8_t vlanidram)
{
    ASSERT_ERR((((uint32_t)vlanidram << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)vlanidram << 4));
}
__INLINE uint8_t nxmac_spp_ram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void nxmac_spp_ram_setf(uint8_t sppram)
{
    ASSERT_ERR((((uint32_t)sppram << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)sppram << 2));
}
__INLINE uint8_t nxmac_use_def_key_ram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_use_def_key_ram_setf(uint8_t usedefkeyram)
{
    ASSERT_ERR((((uint32_t)usedefkeyram << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)usedefkeyram << 1));
}
__INLINE uint8_t nxmac_c_len_ram_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_c_len_ram_setf(uint8_t clenram)
{
    ASSERT_ERR((((uint32_t)clenram << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_ENCR_CNTRL_ADDR, (REG_PL_RD(NXMAC_ENCR_CNTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)clenram << 0));
}
#define NXMAC_ENCR_WPI_INT_KEY_0_ADDR REG_MAC_CORE_BASE_ADDR + 0x00C8
#define NXMAC_ENCR_WPI_INT_KEY_0_OFFSET 0x000000C8
#define NXMAC_ENCR_WPI_INT_KEY_0_INDEX 0x00000032
#define NXMAC_ENCR_WPI_INT_KEY_0_RESET 0x00000000
__INLINE uint32_t nxmac_encr_wpi_int_key_0_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_0_ADDR);
}
__INLINE void nxmac_encr_wpi_int_key_0_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_0_ADDR, value);
}
#define NXMAC_ENCR_INT_KEY_RAM_WORD_0_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_0_LSB 0
#define NXMAC_ENCR_INT_KEY_RAM_WORD_0_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_0_RST 0x0
__INLINE uint32_t nxmac_encr_int_key_ram_word_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_int_key_ram_word_0_setf(uint32_t encrintkeyramword0)
{
    ASSERT_ERR((((uint32_t)encrintkeyramword0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_0_ADDR, (uint32_t)encrintkeyramword0 << 0);
}
#define NXMAC_ENCR_WPI_INT_KEY_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x00CC
#define NXMAC_ENCR_WPI_INT_KEY_1_OFFSET 0x000000CC
#define NXMAC_ENCR_WPI_INT_KEY_1_INDEX 0x00000033
#define NXMAC_ENCR_WPI_INT_KEY_1_RESET 0x00000000
__INLINE uint32_t nxmac_encr_wpi_int_key_1_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_1_ADDR);
}
__INLINE void nxmac_encr_wpi_int_key_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_1_ADDR, value);
}
#define NXMAC_ENCR_INT_KEY_RAM_WORD_1_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_1_LSB 0
#define NXMAC_ENCR_INT_KEY_RAM_WORD_1_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_1_RST 0x0
__INLINE uint32_t nxmac_encr_int_key_ram_word_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_int_key_ram_word_1_setf(uint32_t encrintkeyramword1)
{
    ASSERT_ERR((((uint32_t)encrintkeyramword1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_1_ADDR, (uint32_t)encrintkeyramword1 << 0);
}
#define NXMAC_ENCR_WPI_INT_KEY_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x00D0
#define NXMAC_ENCR_WPI_INT_KEY_2_OFFSET 0x000000D0
#define NXMAC_ENCR_WPI_INT_KEY_2_INDEX 0x00000034
#define NXMAC_ENCR_WPI_INT_KEY_2_RESET 0x00000000
__INLINE uint32_t nxmac_encr_wpi_int_key_2_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_2_ADDR);
}
__INLINE void nxmac_encr_wpi_int_key_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_2_ADDR, value);
}
#define NXMAC_ENCR_INT_KEY_RAM_WORD_2_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_2_LSB 0
#define NXMAC_ENCR_INT_KEY_RAM_WORD_2_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_2_RST 0x0
__INLINE uint32_t nxmac_encr_int_key_ram_word_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_int_key_ram_word_2_setf(uint32_t encrintkeyramword2)
{
    ASSERT_ERR((((uint32_t)encrintkeyramword2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_2_ADDR, (uint32_t)encrintkeyramword2 << 0);
}
#define NXMAC_ENCR_WPI_INT_KEY_3_ADDR REG_MAC_CORE_BASE_ADDR + 0x00D4
#define NXMAC_ENCR_WPI_INT_KEY_3_OFFSET 0x000000D4
#define NXMAC_ENCR_WPI_INT_KEY_3_INDEX 0x00000035
#define NXMAC_ENCR_WPI_INT_KEY_3_RESET 0x00000000
__INLINE uint32_t nxmac_encr_wpi_int_key_3_get(void)
{
    return REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_3_ADDR);
}
__INLINE void nxmac_encr_wpi_int_key_3_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_3_ADDR, value);
}
#define NXMAC_ENCR_INT_KEY_RAM_WORD_3_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_3_LSB 0
#define NXMAC_ENCR_INT_KEY_RAM_WORD_3_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ENCR_INT_KEY_RAM_WORD_3_RST 0x0
__INLINE uint32_t nxmac_encr_int_key_ram_word_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ENCR_WPI_INT_KEY_3_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_encr_int_key_ram_word_3_setf(uint32_t encrintkeyramword3)
{
    ASSERT_ERR((((uint32_t)encrintkeyramword3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ENCR_WPI_INT_KEY_3_ADDR, (uint32_t)encrintkeyramword3 << 0);
}
#define NXMAC_RATES_ADDR REG_MAC_CORE_BASE_ADDR + 0x00DC
#define NXMAC_RATES_OFFSET 0x000000DC
#define NXMAC_RATES_INDEX 0x00000037
#define NXMAC_RATES_RESET 0x00000150
__INLINE uint32_t nxmac_rates_get(void)
{
    return REG_PL_RD(NXMAC_RATES_ADDR);
}
__INLINE void nxmac_rates_set(uint32_t value)
{
    REG_PL_WR(NXMAC_RATES_ADDR, value);
}
#define NXMAC_BSS_BASIC_RATE_SET_MASK ((uint32_t)0x00000FFF)
#define NXMAC_BSS_BASIC_RATE_SET_LSB 0
#define NXMAC_BSS_BASIC_RATE_SET_WIDTH ((uint32_t)0x0000000C)
#define NXMAC_BSS_BASIC_RATE_SET_RST 0x150
__INLINE uint16_t nxmac_bss_basic_rate_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RATES_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000FFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_basic_rate_set_setf(uint16_t bssbasicrateset)
{
    ASSERT_ERR((((uint32_t)bssbasicrateset << 0) & ~((uint32_t)0x00000FFF)) == 0);
    REG_PL_WR(NXMAC_RATES_ADDR, (uint32_t)bssbasicrateset << 0);
}
#define NXMAC_OLBC_ADDR REG_MAC_CORE_BASE_ADDR + 0x00E0
#define NXMAC_OLBC_OFFSET 0x000000E0
#define NXMAC_OLBC_INDEX 0x00000038
#define NXMAC_OLBC_RESET 0x00000000
__INLINE uint32_t nxmac_olbc_get(void)
{
    return REG_PL_RD(NXMAC_OLBC_ADDR);
}
__INLINE void nxmac_olbc_set(uint32_t value)
{
    REG_PL_WR(NXMAC_OLBC_ADDR, value);
}
#define NXMAC_DSSS_COUNT_MASK ((uint32_t)0xFF000000)
#define NXMAC_DSSS_COUNT_LSB 24
#define NXMAC_DSSS_COUNT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_OFDM_COUNT_MASK ((uint32_t)0x00FF0000)
#define NXMAC_OFDM_COUNT_LSB 16
#define NXMAC_OFDM_COUNT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_OLBC_TIMER_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_OLBC_TIMER_LSB 0
#define NXMAC_OLBC_TIMER_WIDTH ((uint32_t)0x00000010)
#define NXMAC_DSSS_COUNT_RST 0x0
#define NXMAC_OFDM_COUNT_RST 0x0
#define NXMAC_OLBC_TIMER_RST 0x0
__INLINE void nxmac_olbc_pack(uint8_t dssscount, uint8_t ofdmcount, uint16_t olbctimer)
{
    ASSERT_ERR((((uint32_t)dssscount << 24) & ~((uint32_t)0xFF000000)) == 0);
    ASSERT_ERR((((uint32_t)ofdmcount << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)olbctimer << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_OLBC_ADDR, ((uint32_t)dssscount << 24) | ((uint32_t)ofdmcount << 16) | ((uint32_t)olbctimer << 0));
}
__INLINE void nxmac_olbc_unpack(uint8_t* dssscount, uint8_t* ofdmcount, uint16_t* olbctimer)
{
    uint32_t localVal = REG_PL_RD(NXMAC_OLBC_ADDR);
    *dssscount = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *ofdmcount = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *olbctimer = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint8_t nxmac_dsss_count_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_OLBC_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void nxmac_dsss_count_setf(uint8_t dssscount)
{
    ASSERT_ERR((((uint32_t)dssscount << 24) & ~((uint32_t)0xFF000000)) == 0);
    REG_PL_WR(NXMAC_OLBC_ADDR, (REG_PL_RD(NXMAC_OLBC_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)dssscount << 24));
}
__INLINE uint8_t nxmac_ofdm_count_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_OLBC_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_ofdm_count_setf(uint8_t ofdmcount)
{
    ASSERT_ERR((((uint32_t)ofdmcount << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_OLBC_ADDR, (REG_PL_RD(NXMAC_OLBC_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)ofdmcount << 16));
}
__INLINE uint16_t nxmac_olbc_timer_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_OLBC_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_olbc_timer_setf(uint16_t olbctimer)
{
    ASSERT_ERR((((uint32_t)olbctimer << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_OLBC_ADDR, (REG_PL_RD(NXMAC_OLBC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)olbctimer << 0));
}
#define NXMAC_TIMINGS_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x00E4
#define NXMAC_TIMINGS_1_OFFSET 0x000000E4
#define NXMAC_TIMINGS_1_INDEX 0x00000039
#define NXMAC_TIMINGS_1_RESET 0x00000000
__INLINE uint32_t nxmac_timings_1_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_1_ADDR);
}
__INLINE void nxmac_timings_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_1_ADDR, value);
}
#define NXMAC_TX_CHAIN_DELAY_IN_MAC_CLK_MASK ((uint32_t)0x0FFC0000)
#define NXMAC_TX_CHAIN_DELAY_IN_MAC_CLK_LSB 18
#define NXMAC_TX_CHAIN_DELAY_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_TX_RF_DELAY_IN_MAC_CLK_MASK ((uint32_t)0x0003FF00)
#define NXMAC_TX_RF_DELAY_IN_MAC_CLK_LSB 8
#define NXMAC_TX_RF_DELAY_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_MAC_CORE_CLK_FREQ_MASK ((uint32_t)0x000000FF)
#define NXMAC_MAC_CORE_CLK_FREQ_LSB 0
#define NXMAC_MAC_CORE_CLK_FREQ_WIDTH ((uint32_t)0x00000008)
#define NXMAC_TX_CHAIN_DELAY_IN_MAC_CLK_RST 0x0
#define NXMAC_TX_RF_DELAY_IN_MAC_CLK_RST 0x0
#define NXMAC_MAC_CORE_CLK_FREQ_RST 0x0
__INLINE void nxmac_timings_1_pack(uint16_t txchaindelayinmacclk, uint16_t txrfdelayinmacclk, uint8_t maccoreclkfreq)
{
    ASSERT_ERR((((uint32_t)txchaindelayinmacclk << 18) & ~((uint32_t)0x0FFC0000)) == 0);
    ASSERT_ERR((((uint32_t)txrfdelayinmacclk << 8) & ~((uint32_t)0x0003FF00)) == 0);
    ASSERT_ERR((((uint32_t)maccoreclkfreq << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_1_ADDR, ((uint32_t)txchaindelayinmacclk << 18) | ((uint32_t)txrfdelayinmacclk << 8) | ((uint32_t)maccoreclkfreq << 0));
}
__INLINE void nxmac_timings_1_unpack(uint16_t* txchaindelayinmacclk, uint16_t* txrfdelayinmacclk, uint8_t* maccoreclkfreq)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_1_ADDR);
    *txchaindelayinmacclk = (localVal & ((uint32_t)0x0FFC0000)) >> 18;
    *txrfdelayinmacclk = (localVal & ((uint32_t)0x0003FF00)) >> 8;
    *maccoreclkfreq = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_tx_chain_delay_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_1_ADDR);
    return ((localVal & ((uint32_t)0x0FFC0000)) >> 18);
}
__INLINE void nxmac_tx_chain_delay_in_mac_clk_setf(uint16_t txchaindelayinmacclk)
{
    ASSERT_ERR((((uint32_t)txchaindelayinmacclk << 18) & ~((uint32_t)0x0FFC0000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_1_ADDR, (REG_PL_RD(NXMAC_TIMINGS_1_ADDR) & ~((uint32_t)0x0FFC0000)) | ((uint32_t)txchaindelayinmacclk << 18));
}
__INLINE uint16_t nxmac_tx_rf_delay_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_1_ADDR);
    return ((localVal & ((uint32_t)0x0003FF00)) >> 8);
}
__INLINE void nxmac_tx_rf_delay_in_mac_clk_setf(uint16_t txrfdelayinmacclk)
{
    ASSERT_ERR((((uint32_t)txrfdelayinmacclk << 8) & ~((uint32_t)0x0003FF00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_1_ADDR, (REG_PL_RD(NXMAC_TIMINGS_1_ADDR) & ~((uint32_t)0x0003FF00)) | ((uint32_t)txrfdelayinmacclk << 8));
}
__INLINE uint8_t nxmac_mac_core_clk_freq_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_mac_core_clk_freq_setf(uint8_t maccoreclkfreq)
{
    ASSERT_ERR((((uint32_t)maccoreclkfreq << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_1_ADDR, (REG_PL_RD(NXMAC_TIMINGS_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)maccoreclkfreq << 0));
}
#define NXMAC_TIMINGS_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x00E8
#define NXMAC_TIMINGS_2_OFFSET 0x000000E8
#define NXMAC_TIMINGS_2_INDEX 0x0000003A
#define NXMAC_TIMINGS_2_RESET 0x00000000
__INLINE uint32_t nxmac_timings_2_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_2_ADDR);
}
__INLINE void nxmac_timings_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_2_ADDR, value);
}
#define NXMAC_SLOT_TIME_IN_MAC_CLK_MASK ((uint32_t)0x00FFFF00)
#define NXMAC_SLOT_TIME_IN_MAC_CLK_LSB 8
#define NXMAC_SLOT_TIME_IN_MAC_CLK_WIDTH ((uint32_t)0x00000010)
#define NXMAC_SLOT_TIME_MASK ((uint32_t)0x000000FF)
#define NXMAC_SLOT_TIME_LSB 0
#define NXMAC_SLOT_TIME_WIDTH ((uint32_t)0x00000008)
#define NXMAC_SLOT_TIME_IN_MAC_CLK_RST 0x0
#define NXMAC_SLOT_TIME_RST 0x0
__INLINE void nxmac_timings_2_pack(uint16_t slottimeinmacclk, uint8_t slottime)
{
    ASSERT_ERR((((uint32_t)slottimeinmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    ASSERT_ERR((((uint32_t)slottime << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_2_ADDR, ((uint32_t)slottimeinmacclk << 8) | ((uint32_t)slottime << 0));
}
__INLINE void nxmac_timings_2_unpack(uint16_t* slottimeinmacclk, uint8_t* slottime)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_2_ADDR);
    *slottimeinmacclk = (localVal & ((uint32_t)0x00FFFF00)) >> 8;
    *slottime = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_slot_time_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_2_ADDR);
    return ((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}
__INLINE void nxmac_slot_time_in_mac_clk_setf(uint16_t slottimeinmacclk)
{
    ASSERT_ERR((((uint32_t)slottimeinmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_2_ADDR, (REG_PL_RD(NXMAC_TIMINGS_2_ADDR) & ~((uint32_t)0x00FFFF00)) | ((uint32_t)slottimeinmacclk << 8));
}
__INLINE uint8_t nxmac_slot_time_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_2_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_slot_time_setf(uint8_t slottime)
{
    ASSERT_ERR((((uint32_t)slottime << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_2_ADDR, (REG_PL_RD(NXMAC_TIMINGS_2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)slottime << 0));
}
#define NXMAC_TIMINGS_3_ADDR REG_MAC_CORE_BASE_ADDR + 0x00EC
#define NXMAC_TIMINGS_3_OFFSET 0x000000EC
#define NXMAC_TIMINGS_3_INDEX 0x0000003B
#define NXMAC_TIMINGS_3_RESET 0x00000000
__INLINE uint32_t nxmac_timings_3_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_3_ADDR);
}
__INLINE void nxmac_timings_3_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_3_ADDR, value);
}
#define NXMAC_RX_RF_DELAY_IN_MAC_CLK_MASK ((uint32_t)0x3FF00000)
#define NXMAC_RX_RF_DELAY_IN_MAC_CLK_LSB 20
#define NXMAC_RX_RF_DELAY_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_TX_DELAY_RF_ON_IN_MAC_CLK_MASK ((uint32_t)0x000FFC00)
#define NXMAC_TX_DELAY_RF_ON_IN_MAC_CLK_LSB 10
#define NXMAC_TX_DELAY_RF_ON_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_MAC_PROC_DELAY_IN_MAC_CLK_MASK ((uint32_t)0x000003FF)
#define NXMAC_MAC_PROC_DELAY_IN_MAC_CLK_LSB 0
#define NXMAC_MAC_PROC_DELAY_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_RX_RF_DELAY_IN_MAC_CLK_RST 0x0
#define NXMAC_TX_DELAY_RF_ON_IN_MAC_CLK_RST 0x0
#define NXMAC_MAC_PROC_DELAY_IN_MAC_CLK_RST 0x0
__INLINE void nxmac_timings_3_pack(uint16_t rxrfdelayinmacclk, uint16_t txdelayrfoninmacclk, uint16_t macprocdelayinmacclk)
{
    ASSERT_ERR((((uint32_t)rxrfdelayinmacclk << 20) & ~((uint32_t)0x3FF00000)) == 0);
    ASSERT_ERR((((uint32_t)txdelayrfoninmacclk << 10) & ~((uint32_t)0x000FFC00)) == 0);
    ASSERT_ERR((((uint32_t)macprocdelayinmacclk << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_3_ADDR, ((uint32_t)rxrfdelayinmacclk << 20) | ((uint32_t)txdelayrfoninmacclk << 10) | ((uint32_t)macprocdelayinmacclk << 0));
}
__INLINE void nxmac_timings_3_unpack(uint16_t* rxrfdelayinmacclk, uint16_t* txdelayrfoninmacclk, uint16_t* macprocdelayinmacclk)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_3_ADDR);
    *rxrfdelayinmacclk = (localVal & ((uint32_t)0x3FF00000)) >> 20;
    *txdelayrfoninmacclk = (localVal & ((uint32_t)0x000FFC00)) >> 10;
    *macprocdelayinmacclk = (localVal & ((uint32_t)0x000003FF)) >> 0;
}
__INLINE uint16_t nxmac_rx_rf_delay_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_3_ADDR);
    return ((localVal & ((uint32_t)0x3FF00000)) >> 20);
}
__INLINE void nxmac_rx_rf_delay_in_mac_clk_setf(uint16_t rxrfdelayinmacclk)
{
    ASSERT_ERR((((uint32_t)rxrfdelayinmacclk << 20) & ~((uint32_t)0x3FF00000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_3_ADDR, (REG_PL_RD(NXMAC_TIMINGS_3_ADDR) & ~((uint32_t)0x3FF00000)) | ((uint32_t)rxrfdelayinmacclk << 20));
}
__INLINE uint16_t nxmac_tx_delay_rf_on_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_3_ADDR);
    return ((localVal & ((uint32_t)0x000FFC00)) >> 10);
}
__INLINE void nxmac_tx_delay_rf_on_in_mac_clk_setf(uint16_t txdelayrfoninmacclk)
{
    ASSERT_ERR((((uint32_t)txdelayrfoninmacclk << 10) & ~((uint32_t)0x000FFC00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_3_ADDR, (REG_PL_RD(NXMAC_TIMINGS_3_ADDR) & ~((uint32_t)0x000FFC00)) | ((uint32_t)txdelayrfoninmacclk << 10));
}
__INLINE uint16_t nxmac_mac_proc_delay_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_3_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void nxmac_mac_proc_delay_in_mac_clk_setf(uint16_t macprocdelayinmacclk)
{
    ASSERT_ERR((((uint32_t)macprocdelayinmacclk << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_3_ADDR, (REG_PL_RD(NXMAC_TIMINGS_3_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)macprocdelayinmacclk << 0));
}
#define NXMAC_TIMINGS_4_ADDR REG_MAC_CORE_BASE_ADDR + 0x00F0
#define NXMAC_TIMINGS_4_OFFSET 0x000000F0
#define NXMAC_TIMINGS_4_INDEX 0x0000003C
#define NXMAC_TIMINGS_4_RESET 0x00000000
__INLINE uint32_t nxmac_timings_4_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_4_ADDR);
}
__INLINE void nxmac_timings_4_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_4_ADDR, value);
}
#define NXMAC_RADIO_WAKE_UP_TIME_MASK ((uint32_t)0xFFC00000)
#define NXMAC_RADIO_WAKE_UP_TIME_LSB 22
#define NXMAC_RADIO_WAKE_UP_TIME_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_RADIO_CHIRP_TIME_MASK ((uint32_t)0x003FF000)
#define NXMAC_RADIO_CHIRP_TIME_LSB 12
#define NXMAC_RADIO_CHIRP_TIME_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_RADIO_WAKE_UP_TIME_RST 0x0
#define NXMAC_RADIO_CHIRP_TIME_RST 0x0
__INLINE void nxmac_timings_4_pack(uint16_t radiowakeuptime, uint16_t radiochirptime)
{
    ASSERT_ERR((((uint32_t)radiowakeuptime << 22) & ~((uint32_t)0xFFC00000)) == 0);
    ASSERT_ERR((((uint32_t)radiochirptime << 12) & ~((uint32_t)0x003FF000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_4_ADDR, ((uint32_t)radiowakeuptime << 22) | ((uint32_t)radiochirptime << 12));
}
__INLINE void nxmac_timings_4_unpack(uint16_t* radiowakeuptime, uint16_t* radiochirptime)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_4_ADDR);
    *radiowakeuptime = (localVal & ((uint32_t)0xFFC00000)) >> 22;
    *radiochirptime = (localVal & ((uint32_t)0x003FF000)) >> 12;
}
__INLINE uint16_t nxmac_radio_wake_up_time_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_4_ADDR);
    return ((localVal & ((uint32_t)0xFFC00000)) >> 22);
}
__INLINE void nxmac_radio_wake_up_time_setf(uint16_t radiowakeuptime)
{
    ASSERT_ERR((((uint32_t)radiowakeuptime << 22) & ~((uint32_t)0xFFC00000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_4_ADDR, (REG_PL_RD(NXMAC_TIMINGS_4_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)radiowakeuptime << 22));
}
__INLINE uint16_t nxmac_radio_chirp_time_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_4_ADDR);
    return ((localVal & ((uint32_t)0x003FF000)) >> 12);
}
__INLINE void nxmac_radio_chirp_time_setf(uint16_t radiochirptime)
{
    ASSERT_ERR((((uint32_t)radiochirptime << 12) & ~((uint32_t)0x003FF000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_4_ADDR, (REG_PL_RD(NXMAC_TIMINGS_4_ADDR) & ~((uint32_t)0x003FF000)) | ((uint32_t)radiochirptime << 12));
}
#define NXMAC_TIMINGS_5_ADDR REG_MAC_CORE_BASE_ADDR + 0x00F4
#define NXMAC_TIMINGS_5_OFFSET 0x000000F4
#define NXMAC_TIMINGS_5_INDEX 0x0000003D
#define NXMAC_TIMINGS_5_RESET 0x00000000
__INLINE uint32_t nxmac_timings_5_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_5_ADDR);
}
__INLINE void nxmac_timings_5_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_5_ADDR, value);
}
#define NXMAC_SIFS_B_IN_MAC_CLK_MASK ((uint32_t)0x00FFFF00)
#define NXMAC_SIFS_B_IN_MAC_CLK_LSB 8
#define NXMAC_SIFS_B_IN_MAC_CLK_WIDTH ((uint32_t)0x00000010)
#define NXMAC_SIFS_B_MASK ((uint32_t)0x000000FF)
#define NXMAC_SIFS_B_LSB 0
#define NXMAC_SIFS_B_WIDTH ((uint32_t)0x00000008)
#define NXMAC_SIFS_B_IN_MAC_CLK_RST 0x0
#define NXMAC_SIFS_B_RST 0x0
__INLINE void nxmac_timings_5_pack(uint16_t sifsbinmacclk, uint8_t sifsb)
{
    ASSERT_ERR((((uint32_t)sifsbinmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    ASSERT_ERR((((uint32_t)sifsb << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_5_ADDR, ((uint32_t)sifsbinmacclk << 8) | ((uint32_t)sifsb << 0));
}
__INLINE void nxmac_timings_5_unpack(uint16_t* sifsbinmacclk, uint8_t* sifsb)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_5_ADDR);
    *sifsbinmacclk = (localVal & ((uint32_t)0x00FFFF00)) >> 8;
    *sifsb = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_sifs_b_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_5_ADDR);
    return ((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}
__INLINE void nxmac_sifs_b_in_mac_clk_setf(uint16_t sifsbinmacclk)
{
    ASSERT_ERR((((uint32_t)sifsbinmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_5_ADDR, (REG_PL_RD(NXMAC_TIMINGS_5_ADDR) & ~((uint32_t)0x00FFFF00)) | ((uint32_t)sifsbinmacclk << 8));
}
__INLINE uint8_t nxmac_sifs_b_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_5_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_sifs_b_setf(uint8_t sifsb)
{
    ASSERT_ERR((((uint32_t)sifsb << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_5_ADDR, (REG_PL_RD(NXMAC_TIMINGS_5_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sifsb << 0));
}
#define NXMAC_TIMINGS_6_ADDR REG_MAC_CORE_BASE_ADDR + 0x00F8
#define NXMAC_TIMINGS_6_OFFSET 0x000000F8
#define NXMAC_TIMINGS_6_INDEX 0x0000003E
#define NXMAC_TIMINGS_6_RESET 0x00000000
__INLINE uint32_t nxmac_timings_6_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_6_ADDR);
}
__INLINE void nxmac_timings_6_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_6_ADDR, value);
}
#define NXMAC_SIFS_A_IN_MAC_CLK_MASK ((uint32_t)0x00FFFF00)
#define NXMAC_SIFS_A_IN_MAC_CLK_LSB 8
#define NXMAC_SIFS_A_IN_MAC_CLK_WIDTH ((uint32_t)0x00000010)
#define NXMAC_SIFS_A_MASK ((uint32_t)0x000000FF)
#define NXMAC_SIFS_A_LSB 0
#define NXMAC_SIFS_A_WIDTH ((uint32_t)0x00000008)
#define NXMAC_SIFS_A_IN_MAC_CLK_RST 0x0
#define NXMAC_SIFS_A_RST 0x0
__INLINE void nxmac_timings_6_pack(uint16_t sifsainmacclk, uint8_t sifsa)
{
    ASSERT_ERR((((uint32_t)sifsainmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    ASSERT_ERR((((uint32_t)sifsa << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_6_ADDR, ((uint32_t)sifsainmacclk << 8) | ((uint32_t)sifsa << 0));
}
__INLINE void nxmac_timings_6_unpack(uint16_t* sifsainmacclk, uint8_t* sifsa)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_6_ADDR);
    *sifsainmacclk = (localVal & ((uint32_t)0x00FFFF00)) >> 8;
    *sifsa = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_sifs_a_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_6_ADDR);
    return ((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}
__INLINE void nxmac_sifs_a_in_mac_clk_setf(uint16_t sifsainmacclk)
{
    ASSERT_ERR((((uint32_t)sifsainmacclk << 8) & ~((uint32_t)0x00FFFF00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_6_ADDR, (REG_PL_RD(NXMAC_TIMINGS_6_ADDR) & ~((uint32_t)0x00FFFF00)) | ((uint32_t)sifsainmacclk << 8));
}
__INLINE uint8_t nxmac_sifs_a_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_6_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_sifs_a_setf(uint8_t sifsa)
{
    ASSERT_ERR((((uint32_t)sifsa << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_6_ADDR, (REG_PL_RD(NXMAC_TIMINGS_6_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sifsa << 0));
}
#define NXMAC_TIMINGS_7_ADDR REG_MAC_CORE_BASE_ADDR + 0x00FC
#define NXMAC_TIMINGS_7_OFFSET 0x000000FC
#define NXMAC_TIMINGS_7_INDEX 0x0000003F
#define NXMAC_TIMINGS_7_RESET 0x00000000
__INLINE uint32_t nxmac_timings_7_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_7_ADDR);
}
__INLINE void nxmac_timings_7_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_7_ADDR, value);
}
#define NXMAC_RX_CCA_DELAY_MASK ((uint32_t)0x00000F00)
#define NXMAC_RX_CCA_DELAY_LSB 8
#define NXMAC_RX_CCA_DELAY_WIDTH ((uint32_t)0x00000004)
#define NXMAC_RIFS_MASK ((uint32_t)0x000000FF)
#define NXMAC_RIFS_LSB 0
#define NXMAC_RIFS_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_CCA_DELAY_RST 0x0
#define NXMAC_RIFS_RST 0x0
__INLINE void nxmac_timings_7_pack(uint8_t rxccadelay, uint8_t rifs)
{
    ASSERT_ERR((((uint32_t)rxccadelay << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)rifs << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_7_ADDR, ((uint32_t)rxccadelay << 8) | ((uint32_t)rifs << 0));
}
__INLINE void nxmac_timings_7_unpack(uint8_t* rxccadelay, uint8_t* rifs)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_7_ADDR);
    *rxccadelay = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *rifs = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_rx_cca_delay_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_7_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_rx_cca_delay_setf(uint8_t rxccadelay)
{
    ASSERT_ERR((((uint32_t)rxccadelay << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_7_ADDR, (REG_PL_RD(NXMAC_TIMINGS_7_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)rxccadelay << 8));
}
__INLINE uint8_t nxmac_rifs_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_7_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_rifs_setf(uint8_t rifs)
{
    ASSERT_ERR((((uint32_t)rifs << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_7_ADDR, (REG_PL_RD(NXMAC_TIMINGS_7_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rifs << 0));
}
#define NXMAC_TIMINGS_8_ADDR REG_MAC_CORE_BASE_ADDR + 0x0100
#define NXMAC_TIMINGS_8_OFFSET 0x00000100
#define NXMAC_TIMINGS_8_INDEX 0x00000040
#define NXMAC_TIMINGS_8_RESET 0x2160C021
__INLINE uint32_t nxmac_timings_8_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
}
__INLINE void nxmac_timings_8_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, value);
}
#define NXMAC_RX_START_DELAY_MIMO_MASK ((uint32_t)0xFF000000)
#define NXMAC_RX_START_DELAY_MIMO_LSB 24
#define NXMAC_RX_START_DELAY_MIMO_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_START_DELAY_SHORT_MASK ((uint32_t)0x00FF0000)
#define NXMAC_RX_START_DELAY_SHORT_LSB 16
#define NXMAC_RX_START_DELAY_SHORT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_START_DELAY_LONG_MASK ((uint32_t)0x0000FF00)
#define NXMAC_RX_START_DELAY_LONG_LSB 8
#define NXMAC_RX_START_DELAY_LONG_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_START_DELAY_OFDM_MASK ((uint32_t)0x000000FF)
#define NXMAC_RX_START_DELAY_OFDM_LSB 0
#define NXMAC_RX_START_DELAY_OFDM_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_START_DELAY_MIMO_RST 0x21
#define NXMAC_RX_START_DELAY_SHORT_RST 0x60
#define NXMAC_RX_START_DELAY_LONG_RST 0xC0
#define NXMAC_RX_START_DELAY_OFDM_RST 0x21
__INLINE void nxmac_timings_8_pack(uint8_t rxstartdelaymimo, uint8_t rxstartdelayshort, uint8_t rxstartdelaylong, uint8_t rxstartdelayofdm)
{
    ASSERT_ERR((((uint32_t)rxstartdelaymimo << 24) & ~((uint32_t)0xFF000000)) == 0);
    ASSERT_ERR((((uint32_t)rxstartdelayshort << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)rxstartdelaylong << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)rxstartdelayofdm << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, ((uint32_t)rxstartdelaymimo << 24) | ((uint32_t)rxstartdelayshort << 16) | ((uint32_t)rxstartdelaylong << 8) | ((uint32_t)rxstartdelayofdm << 0));
}
__INLINE void nxmac_timings_8_unpack(uint8_t* rxstartdelaymimo, uint8_t* rxstartdelayshort, uint8_t* rxstartdelaylong, uint8_t* rxstartdelayofdm)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
    *rxstartdelaymimo = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *rxstartdelayshort = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *rxstartdelaylong = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *rxstartdelayofdm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_rx_start_delay_mimo_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void nxmac_rx_start_delay_mimo_setf(uint8_t rxstartdelaymimo)
{
    ASSERT_ERR((((uint32_t)rxstartdelaymimo << 24) & ~((uint32_t)0xFF000000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, (REG_PL_RD(NXMAC_TIMINGS_8_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rxstartdelaymimo << 24));
}
__INLINE uint8_t nxmac_rx_start_delay_short_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_rx_start_delay_short_setf(uint8_t rxstartdelayshort)
{
    ASSERT_ERR((((uint32_t)rxstartdelayshort << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, (REG_PL_RD(NXMAC_TIMINGS_8_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rxstartdelayshort << 16));
}
__INLINE uint8_t nxmac_rx_start_delay_long_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_rx_start_delay_long_setf(uint8_t rxstartdelaylong)
{
    ASSERT_ERR((((uint32_t)rxstartdelaylong << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, (REG_PL_RD(NXMAC_TIMINGS_8_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rxstartdelaylong << 8));
}
__INLINE uint8_t nxmac_rx_start_delay_ofdm_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_8_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_rx_start_delay_ofdm_setf(uint8_t rxstartdelayofdm)
{
    ASSERT_ERR((((uint32_t)rxstartdelayofdm << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_8_ADDR, (REG_PL_RD(NXMAC_TIMINGS_8_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rxstartdelayofdm << 0));
}
#define NXMAC_TIMINGS_9_ADDR REG_MAC_CORE_BASE_ADDR + 0x0104
#define NXMAC_TIMINGS_9_OFFSET 0x00000104
#define NXMAC_TIMINGS_9_INDEX 0x00000041
#define NXMAC_TIMINGS_9_RESET 0x00000000
__INLINE uint32_t nxmac_timings_9_get(void)
{
    return REG_PL_RD(NXMAC_TIMINGS_9_ADDR);
}
__INLINE void nxmac_timings_9_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TIMINGS_9_ADDR, value);
}
#define NXMAC_RIFS_TO_IN_MAC_CLK_MASK ((uint32_t)0x3FF00000)
#define NXMAC_RIFS_TO_IN_MAC_CLK_LSB 20
#define NXMAC_RIFS_TO_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_RIFS_IN_MAC_CLK_MASK ((uint32_t)0x000FFC00)
#define NXMAC_RIFS_IN_MAC_CLK_LSB 10
#define NXMAC_RIFS_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_TX_DMA_PROC_DLY_IN_MAC_CLK_MASK ((uint32_t)0x000003FF)
#define NXMAC_TX_DMA_PROC_DLY_IN_MAC_CLK_LSB 0
#define NXMAC_TX_DMA_PROC_DLY_IN_MAC_CLK_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_RIFS_TO_IN_MAC_CLK_RST 0x0
#define NXMAC_RIFS_IN_MAC_CLK_RST 0x0
#define NXMAC_TX_DMA_PROC_DLY_IN_MAC_CLK_RST 0x0
__INLINE void nxmac_timings_9_pack(uint16_t rifstoinmacclk, uint16_t rifsinmacclk, uint16_t txdmaprocdlyinmacclk)
{
    ASSERT_ERR((((uint32_t)rifstoinmacclk << 20) & ~((uint32_t)0x3FF00000)) == 0);
    ASSERT_ERR((((uint32_t)rifsinmacclk << 10) & ~((uint32_t)0x000FFC00)) == 0);
    ASSERT_ERR((((uint32_t)txdmaprocdlyinmacclk << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_9_ADDR, ((uint32_t)rifstoinmacclk << 20) | ((uint32_t)rifsinmacclk << 10) | ((uint32_t)txdmaprocdlyinmacclk << 0));
}
__INLINE void nxmac_timings_9_unpack(uint16_t* rifstoinmacclk, uint16_t* rifsinmacclk, uint16_t* txdmaprocdlyinmacclk)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_9_ADDR);
    *rifstoinmacclk = (localVal & ((uint32_t)0x3FF00000)) >> 20;
    *rifsinmacclk = (localVal & ((uint32_t)0x000FFC00)) >> 10;
    *txdmaprocdlyinmacclk = (localVal & ((uint32_t)0x000003FF)) >> 0;
}
__INLINE uint16_t nxmac_rifs_to_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_9_ADDR);
    return ((localVal & ((uint32_t)0x3FF00000)) >> 20);
}
__INLINE void nxmac_rifs_to_in_mac_clk_setf(uint16_t rifstoinmacclk)
{
    ASSERT_ERR((((uint32_t)rifstoinmacclk << 20) & ~((uint32_t)0x3FF00000)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_9_ADDR, (REG_PL_RD(NXMAC_TIMINGS_9_ADDR) & ~((uint32_t)0x3FF00000)) | ((uint32_t)rifstoinmacclk << 20));
}
__INLINE uint16_t nxmac_rifs_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_9_ADDR);
    return ((localVal & ((uint32_t)0x000FFC00)) >> 10);
}
__INLINE void nxmac_rifs_in_mac_clk_setf(uint16_t rifsinmacclk)
{
    ASSERT_ERR((((uint32_t)rifsinmacclk << 10) & ~((uint32_t)0x000FFC00)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_9_ADDR, (REG_PL_RD(NXMAC_TIMINGS_9_ADDR) & ~((uint32_t)0x000FFC00)) | ((uint32_t)rifsinmacclk << 10));
}
__INLINE uint16_t nxmac_tx_dma_proc_dly_in_mac_clk_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TIMINGS_9_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void nxmac_tx_dma_proc_dly_in_mac_clk_setf(uint16_t txdmaprocdlyinmacclk)
{
    ASSERT_ERR((((uint32_t)txdmaprocdlyinmacclk << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_TIMINGS_9_ADDR, (REG_PL_RD(NXMAC_TIMINGS_9_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)txdmaprocdlyinmacclk << 0));
}
#define NXMAC_PROT_TRIG_TIMER_ADDR REG_MAC_CORE_BASE_ADDR + 0x010C
#define NXMAC_PROT_TRIG_TIMER_OFFSET 0x0000010C
#define NXMAC_PROT_TRIG_TIMER_INDEX 0x00000043
#define NXMAC_PROT_TRIG_TIMER_RESET 0x00000009
__INLINE uint32_t nxmac_prot_trig_timer_get(void)
{
    return REG_PL_RD(NXMAC_PROT_TRIG_TIMER_ADDR);
}
__INLINE void nxmac_prot_trig_timer_set(uint32_t value)
{
    REG_PL_WR(NXMAC_PROT_TRIG_TIMER_ADDR, value);
}
#define NXMAC_HCCA_TRIGGER_TIMER_MASK ((uint32_t)0x0000FF00)
#define NXMAC_HCCA_TRIGGER_TIMER_LSB 8
#define NXMAC_HCCA_TRIGGER_TIMER_WIDTH ((uint32_t)0x00000008)
#define NXMAC_EDCA_TRIGGER_TIMER_MASK ((uint32_t)0x000000FF)
#define NXMAC_EDCA_TRIGGER_TIMER_LSB 0
#define NXMAC_EDCA_TRIGGER_TIMER_WIDTH ((uint32_t)0x00000008)
#define NXMAC_HCCA_TRIGGER_TIMER_RST 0x0
#define NXMAC_EDCA_TRIGGER_TIMER_RST 0x9
__INLINE void nxmac_prot_trig_timer_unpack(uint8_t* hccatriggertimer, uint8_t* edcatriggertimer)
{
    uint32_t localVal = REG_PL_RD(NXMAC_PROT_TRIG_TIMER_ADDR);
    *hccatriggertimer = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *edcatriggertimer = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_hcca_trigger_timer_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_PROT_TRIG_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t nxmac_edca_trigger_timer_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_PROT_TRIG_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_edca_trigger_timer_setf(uint8_t edcatriggertimer)
{
    ASSERT_ERR((((uint32_t)edcatriggertimer << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_PROT_TRIG_TIMER_ADDR, (uint32_t)edcatriggertimer << 0);
}
#define NXMAC_TX_TRIGGER_TIMER_ADDR REG_MAC_CORE_BASE_ADDR + 0x0110
#define NXMAC_TX_TRIGGER_TIMER_OFFSET 0x00000110
#define NXMAC_TX_TRIGGER_TIMER_INDEX 0x00000044
#define NXMAC_TX_TRIGGER_TIMER_RESET 0x00000F9C
__INLINE uint32_t nxmac_tx_trigger_timer_get(void)
{
    return REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR);
}
__INLINE void nxmac_tx_trigger_timer_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TX_TRIGGER_TIMER_ADDR, value);
}
#define NXMAC_TX_PACKET_TIMEOUT_MASK ((uint32_t)0x0000FF00)
#define NXMAC_TX_PACKET_TIMEOUT_LSB 8
#define NXMAC_TX_PACKET_TIMEOUT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_TX_ABSOLUTE_TIMEOUT_MASK ((uint32_t)0x000000FF)
#define NXMAC_TX_ABSOLUTE_TIMEOUT_LSB 0
#define NXMAC_TX_ABSOLUTE_TIMEOUT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_TX_PACKET_TIMEOUT_RST 0xF
#define NXMAC_TX_ABSOLUTE_TIMEOUT_RST 0x9C
__INLINE void nxmac_tx_trigger_timer_pack(uint8_t txpackettimeout, uint8_t txabsolutetimeout)
{
    ASSERT_ERR((((uint32_t)txpackettimeout << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)txabsolutetimeout << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TX_TRIGGER_TIMER_ADDR, ((uint32_t)txpackettimeout << 8) | ((uint32_t)txabsolutetimeout << 0));
}
__INLINE void nxmac_tx_trigger_timer_unpack(uint8_t* txpackettimeout, uint8_t* txabsolutetimeout)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR);
    *txpackettimeout = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *txabsolutetimeout = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_tx_packet_timeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_tx_packet_timeout_setf(uint8_t txpackettimeout)
{
    ASSERT_ERR((((uint32_t)txpackettimeout << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_TX_TRIGGER_TIMER_ADDR, (REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)txpackettimeout << 8));
}
__INLINE uint8_t nxmac_tx_absolute_timeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_tx_absolute_timeout_setf(uint8_t txabsolutetimeout)
{
    ASSERT_ERR((((uint32_t)txabsolutetimeout << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_TX_TRIGGER_TIMER_ADDR, (REG_PL_RD(NXMAC_TX_TRIGGER_TIMER_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)txabsolutetimeout << 0));
}
#define NXMAC_RX_TRIGGER_TIMER_ADDR REG_MAC_CORE_BASE_ADDR + 0x0114
#define NXMAC_RX_TRIGGER_TIMER_OFFSET 0x00000114
#define NXMAC_RX_TRIGGER_TIMER_INDEX 0x00000045
#define NXMAC_RX_TRIGGER_TIMER_RESET 0x000F0F9C
__INLINE uint32_t nxmac_rx_trigger_timer_get(void)
{
    return REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR);
}
__INLINE void nxmac_rx_trigger_timer_set(uint32_t value)
{
    REG_PL_WR(NXMAC_RX_TRIGGER_TIMER_ADDR, value);
}
#define NXMAC_RX_PAYLOAD_USED_COUNT_MASK ((uint32_t)0x00FF0000)
#define NXMAC_RX_PAYLOAD_USED_COUNT_LSB 16
#define NXMAC_RX_PAYLOAD_USED_COUNT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_PACKET_TIMEOUT_MASK ((uint32_t)0x0000FF00)
#define NXMAC_RX_PACKET_TIMEOUT_LSB 8
#define NXMAC_RX_PACKET_TIMEOUT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_ABSOLUTE_TIMEOUT_MASK ((uint32_t)0x000000FF)
#define NXMAC_RX_ABSOLUTE_TIMEOUT_LSB 0
#define NXMAC_RX_ABSOLUTE_TIMEOUT_WIDTH ((uint32_t)0x00000008)
#define NXMAC_RX_PAYLOAD_USED_COUNT_RST 0xF
#define NXMAC_RX_PACKET_TIMEOUT_RST 0xF
#define NXMAC_RX_ABSOLUTE_TIMEOUT_RST 0x9C
__INLINE void nxmac_rx_trigger_timer_pack(uint8_t rxpayloadusedcount, uint8_t rxpackettimeout, uint8_t rxabsolutetimeout)
{
    ASSERT_ERR((((uint32_t)rxpayloadusedcount << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)rxpackettimeout << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)rxabsolutetimeout << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_RX_TRIGGER_TIMER_ADDR, ((uint32_t)rxpayloadusedcount << 16) | ((uint32_t)rxpackettimeout << 8) | ((uint32_t)rxabsolutetimeout << 0));
}
__INLINE void nxmac_rx_trigger_timer_unpack(uint8_t* rxpayloadusedcount, uint8_t* rxpackettimeout, uint8_t* rxabsolutetimeout)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR);
    *rxpayloadusedcount = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *rxpackettimeout = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *rxabsolutetimeout = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_rx_payload_used_count_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_rx_payload_used_count_setf(uint8_t rxpayloadusedcount)
{
    ASSERT_ERR((((uint32_t)rxpayloadusedcount << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_RX_TRIGGER_TIMER_ADDR, (REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rxpayloadusedcount << 16));
}
__INLINE uint8_t nxmac_rx_packet_timeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_rx_packet_timeout_setf(uint8_t rxpackettimeout)
{
    ASSERT_ERR((((uint32_t)rxpackettimeout << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_RX_TRIGGER_TIMER_ADDR, (REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rxpackettimeout << 8));
}
__INLINE uint8_t nxmac_rx_absolute_timeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_rx_absolute_timeout_setf(uint8_t rxabsolutetimeout)
{
    ASSERT_ERR((((uint32_t)rxabsolutetimeout << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_RX_TRIGGER_TIMER_ADDR, (REG_PL_RD(NXMAC_RX_TRIGGER_TIMER_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rxabsolutetimeout << 0));
}
#define NXMAC_MIB_TABLE_WRITE_ADDR REG_MAC_CORE_BASE_ADDR + 0x0118
#define NXMAC_MIB_TABLE_WRITE_OFFSET 0x00000118
#define NXMAC_MIB_TABLE_WRITE_INDEX 0x00000046
#define NXMAC_MIB_TABLE_WRITE_RESET 0x00004000
__INLINE uint32_t nxmac_mib_table_write_get(void)
{
    return REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
}
__INLINE void nxmac_mib_table_write_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, value);
}
#define NXMAC_MIB_VALUE_MASK ((uint32_t)0xFFFF0000)
#define NXMAC_MIB_VALUE_LSB 16
#define NXMAC_MIB_VALUE_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MIB_WRITE_BIT ((uint32_t)0x00008000)
#define NXMAC_MIB_WRITE_POS 15
#define NXMAC_MIB_INCREMENT_MODE_BIT ((uint32_t)0x00004000)
#define NXMAC_MIB_INCREMENT_MODE_POS 14
#define NXMAC_MIB_TABLE_INDEX_MASK ((uint32_t)0x000003FF)
#define NXMAC_MIB_TABLE_INDEX_LSB 0
#define NXMAC_MIB_TABLE_INDEX_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_MIB_VALUE_RST 0x0
#define NXMAC_MIB_WRITE_RST 0x0
#define NXMAC_MIB_INCREMENT_MODE_RST 0x1
#define NXMAC_MIB_TABLE_INDEX_RST 0x0
__INLINE void nxmac_mib_table_write_pack(uint16_t mibvalue, uint8_t mibwrite, uint8_t mibincrementmode, uint16_t mibtableindex)
{
    ASSERT_ERR((((uint32_t)mibvalue << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)mibwrite << 15) & ~((uint32_t)0x00008000)) == 0);
    ASSERT_ERR((((uint32_t)mibincrementmode << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)mibtableindex << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, ((uint32_t)mibvalue << 16) | ((uint32_t)mibwrite << 15) | ((uint32_t)mibincrementmode << 14) | ((uint32_t)mibtableindex << 0));
}
__INLINE void nxmac_mib_table_write_unpack(uint16_t* mibvalue, uint8_t* mibwrite, uint8_t* mibincrementmode, uint16_t* mibtableindex)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
    *mibvalue = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *mibwrite = (localVal & ((uint32_t)0x00008000)) >> 15;
    *mibincrementmode = (localVal & ((uint32_t)0x00004000)) >> 14;
    *mibtableindex = (localVal & ((uint32_t)0x000003FF)) >> 0;
}
__INLINE uint16_t nxmac_mib_value_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void nxmac_mib_value_setf(uint16_t mibvalue)
{
    ASSERT_ERR((((uint32_t)mibvalue << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, (REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)mibvalue << 16));
}
__INLINE uint8_t nxmac_mib_write_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void nxmac_mib_write_setf(uint8_t mibwrite)
{
    ASSERT_ERR((((uint32_t)mibwrite << 15) & ~((uint32_t)0x00008000)) == 0);
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, (REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)mibwrite << 15));
}
__INLINE uint8_t nxmac_mib_increment_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void nxmac_mib_increment_mode_setf(uint8_t mibincrementmode)
{
    ASSERT_ERR((((uint32_t)mibincrementmode << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, (REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)mibincrementmode << 14));
}
__INLINE uint16_t nxmac_mib_table_index_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void nxmac_mib_table_index_setf(uint16_t mibtableindex)
{
    ASSERT_ERR((((uint32_t)mibtableindex << 0) & ~((uint32_t)0x000003FF)) == 0);
    REG_PL_WR(NXMAC_MIB_TABLE_WRITE_ADDR, (REG_PL_RD(NXMAC_MIB_TABLE_WRITE_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)mibtableindex << 0));
}
#define NXMAC_MONOTONIC_COUNTER_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x011C
#define NXMAC_MONOTONIC_COUNTER_1_OFFSET 0x0000011C
#define NXMAC_MONOTONIC_COUNTER_1_INDEX 0x00000047
#define NXMAC_MONOTONIC_COUNTER_1_RESET 0x00000000
__INLINE uint32_t nxmac_monotonic_counter_1_get(void)
{
    return REG_PL_RD(NXMAC_MONOTONIC_COUNTER_1_ADDR);
}
#define NXMAC_MONOTONIC_COUNTER_1_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_MONOTONIC_COUNTER_1_LSB 0
#define NXMAC_MONOTONIC_COUNTER_1_WIDTH ((uint32_t)0x00000020)
#define NXMAC_MONOTONIC_COUNTER_1_RST 0x0
__INLINE uint32_t nxmac_monotonic_counter_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MONOTONIC_COUNTER_1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_MONOTONIC_COUNTER_2_LO_ADDR REG_MAC_CORE_BASE_ADDR + 0x0120
#define NXMAC_MONOTONIC_COUNTER_2_LO_OFFSET 0x00000120
#define NXMAC_MONOTONIC_COUNTER_2_LO_INDEX 0x00000048
#define NXMAC_MONOTONIC_COUNTER_2_LO_RESET 0x00000000
__INLINE uint32_t nxmac_monotonic_counter_2_lo_get(void)
{
    return REG_PL_RD(NXMAC_MONOTONIC_COUNTER_2_LO_ADDR);
}
#define NXMAC_MONOTONIC_COUNTER_LOW_2_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_MONOTONIC_COUNTER_LOW_2_LSB 0
#define NXMAC_MONOTONIC_COUNTER_LOW_2_WIDTH ((uint32_t)0x00000020)
#define NXMAC_MONOTONIC_COUNTER_LOW_2_RST 0x0
__INLINE uint32_t nxmac_monotonic_counter_low_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MONOTONIC_COUNTER_2_LO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_MONOTONIC_COUNTER_2_HI_ADDR REG_MAC_CORE_BASE_ADDR + 0x0124
#define NXMAC_MONOTONIC_COUNTER_2_HI_OFFSET 0x00000124
#define NXMAC_MONOTONIC_COUNTER_2_HI_INDEX 0x00000049
#define NXMAC_MONOTONIC_COUNTER_2_HI_RESET 0x00000000
__INLINE uint32_t nxmac_monotonic_counter_2_hi_get(void)
{
    return REG_PL_RD(NXMAC_MONOTONIC_COUNTER_2_HI_ADDR);
}
#define NXMAC_MONOTONIC_COUNTER_HIGH_2_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_MONOTONIC_COUNTER_HIGH_2_LSB 0
#define NXMAC_MONOTONIC_COUNTER_HIGH_2_WIDTH ((uint32_t)0x00000010)
#define NXMAC_MONOTONIC_COUNTER_HIGH_2_RST 0x0
__INLINE uint16_t nxmac_monotonic_counter_high_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MONOTONIC_COUNTER_2_HI_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_ABS_TIMER_ADDR REG_MAC_CORE_BASE_ADDR + 0x0128
#define NXMAC_ABS_TIMER_OFFSET 0x00000128
#define NXMAC_ABS_TIMER_INDEX 0x0000004A
#define NXMAC_ABS_TIMER_RESET 0x00000000
#define NXMAC_ABS_TIMER_COUNT 10
__INLINE uint32_t nxmac_abs_timer_get(int reg_idx)
{
    ASSERT_ERR(reg_idx <= 9);
    return REG_PL_RD(NXMAC_ABS_TIMER_ADDR + reg_idx * 4);
}
__INLINE void nxmac_abs_timer_set(int reg_idx, uint32_t value)
{
    ASSERT_ERR(reg_idx <= 9);
    REG_PL_WR(NXMAC_ABS_TIMER_ADDR + reg_idx * 4, value);
}
#define NXMAC_ABS_TIMER_VALUE_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_ABS_TIMER_VALUE_LSB 0
#define NXMAC_ABS_TIMER_VALUE_WIDTH ((uint32_t)0x00000020)
#define NXMAC_ABS_TIMER_VALUE_RST 0x0
__INLINE uint32_t nxmac_abs_timer_value_getf(int reg_idx)
{
    uint32_t localVal;
    ASSERT_ERR(reg_idx <= 9);
    localVal = REG_PL_RD(NXMAC_ABS_TIMER_ADDR + reg_idx * 4);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_abs_timer_value_setf(int reg_idx, uint32_t abstimervalue)
{
    ASSERT_ERR(reg_idx <= 9);
    ASSERT_ERR((((uint32_t)abstimervalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ABS_TIMER_ADDR + reg_idx * 4, (uint32_t)abstimervalue << 0);
}
#define NXMAC_MAX_RX_LENGTH_ADDR REG_MAC_CORE_BASE_ADDR + 0x0150
#define NXMAC_MAX_RX_LENGTH_OFFSET 0x00000150
#define NXMAC_MAX_RX_LENGTH_INDEX 0x00000054
#define NXMAC_MAX_RX_LENGTH_RESET 0x0000FFFF
__INLINE uint32_t nxmac_max_rx_length_get(void)
{
    return REG_PL_RD(NXMAC_MAX_RX_LENGTH_ADDR);
}
__INLINE void nxmac_max_rx_length_set(uint32_t value)
{
    REG_PL_WR(NXMAC_MAX_RX_LENGTH_ADDR, value);
}
#define NXMAC_MAX_ALLOWED_LENGTH_MASK ((uint32_t)0x000FFFFF)
#define NXMAC_MAX_ALLOWED_LENGTH_LSB 0
#define NXMAC_MAX_ALLOWED_LENGTH_WIDTH ((uint32_t)0x00000014)
#define NXMAC_MAX_ALLOWED_LENGTH_RST 0xFFFF
__INLINE uint32_t nxmac_max_allowed_length_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_MAX_RX_LENGTH_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000FFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_max_allowed_length_setf(uint32_t maxallowedlength)
{
    ASSERT_ERR((((uint32_t)maxallowedlength << 0) & ~((uint32_t)0x000FFFFF)) == 0);
    REG_PL_WR(NXMAC_MAX_RX_LENGTH_ADDR, (uint32_t)maxallowedlength << 0);
}
#define NXMAC_EDCA_AC_0_ADDR REG_MAC_CORE_BASE_ADDR + 0x0200
#define NXMAC_EDCA_AC_0_OFFSET 0x00000200
#define NXMAC_EDCA_AC_0_INDEX 0x00000080
#define NXMAC_EDCA_AC_0_RESET 0x00000A47
__INLINE uint32_t nxmac_edca_ac_0_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
}
__INLINE void nxmac_edca_ac_0_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, value);
}
#define NXMAC_TX_OP_LIMIT_0_MASK ((uint32_t)0x0FFFF000)
#define NXMAC_TX_OP_LIMIT_0_LSB 12
#define NXMAC_TX_OP_LIMIT_0_WIDTH ((uint32_t)0x00000010)
#define NXMAC_CW_MAX_0_MASK ((uint32_t)0x00000F00)
#define NXMAC_CW_MAX_0_LSB 8
#define NXMAC_CW_MAX_0_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CW_MIN_0_MASK ((uint32_t)0x000000F0)
#define NXMAC_CW_MIN_0_LSB 4
#define NXMAC_CW_MIN_0_WIDTH ((uint32_t)0x00000004)
#define NXMAC_AIFSN_0_MASK ((uint32_t)0x0000000F)
#define NXMAC_AIFSN_0_LSB 0
#define NXMAC_AIFSN_0_WIDTH ((uint32_t)0x00000004)
#define NXMAC_TX_OP_LIMIT_0_RST 0x0
#define NXMAC_CW_MAX_0_RST 0xA
#define NXMAC_CW_MIN_0_RST 0x4
#define NXMAC_AIFSN_0_RST 0x7
__INLINE void nxmac_edca_ac_0_pack(uint16_t txoplimit0, uint8_t cwmax0, uint8_t cwmin0, uint8_t aifsn0)
{
    ASSERT_ERR((((uint32_t)txoplimit0 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    ASSERT_ERR((((uint32_t)cwmax0 << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)cwmin0 << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)aifsn0 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, ((uint32_t)txoplimit0 << 12) | ((uint32_t)cwmax0 << 8) | ((uint32_t)cwmin0 << 4) | ((uint32_t)aifsn0 << 0));
}
__INLINE void nxmac_edca_ac_0_unpack(uint16_t* txoplimit0, uint8_t* cwmax0, uint8_t* cwmin0, uint8_t* aifsn0)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
    *txoplimit0 = (localVal & ((uint32_t)0x0FFFF000)) >> 12;
    *cwmax0 = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *cwmin0 = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *aifsn0 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint16_t nxmac_tx_op_limit_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
    return ((localVal & ((uint32_t)0x0FFFF000)) >> 12);
}
__INLINE void nxmac_tx_op_limit_0_setf(uint16_t txoplimit0)
{
    ASSERT_ERR((((uint32_t)txoplimit0 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_0_ADDR) & ~((uint32_t)0x0FFFF000)) | ((uint32_t)txoplimit0 << 12));
}
__INLINE uint8_t nxmac_cw_max_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_cw_max_0_setf(uint8_t cwmax0)
{
    ASSERT_ERR((((uint32_t)cwmax0 << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_0_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)cwmax0 << 8));
}
__INLINE uint8_t nxmac_cw_min_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_cw_min_0_setf(uint8_t cwmin0)
{
    ASSERT_ERR((((uint32_t)cwmin0 << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_0_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)cwmin0 << 4));
}
__INLINE uint8_t nxmac_aifsn_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_0_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void nxmac_aifsn_0_setf(uint8_t aifsn0)
{
    ASSERT_ERR((((uint32_t)aifsn0 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_0_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)aifsn0 << 0));
}
#define NXMAC_EDCA_AC_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0204
#define NXMAC_EDCA_AC_1_OFFSET 0x00000204
#define NXMAC_EDCA_AC_1_INDEX 0x00000081
#define NXMAC_EDCA_AC_1_RESET 0x00000A43
__INLINE uint32_t nxmac_edca_ac_1_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
}
__INLINE void nxmac_edca_ac_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, value);
}
#define NXMAC_TX_OP_LIMIT_1_MASK ((uint32_t)0x0FFFF000)
#define NXMAC_TX_OP_LIMIT_1_LSB 12
#define NXMAC_TX_OP_LIMIT_1_WIDTH ((uint32_t)0x00000010)
#define NXMAC_CW_MAX_1_MASK ((uint32_t)0x00000F00)
#define NXMAC_CW_MAX_1_LSB 8
#define NXMAC_CW_MAX_1_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CW_MIN_1_MASK ((uint32_t)0x000000F0)
#define NXMAC_CW_MIN_1_LSB 4
#define NXMAC_CW_MIN_1_WIDTH ((uint32_t)0x00000004)
#define NXMAC_AIFSN_1_MASK ((uint32_t)0x0000000F)
#define NXMAC_AIFSN_1_LSB 0
#define NXMAC_AIFSN_1_WIDTH ((uint32_t)0x00000004)
#define NXMAC_TX_OP_LIMIT_1_RST 0x0
#define NXMAC_CW_MAX_1_RST 0xA
#define NXMAC_CW_MIN_1_RST 0x4
#define NXMAC_AIFSN_1_RST 0x3
__INLINE void nxmac_edca_ac_1_pack(uint16_t txoplimit1, uint8_t cwmax1, uint8_t cwmin1, uint8_t aifsn1)
{
    ASSERT_ERR((((uint32_t)txoplimit1 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    ASSERT_ERR((((uint32_t)cwmax1 << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)cwmin1 << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)aifsn1 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, ((uint32_t)txoplimit1 << 12) | ((uint32_t)cwmax1 << 8) | ((uint32_t)cwmin1 << 4) | ((uint32_t)aifsn1 << 0));
}
__INLINE void nxmac_edca_ac_1_unpack(uint16_t* txoplimit1, uint8_t* cwmax1, uint8_t* cwmin1, uint8_t* aifsn1)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
    *txoplimit1 = (localVal & ((uint32_t)0x0FFFF000)) >> 12;
    *cwmax1 = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *cwmin1 = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *aifsn1 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint16_t nxmac_tx_op_limit_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
    return ((localVal & ((uint32_t)0x0FFFF000)) >> 12);
}
__INLINE void nxmac_tx_op_limit_1_setf(uint16_t txoplimit1)
{
    ASSERT_ERR((((uint32_t)txoplimit1 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_1_ADDR) & ~((uint32_t)0x0FFFF000)) | ((uint32_t)txoplimit1 << 12));
}
__INLINE uint8_t nxmac_cw_max_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_cw_max_1_setf(uint8_t cwmax1)
{
    ASSERT_ERR((((uint32_t)cwmax1 << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_1_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)cwmax1 << 8));
}
__INLINE uint8_t nxmac_cw_min_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_cw_min_1_setf(uint8_t cwmin1)
{
    ASSERT_ERR((((uint32_t)cwmin1 << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)cwmin1 << 4));
}
__INLINE uint8_t nxmac_aifsn_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_1_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void nxmac_aifsn_1_setf(uint8_t aifsn1)
{
    ASSERT_ERR((((uint32_t)aifsn1 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_1_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)aifsn1 << 0));
}
#define NXMAC_EDCA_AC_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0208
#define NXMAC_EDCA_AC_2_OFFSET 0x00000208
#define NXMAC_EDCA_AC_2_INDEX 0x00000082
#define NXMAC_EDCA_AC_2_RESET 0x0005E432
__INLINE uint32_t nxmac_edca_ac_2_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
}
__INLINE void nxmac_edca_ac_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, value);
}
#define NXMAC_TX_OP_LIMIT_2_MASK ((uint32_t)0x0FFFF000)
#define NXMAC_TX_OP_LIMIT_2_LSB 12
#define NXMAC_TX_OP_LIMIT_2_WIDTH ((uint32_t)0x00000010)
#define NXMAC_CW_MAX_2_MASK ((uint32_t)0x00000F00)
#define NXMAC_CW_MAX_2_LSB 8
#define NXMAC_CW_MAX_2_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CW_MIN_2_MASK ((uint32_t)0x000000F0)
#define NXMAC_CW_MIN_2_LSB 4
#define NXMAC_CW_MIN_2_WIDTH ((uint32_t)0x00000004)
#define NXMAC_AIFSN_2_MASK ((uint32_t)0x0000000F)
#define NXMAC_AIFSN_2_LSB 0
#define NXMAC_AIFSN_2_WIDTH ((uint32_t)0x00000004)
#define NXMAC_TX_OP_LIMIT_2_RST 0x5E
#define NXMAC_CW_MAX_2_RST 0x4
#define NXMAC_CW_MIN_2_RST 0x3
#define NXMAC_AIFSN_2_RST 0x2
__INLINE void nxmac_edca_ac_2_pack(uint16_t txoplimit2, uint8_t cwmax2, uint8_t cwmin2, uint8_t aifsn2)
{
    ASSERT_ERR((((uint32_t)txoplimit2 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    ASSERT_ERR((((uint32_t)cwmax2 << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)cwmin2 << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)aifsn2 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, ((uint32_t)txoplimit2 << 12) | ((uint32_t)cwmax2 << 8) | ((uint32_t)cwmin2 << 4) | ((uint32_t)aifsn2 << 0));
}
__INLINE void nxmac_edca_ac_2_unpack(uint16_t* txoplimit2, uint8_t* cwmax2, uint8_t* cwmin2, uint8_t* aifsn2)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
    *txoplimit2 = (localVal & ((uint32_t)0x0FFFF000)) >> 12;
    *cwmax2 = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *cwmin2 = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *aifsn2 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint16_t nxmac_tx_op_limit_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
    return ((localVal & ((uint32_t)0x0FFFF000)) >> 12);
}
__INLINE void nxmac_tx_op_limit_2_setf(uint16_t txoplimit2)
{
    ASSERT_ERR((((uint32_t)txoplimit2 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_2_ADDR) & ~((uint32_t)0x0FFFF000)) | ((uint32_t)txoplimit2 << 12));
}
__INLINE uint8_t nxmac_cw_max_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_cw_max_2_setf(uint8_t cwmax2)
{
    ASSERT_ERR((((uint32_t)cwmax2 << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_2_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)cwmax2 << 8));
}
__INLINE uint8_t nxmac_cw_min_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_cw_min_2_setf(uint8_t cwmin2)
{
    ASSERT_ERR((((uint32_t)cwmin2 << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_2_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)cwmin2 << 4));
}
__INLINE uint8_t nxmac_aifsn_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_2_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void nxmac_aifsn_2_setf(uint8_t aifsn2)
{
    ASSERT_ERR((((uint32_t)aifsn2 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_2_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)aifsn2 << 0));
}
#define NXMAC_EDCA_AC_3_ADDR REG_MAC_CORE_BASE_ADDR + 0x020C
#define NXMAC_EDCA_AC_3_OFFSET 0x0000020C
#define NXMAC_EDCA_AC_3_INDEX 0x00000083
#define NXMAC_EDCA_AC_3_RESET 0x0002F322
__INLINE uint32_t nxmac_edca_ac_3_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
}
__INLINE void nxmac_edca_ac_3_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, value);
}
#define NXMAC_TX_OP_LIMIT_3_MASK ((uint32_t)0x0FFFF000)
#define NXMAC_TX_OP_LIMIT_3_LSB 12
#define NXMAC_TX_OP_LIMIT_3_WIDTH ((uint32_t)0x00000010)
#define NXMAC_CW_MAX_3_MASK ((uint32_t)0x00000F00)
#define NXMAC_CW_MAX_3_LSB 8
#define NXMAC_CW_MAX_3_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CW_MIN_3_MASK ((uint32_t)0x000000F0)
#define NXMAC_CW_MIN_3_LSB 4
#define NXMAC_CW_MIN_3_WIDTH ((uint32_t)0x00000004)
#define NXMAC_AIFSN_3_MASK ((uint32_t)0x0000000F)
#define NXMAC_AIFSN_3_LSB 0
#define NXMAC_AIFSN_3_WIDTH ((uint32_t)0x00000004)
#define NXMAC_TX_OP_LIMIT_3_RST 0x2F
#define NXMAC_CW_MAX_3_RST 0x3
#define NXMAC_CW_MIN_3_RST 0x2
#define NXMAC_AIFSN_3_RST 0x2
__INLINE void nxmac_edca_ac_3_pack(uint16_t txoplimit3, uint8_t cwmax3, uint8_t cwmin3, uint8_t aifsn3)
{
    ASSERT_ERR((((uint32_t)txoplimit3 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    ASSERT_ERR((((uint32_t)cwmax3 << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)cwmin3 << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)aifsn3 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, ((uint32_t)txoplimit3 << 12) | ((uint32_t)cwmax3 << 8) | ((uint32_t)cwmin3 << 4) | ((uint32_t)aifsn3 << 0));
}
__INLINE void nxmac_edca_ac_3_unpack(uint16_t* txoplimit3, uint8_t* cwmax3, uint8_t* cwmin3, uint8_t* aifsn3)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
    *txoplimit3 = (localVal & ((uint32_t)0x0FFFF000)) >> 12;
    *cwmax3 = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *cwmin3 = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *aifsn3 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint16_t nxmac_tx_op_limit_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
    return ((localVal & ((uint32_t)0x0FFFF000)) >> 12);
}
__INLINE void nxmac_tx_op_limit_3_setf(uint16_t txoplimit3)
{
    ASSERT_ERR((((uint32_t)txoplimit3 << 12) & ~((uint32_t)0x0FFFF000)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_3_ADDR) & ~((uint32_t)0x0FFFF000)) | ((uint32_t)txoplimit3 << 12));
}
__INLINE uint8_t nxmac_cw_max_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_cw_max_3_setf(uint8_t cwmax3)
{
    ASSERT_ERR((((uint32_t)cwmax3 << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_3_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)cwmax3 << 8));
}
__INLINE uint8_t nxmac_cw_min_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_cw_min_3_setf(uint8_t cwmin3)
{
    ASSERT_ERR((((uint32_t)cwmin3 << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_3_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)cwmin3 << 4));
}
__INLINE uint8_t nxmac_aifsn_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_AC_3_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void nxmac_aifsn_3_setf(uint8_t aifsn3)
{
    ASSERT_ERR((((uint32_t)aifsn3 << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_EDCA_AC_3_ADDR, (REG_PL_RD(NXMAC_EDCA_AC_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)aifsn3 << 0));
}
#define NXMAC_EDCA_CCA_BUSY_ADDR REG_MAC_CORE_BASE_ADDR + 0x0220
#define NXMAC_EDCA_CCA_BUSY_OFFSET 0x00000220
#define NXMAC_EDCA_CCA_BUSY_INDEX 0x00000088
#define NXMAC_EDCA_CCA_BUSY_RESET 0x00000000
__INLINE uint32_t nxmac_edca_cca_busy_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_CCA_BUSY_ADDR);
}
__INLINE void nxmac_edca_cca_busy_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_CCA_BUSY_ADDR, value);
}
#define NXMAC_CCA_BUSY_DUR_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_CCA_BUSY_DUR_LSB 0
#define NXMAC_CCA_BUSY_DUR_WIDTH ((uint32_t)0x00000020)
#define NXMAC_CCA_BUSY_DUR_RST 0x0
__INLINE uint32_t nxmac_cca_busy_dur_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CCA_BUSY_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_cca_busy_dur_setf(uint32_t ccabusydur)
{
    ASSERT_ERR((((uint32_t)ccabusydur << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_EDCA_CCA_BUSY_ADDR, (uint32_t)ccabusydur << 0);
}
#define NXMAC_EDCA_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0224
#define NXMAC_EDCA_CNTRL_OFFSET 0x00000224
#define NXMAC_EDCA_CNTRL_INDEX 0x00000089
#define NXMAC_EDCA_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_edca_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
}
__INLINE void nxmac_edca_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, value);
}
#define NXMAC_KEEP_TXOP_OPEN_BIT ((uint32_t)0x00000020)
#define NXMAC_KEEP_TXOP_OPEN_POS 5
#define NXMAC_REM_TXOP_IN_DUR_FIELD_BIT ((uint32_t)0x00000010)
#define NXMAC_REM_TXOP_IN_DUR_FIELD_POS 4
#define NXMAC_SEND_CF_END_BIT ((uint32_t)0x00000002)
#define NXMAC_SEND_CF_END_POS 1
#define NXMAC_SEND_CF_END_NOW_BIT ((uint32_t)0x00000001)
#define NXMAC_SEND_CF_END_NOW_POS 0
#define NXMAC_KEEP_TXOP_OPEN_RST 0x0
#define NXMAC_REM_TXOP_IN_DUR_FIELD_RST 0x0
#define NXMAC_SEND_CF_END_RST 0x0
#define NXMAC_SEND_CF_END_NOW_RST 0x0
__INLINE void nxmac_edca_cntrl_pack(uint8_t keeptxopopen, uint8_t remtxopindurfield, uint8_t sendcfend, uint8_t sendcfendnow)
{
    ASSERT_ERR((((uint32_t)keeptxopopen << 5) & ~((uint32_t)0x00000020)) == 0);
    ASSERT_ERR((((uint32_t)remtxopindurfield << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)sendcfend << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)sendcfendnow << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, ((uint32_t)keeptxopopen << 5) | ((uint32_t)remtxopindurfield << 4) | ((uint32_t)sendcfend << 1) | ((uint32_t)sendcfendnow << 0));
}
__INLINE void nxmac_edca_cntrl_unpack(uint8_t* keeptxopopen, uint8_t* remtxopindurfield, uint8_t* sendcfend, uint8_t* sendcfendnow)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
    *keeptxopopen = (localVal & ((uint32_t)0x00000020)) >> 5;
    *remtxopindurfield = (localVal & ((uint32_t)0x00000010)) >> 4;
    *sendcfend = (localVal & ((uint32_t)0x00000002)) >> 1;
    *sendcfendnow = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_keep_txop_open_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void nxmac_keep_txop_open_setf(uint8_t keeptxopopen)
{
    ASSERT_ERR((((uint32_t)keeptxopopen << 5) & ~((uint32_t)0x00000020)) == 0);
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, (REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)keeptxopopen << 5));
}
__INLINE uint8_t nxmac_rem_txop_in_dur_field_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void nxmac_rem_txop_in_dur_field_setf(uint8_t remtxopindurfield)
{
    ASSERT_ERR((((uint32_t)remtxopindurfield << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, (REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)remtxopindurfield << 4));
}
__INLINE uint8_t nxmac_send_cf_end_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void nxmac_send_cf_end_setf(uint8_t sendcfend)
{
    ASSERT_ERR((((uint32_t)sendcfend << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, (REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)sendcfend << 1));
}
__INLINE uint8_t nxmac_send_cf_end_now_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_send_cf_end_now_setf(uint8_t sendcfendnow)
{
    ASSERT_ERR((((uint32_t)sendcfendnow << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_EDCA_CNTRL_ADDR, (REG_PL_RD(NXMAC_EDCA_CNTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)sendcfendnow << 0));
}
#define NXMAC_QUIET_ELEMENT_1A_ADDR REG_MAC_CORE_BASE_ADDR + 0x0280
#define NXMAC_QUIET_ELEMENT_1A_OFFSET 0x00000280
#define NXMAC_QUIET_ELEMENT_1A_INDEX 0x000000A0
#define NXMAC_QUIET_ELEMENT_1A_RESET 0x00000000
__INLINE uint32_t nxmac_quiet_element_1a_get(void)
{
    return REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR);
}
__INLINE void nxmac_quiet_element_1a_set(uint32_t value)
{
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1A_ADDR, value);
}
#define NXMAC_QUIET_DURATION_1_MASK ((uint32_t)0xFFFF0000)
#define NXMAC_QUIET_DURATION_1_LSB 16
#define NXMAC_QUIET_DURATION_1_WIDTH ((uint32_t)0x00000010)
#define NXMAC_QUIET_PERIOD_1_MASK ((uint32_t)0x0000FF00)
#define NXMAC_QUIET_PERIOD_1_LSB 8
#define NXMAC_QUIET_PERIOD_1_WIDTH ((uint32_t)0x00000008)
#define NXMAC_QUIET_COUNT_1_MASK ((uint32_t)0x000000FF)
#define NXMAC_QUIET_COUNT_1_LSB 0
#define NXMAC_QUIET_COUNT_1_WIDTH ((uint32_t)0x00000008)
#define NXMAC_QUIET_DURATION_1_RST 0x0
#define NXMAC_QUIET_PERIOD_1_RST 0x0
#define NXMAC_QUIET_COUNT_1_RST 0x0
__INLINE void nxmac_quiet_element_1a_pack(uint16_t quietduration1, uint8_t quietperiod1, uint8_t quietcount1)
{
    ASSERT_ERR((((uint32_t)quietduration1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)quietperiod1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)quietcount1 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1A_ADDR, ((uint32_t)quietduration1 << 16) | ((uint32_t)quietperiod1 << 8) | ((uint32_t)quietcount1 << 0));
}
__INLINE void nxmac_quiet_element_1a_unpack(uint16_t* quietduration1, uint8_t* quietperiod1, uint8_t* quietcount1)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR);
    *quietduration1 = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *quietperiod1 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *quietcount1 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_quiet_duration_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void nxmac_quiet_duration_1_setf(uint16_t quietduration1)
{
    ASSERT_ERR((((uint32_t)quietduration1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)quietduration1 << 16));
}
__INLINE uint8_t nxmac_quiet_period_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_quiet_period_1_setf(uint8_t quietperiod1)
{
    ASSERT_ERR((((uint32_t)quietperiod1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)quietperiod1 << 8));
}
__INLINE uint8_t nxmac_quiet_count_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_quiet_count_1_setf(uint8_t quietcount1)
{
    ASSERT_ERR((((uint32_t)quietcount1 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_1A_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)quietcount1 << 0));
}
#define NXMAC_QUIET_ELEMENT_1B_ADDR REG_MAC_CORE_BASE_ADDR + 0x0284
#define NXMAC_QUIET_ELEMENT_1B_OFFSET 0x00000284
#define NXMAC_QUIET_ELEMENT_1B_INDEX 0x000000A1
#define NXMAC_QUIET_ELEMENT_1B_RESET 0x00000000
__INLINE uint32_t nxmac_quiet_element_1b_get(void)
{
    return REG_PL_RD(NXMAC_QUIET_ELEMENT_1B_ADDR);
}
__INLINE void nxmac_quiet_element_1b_set(uint32_t value)
{
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1B_ADDR, value);
}
#define NXMAC_QUIET_OFFSET_1_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_QUIET_OFFSET_1_LSB 0
#define NXMAC_QUIET_OFFSET_1_WIDTH ((uint32_t)0x00000010)
#define NXMAC_QUIET_OFFSET_1_RST 0x0
__INLINE uint16_t nxmac_quiet_offset_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_1B_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_quiet_offset_1_setf(uint16_t quietoffset1)
{
    ASSERT_ERR((((uint32_t)quietoffset1 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_1B_ADDR, (uint32_t)quietoffset1 << 0);
}
#define NXMAC_QUIET_ELEMENT_2A_ADDR REG_MAC_CORE_BASE_ADDR + 0x0288
#define NXMAC_QUIET_ELEMENT_2A_OFFSET 0x00000288
#define NXMAC_QUIET_ELEMENT_2A_INDEX 0x000000A2
#define NXMAC_QUIET_ELEMENT_2A_RESET 0x00000000
__INLINE uint32_t nxmac_quiet_element_2a_get(void)
{
    return REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR);
}
__INLINE void nxmac_quiet_element_2a_set(uint32_t value)
{
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2A_ADDR, value);
}
#define NXMAC_QUIET_DURATION_2_MASK ((uint32_t)0xFFFF0000)
#define NXMAC_QUIET_DURATION_2_LSB 16
#define NXMAC_QUIET_DURATION_2_WIDTH ((uint32_t)0x00000010)
#define NXMAC_QUIET_PERIOD_2_MASK ((uint32_t)0x0000FF00)
#define NXMAC_QUIET_PERIOD_2_LSB 8
#define NXMAC_QUIET_PERIOD_2_WIDTH ((uint32_t)0x00000008)
#define NXMAC_QUIET_COUNT_2_MASK ((uint32_t)0x000000FF)
#define NXMAC_QUIET_COUNT_2_LSB 0
#define NXMAC_QUIET_COUNT_2_WIDTH ((uint32_t)0x00000008)
#define NXMAC_QUIET_DURATION_2_RST 0x0
#define NXMAC_QUIET_PERIOD_2_RST 0x0
#define NXMAC_QUIET_COUNT_2_RST 0x0
__INLINE void nxmac_quiet_element_2a_pack(uint16_t quietduration2, uint8_t quietperiod2, uint8_t quietcount2)
{
    ASSERT_ERR((((uint32_t)quietduration2 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)quietperiod2 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)quietcount2 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2A_ADDR, ((uint32_t)quietduration2 << 16) | ((uint32_t)quietperiod2 << 8) | ((uint32_t)quietcount2 << 0));
}
__INLINE void nxmac_quiet_element_2a_unpack(uint16_t* quietduration2, uint8_t* quietperiod2, uint8_t* quietcount2)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR);
    *quietduration2 = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *quietperiod2 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *quietcount2 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint16_t nxmac_quiet_duration_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void nxmac_quiet_duration_2_setf(uint16_t quietduration2)
{
    ASSERT_ERR((((uint32_t)quietduration2 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)quietduration2 << 16));
}
__INLINE uint8_t nxmac_quiet_period_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_quiet_period_2_setf(uint8_t quietperiod2)
{
    ASSERT_ERR((((uint32_t)quietperiod2 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)quietperiod2 << 8));
}
__INLINE uint8_t nxmac_quiet_count_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_quiet_count_2_setf(uint8_t quietcount2)
{
    ASSERT_ERR((((uint32_t)quietcount2 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2A_ADDR, (REG_PL_RD(NXMAC_QUIET_ELEMENT_2A_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)quietcount2 << 0));
}
#define NXMAC_QUIET_ELEMENT_2B_ADDR REG_MAC_CORE_BASE_ADDR + 0x028C
#define NXMAC_QUIET_ELEMENT_2B_OFFSET 0x0000028C
#define NXMAC_QUIET_ELEMENT_2B_INDEX 0x000000A3
#define NXMAC_QUIET_ELEMENT_2B_RESET 0x00000000
__INLINE uint32_t nxmac_quiet_element_2b_get(void)
{
    return REG_PL_RD(NXMAC_QUIET_ELEMENT_2B_ADDR);
}
__INLINE void nxmac_quiet_element_2b_set(uint32_t value)
{
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2B_ADDR, value);
}
#define NXMAC_QUIET_OFFSET_2_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_QUIET_OFFSET_2_LSB 0
#define NXMAC_QUIET_OFFSET_2_WIDTH ((uint32_t)0x00000010)
#define NXMAC_QUIET_OFFSET_2_RST 0x0
__INLINE uint16_t nxmac_quiet_offset_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_QUIET_ELEMENT_2B_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_quiet_offset_2_setf(uint16_t quietoffset2)
{
    ASSERT_ERR((((uint32_t)quietoffset2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_QUIET_ELEMENT_2B_ADDR, (uint32_t)quietoffset2 << 0);
}
#define NXMAC_ADD_CCA_BUSY_SEC_20_ADDR REG_MAC_CORE_BASE_ADDR + 0x0290
#define NXMAC_ADD_CCA_BUSY_SEC_20_OFFSET 0x00000290
#define NXMAC_ADD_CCA_BUSY_SEC_20_INDEX 0x000000A4
#define NXMAC_ADD_CCA_BUSY_SEC_20_RESET 0x00000000
__INLINE uint32_t nxmac_add_cca_busy_sec_20_get(void)
{
    return REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_20_ADDR);
}
__INLINE void nxmac_add_cca_busy_sec_20_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_20_ADDR, value);
}
#define NXMAC_CCA_BUSY_DUR_SEC_20_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_CCA_BUSY_DUR_SEC_20_LSB 0
#define NXMAC_CCA_BUSY_DUR_SEC_20_WIDTH ((uint32_t)0x00000020)
#define NXMAC_CCA_BUSY_DUR_SEC_20_RST 0x0
__INLINE uint32_t nxmac_cca_busy_dur_sec_20_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_20_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_cca_busy_dur_sec_20_setf(uint32_t ccabusydursec20)
{
    ASSERT_ERR((((uint32_t)ccabusydursec20 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_20_ADDR, (uint32_t)ccabusydursec20 << 0);
}
#define NXMAC_ADD_CCA_BUSY_SEC_40_ADDR REG_MAC_CORE_BASE_ADDR + 0x0294
#define NXMAC_ADD_CCA_BUSY_SEC_40_OFFSET 0x00000294
#define NXMAC_ADD_CCA_BUSY_SEC_40_INDEX 0x000000A5
#define NXMAC_ADD_CCA_BUSY_SEC_40_RESET 0x00000000
__INLINE uint32_t nxmac_add_cca_busy_sec_40_get(void)
{
    return REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_40_ADDR);
}
__INLINE void nxmac_add_cca_busy_sec_40_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_40_ADDR, value);
}
#define NXMAC_CCA_BUSY_DUR_SEC_40_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_CCA_BUSY_DUR_SEC_40_LSB 0
#define NXMAC_CCA_BUSY_DUR_SEC_40_WIDTH ((uint32_t)0x00000020)
#define NXMAC_CCA_BUSY_DUR_SEC_40_RST 0x0
__INLINE uint32_t nxmac_cca_busy_dur_sec_40_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_40_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_cca_busy_dur_sec_40_setf(uint32_t ccabusydursec40)
{
    ASSERT_ERR((((uint32_t)ccabusydursec40 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_40_ADDR, (uint32_t)ccabusydursec40 << 0);
}
#define NXMAC_ADD_CCA_BUSY_SEC_80_ADDR REG_MAC_CORE_BASE_ADDR + 0x0298
#define NXMAC_ADD_CCA_BUSY_SEC_80_OFFSET 0x00000298
#define NXMAC_ADD_CCA_BUSY_SEC_80_INDEX 0x000000A6
#define NXMAC_ADD_CCA_BUSY_SEC_80_RESET 0x00000000
__INLINE uint32_t nxmac_add_cca_busy_sec_80_get(void)
{
    return REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_80_ADDR);
}
__INLINE void nxmac_add_cca_busy_sec_80_set(uint32_t value)
{
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_80_ADDR, value);
}
#define NXMAC_CCA_BUSY_DUR_SEC_80_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_CCA_BUSY_DUR_SEC_80_LSB 0
#define NXMAC_CCA_BUSY_DUR_SEC_80_WIDTH ((uint32_t)0x00000020)
#define NXMAC_CCA_BUSY_DUR_SEC_80_RST 0x0
__INLINE uint32_t nxmac_cca_busy_dur_sec_80_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_ADD_CCA_BUSY_SEC_80_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_cca_busy_dur_sec_80_setf(uint32_t ccabusydursec80)
{
    ASSERT_ERR((((uint32_t)ccabusydursec80 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(NXMAC_ADD_CCA_BUSY_SEC_80_ADDR, (uint32_t)ccabusydursec80 << 0);
}
#define NXMAC_STBC_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0300
#define NXMAC_STBC_CNTRL_OFFSET 0x00000300
#define NXMAC_STBC_CNTRL_INDEX 0x000000C0
#define NXMAC_STBC_CNTRL_RESET 0x00000000
__INLINE uint32_t nxmac_stbc_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
}
__INLINE void nxmac_stbc_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, value);
}
#define NXMAC_BASIC_STBCMCS_MASK ((uint32_t)0xFE000000)
#define NXMAC_BASIC_STBCMCS_LSB 25
#define NXMAC_BASIC_STBCMCS_WIDTH ((uint32_t)0x00000007)
#define NXMAC_DUAL_CTS_PROT_BIT ((uint32_t)0x01000000)
#define NXMAC_DUAL_CTS_PROT_POS 24
#define NXMAC_CTS_STBC_DUR_MASK ((uint32_t)0x00FF0000)
#define NXMAC_CTS_STBC_DUR_LSB 16
#define NXMAC_CTS_STBC_DUR_WIDTH ((uint32_t)0x00000008)
#define NXMAC_CF_END_STBC_DUR_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_CF_END_STBC_DUR_LSB 0
#define NXMAC_CF_END_STBC_DUR_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BASIC_STBCMCS_RST 0x0
#define NXMAC_DUAL_CTS_PROT_RST 0x0
#define NXMAC_CTS_STBC_DUR_RST 0x0
#define NXMAC_CF_END_STBC_DUR_RST 0x0
__INLINE void nxmac_stbc_cntrl_pack(uint8_t basicstbcmcs, uint8_t dualctsprot, uint8_t ctsstbcdur, uint16_t cfendstbcdur)
{
    ASSERT_ERR((((uint32_t)basicstbcmcs << 25) & ~((uint32_t)0xFE000000)) == 0);
    ASSERT_ERR((((uint32_t)dualctsprot << 24) & ~((uint32_t)0x01000000)) == 0);
    ASSERT_ERR((((uint32_t)ctsstbcdur << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)cfendstbcdur << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, ((uint32_t)basicstbcmcs << 25) | ((uint32_t)dualctsprot << 24) | ((uint32_t)ctsstbcdur << 16) | ((uint32_t)cfendstbcdur << 0));
}
__INLINE void nxmac_stbc_cntrl_unpack(uint8_t* basicstbcmcs, uint8_t* dualctsprot, uint8_t* ctsstbcdur, uint16_t* cfendstbcdur)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
    *basicstbcmcs = (localVal & ((uint32_t)0xFE000000)) >> 25;
    *dualctsprot = (localVal & ((uint32_t)0x01000000)) >> 24;
    *ctsstbcdur = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *cfendstbcdur = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint8_t nxmac_basic_stbcmcs_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE void nxmac_basic_stbcmcs_setf(uint8_t basicstbcmcs)
{
    ASSERT_ERR((((uint32_t)basicstbcmcs << 25) & ~((uint32_t)0xFE000000)) == 0);
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, (REG_PL_RD(NXMAC_STBC_CNTRL_ADDR) & ~((uint32_t)0xFE000000)) | ((uint32_t)basicstbcmcs << 25));
}
__INLINE uint8_t nxmac_dual_cts_prot_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void nxmac_dual_cts_prot_setf(uint8_t dualctsprot)
{
    ASSERT_ERR((((uint32_t)dualctsprot << 24) & ~((uint32_t)0x01000000)) == 0);
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, (REG_PL_RD(NXMAC_STBC_CNTRL_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)dualctsprot << 24));
}
__INLINE uint8_t nxmac_cts_stbc_dur_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_cts_stbc_dur_setf(uint8_t ctsstbcdur)
{
    ASSERT_ERR((((uint32_t)ctsstbcdur << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, (REG_PL_RD(NXMAC_STBC_CNTRL_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)ctsstbcdur << 16));
}
__INLINE uint16_t nxmac_cf_end_stbc_dur_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_STBC_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_cf_end_stbc_dur_setf(uint16_t cfendstbcdur)
{
    ASSERT_ERR((((uint32_t)cfendstbcdur << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_STBC_CNTRL_ADDR, (REG_PL_RD(NXMAC_STBC_CNTRL_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)cfendstbcdur << 0));
}
#define NXMAC_START_TX_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0304
#define NXMAC_START_TX_1_OFFSET 0x00000304
#define NXMAC_START_TX_1_INDEX 0x000000C1
#define NXMAC_START_TX_1_RESET 0x00000000
__INLINE uint32_t nxmac_start_tx_1_get(void)
{
    return REG_PL_RD(NXMAC_START_TX_1_ADDR);
}
__INLINE void nxmac_start_tx_1_set(uint32_t value)
{
    REG_PL_WR(NXMAC_START_TX_1_ADDR, value);
}
#define NXMAC_START_TX_BW_MASK ((uint32_t)0x30000000)
#define NXMAC_START_TX_BW_LSB 28
#define NXMAC_START_TX_BW_WIDTH ((uint32_t)0x00000002)
#define NXMAC_START_TX_PRE_TYPE_BIT ((uint32_t)0x08000000)
#define NXMAC_START_TX_PRE_TYPE_POS 27
#define NXMAC_START_TX_FORMAT_MOD_MASK ((uint32_t)0x07000000)
#define NXMAC_START_TX_FORMAT_MOD_LSB 24
#define NXMAC_START_TX_FORMAT_MOD_WIDTH ((uint32_t)0x00000003)
#define NXMAC_START_TX_MCS_INDEX_0_MASK ((uint32_t)0x00FF0000)
#define NXMAC_START_TX_MCS_INDEX_0_LSB 16
#define NXMAC_START_TX_MCS_INDEX_0_WIDTH ((uint32_t)0x00000008)
#define NXMAC_START_TX_KSR_INDEX_MASK ((uint32_t)0x0000FFC0)
#define NXMAC_START_TX_KSR_INDEX_LSB 6
#define NXMAC_START_TX_KSR_INDEX_WIDTH ((uint32_t)0x0000000A)
#define NXMAC_START_TX_AC_MASK ((uint32_t)0x00000018)
#define NXMAC_START_TX_AC_LSB 3
#define NXMAC_START_TX_AC_WIDTH ((uint32_t)0x00000002)
#define NXMAC_START_TX_FRM_EX_TYPE_MASK ((uint32_t)0x00000006)
#define NXMAC_START_TX_FRM_EX_TYPE_LSB 1
#define NXMAC_START_TX_FRM_EX_TYPE_WIDTH ((uint32_t)0x00000002)
#define NXMAC_START_TX_FRAME_EX_BIT ((uint32_t)0x00000001)
#define NXMAC_START_TX_FRAME_EX_POS 0
#define NXMAC_START_TX_BW_RST 0x0
#define NXMAC_START_TX_PRE_TYPE_RST 0x0
#define NXMAC_START_TX_FORMAT_MOD_RST 0x0
#define NXMAC_START_TX_MCS_INDEX_0_RST 0x0
#define NXMAC_START_TX_KSR_INDEX_RST 0x0
#define NXMAC_START_TX_AC_RST 0x0
#define NXMAC_START_TX_FRM_EX_TYPE_RST 0x0
#define NXMAC_START_TX_FRAME_EX_RST 0x0
__INLINE void nxmac_start_tx_1_pack(uint8_t starttxbw, uint8_t starttxpretype, uint8_t starttxformatmod, uint8_t starttxmcsindex0, uint16_t starttxksrindex, uint8_t starttxac, uint8_t starttxfrmextype, uint8_t starttxframeex)
{
    ASSERT_ERR((((uint32_t)starttxbw << 28) & ~((uint32_t)0x30000000)) == 0);
    ASSERT_ERR((((uint32_t)starttxpretype << 27) & ~((uint32_t)0x08000000)) == 0);
    ASSERT_ERR((((uint32_t)starttxformatmod << 24) & ~((uint32_t)0x07000000)) == 0);
    ASSERT_ERR((((uint32_t)starttxmcsindex0 << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)starttxksrindex << 6) & ~((uint32_t)0x0000FFC0)) == 0);
    ASSERT_ERR((((uint32_t)starttxac << 3) & ~((uint32_t)0x00000018)) == 0);
    ASSERT_ERR((((uint32_t)starttxfrmextype << 1) & ~((uint32_t)0x00000006)) == 0);
    ASSERT_ERR((((uint32_t)starttxframeex << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, ((uint32_t)starttxbw << 28) | ((uint32_t)starttxpretype << 27) | ((uint32_t)starttxformatmod << 24) | ((uint32_t)starttxmcsindex0 << 16) | ((uint32_t)starttxksrindex << 6) | ((uint32_t)starttxac << 3) | ((uint32_t)starttxfrmextype << 1) | ((uint32_t)starttxframeex << 0));
}
__INLINE void nxmac_start_tx_1_unpack(uint8_t* starttxbw, uint8_t* starttxpretype, uint8_t* starttxformatmod, uint8_t* starttxmcsindex0, uint16_t* starttxksrindex, uint8_t* starttxac, uint8_t* starttxfrmextype, uint8_t* starttxframeex)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    *starttxbw = (localVal & ((uint32_t)0x30000000)) >> 28;
    *starttxpretype = (localVal & ((uint32_t)0x08000000)) >> 27;
    *starttxformatmod = (localVal & ((uint32_t)0x07000000)) >> 24;
    *starttxmcsindex0 = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *starttxksrindex = (localVal & ((uint32_t)0x0000FFC0)) >> 6;
    *starttxac = (localVal & ((uint32_t)0x00000018)) >> 3;
    *starttxfrmextype = (localVal & ((uint32_t)0x00000006)) >> 1;
    *starttxframeex = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_start_tx_bw_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void nxmac_start_tx_bw_setf(uint8_t starttxbw)
{
    ASSERT_ERR((((uint32_t)starttxbw << 28) & ~((uint32_t)0x30000000)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)starttxbw << 28));
}
__INLINE uint8_t nxmac_start_tx_pre_type_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void nxmac_start_tx_pre_type_setf(uint8_t starttxpretype)
{
    ASSERT_ERR((((uint32_t)starttxpretype << 27) & ~((uint32_t)0x08000000)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)starttxpretype << 27));
}
__INLINE uint8_t nxmac_start_tx_format_mod_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void nxmac_start_tx_format_mod_setf(uint8_t starttxformatmod)
{
    ASSERT_ERR((((uint32_t)starttxformatmod << 24) & ~((uint32_t)0x07000000)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)starttxformatmod << 24));
}
__INLINE uint8_t nxmac_start_tx_mcs_index_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_start_tx_mcs_index_0_setf(uint8_t starttxmcsindex0)
{
    ASSERT_ERR((((uint32_t)starttxmcsindex0 << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)starttxmcsindex0 << 16));
}
__INLINE uint16_t nxmac_start_tx_ksr_index_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFC0)) >> 6);
}
__INLINE void nxmac_start_tx_ksr_index_setf(uint16_t starttxksrindex)
{
    ASSERT_ERR((((uint32_t)starttxksrindex << 6) & ~((uint32_t)0x0000FFC0)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x0000FFC0)) | ((uint32_t)starttxksrindex << 6));
}
__INLINE uint8_t nxmac_start_tx_ac_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x00000018)) >> 3);
}
__INLINE void nxmac_start_tx_ac_setf(uint8_t starttxac)
{
    ASSERT_ERR((((uint32_t)starttxac << 3) & ~((uint32_t)0x00000018)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x00000018)) | ((uint32_t)starttxac << 3));
}
__INLINE uint8_t nxmac_start_tx_frm_ex_type_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void nxmac_start_tx_frm_ex_type_setf(uint8_t starttxfrmextype)
{
    ASSERT_ERR((((uint32_t)starttxfrmextype << 1) & ~((uint32_t)0x00000006)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)starttxfrmextype << 1));
}
__INLINE uint8_t nxmac_start_tx_frame_ex_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_start_tx_frame_ex_setf(uint8_t starttxframeex)
{
    ASSERT_ERR((((uint32_t)starttxframeex << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_START_TX_1_ADDR, (REG_PL_RD(NXMAC_START_TX_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)starttxframeex << 0));
}
#define NXMAC_START_TX_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0308
#define NXMAC_START_TX_2_OFFSET 0x00000308
#define NXMAC_START_TX_2_INDEX 0x000000C2
#define NXMAC_START_TX_2_RESET 0x00000000
__INLINE uint32_t nxmac_start_tx_2_get(void)
{
    return REG_PL_RD(NXMAC_START_TX_2_ADDR);
}
__INLINE void nxmac_start_tx_2_set(uint32_t value)
{
    REG_PL_WR(NXMAC_START_TX_2_ADDR, value);
}
#define NXMAC_DUR_CONTROL_FRM_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_DUR_CONTROL_FRM_LSB 0
#define NXMAC_DUR_CONTROL_FRM_WIDTH ((uint32_t)0x00000010)
#define NXMAC_DUR_CONTROL_FRM_RST 0x0
__INLINE uint16_t nxmac_dur_control_frm_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_dur_control_frm_setf(uint16_t durcontrolfrm)
{
    ASSERT_ERR((((uint32_t)durcontrolfrm << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_START_TX_2_ADDR, (uint32_t)durcontrolfrm << 0);
}
#define NXMAC_START_TX_3_ADDR REG_MAC_CORE_BASE_ADDR + 0x030C
#define NXMAC_START_TX_3_OFFSET 0x0000030C
#define NXMAC_START_TX_3_INDEX 0x000000C3
#define NXMAC_START_TX_3_RESET 0x00000000
__INLINE uint32_t nxmac_start_tx_3_get(void)
{
    return REG_PL_RD(NXMAC_START_TX_3_ADDR);
}
__INLINE void nxmac_start_tx_3_set(uint32_t value)
{
    REG_PL_WR(NXMAC_START_TX_3_ADDR, value);
}
#define NXMAC_START_TX_SMM_INDEX_MASK ((uint32_t)0xFF000000)
#define NXMAC_START_TX_SMM_INDEX_LSB 24
#define NXMAC_START_TX_SMM_INDEX_WIDTH ((uint32_t)0x00000008)
#define NXMAC_START_TX_ANTENNA_SET_MASK ((uint32_t)0x00FF0000)
#define NXMAC_START_TX_ANTENNA_SET_LSB 16
#define NXMAC_START_TX_ANTENNA_SET_WIDTH ((uint32_t)0x00000008)
#define NXMAC_START_TX_LSTP_BIT ((uint32_t)0x00002000)
#define NXMAC_START_TX_LSTP_POS 13
#define NXMAC_START_TX_SMOOTHING_BIT ((uint32_t)0x00001000)
#define NXMAC_START_TX_SMOOTHING_POS 12
#define NXMAC_START_TX_SHORT_GI_BIT ((uint32_t)0x00000100)
#define NXMAC_START_TX_SHORT_GI_POS 8
#define NXMAC_START_TX_N_TX_MASK ((uint32_t)0x000000E0)
#define NXMAC_START_TX_N_TX_LSB 5
#define NXMAC_START_TX_N_TX_WIDTH ((uint32_t)0x00000003)
#define NXMAC_START_TX_FEC_CODING_BIT ((uint32_t)0x00000010)
#define NXMAC_START_TX_FEC_CODING_POS 4
#define NXMAC_START_TX_STBC_MASK ((uint32_t)0x0000000C)
#define NXMAC_START_TX_STBC_LSB 2
#define NXMAC_START_TX_STBC_WIDTH ((uint32_t)0x00000002)
#define NXMAC_START_TX_NUM_EXTN_SS_MASK ((uint32_t)0x00000003)
#define NXMAC_START_TX_NUM_EXTN_SS_LSB 0
#define NXMAC_START_TX_NUM_EXTN_SS_WIDTH ((uint32_t)0x00000002)
#define NXMAC_START_TX_SMM_INDEX_RST 0x0
#define NXMAC_START_TX_ANTENNA_SET_RST 0x0
#define NXMAC_START_TX_LSTP_RST 0x0
#define NXMAC_START_TX_SMOOTHING_RST 0x0
#define NXMAC_START_TX_SHORT_GI_RST 0x0
#define NXMAC_START_TX_N_TX_RST 0x0
#define NXMAC_START_TX_FEC_CODING_RST 0x0
#define NXMAC_START_TX_STBC_RST 0x0
#define NXMAC_START_TX_NUM_EXTN_SS_RST 0x0
__INLINE void nxmac_start_tx_3_pack(uint8_t starttxsmmindex, uint8_t starttxantennaset, uint8_t starttxlstp, uint8_t starttxsmoothing, uint8_t starttxshortgi, uint8_t starttxntx, uint8_t starttxfeccoding, uint8_t starttxstbc, uint8_t starttxnumextnss)
{
    ASSERT_ERR((((uint32_t)starttxsmmindex << 24) & ~((uint32_t)0xFF000000)) == 0);
    ASSERT_ERR((((uint32_t)starttxantennaset << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)starttxlstp << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)starttxsmoothing << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)starttxshortgi << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)starttxntx << 5) & ~((uint32_t)0x000000E0)) == 0);
    ASSERT_ERR((((uint32_t)starttxfeccoding << 4) & ~((uint32_t)0x00000010)) == 0);
    ASSERT_ERR((((uint32_t)starttxstbc << 2) & ~((uint32_t)0x0000000C)) == 0);
    ASSERT_ERR((((uint32_t)starttxnumextnss << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, ((uint32_t)starttxsmmindex << 24) | ((uint32_t)starttxantennaset << 16) | ((uint32_t)starttxlstp << 13) | ((uint32_t)starttxsmoothing << 12) | ((uint32_t)starttxshortgi << 8) | ((uint32_t)starttxntx << 5) | ((uint32_t)starttxfeccoding << 4) | ((uint32_t)starttxstbc << 2) | ((uint32_t)starttxnumextnss << 0));
}
__INLINE void nxmac_start_tx_3_unpack(uint8_t* starttxsmmindex, uint8_t* starttxantennaset, uint8_t* starttxlstp, uint8_t* starttxsmoothing, uint8_t* starttxshortgi, uint8_t* starttxntx, uint8_t* starttxfeccoding, uint8_t* starttxstbc, uint8_t* starttxnumextnss)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    *starttxsmmindex = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *starttxantennaset = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *starttxlstp = (localVal & ((uint32_t)0x00002000)) >> 13;
    *starttxsmoothing = (localVal & ((uint32_t)0x00001000)) >> 12;
    *starttxshortgi = (localVal & ((uint32_t)0x00000100)) >> 8;
    *starttxntx = (localVal & ((uint32_t)0x000000E0)) >> 5;
    *starttxfeccoding = (localVal & ((uint32_t)0x00000010)) >> 4;
    *starttxstbc = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *starttxnumextnss = (localVal & ((uint32_t)0x00000003)) >> 0;
}
__INLINE uint8_t nxmac_start_tx_smm_index_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void nxmac_start_tx_smm_index_setf(uint8_t starttxsmmindex)
{
    ASSERT_ERR((((uint32_t)starttxsmmindex << 24) & ~((uint32_t)0xFF000000)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)starttxsmmindex << 24));
}
__INLINE uint8_t nxmac_start_tx_antenna_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void nxmac_start_tx_antenna_set_setf(uint8_t starttxantennaset)
{
    ASSERT_ERR((((uint32_t)starttxantennaset << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)starttxantennaset << 16));
}
__INLINE uint8_t nxmac_start_tx_lstp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void nxmac_start_tx_lstp_setf(uint8_t starttxlstp)
{
    ASSERT_ERR((((uint32_t)starttxlstp << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)starttxlstp << 13));
}
__INLINE uint8_t nxmac_start_tx_smoothing_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void nxmac_start_tx_smoothing_setf(uint8_t starttxsmoothing)
{
    ASSERT_ERR((((uint32_t)starttxsmoothing << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)starttxsmoothing << 12));
}
__INLINE uint8_t nxmac_start_tx_short_gi_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void nxmac_start_tx_short_gi_setf(uint8_t starttxshortgi)
{
    ASSERT_ERR((((uint32_t)starttxshortgi << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)starttxshortgi << 8));
}
__INLINE uint8_t nxmac_start_tx_n_tx_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void nxmac_start_tx_n_tx_setf(uint8_t starttxntx)
{
    ASSERT_ERR((((uint32_t)starttxntx << 5) & ~((uint32_t)0x000000E0)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)starttxntx << 5));
}
__INLINE uint8_t nxmac_start_tx_fec_coding_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void nxmac_start_tx_fec_coding_setf(uint8_t starttxfeccoding)
{
    ASSERT_ERR((((uint32_t)starttxfeccoding << 4) & ~((uint32_t)0x00000010)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)starttxfeccoding << 4));
}
__INLINE uint8_t nxmac_start_tx_stbc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void nxmac_start_tx_stbc_setf(uint8_t starttxstbc)
{
    ASSERT_ERR((((uint32_t)starttxstbc << 2) & ~((uint32_t)0x0000000C)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)starttxstbc << 2));
}
__INLINE uint8_t nxmac_start_tx_num_extn_ss_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_START_TX_3_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void nxmac_start_tx_num_extn_ss_setf(uint8_t starttxnumextnss)
{
    ASSERT_ERR((((uint32_t)starttxnumextnss << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(NXMAC_START_TX_3_ADDR, (REG_PL_RD(NXMAC_START_TX_3_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)starttxnumextnss << 0));
}
#define NXMAC_TX_BW_CNTRL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0310
#define NXMAC_TX_BW_CNTRL_OFFSET 0x00000310
#define NXMAC_TX_BW_CNTRL_INDEX 0x000000C4
#define NXMAC_TX_BW_CNTRL_RESET 0x00020A18
__INLINE uint32_t nxmac_tx_bw_cntrl_get(void)
{
    return REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
}
__INLINE void nxmac_tx_bw_cntrl_set(uint32_t value)
{
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, value);
}
#define NXMAC_MAX_SUPPORTED_BW_MASK ((uint32_t)0x00030000)
#define NXMAC_MAX_SUPPORTED_BW_LSB 16
#define NXMAC_MAX_SUPPORTED_BW_WIDTH ((uint32_t)0x00000002)
#define NXMAC_A_PPDU_MAX_TIME_MASK ((uint32_t)0x0000FF00)
#define NXMAC_A_PPDU_MAX_TIME_LSB 8
#define NXMAC_A_PPDU_MAX_TIME_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DYN_BW_EN_BIT ((uint32_t)0x00000080)
#define NXMAC_DYN_BW_EN_POS 7
#define NXMAC_NUM_TRY_BW_ACQUISITION_MASK ((uint32_t)0x00000070)
#define NXMAC_NUM_TRY_BW_ACQUISITION_LSB 4
#define NXMAC_NUM_TRY_BW_ACQUISITION_WIDTH ((uint32_t)0x00000003)
#define NXMAC_DROP_TO_LOWER_BW_BIT ((uint32_t)0x00000008)
#define NXMAC_DROP_TO_LOWER_BW_POS 3
#define NXMAC_DEFAULT_BWTXOP_MASK ((uint32_t)0x00000006)
#define NXMAC_DEFAULT_BWTXOP_LSB 1
#define NXMAC_DEFAULT_BWTXOP_WIDTH ((uint32_t)0x00000002)
#define NXMAC_DEFAULT_BWTXOPV_BIT ((uint32_t)0x00000001)
#define NXMAC_DEFAULT_BWTXOPV_POS 0
#define NXMAC_MAX_SUPPORTED_BW_RST 0x2
#define NXMAC_A_PPDU_MAX_TIME_RST 0xA
#define NXMAC_DYN_BW_EN_RST 0x0
#define NXMAC_NUM_TRY_BW_ACQUISITION_RST 0x1
#define NXMAC_DROP_TO_LOWER_BW_RST 0x1
#define NXMAC_DEFAULT_BWTXOP_RST 0x0
#define NXMAC_DEFAULT_BWTXOPV_RST 0x0
__INLINE void nxmac_tx_bw_cntrl_pack(uint8_t maxsupportedbw, uint8_t appdumaxtime, uint8_t dynbwen, uint8_t numtrybwacquisition, uint8_t droptolowerbw, uint8_t defaultbwtxop, uint8_t defaultbwtxopv)
{
    ASSERT_ERR((((uint32_t)maxsupportedbw << 16) & ~((uint32_t)0x00030000)) == 0);
    ASSERT_ERR((((uint32_t)appdumaxtime << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)dynbwen << 7) & ~((uint32_t)0x00000080)) == 0);
    ASSERT_ERR((((uint32_t)numtrybwacquisition << 4) & ~((uint32_t)0x00000070)) == 0);
    ASSERT_ERR((((uint32_t)droptolowerbw << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)defaultbwtxop << 1) & ~((uint32_t)0x00000006)) == 0);
    ASSERT_ERR((((uint32_t)defaultbwtxopv << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, ((uint32_t)maxsupportedbw << 16) | ((uint32_t)appdumaxtime << 8) | ((uint32_t)dynbwen << 7) | ((uint32_t)numtrybwacquisition << 4) | ((uint32_t)droptolowerbw << 3) | ((uint32_t)defaultbwtxop << 1) | ((uint32_t)defaultbwtxopv << 0));
}
__INLINE void nxmac_tx_bw_cntrl_unpack(uint8_t* maxsupportedbw, uint8_t* appdumaxtime, uint8_t* dynbwen, uint8_t* numtrybwacquisition, uint8_t* droptolowerbw, uint8_t* defaultbwtxop, uint8_t* defaultbwtxopv)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    *maxsupportedbw = (localVal & ((uint32_t)0x00030000)) >> 16;
    *appdumaxtime = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *dynbwen = (localVal & ((uint32_t)0x00000080)) >> 7;
    *numtrybwacquisition = (localVal & ((uint32_t)0x00000070)) >> 4;
    *droptolowerbw = (localVal & ((uint32_t)0x00000008)) >> 3;
    *defaultbwtxop = (localVal & ((uint32_t)0x00000006)) >> 1;
    *defaultbwtxopv = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_max_supported_bw_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void nxmac_max_supported_bw_setf(uint8_t maxsupportedbw)
{
    ASSERT_ERR((((uint32_t)maxsupportedbw << 16) & ~((uint32_t)0x00030000)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)maxsupportedbw << 16));
}
__INLINE uint8_t nxmac_a_ppdu_max_time_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_a_ppdu_max_time_setf(uint8_t appdumaxtime)
{
    ASSERT_ERR((((uint32_t)appdumaxtime << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)appdumaxtime << 8));
}
__INLINE uint8_t nxmac_dyn_bw_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void nxmac_dyn_bw_en_setf(uint8_t dynbwen)
{
    ASSERT_ERR((((uint32_t)dynbwen << 7) & ~((uint32_t)0x00000080)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)dynbwen << 7));
}
__INLINE uint8_t nxmac_num_try_bw_acquisition_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void nxmac_num_try_bw_acquisition_setf(uint8_t numtrybwacquisition)
{
    ASSERT_ERR((((uint32_t)numtrybwacquisition << 4) & ~((uint32_t)0x00000070)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)numtrybwacquisition << 4));
}
__INLINE uint8_t nxmac_drop_to_lower_bw_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void nxmac_drop_to_lower_bw_setf(uint8_t droptolowerbw)
{
    ASSERT_ERR((((uint32_t)droptolowerbw << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)droptolowerbw << 3));
}
__INLINE uint8_t nxmac_default_bwtxop_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void nxmac_default_bwtxop_setf(uint8_t defaultbwtxop)
{
    ASSERT_ERR((((uint32_t)defaultbwtxop << 1) & ~((uint32_t)0x00000006)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)defaultbwtxop << 1));
}
__INLINE uint8_t nxmac_default_bwtxopv_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_default_bwtxopv_setf(uint8_t defaultbwtxopv)
{
    ASSERT_ERR((((uint32_t)defaultbwtxopv << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_TX_BW_CNTRL_ADDR, (REG_PL_RD(NXMAC_TX_BW_CNTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)defaultbwtxopv << 0));
}
#define NXMAC_HTMCS_ADDR REG_MAC_CORE_BASE_ADDR + 0x0314
#define NXMAC_HTMCS_OFFSET 0x00000314
#define NXMAC_HTMCS_INDEX 0x000000C5
#define NXMAC_HTMCS_RESET 0x0000FFFF
__INLINE uint32_t nxmac_htmcs_get(void)
{
    return REG_PL_RD(NXMAC_HTMCS_ADDR);
}
__INLINE void nxmac_htmcs_set(uint32_t value)
{
    REG_PL_WR(NXMAC_HTMCS_ADDR, value);
}
#define NXMAC_BSS_BASIC_HTMCS_SET_UM_MASK ((uint32_t)0x003F0000)
#define NXMAC_BSS_BASIC_HTMCS_SET_UM_LSB 16
#define NXMAC_BSS_BASIC_HTMCS_SET_UM_WIDTH ((uint32_t)0x00000006)
#define NXMAC_BSS_BASIC_HTMCS_SET_EM_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BSS_BASIC_HTMCS_SET_EM_LSB 0
#define NXMAC_BSS_BASIC_HTMCS_SET_EM_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BSS_BASIC_HTMCS_SET_UM_RST 0x0
#define NXMAC_BSS_BASIC_HTMCS_SET_EM_RST 0xFFFF
__INLINE void nxmac_htmcs_pack(uint8_t bssbasichtmcssetum, uint16_t bssbasichtmcssetem)
{
    ASSERT_ERR((((uint32_t)bssbasichtmcssetum << 16) & ~((uint32_t)0x003F0000)) == 0);
    ASSERT_ERR((((uint32_t)bssbasichtmcssetem << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_HTMCS_ADDR, ((uint32_t)bssbasichtmcssetum << 16) | ((uint32_t)bssbasichtmcssetem << 0));
}
__INLINE void nxmac_htmcs_unpack(uint8_t* bssbasichtmcssetum, uint16_t* bssbasichtmcssetem)
{
    uint32_t localVal = REG_PL_RD(NXMAC_HTMCS_ADDR);
    *bssbasichtmcssetum = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *bssbasichtmcssetem = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}
__INLINE uint8_t nxmac_bss_basic_htmcs_set_um_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_HTMCS_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void nxmac_bss_basic_htmcs_set_um_setf(uint8_t bssbasichtmcssetum)
{
    ASSERT_ERR((((uint32_t)bssbasichtmcssetum << 16) & ~((uint32_t)0x003F0000)) == 0);
    REG_PL_WR(NXMAC_HTMCS_ADDR, (REG_PL_RD(NXMAC_HTMCS_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)bssbasichtmcssetum << 16));
}
__INLINE uint16_t nxmac_bss_basic_htmcs_set_em_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_HTMCS_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void nxmac_bss_basic_htmcs_set_em_setf(uint16_t bssbasichtmcssetem)
{
    ASSERT_ERR((((uint32_t)bssbasichtmcssetem << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_HTMCS_ADDR, (REG_PL_RD(NXMAC_HTMCS_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)bssbasichtmcssetem << 0));
}
#define NXMAC_VHTMCS_ADDR REG_MAC_CORE_BASE_ADDR + 0x031C
#define NXMAC_VHTMCS_OFFSET 0x0000031C
#define NXMAC_VHTMCS_INDEX 0x000000C7
#define NXMAC_VHTMCS_RESET 0x0000FFFF
__INLINE uint32_t nxmac_vhtmcs_get(void)
{
    return REG_PL_RD(NXMAC_VHTMCS_ADDR);
}
__INLINE void nxmac_vhtmcs_set(uint32_t value)
{
    REG_PL_WR(NXMAC_VHTMCS_ADDR, value);
}
#define NXMAC_BSS_BASIC_VHTMCS_SET_MASK ((uint32_t)0x0000FFFF)
#define NXMAC_BSS_BASIC_VHTMCS_SET_LSB 0
#define NXMAC_BSS_BASIC_VHTMCS_SET_WIDTH ((uint32_t)0x00000010)
#define NXMAC_BSS_BASIC_VHTMCS_SET_RST 0xFFFF
__INLINE uint16_t nxmac_bss_basic_vhtmcs_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_VHTMCS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_bss_basic_vhtmcs_set_setf(uint16_t bssbasicvhtmcsset)
{
    ASSERT_ERR((((uint32_t)bssbasicvhtmcsset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(NXMAC_VHTMCS_ADDR, (uint32_t)bssbasicvhtmcsset << 0);
}
#define NXMAC_LSTP_ADDR REG_MAC_CORE_BASE_ADDR + 0x0320
#define NXMAC_LSTP_OFFSET 0x00000320
#define NXMAC_LSTP_INDEX 0x000000C8
#define NXMAC_LSTP_RESET 0x00000000
__INLINE uint32_t nxmac_lstp_get(void)
{
    return REG_PL_RD(NXMAC_LSTP_ADDR);
}
__INLINE void nxmac_lstp_set(uint32_t value)
{
    REG_PL_WR(NXMAC_LSTP_ADDR, value);
}
#define NXMAC_SUPPORT_LSTP_BIT ((uint32_t)0x00000001)
#define NXMAC_SUPPORT_LSTP_POS 0
#define NXMAC_SUPPORT_LSTP_RST 0x0
__INLINE uint8_t nxmac_support_lstp_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_LSTP_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_support_lstp_setf(uint8_t supportlstp)
{
    ASSERT_ERR((((uint32_t)supportlstp << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_LSTP_ADDR, (uint32_t)supportlstp << 0);
}
#define NXMAC_COEX_CONTROL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0400
#define NXMAC_COEX_CONTROL_OFFSET 0x00000400
#define NXMAC_COEX_CONTROL_INDEX 0x00000100
#define NXMAC_COEX_CONTROL_RESET 0x00000000
__INLINE uint32_t nxmac_coex_control_get(void)
{
    return REG_PL_RD(NXMAC_COEX_CONTROL_ADDR);
}
__INLINE void nxmac_coex_control_set(uint32_t value)
{
    REG_PL_WR(NXMAC_COEX_CONTROL_ADDR, value);
}
#define NXMAC_COEX_WLAN_CHAN_FREQ_MASK ((uint32_t)0x007F0000)
#define NXMAC_COEX_WLAN_CHAN_FREQ_LSB 16
#define NXMAC_COEX_WLAN_CHAN_FREQ_WIDTH ((uint32_t)0x00000007)
#define NXMAC_COEX_WLAN_CHAN_OFFSET_BIT ((uint32_t)0x00001000)
#define NXMAC_COEX_WLAN_CHAN_OFFSET_POS 12
#define NXMAC_COEX_ENABLE_BIT ((uint32_t)0x00000001)
#define NXMAC_COEX_ENABLE_POS 0
#define NXMAC_COEX_WLAN_CHAN_FREQ_RST 0x0
#define NXMAC_COEX_WLAN_CHAN_OFFSET_RST 0x0
#define NXMAC_COEX_ENABLE_RST 0x0
__INLINE void nxmac_coex_control_pack(uint8_t coexwlanchanfreq, uint8_t coexwlanchanoffset, uint8_t coexenable)
{
    ASSERT_ERR((((uint32_t)coexwlanchanfreq << 16) & ~((uint32_t)0x007F0000)) == 0);
    ASSERT_ERR((((uint32_t)coexwlanchanoffset << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)coexenable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_COEX_CONTROL_ADDR, ((uint32_t)coexwlanchanfreq << 16) | ((uint32_t)coexwlanchanoffset << 12) | ((uint32_t)coexenable << 0));
}
__INLINE void nxmac_coex_control_unpack(uint8_t* coexwlanchanfreq, uint8_t* coexwlanchanoffset, uint8_t* coexenable)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_CONTROL_ADDR);
    *coexwlanchanfreq = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *coexwlanchanoffset = (localVal & ((uint32_t)0x00001000)) >> 12;
    *coexenable = (localVal & ((uint32_t)0x00000001)) >> 0;
}
__INLINE uint8_t nxmac_coex_wlan_chan_freq_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_CONTROL_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void nxmac_coex_wlan_chan_freq_setf(uint8_t coexwlanchanfreq)
{
    ASSERT_ERR((((uint32_t)coexwlanchanfreq << 16) & ~((uint32_t)0x007F0000)) == 0);
    REG_PL_WR(NXMAC_COEX_CONTROL_ADDR, (REG_PL_RD(NXMAC_COEX_CONTROL_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)coexwlanchanfreq << 16));
}
__INLINE uint8_t nxmac_coex_wlan_chan_offset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_CONTROL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void nxmac_coex_wlan_chan_offset_setf(uint8_t coexwlanchanoffset)
{
    ASSERT_ERR((((uint32_t)coexwlanchanoffset << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(NXMAC_COEX_CONTROL_ADDR, (REG_PL_RD(NXMAC_COEX_CONTROL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)coexwlanchanoffset << 12));
}
__INLINE uint8_t nxmac_coex_enable_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_CONTROL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void nxmac_coex_enable_setf(uint8_t coexenable)
{
    ASSERT_ERR((((uint32_t)coexenable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_COEX_CONTROL_ADDR, (REG_PL_RD(NXMAC_COEX_CONTROL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)coexenable << 0));
}
#define NXMAC_COEX_PTI_ADDR REG_MAC_CORE_BASE_ADDR + 0x0404
#define NXMAC_COEX_PTI_OFFSET 0x00000404
#define NXMAC_COEX_PTI_INDEX 0x00000101
#define NXMAC_COEX_PTI_RESET 0x00246637
__INLINE uint32_t nxmac_coex_pti_get(void)
{
    return REG_PL_RD(NXMAC_COEX_PTI_ADDR);
}
__INLINE void nxmac_coex_pti_set(uint32_t value)
{
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, value);
}
#define NXMAC_COEX_PTI_BCN_DATA_MASK ((uint32_t)0xF0000000)
#define NXMAC_COEX_PTI_BCN_DATA_LSB 28
#define NXMAC_COEX_PTI_BCN_DATA_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTIBK_DATA_MASK ((uint32_t)0x0F000000)
#define NXMAC_COEX_PTIBK_DATA_LSB 24
#define NXMAC_COEX_PTIBK_DATA_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTIBE_DATA_MASK ((uint32_t)0x00F00000)
#define NXMAC_COEX_PTIBE_DATA_LSB 20
#define NXMAC_COEX_PTIBE_DATA_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTIVI_DATA_MASK ((uint32_t)0x000F0000)
#define NXMAC_COEX_PTIVI_DATA_LSB 16
#define NXMAC_COEX_PTIVI_DATA_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTIVO_DATA_MASK ((uint32_t)0x0000F000)
#define NXMAC_COEX_PTIVO_DATA_LSB 12
#define NXMAC_COEX_PTIVO_DATA_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTI_MGT_MASK ((uint32_t)0x00000F00)
#define NXMAC_COEX_PTI_MGT_LSB 8
#define NXMAC_COEX_PTI_MGT_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTI_CNTL_MASK ((uint32_t)0x000000F0)
#define NXMAC_COEX_PTI_CNTL_LSB 4
#define NXMAC_COEX_PTI_CNTL_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTI_ACK_MASK ((uint32_t)0x0000000F)
#define NXMAC_COEX_PTI_ACK_LSB 0
#define NXMAC_COEX_PTI_ACK_WIDTH ((uint32_t)0x00000004)
#define NXMAC_COEX_PTI_BCN_DATA_RST 0x0
#define NXMAC_COEX_PTIBK_DATA_RST 0x0
#define NXMAC_COEX_PTIBE_DATA_RST 0x2
#define NXMAC_COEX_PTIVI_DATA_RST 0x4
#define NXMAC_COEX_PTIVO_DATA_RST 0x6
#define NXMAC_COEX_PTI_MGT_RST 0x6
#define NXMAC_COEX_PTI_CNTL_RST 0x3
#define NXMAC_COEX_PTI_ACK_RST 0x7
__INLINE void nxmac_coex_pti_pack(uint8_t coexptibcndata, uint8_t coexptibkdata, uint8_t coexptibedata, uint8_t coexptividata, uint8_t coexptivodata, uint8_t coexptimgt, uint8_t coexpticntl, uint8_t coexptiack)
{
    ASSERT_ERR((((uint32_t)coexptibcndata << 28) & ~((uint32_t)0xF0000000)) == 0);
    ASSERT_ERR((((uint32_t)coexptibkdata << 24) & ~((uint32_t)0x0F000000)) == 0);
    ASSERT_ERR((((uint32_t)coexptibedata << 20) & ~((uint32_t)0x00F00000)) == 0);
    ASSERT_ERR((((uint32_t)coexptividata << 16) & ~((uint32_t)0x000F0000)) == 0);
    ASSERT_ERR((((uint32_t)coexptivodata << 12) & ~((uint32_t)0x0000F000)) == 0);
    ASSERT_ERR((((uint32_t)coexptimgt << 8) & ~((uint32_t)0x00000F00)) == 0);
    ASSERT_ERR((((uint32_t)coexpticntl << 4) & ~((uint32_t)0x000000F0)) == 0);
    ASSERT_ERR((((uint32_t)coexptiack << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, ((uint32_t)coexptibcndata << 28) | ((uint32_t)coexptibkdata << 24) | ((uint32_t)coexptibedata << 20) | ((uint32_t)coexptividata << 16) | ((uint32_t)coexptivodata << 12) | ((uint32_t)coexptimgt << 8) | ((uint32_t)coexpticntl << 4) | ((uint32_t)coexptiack << 0));
}
__INLINE void nxmac_coex_pti_unpack(uint8_t* coexptibcndata, uint8_t* coexptibkdata, uint8_t* coexptibedata, uint8_t* coexptividata, uint8_t* coexptivodata, uint8_t* coexptimgt, uint8_t* coexpticntl, uint8_t* coexptiack)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    *coexptibcndata = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *coexptibkdata = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *coexptibedata = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *coexptividata = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *coexptivodata = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *coexptimgt = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *coexpticntl = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *coexptiack = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint8_t nxmac_coex_pti_bcn_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void nxmac_coex_pti_bcn_data_setf(uint8_t coexptibcndata)
{
    ASSERT_ERR((((uint32_t)coexptibcndata << 28) & ~((uint32_t)0xF0000000)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)coexptibcndata << 28));
}
__INLINE uint8_t nxmac_coex_ptibk_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void nxmac_coex_ptibk_data_setf(uint8_t coexptibkdata)
{
    ASSERT_ERR((((uint32_t)coexptibkdata << 24) & ~((uint32_t)0x0F000000)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)coexptibkdata << 24));
}
__INLINE uint8_t nxmac_coex_ptibe_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void nxmac_coex_ptibe_data_setf(uint8_t coexptibedata)
{
    ASSERT_ERR((((uint32_t)coexptibedata << 20) & ~((uint32_t)0x00F00000)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)coexptibedata << 20));
}
__INLINE uint8_t nxmac_coex_ptivi_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void nxmac_coex_ptivi_data_setf(uint8_t coexptividata)
{
    ASSERT_ERR((((uint32_t)coexptividata << 16) & ~((uint32_t)0x000F0000)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)coexptividata << 16));
}
__INLINE uint8_t nxmac_coex_ptivo_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void nxmac_coex_ptivo_data_setf(uint8_t coexptivodata)
{
    ASSERT_ERR((((uint32_t)coexptivodata << 12) & ~((uint32_t)0x0000F000)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)coexptivodata << 12));
}
__INLINE uint8_t nxmac_coex_pti_mgt_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void nxmac_coex_pti_mgt_setf(uint8_t coexptimgt)
{
    ASSERT_ERR((((uint32_t)coexptimgt << 8) & ~((uint32_t)0x00000F00)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)coexptimgt << 8));
}
__INLINE uint8_t nxmac_coex_pti_cntl_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void nxmac_coex_pti_cntl_setf(uint8_t coexpticntl)
{
    ASSERT_ERR((((uint32_t)coexpticntl << 4) & ~((uint32_t)0x000000F0)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)coexpticntl << 4));
}
__INLINE uint8_t nxmac_coex_pti_ack_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_COEX_PTI_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void nxmac_coex_pti_ack_setf(uint8_t coexptiack)
{
    ASSERT_ERR((((uint32_t)coexptiack << 0) & ~((uint32_t)0x0000000F)) == 0);
    REG_PL_WR(NXMAC_COEX_PTI_ADDR, (REG_PL_RD(NXMAC_COEX_PTI_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)coexptiack << 0));
}
#define NXMAC_DEBUG_HWSM_1_ADDR REG_MAC_CORE_BASE_ADDR + 0x0500
#define NXMAC_DEBUG_HWSM_1_OFFSET 0x00000500
#define NXMAC_DEBUG_HWSM_1_INDEX 0x00000140
#define NXMAC_DEBUG_HWSM_1_RESET 0x00000000
__INLINE uint32_t nxmac_debug_hwsm_1_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_HWSM_1_ADDR);
}
#define NXMAC_MAC_CONTROL_LS_MASK ((uint32_t)0xFF000000)
#define NXMAC_MAC_CONTROL_LS_LSB 24
#define NXMAC_MAC_CONTROL_LS_WIDTH ((uint32_t)0x00000008)
#define NXMAC_TX_CONTROL_LS_MASK ((uint32_t)0x0001FF00)
#define NXMAC_TX_CONTROL_LS_LSB 8
#define NXMAC_TX_CONTROL_LS_WIDTH ((uint32_t)0x00000009)
#define NXMAC_RX_CONTROL_LS_MASK ((uint32_t)0x0000001F)
#define NXMAC_RX_CONTROL_LS_LSB 0
#define NXMAC_RX_CONTROL_LS_WIDTH ((uint32_t)0x00000005)
#define NXMAC_MAC_CONTROL_LS_RST 0x0
#define NXMAC_TX_CONTROL_LS_RST 0x0
#define NXMAC_RX_CONTROL_LS_RST 0x0
__INLINE void nxmac_debug_hwsm_1_unpack(uint8_t* maccontrolls, uint16_t* txcontrolls, uint8_t* rxcontrolls)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_1_ADDR);
    *maccontrolls = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *txcontrolls = (localVal & ((uint32_t)0x0001FF00)) >> 8;
    *rxcontrolls = (localVal & ((uint32_t)0x0000001F)) >> 0;
}
__INLINE uint8_t nxmac_mac_control_ls_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_1_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint16_t nxmac_tx_control_ls_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_1_ADDR);
    return ((localVal & ((uint32_t)0x0001FF00)) >> 8);
}
__INLINE uint8_t nxmac_rx_control_ls_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_1_ADDR);
    return ((localVal & ((uint32_t)0x0000001F)) >> 0);
}
#define NXMAC_DEBUG_HWSM_2_ADDR REG_MAC_CORE_BASE_ADDR + 0x0504
#define NXMAC_DEBUG_HWSM_2_OFFSET 0x00000504
#define NXMAC_DEBUG_HWSM_2_INDEX 0x00000141
#define NXMAC_DEBUG_HWSM_2_RESET 0x00000000
__INLINE uint32_t nxmac_debug_hwsm_2_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_HWSM_2_ADDR);
}
#define NXMAC_MAC_CONTROL_CS_MASK ((uint32_t)0xFF000000)
#define NXMAC_MAC_CONTROL_CS_LSB 24
#define NXMAC_MAC_CONTROL_CS_WIDTH ((uint32_t)0x00000008)
#define NXMAC_TX_CONTROL_CS_MASK ((uint32_t)0x0001FF00)
#define NXMAC_TX_CONTROL_CS_LSB 8
#define NXMAC_TX_CONTROL_CS_WIDTH ((uint32_t)0x00000009)
#define NXMAC_RX_CONTROL_CS_MASK ((uint32_t)0x0000001F)
#define NXMAC_RX_CONTROL_CS_LSB 0
#define NXMAC_RX_CONTROL_CS_WIDTH ((uint32_t)0x00000005)
#define NXMAC_MAC_CONTROL_CS_RST 0x0
#define NXMAC_TX_CONTROL_CS_RST 0x0
#define NXMAC_RX_CONTROL_CS_RST 0x0
__INLINE void nxmac_debug_hwsm_2_unpack(uint8_t* maccontrolcs, uint16_t* txcontrolcs, uint8_t* rxcontrolcs)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_2_ADDR);
    *maccontrolcs = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *txcontrolcs = (localVal & ((uint32_t)0x0001FF00)) >> 8;
    *rxcontrolcs = (localVal & ((uint32_t)0x0000001F)) >> 0;
}
__INLINE uint8_t nxmac_mac_control_cs_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_2_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint16_t nxmac_tx_control_cs_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_2_ADDR);
    return ((localVal & ((uint32_t)0x0001FF00)) >> 8);
}
__INLINE uint8_t nxmac_rx_control_cs_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_HWSM_2_ADDR);
    return ((localVal & ((uint32_t)0x0000001F)) >> 0);
}
#define NXMAC_DEBUG_PORT_VALUE_ADDR REG_MAC_CORE_BASE_ADDR + 0x050C
#define NXMAC_DEBUG_PORT_VALUE_OFFSET 0x0000050C
#define NXMAC_DEBUG_PORT_VALUE_INDEX 0x00000143
#define NXMAC_DEBUG_PORT_VALUE_RESET 0x00000000
__INLINE uint32_t nxmac_debug_port_value_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_PORT_VALUE_ADDR);
}
#define NXMAC_DEBUG_PORT_READ_MASK ((uint32_t)0xFFFFFFFF)
#define NXMAC_DEBUG_PORT_READ_LSB 0
#define NXMAC_DEBUG_PORT_READ_WIDTH ((uint32_t)0x00000020)
#define NXMAC_DEBUG_PORT_READ_RST 0x0
__INLINE uint32_t nxmac_debug_port_read_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_PORT_VALUE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}
#define NXMAC_DEBUG_PORT_SEL_ADDR REG_MAC_CORE_BASE_ADDR + 0x0510
#define NXMAC_DEBUG_PORT_SEL_OFFSET 0x00000510
#define NXMAC_DEBUG_PORT_SEL_INDEX 0x00000144
#define NXMAC_DEBUG_PORT_SEL_RESET 0x00000000
__INLINE uint32_t nxmac_debug_port_sel_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR);
}
__INLINE void nxmac_debug_port_sel_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DEBUG_PORT_SEL_ADDR, value);
}
#define NXMAC_DEBUG_PORT_SEL_2_MASK ((uint32_t)0x0000FF00)
#define NXMAC_DEBUG_PORT_SEL_2_LSB 8
#define NXMAC_DEBUG_PORT_SEL_2_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DEBUG_PORT_SEL_1_MASK ((uint32_t)0x000000FF)
#define NXMAC_DEBUG_PORT_SEL_1_LSB 0
#define NXMAC_DEBUG_PORT_SEL_1_WIDTH ((uint32_t)0x00000008)
#define NXMAC_DEBUG_PORT_SEL_2_RST 0x0
#define NXMAC_DEBUG_PORT_SEL_1_RST 0x0
__INLINE void nxmac_debug_port_sel_pack(uint8_t debugportsel2, uint8_t debugportsel1)
{
    ASSERT_ERR((((uint32_t)debugportsel2 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)debugportsel1 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_DEBUG_PORT_SEL_ADDR, ((uint32_t)debugportsel2 << 8) | ((uint32_t)debugportsel1 << 0));
}
__INLINE void nxmac_debug_port_sel_unpack(uint8_t* debugportsel2, uint8_t* debugportsel1)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR);
    *debugportsel2 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *debugportsel1 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_debug_port_sel_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void nxmac_debug_port_sel_2_setf(uint8_t debugportsel2)
{
    ASSERT_ERR((((uint32_t)debugportsel2 << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(NXMAC_DEBUG_PORT_SEL_ADDR, (REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)debugportsel2 << 8));
}
__INLINE uint8_t nxmac_debug_port_sel_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void nxmac_debug_port_sel_1_setf(uint8_t debugportsel1)
{
    ASSERT_ERR((((uint32_t)debugportsel1 << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(NXMAC_DEBUG_PORT_SEL_ADDR, (REG_PL_RD(NXMAC_DEBUG_PORT_SEL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)debugportsel1 << 0));
}
#define NXMAC_DEBUG_NAV_ADDR REG_MAC_CORE_BASE_ADDR + 0x0514
#define NXMAC_DEBUG_NAV_OFFSET 0x00000514
#define NXMAC_DEBUG_NAV_INDEX 0x00000145
#define NXMAC_DEBUG_NAV_RESET 0x00000000
__INLINE uint32_t nxmac_debug_nav_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_NAV_ADDR);
}
__INLINE void nxmac_debug_nav_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DEBUG_NAV_ADDR, value);
}
#define NXMAC_NAV_COUNTER_MASK ((uint32_t)0x03FFFFFF)
#define NXMAC_NAV_COUNTER_LSB 0
#define NXMAC_NAV_COUNTER_WIDTH ((uint32_t)0x0000001A)
#define NXMAC_NAV_COUNTER_RST 0x0
__INLINE uint32_t nxmac_nav_counter_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_NAV_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x03FFFFFF)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_nav_counter_setf(uint32_t navcounter)
{
    ASSERT_ERR((((uint32_t)navcounter << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
    REG_PL_WR(NXMAC_DEBUG_NAV_ADDR, (uint32_t)navcounter << 0);
}
#define NXMAC_DEBUG_CW_ADDR REG_MAC_CORE_BASE_ADDR + 0x0518
#define NXMAC_DEBUG_CW_OFFSET 0x00000518
#define NXMAC_DEBUG_CW_INDEX 0x00000146
#define NXMAC_DEBUG_CW_RESET 0x00002344
__INLINE uint32_t nxmac_debug_cw_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
}
__INLINE void nxmac_debug_cw_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DEBUG_CW_ADDR, value);
}
#define NXMAC_BACKOFF_OFFSET_MASK ((uint32_t)0x03000000)
#define NXMAC_BACKOFF_OFFSET_LSB 24
#define NXMAC_BACKOFF_OFFSET_WIDTH ((uint32_t)0x00000002)
#define NXMAC_ACTIVE_AC_MASK ((uint32_t)0x00030000)
#define NXMAC_ACTIVE_AC_LSB 16
#define NXMAC_ACTIVE_AC_WIDTH ((uint32_t)0x00000002)
#define NXMAC_CURRENT_CW_3_MASK ((uint32_t)0x0000F000)
#define NXMAC_CURRENT_CW_3_LSB 12
#define NXMAC_CURRENT_CW_3_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CURRENT_CW_2_MASK ((uint32_t)0x00000F00)
#define NXMAC_CURRENT_CW_2_LSB 8
#define NXMAC_CURRENT_CW_2_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CURRENT_CW_1_MASK ((uint32_t)0x000000F0)
#define NXMAC_CURRENT_CW_1_LSB 4
#define NXMAC_CURRENT_CW_1_WIDTH ((uint32_t)0x00000004)
#define NXMAC_CURRENT_CW_0_MASK ((uint32_t)0x0000000F)
#define NXMAC_CURRENT_CW_0_LSB 0
#define NXMAC_CURRENT_CW_0_WIDTH ((uint32_t)0x00000004)
#define NXMAC_BACKOFF_OFFSET_RST 0x0
#define NXMAC_ACTIVE_AC_RST 0x0
#define NXMAC_CURRENT_CW_3_RST 0x2
#define NXMAC_CURRENT_CW_2_RST 0x3
#define NXMAC_CURRENT_CW_1_RST 0x4
#define NXMAC_CURRENT_CW_0_RST 0x4
__INLINE void nxmac_debug_cw_unpack(uint8_t* backoffoffset, uint8_t* activeac, uint8_t* currentcw3, uint8_t* currentcw2, uint8_t* currentcw1, uint8_t* currentcw0)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    *backoffoffset = (localVal & ((uint32_t)0x03000000)) >> 24;
    *activeac = (localVal & ((uint32_t)0x00030000)) >> 16;
    *currentcw3 = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *currentcw2 = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *currentcw1 = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *currentcw0 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}
__INLINE uint8_t nxmac_backoff_offset_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE void nxmac_backoff_offset_setf(uint8_t backoffoffset)
{
    ASSERT_ERR((((uint32_t)backoffoffset << 24) & ~((uint32_t)0x03000000)) == 0);
    REG_PL_WR(NXMAC_DEBUG_CW_ADDR, (uint32_t)backoffoffset << 24);
}
__INLINE uint8_t nxmac_active_ac_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE uint8_t nxmac_current_cw_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t nxmac_current_cw_2_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t nxmac_current_cw_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t nxmac_current_cw_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_CW_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}
#define NXMAC_DEBUG_QSRC_ADDR REG_MAC_CORE_BASE_ADDR + 0x051C
#define NXMAC_DEBUG_QSRC_OFFSET 0x0000051C
#define NXMAC_DEBUG_QSRC_INDEX 0x00000147
#define NXMAC_DEBUG_QSRC_RESET 0x00000000
__INLINE uint32_t nxmac_debug_qsrc_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
}
#define NXMAC_AC_3QSRC_MASK ((uint32_t)0xFF000000)
#define NXMAC_AC_3QSRC_LSB 24
#define NXMAC_AC_3QSRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_2QSRC_MASK ((uint32_t)0x00FF0000)
#define NXMAC_AC_2QSRC_LSB 16
#define NXMAC_AC_2QSRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_1QSRC_MASK ((uint32_t)0x0000FF00)
#define NXMAC_AC_1QSRC_LSB 8
#define NXMAC_AC_1QSRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_0QSRC_MASK ((uint32_t)0x000000FF)
#define NXMAC_AC_0QSRC_LSB 0
#define NXMAC_AC_0QSRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_3QSRC_RST 0x0
#define NXMAC_AC_2QSRC_RST 0x0
#define NXMAC_AC_1QSRC_RST 0x0
#define NXMAC_AC_0QSRC_RST 0x0
__INLINE void nxmac_debug_qsrc_unpack(uint8_t* ac3qsrc, uint8_t* ac2qsrc, uint8_t* ac1qsrc, uint8_t* ac0qsrc)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
    *ac3qsrc = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *ac2qsrc = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *ac1qsrc = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *ac0qsrc = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_ac_3qsrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t nxmac_ac_2qsrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t nxmac_ac_1qsrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t nxmac_ac_0qsrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QSRC_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
#define NXMAC_DEBUG_QLRC_ADDR REG_MAC_CORE_BASE_ADDR + 0x0520
#define NXMAC_DEBUG_QLRC_OFFSET 0x00000520
#define NXMAC_DEBUG_QLRC_INDEX 0x00000148
#define NXMAC_DEBUG_QLRC_RESET 0x00000000
__INLINE uint32_t nxmac_debug_qlrc_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
}
#define NXMAC_AC_3QLRC_MASK ((uint32_t)0xFF000000)
#define NXMAC_AC_3QLRC_LSB 24
#define NXMAC_AC_3QLRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_2QLRC_MASK ((uint32_t)0x00FF0000)
#define NXMAC_AC_2QLRC_LSB 16
#define NXMAC_AC_2QLRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_1QLRC_MASK ((uint32_t)0x0000FF00)
#define NXMAC_AC_1QLRC_LSB 8
#define NXMAC_AC_1QLRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_0QLRC_MASK ((uint32_t)0x000000FF)
#define NXMAC_AC_0QLRC_LSB 0
#define NXMAC_AC_0QLRC_WIDTH ((uint32_t)0x00000008)
#define NXMAC_AC_3QLRC_RST 0x0
#define NXMAC_AC_2QLRC_RST 0x0
#define NXMAC_AC_1QLRC_RST 0x0
#define NXMAC_AC_0QLRC_RST 0x0
__INLINE void nxmac_debug_qlrc_unpack(uint8_t* ac3qlrc, uint8_t* ac2qlrc, uint8_t* ac1qlrc, uint8_t* ac0qlrc)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
    *ac3qlrc = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *ac2qlrc = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *ac1qlrc = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *ac0qlrc = (localVal & ((uint32_t)0x000000FF)) >> 0;
}
__INLINE uint8_t nxmac_ac_3qlrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t nxmac_ac_2qlrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t nxmac_ac_1qlrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t nxmac_ac_0qlrc_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_QLRC_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}
#define NXMAC_DEBUG_PHY_ADDR REG_MAC_CORE_BASE_ADDR + 0x055C
#define NXMAC_DEBUG_PHY_OFFSET 0x0000055C
#define NXMAC_DEBUG_PHY_INDEX 0x00000157
#define NXMAC_DEBUG_PHY_RESET 0x00000000
__INLINE uint32_t nxmac_debug_phy_get(void)
{
    return REG_PL_RD(NXMAC_DEBUG_PHY_ADDR);
}
__INLINE void nxmac_debug_phy_set(uint32_t value)
{
    REG_PL_WR(NXMAC_DEBUG_PHY_ADDR, value);
}
#define NXMAC_RX_REQ_FORCE_DEASSERTION_BIT ((uint32_t)0x00000001)
#define NXMAC_RX_REQ_FORCE_DEASSERTION_POS 0
#define NXMAC_RX_REQ_FORCE_DEASSERTION_RST 0x0
__INLINE uint8_t nxmac_rx_req_force_deassertion_getf(void)
{
    uint32_t localVal = REG_PL_RD(NXMAC_DEBUG_PHY_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}
__INLINE void nxmac_rx_req_force_deassertion_setf(uint8_t rxreqforcedeassertion)
{
    ASSERT_ERR((((uint32_t)rxreqforcedeassertion << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(NXMAC_DEBUG_PHY_ADDR, (uint32_t)rxreqforcedeassertion << 0);
}
#endif
