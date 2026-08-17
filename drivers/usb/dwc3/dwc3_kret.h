/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2021, The Linux Foundation. All rights reserved.
 */

#ifndef __LINUX_USB_DWC3_KRET_H
#define __LINUX_USB_DWC3_KRET_H

#include <linux/scatterlist.h>
#include <linux/usb/gadget.h>

int dwc3_kretprobe_init(void);
void dwc3_kretprobe_exit(void);

#endif /* __LINUX_USB_DWC3_KRET_H */
