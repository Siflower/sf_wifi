#ifndef _SIWIFI_V7_H_
#define _SIWIFI_V7_H_ 
#include <linux/pci.h>
#include "siwifi_platform.h"
int siwifi_v7_platform_init(struct pci_dev *pci_dev,
                          struct siwifi_plat **siwifi_plat);
#endif
