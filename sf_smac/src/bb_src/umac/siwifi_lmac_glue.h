#ifndef _SIWIFI_LMAC_GLUE_H_
#define _SIWIFI_LMAC_GLUE_H_ 
#include <linux/wait.h>
#include <linux/timer.h>
#include <linux/clk.h>
#include "siwifi_defs.h"
struct mpw0_plat_data {
    int deep_debug_type;
    int lmac_prepared;
    wait_queue_head_t lmac_wq;
    void __iomem *base;
    int umac_irq;
    int32_t la_clk;
    struct clk *pl_clk;
    struct clk *bus_clk;
#if (defined(CONFIG_SF16A18_WIFI_LA_ENABLE) && (defined(CFG_A28_MPW_LA_CLK_BUG) || defined(CFG_A28_FULLMASK_LA_BUG)))
 struct clk *other_band_pl_clk;
    struct clk *other_band_bus_clk;
#endif
#ifdef CONFIG_SF16A18_LMAC_USE_M_SFDSP
    struct clk *m_SFDSP_clk;
#endif
    uint8_t band;
    uint8_t on;
};
int lmac_glue_init(struct mpw0_plat_data *priv, struct device *device);
u8 *lmac_glue_share_mem_init(struct mpw0_plat_data *priv);
int lmac_glue_start(struct siwifi_hw *siwifi_hw, struct mpw0_plat_data *priv);
void lmac_glue_stop(struct siwifi_hw *siwifi_hw, struct mpw0_plat_data *priv);
void lmac_glue_deinit(struct mpw0_plat_data *priv);
void notify_lmac_complete_ipc(struct siwifi_hw *siwifi_hw);
void notify_lmac_la_init_ipc(struct siwifi_hw *siwifi_hw, int8_t type,int8_t enable);
#endif
