#ifndef _IQ_TE_REG_DEF_H_
#define _IQ_TE_REG_DEF_H_ 
#define REG_SYSCTL_BASE 0xB9E00000
#define REG_SYSM_SHARE_RAM_SEL (REG_SYSCTL_BASE + 0x242C)
#define REG_SYSM_IQ_ENGINE_SEL (REG_SYSCTL_BASE + 0x2430)
#define REG_SYSM_IQ_ENGINE_CONF (REG_SYSCTL_BASE + 0x2434)
#define REG_SYSM_WIFI_LB_SYSM_RESET (REG_SYSCTL_BASE + 0x2C64)
#define REG_SYSM_WIFI_LB_SOFT_RESET (REG_SYSCTL_BASE + 0x8000)
#define REG_SYSM_WIFI_LB_SOFT_CLK_EN (REG_SYSCTL_BASE + 0x8004)
#define REG_SYSM_WIFI_LB_SOFT_BOE (REG_SYSCTL_BASE + 0x800C)
#define REG_SYSM_WIFI_LB_LA_CLK_SEL (REG_SYSCTL_BASE + 0x8040)
#define REG_SYSM_WIFI_LB_IQ_GEN_DUMP_EN (REG_SYSCTL_BASE + 0x8044)
#define REG_SYSM_WIFI_LB_IQ_DUMP_LENGTH_0 (REG_SYSCTL_BASE + 0x8048)
#define REG_SYSM_WIFI_LB_IQ_DUMP_LENGTH_1 (REG_SYSCTL_BASE + 0x804C)
#define REG_SYSM_WIFI_LB_IQ_DUMP_LENGTH_2 (REG_SYSCTL_BASE + 0x8050)
#define REG_SYSM_WIFI_LB_IQ_DUMP_LENGTH_3 (REG_SYSCTL_BASE + 0x8054)
#define REG_SYSM_WIFI_LB_IQ_GEN_LENGTH_0 (REG_SYSCTL_BASE + 0x8058)
#define REG_SYSM_WIFI_LB_IQ_GEN_LENGTH_1 (REG_SYSCTL_BASE + 0x805C)
#define REG_SYSM_WIFI_LB_IQ_GEN_LENGTH_2 (REG_SYSCTL_BASE + 0x8060)
#define REG_SYSM_WIFI_LB_IQ_GEN_LENGTH_3 (REG_SYSCTL_BASE + 0x8064)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_MODE (REG_SYSCTL_BASE + 0x3800)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_TRIGGER (REG_SYSCTL_BASE + 0x3804)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_DMAREQ (REG_SYSCTL_BASE + 0x3808)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_DMAACK (REG_SYSCTL_BASE + 0x380C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_0 (REG_SYSCTL_BASE + 0x3810)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_1 (REG_SYSCTL_BASE + 0x3814)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_2 (REG_SYSCTL_BASE + 0x3818)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_OFFSET_3 (REG_SYSCTL_BASE + 0x381C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_0 (REG_SYSCTL_BASE + 0x3820)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_1 (REG_SYSCTL_BASE + 0x3824)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_2 (REG_SYSCTL_BASE + 0x3828)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_LENGTH_3 (REG_SYSCTL_BASE + 0x382C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_DMAADEAD (REG_SYSCTL_BASE + 0x3830)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_COUNTER_0_FF2 (REG_SYSCTL_BASE + 0x3834)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_COUNTER_1_FF2 (REG_SYSCTL_BASE + 0x3838)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_COUNTER_2_FF2 (REG_SYSCTL_BASE + 0x383C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_RECORD_COUNTER_3_FF2 (REG_SYSCTL_BASE + 0x3840)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_MODE (REG_SYSCTL_BASE + 0x3A00)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_TRIGGER (REG_SYSCTL_BASE + 0x3A04)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_DMAREQ (REG_SYSCTL_BASE + 0x3A08)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_DMAACK (REG_SYSCTL_BASE + 0x3A0C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_0 (REG_SYSCTL_BASE + 0x3A10)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_1 (REG_SYSCTL_BASE + 0x3A14)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_2 (REG_SYSCTL_BASE + 0x3A18)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_OFFSET_3 (REG_SYSCTL_BASE + 0x3A1C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_0 (REG_SYSCTL_BASE + 0x3A20)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_1 (REG_SYSCTL_BASE + 0x3A24)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_2 (REG_SYSCTL_BASE + 0x3A28)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_LENGTH_3 (REG_SYSCTL_BASE + 0x3A2C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_DMAADEAD (REG_SYSCTL_BASE + 0x3A30)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_COUNTER_0_FF2 (REG_SYSCTL_BASE + 0x3A34)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_COUNTER_1_FF2 (REG_SYSCTL_BASE + 0x3A38)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_COUNTER_2_FF2 (REG_SYSCTL_BASE + 0x3A3C)
#define REG_SYSM_WIFI_LB_IQ_ENGINE_PLAYER_COUNTER_3_FF2 (REG_SYSCTL_BASE + 0x3A40)
#define REG_SYSM_WIFI_HB_SYSM_RESET (REG_SYSCTL_BASE + 0x2C68)
#define REG_SYSM_WIFI_HB_SOFT_RESET (REG_SYSCTL_BASE + 0x8400)
#define REG_SYSM_WIFI_HB_SOFT_CLK_EN (REG_SYSCTL_BASE + 0x8404)
#define REG_SYSM_WIFI_HB_SOFT_BOE (REG_SYSCTL_BASE + 0x840C)
#define REG_SYSM_WIFI_HB_LA_CLK_SEL (REG_SYSCTL_BASE + 0x8440)
#define REG_SYSM_WIFI_HB_IQ_GEN_DUMP_EN (REG_SYSCTL_BASE + 0x8444)
#define REG_SYSM_WIFI_HB_IQ_DUMP_LENGTH_0 (REG_SYSCTL_BASE + 0x8448)
#define REG_SYSM_WIFI_HB_IQ_DUMP_LENGTH_1 (REG_SYSCTL_BASE + 0x844C)
#define REG_SYSM_WIFI_HB_IQ_DUMP_LENGTH_2 (REG_SYSCTL_BASE + 0x8450)
#define REG_SYSM_WIFI_HB_IQ_DUMP_LENGTH_3 (REG_SYSCTL_BASE + 0x8454)
#define REG_SYSM_WIFI_HB_IQ_GEN_LENGTH_0 (REG_SYSCTL_BASE + 0x8458)
#define REG_SYSM_WIFI_HB_IQ_GEN_LENGTH_1 (REG_SYSCTL_BASE + 0x845C)
#define REG_SYSM_WIFI_HB_IQ_GEN_LENGTH_2 (REG_SYSCTL_BASE + 0x8460)
#define REG_SYSM_WIFI_HB_IQ_GEN_LENGTH_3 (REG_SYSCTL_BASE + 0x8464)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_MODE (REG_SYSCTL_BASE + 0x3900)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_TRIGGER (REG_SYSCTL_BASE + 0x3904)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_DMAREQ (REG_SYSCTL_BASE + 0x3908)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_DMAACK (REG_SYSCTL_BASE + 0x390C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_0 (REG_SYSCTL_BASE + 0x3910)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_1 (REG_SYSCTL_BASE + 0x3914)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_2 (REG_SYSCTL_BASE + 0x3918)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_OFFSET_3 (REG_SYSCTL_BASE + 0x391C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_0 (REG_SYSCTL_BASE + 0x3920)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_1 (REG_SYSCTL_BASE + 0x3924)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_2 (REG_SYSCTL_BASE + 0x3928)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_LENGTH_3 (REG_SYSCTL_BASE + 0x392C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_DMAADEAD (REG_SYSCTL_BASE + 0x3930)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_COUNTER_0_FF2 (REG_SYSCTL_BASE + 0x3934)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_COUNTER_1_FF2 (REG_SYSCTL_BASE + 0x3938)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_COUNTER_2_FF2 (REG_SYSCTL_BASE + 0x393C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_RECORD_COUNTER_3_FF2 (REG_SYSCTL_BASE + 0x3940)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_MODE (REG_SYSCTL_BASE + 0x3B00)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_TRIGGER (REG_SYSCTL_BASE + 0x3B04)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_DMAREQ (REG_SYSCTL_BASE + 0x3B08)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_DMAACK (REG_SYSCTL_BASE + 0x3B0C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_0 (REG_SYSCTL_BASE + 0x3B10)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_1 (REG_SYSCTL_BASE + 0x3B14)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_2 (REG_SYSCTL_BASE + 0x3B18)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_OFFSET_3 (REG_SYSCTL_BASE + 0x3B1C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_0 (REG_SYSCTL_BASE + 0x3B20)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_1 (REG_SYSCTL_BASE + 0x3B24)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_2 (REG_SYSCTL_BASE + 0x3B28)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_LENGTH_3 (REG_SYSCTL_BASE + 0x3B2C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_DMAADEAD (REG_SYSCTL_BASE + 0x3B30)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_COUNTER_0_FF2 (REG_SYSCTL_BASE + 0x3B34)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_COUNTER_1_FF2 (REG_SYSCTL_BASE + 0x3B38)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_COUNTER_2_FF2 (REG_SYSCTL_BASE + 0x3B3C)
#define REG_SYSM_WIFI_HB_IQ_ENGINE_PLAYER_COUNTER_3_FF2 (REG_SYSCTL_BASE + 0x3B40)
#define SIFLOWER_WIFI_INTC_IQR_LOWRAM_FULL 192
#define SIFLOWER_WIFI_INTC_IQR_HIGHRAM_FULL 193
#define SIFLOWER_WIFI_INTC_IQP_LOWRAM_FULL 194
#define SIFLOWER_WIFI_INTC_IQP_HIGHRAM_FULL 195
#define SIFLOWER_WIFI_INTC_IQP_24G_RX_ERROR 196
#define SIFLOWER_WIFI_INTC_IQP_24G_TX_ERROR 197
#define SIFLOWER_WIFI_INTC_IQP_5G_RX_ERROR 198
#define SIFLOWER_WIFI_INTC_IQP_5G_TX_ERROR 199
#define REG_SYSM_IRAM_SYSM_RESET (REG_SYSCTL_BASE + 0x2C30)
#define REG_SYSM_IRAM_SOFT_RESET (REG_SYSCTL_BASE + 0x0C00)
#define REG_SYSM_IRAM_SOFT_CLK_EN (REG_SYSCTL_BASE + 0x0C04)
#define REG_SYSM_IRAM_SOFT_BOE (REG_SYSCTL_BASE + 0x0C0C)
#define REG_SYSM_IRAM_SOFT_RESET1 (REG_SYSCTL_BASE + 0x0C1C)
#define REG_SYSM_IRAM_SOFT_CLK_EN1 (REG_SYSCTL_BASE + 0x0C20)
#endif
