#include <linux/types.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <asm/io.h>
#include "iq_te_reg_def.h"
#include "iq_te_core.h"
#include "rf_access.h"
#ifdef __MIPSEL__
#define CPU2HW(ptr) ((ptr) ? (CPHYSADDR(ptr)) : (0))
#else
#define CPU2HW(ptr) ((ptr) ? ((ptr&0x1FFFFFFF)) : (0))
#endif
#ifndef SIFLOWER_IRAM_BASE
#define SIFLOWER_IRAM_BASE 0xBC000000
#endif
#define SIFLOWER_IRAM_SIZE (96*1024)
#define DMA_COPY_DDR_SIZE (48*1024)
#define DMA_HARDWARE_ALIGNMENT (8)
#define REG_PL_RD8(addr) readb((void *)addr)
#define REG_PL_WR8(addr,value) writeb(value, ((void *)addr))
#define REG_PL_RD32(addr) readl((void *)addr)
#define REG_PL_WR32(addr,value) writel(value, ((void *)addr))
#define REG_LB_MDM_CFG_BASE_ADDR (0xB1100000)
#define REG_HB_MDM_CFG_BASE_ADDR (0xB1500000)
#define MDM_MDMCONF_ADDR_OFFSET (0x0800)
#define MDM_CLKGATEFCTRL0_ADDR_OFFSET (0x0874)
struct iq_test_engine_platform_context *g_iq_te_pl_ctx;
uint8_t g_share_memory_select_reg_value = 0;
static char *iq_player_data_path = "/lib/firmware/iq_player_data.bin";
static void mdm_feclkforce_setf(uint8_t band, uint8_t feclkforce)
{
    uint32_t mdm_clkgatefctrl0_addr = (band & HIGH_BAND) ? (REG_HB_MDM_CFG_BASE_ADDR + MDM_CLKGATEFCTRL0_ADDR_OFFSET) : (REG_LB_MDM_CFG_BASE_ADDR + MDM_CLKGATEFCTRL0_ADDR_OFFSET);
    REG_PL_WR32(mdm_clkgatefctrl0_addr, (REG_PL_RD32(mdm_clkgatefctrl0_addr) & ~((uint32_t)0x01000000)) | ((uint32_t)feclkforce << 24));
}
static void save_share_memory_select_reg_value(void)
{
    uint32_t share_ram_sel = REG_SYSM_SHARE_RAM_SEL;
    g_share_memory_select_reg_value = REG_PL_RD8(share_ram_sel);
}
static void restore_share_memory_select_reg_value(void)
{
    uint32_t share_ram_sel = REG_SYSM_SHARE_RAM_SEL;
    REG_PL_WR8(share_ram_sel, g_share_memory_select_reg_value);
}
int8_t iq_engine_rp_init(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    mdm_feclkforce_setf(p_ctx->band_type, 1);
    return 0;
}
void iq_engine_rp_deinit(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    mdm_feclkforce_setf(p_ctx->band_type, 0);
}
void iq_engine_player_start(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    uint32_t share_ram_sel = REG_SYSM_SHARE_RAM_SEL;
    uint32_t iq_engine_sel = REG_SYSM_IQ_ENGINE_SEL;
    uint32_t iq_engine_conf = REG_SYSM_IQ_ENGINE_CONF;
    uint32_t iq_engine_player_mode = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_MODE : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_MODE;
    uint32_t iq_engine_player_offset_0 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_0 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_0;
    uint32_t iq_engine_player_offset_1 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_1 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_1;
    uint32_t iq_engine_player_offset_2 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_2 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_2;
    uint32_t iq_engine_player_offset_3 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_3 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_3;
    uint32_t iq_engine_player_length_0 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_0 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_0;
    uint32_t iq_engine_player_length_1 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_1 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_1;
    uint32_t iq_engine_player_length_2 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_2 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_2;
    uint32_t iq_engine_player_length_3 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_3 : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_3;
    uint32_t iq_engine_player_trigger = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_TRIGGER : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_TRIGGER;
    save_share_memory_select_reg_value();
    if (p_ctx->band_type & HIGH_BAND) {
        if (p_ctx->sel_bb) {
            REG_PL_WR8(share_ram_sel, 0x02);
        } else {
            if (!p_ctx->rp_mode) {
                REG_PL_WR8(share_ram_sel, 0x02);
            } else {
                REG_PL_WR8(share_ram_sel, 0x01);
            }
        }
        REG_PL_WR8(iq_engine_sel, 0x08);
    } else if (p_ctx->band_type & LOW_BAND) {
        if (p_ctx->sel_bb) {
            REG_PL_WR8(share_ram_sel, 0x01);
        } else {
            if (!p_ctx->rp_mode) {
                REG_PL_WR8(share_ram_sel, 0x01);
            } else {
                REG_PL_WR8(share_ram_sel, 0x02);
            }
        }
        REG_PL_WR8(iq_engine_sel, 0x04);
    }
    if (p_ctx->sel_bb)
        REG_PL_WR8(iq_engine_conf, 0x03);
    else
        REG_PL_WR8(iq_engine_conf, 0x02);
    REG_PL_WR8(iq_engine_player_mode, !!p_ctx->use_dma);
    REG_PL_WR8(iq_engine_player_offset_0, p_ctx->iq_offset & 0xFF);
    REG_PL_WR8(iq_engine_player_offset_1, (p_ctx->iq_offset & 0xFF00) >> 8);
    REG_PL_WR8(iq_engine_player_offset_2, (p_ctx->iq_offset & 0xFF0000) >> 16);
    REG_PL_WR8(iq_engine_player_offset_3, (p_ctx->iq_offset & 0xFF000000) >> 24);
    REG_PL_WR8(iq_engine_player_length_0, p_ctx->iq_length & 0xFF);
    REG_PL_WR8(iq_engine_player_length_1, (p_ctx->iq_length & 0xFF00) >> 8);
    REG_PL_WR8(iq_engine_player_length_2, (p_ctx->iq_length & 0xFF0000) >> 16);
    REG_PL_WR8(iq_engine_player_length_3, (p_ctx->iq_length & 0xFF000000) >> 24);
    REG_PL_WR8(iq_engine_player_trigger, 1);
}
void iq_engine_player_stop(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    uint32_t iq_engine_sel = REG_SYSM_IQ_ENGINE_SEL;
    uint32_t iq_engine_conf = REG_SYSM_IQ_ENGINE_CONF;
    uint32_t iq_engine_player_trigger = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_TRIGGER : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_TRIGGER;
    REG_PL_WR8(iq_engine_player_trigger, 0);
    REG_PL_WR8(iq_engine_conf, 0x00);
    REG_PL_WR8(iq_engine_sel, 0x00);
    restore_share_memory_select_reg_value();
}
void iq_engine_record_start(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    uint32_t share_ram_sel = REG_SYSM_SHARE_RAM_SEL;
    uint32_t iq_engine_sel = REG_SYSM_IQ_ENGINE_SEL;
    uint32_t iq_engine_conf = REG_SYSM_IQ_ENGINE_CONF;
    uint32_t iq_engine_record_mode = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_MODE : REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_MODE;
    uint32_t iq_engine_record_offset_0 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_0 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_0;
    uint32_t iq_engine_record_offset_1 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_1 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_1;
    uint32_t iq_engine_record_offset_2 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_2 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_2;
    uint32_t iq_engine_record_offset_3 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_3 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_3;
    uint32_t iq_engine_record_length_0 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_0 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_0;
    uint32_t iq_engine_record_length_1 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_1 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_1;
    uint32_t iq_engine_record_length_2 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_2 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_2;
    uint32_t iq_engine_record_length_3 = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_3 : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_3;
    uint32_t iq_engine_record_trigger = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_TRIGGER : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_TRIGGER;
    save_share_memory_select_reg_value();
    if (p_ctx->band_type & HIGH_BAND) {
        REG_PL_WR8(share_ram_sel, 0x02);
        REG_PL_WR8(iq_engine_sel, 0x02);
    } else if (p_ctx->band_type & LOW_BAND) {
        REG_PL_WR8(share_ram_sel, 0x01);
        REG_PL_WR8(iq_engine_sel, 0x01);
    }
    if (p_ctx->sel_bb)
        REG_PL_WR8(iq_engine_conf, 0x03);
    else
        REG_PL_WR8(iq_engine_conf, 0x02);
    REG_PL_WR8(iq_engine_record_mode, ((!!p_ctx->use_dma) << 0) | ((!!p_ctx->over_write) << 1));
    REG_PL_WR8(iq_engine_record_offset_0, p_ctx->iq_offset & 0xFF);
    REG_PL_WR8(iq_engine_record_offset_1, (p_ctx->iq_offset & 0xFF00) >> 8);
    REG_PL_WR8(iq_engine_record_offset_2, (p_ctx->iq_offset & 0xFF0000) >> 16);
    REG_PL_WR8(iq_engine_record_offset_3, (p_ctx->iq_offset & 0xFF000000) >> 24);
    REG_PL_WR8(iq_engine_record_length_0, p_ctx->iq_length & 0xFF);
    REG_PL_WR8(iq_engine_record_length_1, (p_ctx->iq_length & 0xFF00) >> 8);
    REG_PL_WR8(iq_engine_record_length_2, (p_ctx->iq_length & 0xFF0000) >> 16);
    REG_PL_WR8(iq_engine_record_length_3, (p_ctx->iq_length & 0xFF000000) >> 24);
    REG_PL_WR8(iq_engine_record_trigger, 1);
}
void iq_engine_record_stop(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    uint32_t iq_engine_sel = REG_SYSM_IQ_ENGINE_SEL;
    uint32_t iq_engine_conf = REG_SYSM_IQ_ENGINE_CONF;
    uint32_t iq_engine_record_trigger = (p_ctx->band_type & HIGH_BAND) ? REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_TRIGGER : REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_TRIGGER;
    REG_PL_WR8(iq_engine_record_trigger, 0);
    REG_PL_WR8(iq_engine_conf, 0x00);
    REG_PL_WR8(iq_engine_sel, 0x00);
    restore_share_memory_select_reg_value();
}
static int iq_engine_parameters_prepare(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    int ret = 0;
    if (!p_ctx) {
        printk("iq_engine global context is not initail\n");
        ret = -10;
        goto PARAM_ERR;
    }
    if ((p_ctx->band_type & 0x3) == 0) {
        p_ctx->band_type = 2;
    }
    if (p_ctx->iq_offset > 96 * 1024) {
        p_ctx->iq_offset = 0;
        printk("iq_engine invalid iq_offset %d, so force to zero\n", p_ctx->iq_offset);
    }
    if (p_ctx->iq_length > 1024 * 1024) {
        p_ctx->iq_length = 96 * 1024;
        printk("iq_engine invalid iq_length %d, so force to 96K\n", p_ctx->iq_length);
    }
    if (!p_ctx->op_time) {
        p_ctx->op_time = 100;
    }
    p_ctx->use_dma = 0;
PARAM_ERR:
    return ret;
}
extern int call_umhelper(char *cmd, char *args);
int iq_engine_environment_prepare(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    if (p_ctx->sel_bb) {
        if (p_ctx->band_type & HIGH_BAND) {
            if (call_umhelper("/bin/sfwifi", "remove_band lb")) {
                printk("try to remove lb failed!\n");
                return -1;
            }
        } else if (p_ctx->band_type & LOW_BAND) {
            if (call_umhelper("/bin/sfwifi", "remove_band hb")) {
                printk("try to remove hb failed!\n");
                return -1;
            }
        }
    } else {
        if (p_ctx->band_type & HIGH_BAND) {
            if (p_ctx->rp_mode == 0) {
                if (call_umhelper("/bin/sfwifi", "remove_band lb")) {
                    printk("try to remove lb failed!\n");
                    return -1;
                }
            } else {
                if (call_umhelper("/bin/sfwifi", "remove_band hb")) {
                    printk("try to remove hb failed!\n");
                    return -1;
                }
            }
        } else if (p_ctx->band_type & LOW_BAND) {
            if (p_ctx->rp_mode == 0) {
                if (call_umhelper("/bin/sfwifi", "remove_band hb")) {
                    printk("try to remove hb failed!\n");
                    return -1;
                }
            } else {
                if (call_umhelper("/bin/sfwifi", "remove_band lb")) {
                    printk("try to remove lb failed!\n");
                    return -1;
                }
            }
        }
    }
    return 0;
}
static int load_player_data_from_bin_file(void *iq_te_ctx, char * path)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    struct file *fp;
    mm_segment_t fs;
    int iram_start_addr;
    size_t iram_length;
    ssize_t size;
    loff_t pos = 0;
    fp = filp_open(path, O_RDWR, 0644);
    if (IS_ERR(fp)) {
        printk("Can't open file : %s!\n", path);
        return PTR_ERR(fp);
    }
    if (p_ctx->sel_bb) {
        if (p_ctx->band_type & HIGH_BAND)
            iram_start_addr = SIFLOWER_IRAM_BASE;
        else
            iram_start_addr = (SIFLOWER_IRAM_BASE + SIFLOWER_IRAM_SIZE);
    } else {
        if (p_ctx->band_type & HIGH_BAND)
            iram_start_addr = (SIFLOWER_IRAM_BASE + SIFLOWER_IRAM_SIZE);
        else
            iram_start_addr = SIFLOWER_IRAM_BASE;
    }
    iram_length = (size_t)(p_ctx->iq_length * 4);
    fs = get_fs();
    set_fs(KERNEL_DS);
    size = kernel_read(fp, (char *)iram_start_addr, iram_length, &pos);
 set_fs(fs);
    filp_close(fp, NULL);
    return 0;
}
int iq_engine_player_once(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    int ret = 0;
    printk("%s\n", __func__);
    mutex_lock(&p_ctx->iq_te_mtx);
    ret = iq_engine_parameters_prepare(p_ctx);
    if (ret) {
        printk("%s iq_engine_parameters_prepare err\n", __func__);
        goto ERR_PLAYER_PARAM;
    }
    ret = iq_engine_environment_prepare(p_ctx);
    if (ret) {
        printk("%s iq_engind_environment_prepare err\n", __func__);
    }
    ret = load_player_data_from_bin_file(p_ctx, iq_player_data_path);
    if (ret) {
        printk("%s load_player_data_from_bin_file err\n", __func__);
        goto ERR_PLAYER;
    }
    ret = iq_engine_rp_init(p_ctx);
    if (ret) {
        printk("%s iq_engine_rp_init err\n", __func__);
        goto ERR_PLAYER;
    }
    iq_engine_player_start(p_ctx);
    mdelay(p_ctx->op_time);
    iq_engine_player_stop(p_ctx);
    iq_engine_rp_deinit(p_ctx);
ERR_PLAYER:
ERR_PLAYER_PARAM:
    mutex_unlock(&p_ctx->iq_te_mtx);
    return ret;
}
int iq_engine_record_once(void *iq_te_ctx)
{
    struct iq_test_engine_platform_context *p_ctx = (struct iq_test_engine_platform_context *)iq_te_ctx;
    int ret = 0;
    printk("%s\n", __func__);
    mutex_lock(&p_ctx->iq_te_mtx);
    ret = iq_engine_parameters_prepare(p_ctx);
    if (ret) {
        printk("%s iq_engine_parameters_prepare err\n", __func__);
        goto ERR_RECORD_PARAM;
    }
    ret = iq_engine_environment_prepare(p_ctx);
    if (ret) {
        printk("%s iq_engind_environment_prepare err\n", __func__);
    }
    ret = iq_engine_rp_init(p_ctx);
    if (ret) {
        printk("%s iq_engine_rp_init err\n", __func__);
        goto ERR_RECORD;
    }
    iq_engine_record_start(p_ctx);
    mdelay(p_ctx->op_time);
    iq_engine_record_stop(p_ctx);
    iq_engine_rp_deinit(p_ctx);
ERR_RECORD:
ERR_RECORD_PARAM:
    mutex_unlock(&p_ctx->iq_te_mtx);
    return ret;
}
void sys_iram_reset(void)
{
    REG_PL_WR8(REG_SYSM_IRAM_SYSM_RESET, 0x00);
    REG_PL_WR8(REG_SYSM_IRAM_SYSM_RESET, 0x01);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_CLK_EN, 0xFF);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_CLK_EN1, 0xFF);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_RESET, 0xFF);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_RESET, 0x00);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_RESET1, 0xFF);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_RESET1, 0x00);
    REG_PL_WR8(REG_SYSM_IRAM_SOFT_BOE, 0x0F);
}
