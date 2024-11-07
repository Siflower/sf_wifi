#include <linux/module.h>
#include <linux/firmware.h>
#include <linux/delay.h>
#include "siwifi_platform.h"
#include "reg_access.h"
#include "hal_desc.h"
#include "siwifi_main.h"
#include "siwifi_pci.h"
#include "ipc_host.h"
#ifdef CONFIG_SIWIFI_TL4
static int siwifi_plat_tl4_fw_upload(struct siwifi_plat *siwifi_plat, u8* fw_addr,
                                   char *filename)
{
    struct device *dev = siwifi_platform_get_dev(siwifi_plat);
    const struct firmware *fw;
    int err = 0;
    u32 *dst;
    u8 const *file_data;
    char typ0, typ1;
    u32 addr0, addr1;
    u32 dat0, dat1;
    int remain;
    err = request_firmware(&fw, filename, dev);
    if (err) {
        return err;
    }
    file_data = fw->data;
    remain = fw->size;
    dev_dbg(dev, "Now copy %s firmware, @ = %p\n", filename, fw_addr);
    while (remain >= 16) {
        u32 data, offset;
        if (sscanf(file_data, "%c:%08X %04X", &typ0, &addr0, &dat0) != 3)
            break;
        if ((addr0 & 0x01) != 0) {
            addr0 = addr0 - 1;
            dat0 = 0;
        } else {
            file_data += 16;
            remain -= 16;
        }
        if ((remain < 16) ||
            (sscanf(file_data, "%c:%08X %04X", &typ1, &addr1, &dat1) != 3) ||
            (typ1 != typ0) || (addr1 != (addr0 + 1))) {
            typ1 = typ0;
            addr1 = addr0 + 1;
            dat1 = 0;
        } else {
            file_data += 16;
            remain -= 16;
        }
        if (typ0 == 'C') {
            offset = 0x00200000;
            if ((addr1 % 4) == 3)
                offset += 2*(addr1 - 3);
            else
                offset += 2*(addr1 + 1);
            data = dat1 | (dat0 << 16);
        } else {
            offset = 2*(addr1 - 1);
            data = dat0 | (dat1 << 16);
        }
        dst = (u32 *)(fw_addr + offset);
        *dst = data;
    }
    release_firmware(fw);
    return err;
}
#endif
static int siwifi_plat_bin_fw_upload(struct siwifi_plat *siwifi_plat, u8* fw_addr,
                               char *filename)
{
    const struct firmware *fw;
    struct device *dev = siwifi_platform_get_dev(siwifi_plat);
    int err = 0;
    unsigned int i, size;
    u32 *src, *dst;
    err = request_firmware(&fw, filename, dev);
    if (err) {
        return err;
    }
    dev_dbg(dev, "Now copy %s firmware, @ = %p\n", filename, fw_addr);
    src = (u32 *)fw->data;
    dst = (u32 *)fw_addr;
    size = (unsigned int)fw->size;
    for (i = 0; i < size; i += 4) {
        *dst++ = *src++;
    }
    release_firmware(fw);
    return err;
}
#ifndef CONFIG_SIWIFI_TL4
#define IHEX_REC_DATA 0
#define IHEX_REC_EOF 1
#define IHEX_REC_EXT_SEG_ADD 2
#define IHEX_REC_START_SEG_ADD 3
#define IHEX_REC_EXT_LIN_ADD 4
#define IHEX_REC_START_LIN_ADD 5
static int siwifi_plat_ihex_fw_upload(struct siwifi_plat *siwifi_plat, u8* fw_addr,
                                    char *filename)
{
    const struct firmware *fw;
    struct device *dev = siwifi_platform_get_dev(siwifi_plat);
    u8 const *src, *end;
    u32 *dst;
    u16 haddr, segaddr, addr;
    u32 hwaddr;
    u8 load_fw, byte_count, checksum, csum, rec_type;
    int err, rec_idx;
    char hex_buff[9];
    err = request_firmware(&fw, filename, dev);
    if (err) {
        return err;
    }
    dev_dbg(dev, "Now copy %s firmware, @ = %p\n", filename, fw_addr);
    src = fw->data;
    end = src + (unsigned int)fw->size;
    haddr = 0;
    segaddr = 0;
    load_fw = 1;
    err = -EINVAL;
    rec_idx = 0;
    hwaddr = 0;
#define IHEX_READ8(_val,_cs) { \
        hex_buff[2] = 0; \
        strncpy(hex_buff, src, 2); \
        if (kstrtou8(hex_buff, 16, &_val)) \
            goto end; \
        src += 2; \
        if (_cs) \
            csum += _val; \
    }
#define IHEX_READ16(_val) { \
        hex_buff[4] = 0; \
        strncpy(hex_buff, src, 4); \
        if (kstrtou16(hex_buff, 16, &_val)) \
            goto end; \
        src += 4; \
        csum += (_val & 0xff) + (_val >> 8); \
    }
#define IHEX_READ32(_val) { \
        hex_buff[8] = 0; \
        strncpy(hex_buff, src, 8); \
        if (kstrtouint(hex_buff, 16, &_val)) \
            goto end; \
        src += 8; \
        csum += (_val & 0xff) + ((_val >> 8) & 0xff) + \
            ((_val >> 16) & 0xff) + (_val >> 24); \
    }
#define IHEX_READ32_PAD(_val,_nb) { \
        memset(hex_buff, '0', 8); \
        hex_buff[8] = 0; \
        strncpy(hex_buff, src, (2 * _nb)); \
        if (kstrtouint(hex_buff, 16, &_val)) \
            goto end; \
        src += (2 * _nb); \
        csum += (_val & 0xff) + ((_val >> 8) & 0xff) + \
            ((_val >> 16) & 0xff) + (_val >> 24); \
}
    while (load_fw && (src < end)) {
        rec_idx++;
        csum = 0;
        if (*src != ':')
            goto end;
        src++;
        IHEX_READ8(byte_count, 1);
        IHEX_READ16(addr);
        IHEX_READ8(rec_type, 1);
        switch(rec_type) {
            case IHEX_REC_DATA:
            {
                dst = (u32 *) (fw_addr + hwaddr + addr);
                while (byte_count) {
                    u32 val;
                    if (byte_count >= 4) {
                        IHEX_READ32(val);
                        byte_count -= 4;
                    } else {
                        IHEX_READ32_PAD(val, byte_count);
                        byte_count = 0;
                    }
                    *dst++ = __swab32(val);
                }
                break;
            }
            case IHEX_REC_EOF:
            {
                load_fw = 0;
                err = 0;
                break;
            }
            case IHEX_REC_EXT_SEG_ADD:
            {
                IHEX_READ16(segaddr);
                hwaddr = (haddr << 16) + (segaddr << 4);
                break;
            }
            case IHEX_REC_EXT_LIN_ADD:
            {
                IHEX_READ16(haddr);
                hwaddr = (haddr << 16) + (segaddr << 4);
                break;
            }
            case IHEX_REC_START_LIN_ADD:
            {
                u32 val;
                IHEX_READ32(val);
                break;
            }
            case IHEX_REC_START_SEG_ADD:
            default:
            {
                dev_err(dev, "ihex: record type %d not supported\n", rec_type);
                load_fw = 0;
            }
        }
        IHEX_READ8(checksum, 0);
        if (checksum != (u8)(~csum + 1))
            goto end;
        src ++;
    }
#undef IHEX_READ8
#undef IHEX_READ16
#undef IHEX_READ32
#undef IHEX_READ32_PAD
  end:
    release_firmware(fw);
    if (err)
        dev_err(dev, "%s: Invalid ihex record around line %d\n", filename, rec_idx);
    return err;
}
#endif
#ifndef CONFIG_SIWIFI_SDM
static u32 siwifi_plat_get_rf(struct siwifi_plat *siwifi_plat)
{
    u32 ver;
    ver = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, MDM_HDMCONFIG_ADDR);
    ver = __MDM_PHYCFG_FROM_VERS(ver);
    WARN(((ver != MDM_PHY_CONFIG_TRIDENT) &&
          (ver != MDM_PHY_CONFIG_ELMA) &&
          (ver != MDM_PHY_CONFIG_KARST)),
         "bad phy version 0x%08x\n", ver);
    return ver;
}
static void siwifi_plat_stop_agcfsm(struct siwifi_plat *siwifi_plat, int agc_reg,
                                  u32 *agcctl, u32 *memclk, u8 agc_ver,
                                  u32 clkctrladdr)
{
    *memclk = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, clkctrladdr);
    *agcctl = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, agc_reg);
    SIWIFI_REG_WRITE((*agcctl) | BIT(12), siwifi_plat, SIWIFI_ADDR_SYSTEM, agc_reg);
    if (agc_ver > 0) {
        SIWIFI_REG_WRITE((*memclk) | BIT(29), siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       clkctrladdr);
    } else {
        SIWIFI_REG_WRITE((*memclk) & ~BIT(3), siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       clkctrladdr);
    }
}
static void siwifi_plat_start_agcfsm(struct siwifi_plat *siwifi_plat, int agc_reg,
                                   u32 agcctl, u32 memclk, u8 agc_ver,
                                   u32 clkctrladdr)
{
    if (agc_ver > 0)
        SIWIFI_REG_WRITE(memclk & ~BIT(29), siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       clkctrladdr);
    else
        SIWIFI_REG_WRITE(memclk | BIT(3), siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       clkctrladdr);
    SIWIFI_REG_WRITE(agcctl & ~BIT(12), siwifi_plat, SIWIFI_ADDR_SYSTEM, agc_reg);
}
#endif
static int siwifi_plat_fcu_load(struct siwifi_hw *siwifi_hw)
{
    int ret=0;
#ifndef CONFIG_SIWIFI_SDM
    struct siwifi_plat *siwifi_plat = siwifi_hw->plat;
    u32 agcctl, memclk;
    siwifi_hw->phy_cnt = 1;
    if (siwifi_plat_get_rf(siwifi_plat) != MDM_PHY_CONFIG_ELMA)
        return 0;
    agcctl = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, RIU_SIWIFIAGCCNTL_ADDR);
    if (!__RIU_FCU_PRESENT(agcctl))
        return 0;
    siwifi_hw->phy_cnt = 2;
    siwifi_plat_stop_agcfsm(siwifi_plat, FCU_SIWIFIFCAGCCNTL_ADDR, &agcctl, &memclk, 0,
                          MDM_MEMCLKCTRL0_ADDR);
    ret = siwifi_plat_bin_fw_upload(siwifi_plat,
                              SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_SYSTEM, PHY_FCU_UCODE_ADDR),
                              SIWIFI_FCU_FW_NAME);
    siwifi_plat_start_agcfsm(siwifi_plat, FCU_SIWIFIFCAGCCNTL_ADDR, agcctl, memclk, 0,
                           MDM_MEMCLKCTRL0_ADDR);
#endif
    return ret;
}
#ifndef CONFIG_SIWIFI_SDM
static u8 siwifi_get_agc_load_version(struct siwifi_plat *siwifi_plat, u32 rf, u32 *clkctrladdr)
{
    u8 agc_load_ver = 0;
    u32 agc_ver;
    u32 regval;
    if (rf != MDM_PHY_CONFIG_KARST) {
        *clkctrladdr = MDM_MEMCLKCTRL0_ADDR;
        return 0;
    }
    regval = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, SYSCTRL_SIGNATURE_ADDR);
    if (__FPGA_TYPE(regval) == 0xC0CA)
        *clkctrladdr = CRM_CLKGATEFCTRL0_ADDR;
    else
        *clkctrladdr = MDM_CLKGATEFCTRL0_ADDR;
    agc_ver = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, RIU_SIWIFIVERSION_ADDR);
    agc_load_ver = __RIU_AGCLOAD_FROM_VERS(agc_ver);
    return agc_load_ver;
}
#endif
static int siwifi_plat_agc_load(struct siwifi_plat *siwifi_plat)
{
    int ret = 0;
#ifndef CONFIG_SIWIFI_SDM
    u32 agc = 0, agcctl, memclk;
    u32 clkctrladdr;
    u32 rf = siwifi_plat_get_rf(siwifi_plat);
    u8 agc_ver;
    switch (rf) {
        case MDM_PHY_CONFIG_TRIDENT:
            agc = AGC_SIWIFIAGCCNTL_ADDR;
            break;
        case MDM_PHY_CONFIG_ELMA:
        case MDM_PHY_CONFIG_KARST:
            agc = RIU_SIWIFIAGCCNTL_ADDR;
            break;
        default:
            return -1;
    }
    agc_ver = siwifi_get_agc_load_version(siwifi_plat, rf, &clkctrladdr);
    siwifi_plat_stop_agcfsm(siwifi_plat, agc, &agcctl, &memclk, agc_ver, clkctrladdr);
    ret = siwifi_plat_bin_fw_upload(siwifi_plat,
                              SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_SYSTEM, PHY_AGC_UCODE_ADDR),
                              SIWIFI_AGC_FW_NAME);
    if (!ret && (agc_ver == 1)) {
        SIWIFI_REG_WRITE(BIT(28), siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       RIU_SIWIFIDYNAMICCONFIG_ADDR);
        while (SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM,
                             RIU_SIWIFIDYNAMICCONFIG_ADDR) & BIT(28));
        if (!(SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM,
                            RIU_AGCMEMBISTSTAT_ADDR) & BIT(0))) {
            dev_err(siwifi_platform_get_dev(siwifi_plat),
                    "AGC RAM not loaded correctly 0x%08x\n",
                    SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM,
                                  RIU_AGCMEMSIGNATURESTAT_ADDR));
            ret = -EIO;
        }
    }
    siwifi_plat_start_agcfsm(siwifi_plat, agc, agcctl, memclk, agc_ver, clkctrladdr);
#endif
    return ret;
}
static int siwifi_ldpc_load(struct siwifi_hw *siwifi_hw)
{
#ifndef CONFIG_SIWIFI_SDM
    struct siwifi_plat *siwifi_plat = siwifi_hw->plat;
    u32 rf = siwifi_plat_get_rf(siwifi_plat);
    u32 phy_feat = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, MDM_HDMCONFIG_ADDR);
    if ((rf != MDM_PHY_CONFIG_KARST) ||
        (phy_feat & (MDM_LDPCDEC_BIT | MDM_LDPCENC_BIT)) !=
        (MDM_LDPCDEC_BIT | MDM_LDPCENC_BIT)) {
        goto disable_ldpc;
    }
    if (siwifi_plat_bin_fw_upload(siwifi_plat,
                            SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_SYSTEM, PHY_LDPC_RAM_ADDR),
                            SIWIFI_LDPC_RAM_NAME)) {
        goto disable_ldpc;
    }
    return 0;
  disable_ldpc:
    siwifi_hw->mod_params->ldpc_on = false;
#endif
    return 0;
}
static int siwifi_plat_lmac_load(struct siwifi_plat *siwifi_plat)
{
    int ret;
    #ifdef CONFIG_SIWIFI_TL4
    ret = siwifi_plat_tl4_fw_upload(siwifi_plat,
                                  SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_CPU, RAM_LMAC_FW_ADDR),
                                  SIWIFI_MAC_FW_NAME);
    #else
    ret = siwifi_plat_ihex_fw_upload(siwifi_plat,
                                   SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_CPU, RAM_LMAC_FW_ADDR),
                                   SIWIFI_MAC_FW_NAME);
    if (ret == -ENOENT)
    {
        ret = siwifi_plat_bin_fw_upload(siwifi_plat,
                                      SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_CPU, RAM_LMAC_FW_ADDR),
                                      SIWIFI_MAC_FW_NAME2);
    }
    #endif
    return ret;
}
static void siwifi_plat_mpif_sel(struct siwifi_plat *siwifi_plat)
{
#ifndef CONFIG_SIWIFI_SDM
    u32 regval;
    u32 type;
    regval = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, SYSCTRL_SIGNATURE_ADDR);
    type = __FPGA_TYPE(regval);
    if ((type != 0xCAFE) && (type != 0XC0CA) && (regval & 0xF) < 0x3)
    {
        SIWIFI_REG_WRITE(0x3, siwifi_plat, SIWIFI_ADDR_SYSTEM, FPGAB_MPIF_SEL_ADDR);
    }
#endif
}
static int siwifi_platform_reset(struct siwifi_plat *siwifi_plat)
{
    u32 regval;
    SIWIFI_REG_WRITE(SOFT_RESET | FPGA_B_RESET, siwifi_plat,
                   SIWIFI_ADDR_SYSTEM, SYSCTRL_MISC_CNTL_ADDR);
    msleep(100);
    regval = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM, SYSCTRL_MISC_CNTL_ADDR);
    if (regval & SOFT_RESET) {
        dev_err(siwifi_platform_get_dev(siwifi_plat), "reset: failed\n");
        return -EIO;
    }
    SIWIFI_REG_WRITE(regval & ~FPGA_B_RESET, siwifi_plat,
                   SIWIFI_ADDR_SYSTEM, SYSCTRL_MISC_CNTL_ADDR);
    msleep(100);
    return 0;
}
static void* siwifi_term_save_config(struct siwifi_plat *siwifi_plat)
{
    const u32 *reg_list;
    u32 *reg_value, *res;
    int i, size = 0;
    if (siwifi_plat->get_config_reg) {
        size = siwifi_plat->get_config_reg(&reg_list);
    }
    if (size <= 0)
        return NULL;
    res = siwifi_kmalloc(sizeof(u32) * size, GFP_KERNEL);
    if (!res)
        return NULL;
    reg_value = res;
    for (i = 0; i < size; i++) {
        *reg_value++ = SIWIFI_REG_READ(siwifi_plat, SIWIFI_ADDR_SYSTEM,
                                     *reg_list++);
    }
    return res;
}
static void siwifi_term_restore_config(struct siwifi_plat *siwifi_plat,
                                     u32 *reg_value)
{
    const u32 *reg_list;
    int i, size = 0;
    if (!reg_value || !siwifi_plat->get_config_reg)
        return;
    size = siwifi_plat->get_config_reg(&reg_list);
    for (i = 0; i < size; i++) {
        SIWIFI_REG_WRITE(*reg_value++, siwifi_plat, SIWIFI_ADDR_SYSTEM,
                       *reg_list++);
    }
}
static int siwifi_check_fw_compatibility(struct siwifi_hw *siwifi_hw)
{
    struct ipc_shared_env_tag *shared = siwifi_hw->ipc_env->shared;
    struct wiphy *wiphy = siwifi_hw->wiphy;
    int ipc_shared_version = 11;
    int res = 0;
    if(shared->comp_info.ipc_shared_version != ipc_shared_version)
    {
        wiphy_err(wiphy, "Different versions of IPC shared version between driver and FW (%d != %d)\n ",
                  ipc_shared_version, shared->comp_info.ipc_shared_version);
        res = -1;
    }
    if(shared->comp_info.radarbuf_cnt != IPC_RADARBUF_CNT)
    {
        wiphy_err(wiphy, "Different number of host buffers available for Radar events handling "\
                  "between driver and FW (%d != %d)\n", IPC_RADARBUF_CNT,
                  shared->comp_info.radarbuf_cnt);
        res = -1;
    }
    if(shared->comp_info.unsuprxvecbuf_cnt != IPC_UNSUPRXVECBUF_CNT)
    {
        wiphy_err(wiphy, "Different number of host buffers available for unsupported Rx vectors "\
                  "handling between driver and FW (%d != %d)\n", IPC_UNSUPRXVECBUF_CNT,
                  shared->comp_info.unsuprxvecbuf_cnt);
        res = -1;
    }
    if(shared->comp_info.rxdesc_cnt != IPC_RXDESC_CNT)
    {
        wiphy_err(wiphy, "Different number of shared descriptors available for Data RX handling "\
                  "between driver and FW (%d != %d)\n", IPC_RXDESC_CNT,
                  shared->comp_info.rxdesc_cnt);
        res = -1;
    }
    if(shared->comp_info.rxbuf_cnt != IPC_RXBUF_CNT)
    {
        wiphy_err(wiphy, "Different number of host buffers available for Data Rx handling "\
                  "between driver and FW (%d != %d)\n", IPC_RXBUF_CNT,
                  shared->comp_info.rxbuf_cnt);
        res = -1;
    }
    if(shared->comp_info.msge2a_buf_cnt != IPC_MSGE2A_BUF_CNT)
    {
        wiphy_err(wiphy, "Different number of host buffers available for Emb->App MSGs "\
                  "sending between driver and FW (%d != %d)\n", IPC_MSGE2A_BUF_CNT,
                  shared->comp_info.msge2a_buf_cnt);
        res = -1;
    }
    if(shared->comp_info.dbgbuf_cnt != IPC_DBGBUF_CNT)
    {
        wiphy_err(wiphy, "Different number of host buffers available for debug messages "\
                  "sending between driver and FW (%d != %d)\n", IPC_DBGBUF_CNT,
                  shared->comp_info.dbgbuf_cnt);
        res = -1;
    }
    if(shared->comp_info.bk_txq != NX_TXDESC_CNT0)
    {
        wiphy_err(wiphy, "Driver and FW have different sizes of BK TX queue (%d != %d)\n",
                  NX_TXDESC_CNT0, shared->comp_info.bk_txq);
        res = -1;
    }
    if(shared->comp_info.be_txq != NX_TXDESC_CNT1)
    {
        wiphy_err(wiphy, "Driver and FW have different sizes of BE TX queue (%d != %d)\n",
                  NX_TXDESC_CNT1, shared->comp_info.be_txq);
        res = -1;
    }
    if(shared->comp_info.vi_txq != NX_TXDESC_CNT2)
    {
        wiphy_err(wiphy, "Driver and FW have different sizes of VI TX queue (%d != %d)\n",
                  NX_TXDESC_CNT2, shared->comp_info.vi_txq);
        res = -1;
    }
    if(shared->comp_info.vo_txq != NX_TXDESC_CNT3)
    {
        wiphy_err(wiphy, "Driver and FW have different sizes of VO TX queue (%d != %d)\n",
                  NX_TXDESC_CNT3, shared->comp_info.vo_txq);
        res = -1;
    }
    #if NX_TXQ_CNT == 5
    if(shared->comp_info.bcn_txq != NX_TXDESC_CNT4)
    {
        wiphy_err(wiphy, "Driver and FW have different sizes of BCN TX queue (%d != %d)\n",
                NX_TXDESC_CNT4, shared->comp_info.bcn_txq);
        res = -1;
    }
    #else
    if (shared->comp_info.bcn_txq > 0)
    {
        wiphy_err(wiphy, "BCMC enabled in firmware but disabled in driver\n");
        res = -1;
    }
    #endif
    if(shared->comp_info.ipc_shared_size != sizeof(ipc_shared_env))
    {
        wiphy_err(wiphy, "Different sizes of IPC shared between driver and FW (%zd != %d)\n",
                  sizeof(ipc_shared_env), shared->comp_info.ipc_shared_size);
        res = -1;
    }
    if(shared->comp_info.msg_api != MSG_API_VER)
    {
        wiphy_warn(wiphy, "WARNING: Different supported message API versions between "\
                   "driver and FW (%d != %d)\n", MSG_API_VER, shared->comp_info.msg_api);
    }
    return res;
}
int siwifi_platform_on(struct siwifi_hw *siwifi_hw, void *config)
{
    u8 *shared_ram;
    struct siwifi_plat *siwifi_plat = siwifi_hw->plat;
    int ret;
    if (siwifi_plat->enabled)
        return 0;
    if (siwifi_platform_reset(siwifi_plat))
        return -1;
    siwifi_plat_mpif_sel(siwifi_plat);
    if ((ret = siwifi_plat_fcu_load(siwifi_hw)))
        return ret;
    if ((ret = siwifi_plat_agc_load(siwifi_plat)))
        return ret;
    if ((ret = siwifi_ldpc_load(siwifi_hw)))
        return ret;
    if ((ret = siwifi_plat_lmac_load(siwifi_plat)))
        return ret;
    shared_ram = SIWIFI_ADDR(siwifi_plat, SIWIFI_ADDR_SYSTEM, SHARED_RAM_START_ADDR);
    if ((ret = siwifi_ipc_init(siwifi_hw, shared_ram)))
        return ret;
    if ((ret = siwifi_plat->enable(siwifi_hw)))
        return ret;
    SIWIFI_REG_WRITE(BOOTROM_ENABLE, siwifi_plat,
                   SIWIFI_ADDR_SYSTEM, SYSCTRL_MISC_CNTL_ADDR);
    msleep(500);
    if ((ret = siwifi_check_fw_compatibility(siwifi_hw)))
    {
        siwifi_hw->plat->disable(siwifi_hw);
        tasklet_kill(&siwifi_hw->task);
        siwifi_ipc_deinit(siwifi_hw);
        return ret;
    }
    if (config)
        siwifi_term_restore_config(siwifi_plat, config);
    siwifi_ipc_start(siwifi_hw);
    siwifi_plat->enabled = true;
    return 0;
}
void siwifi_platform_off(struct siwifi_hw *siwifi_hw, void **config)
{
    if (!siwifi_hw->plat->enabled) {
        if (config)
            *config = NULL;
        return;
    }
    siwifi_ipc_stop(siwifi_hw);
    if (config)
        *config = siwifi_term_save_config(siwifi_hw->plat);
    siwifi_hw->plat->disable(siwifi_hw);
    tasklet_kill(&siwifi_hw->task);
    siwifi_ipc_deinit(siwifi_hw);
    siwifi_platform_reset(siwifi_hw->plat);
    siwifi_hw->plat->enabled = false;
}
int siwifi_platform_init(struct siwifi_plat *siwifi_plat, void **platform_data)
{
    SIWIFI_DBG(SIWIFI_FN_ENTRY_STR);
    siwifi_plat->enabled = false;
    return siwifi_cfg80211_init(siwifi_plat, platform_data);
}
void siwifi_platform_deinit(struct siwifi_hw *siwifi_hw)
{
    SIWIFI_DBG(SIWIFI_FN_ENTRY_STR);
    siwifi_cfg80211_deinit(siwifi_hw);
}
int siwifi_platform_register_drv(void)
{
    return siwifi_pci_register_drv();
}
void siwifi_platform_unregister_drv(void)
{
    return siwifi_pci_unregister_drv();
}
#ifndef CONFIG_SIWIFI_SDM
MODULE_FIRMWARE(SIWIFI_AGC_FW_NAME);
MODULE_FIRMWARE(SIWIFI_FCU_FW_NAME);
MODULE_FIRMWARE(SIWIFI_LDPC_RAM_NAME);
#endif
MODULE_FIRMWARE(SIWIFI_MAC_FW_NAME);
#ifndef CONFIG_SIWIFI_TL4
MODULE_FIRMWARE(SIWIFI_MAC_FW_NAME2);
#endif
