// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2012-2021, The Linux Foundation. All rights reserved.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/irq.h>
#include <linux/irqdesc.h>
#include <linux/sched.h>
#include "core.h"
#include "gadget.h"
#include "../host/xhci.h"

struct kprobe_data {
	void *x0;
	void *x1;
	void *x2;
};

static int entry___dwc3_set_mode(struct kretprobe_instance *ri,
				   struct pt_regs *regs)
{
	pr_info("%s\n", __func__);

	return 0;
}

static int entry_dwc3_core_soft_reset(struct kretprobe_instance *ri,
				   struct pt_regs *regs)
{
	pr_info("%s\n", __func__);

	return 0;
}

static int entry_dwc3_core_init(struct kretprobe_instance *ri,
				   struct pt_regs *regs)
{
	pr_info("%s+++\n", __func__);

	return 0;
}

static int exit_dwc3_core_init(struct kretprobe_instance *ri,
				   struct pt_regs *regs)
{
	pr_info("%s---\n", __func__);

	return 0;
}

static int entry_xhci_endpoint_init(struct kretprobe_instance *ri,
					struct pt_regs *regs)
{
	struct usb_device *udev;
	struct usb_host_endpoint *ep;
	struct usb_endpoint_descriptor *desc;

	udev = (struct usb_device *)regs->regs[2]; // x2 = udev
	ep = (struct usb_host_endpoint *)regs->regs[3]; // x3 = ep

	if (!udev || !ep)
		return 0;

	desc = &ep->desc;

	pr_info("xhci_kprobe: ep=0x%x old bInterval=%u\n", desc->bEndpointAddress, desc->bInterval);

	if (le16_to_cpu(udev->descriptor.idVendor) == 0x152a &&
		le16_to_cpu(udev->descriptor.idProduct) == 0x8759) {
		if (usb_endpoint_xfer_isoc(desc)) {
			if ((desc->bmAttributes & USB_ENDPOINT_USAGE_MASK) == USB_ENDPOINT_USAGE_FEEDBACK) {
				if (usb_endpoint_dir_in(desc))
						desc->bInterval = 6;
			}
		}
	}

	pr_info("xhci_kprobe: bInterval changed to %u\n", desc->bInterval);

	return 0;
}

#define ENTRY_EXIT(name) {\
	.handler = exit_##name,\
	.entry_handler = entry_##name,\
	.data_size = sizeof(struct kprobe_data),\
	.maxactive = 8,\
	.kp.symbol_name = #name,\
}

#define ENTRY(name) {\
	.entry_handler = entry_##name,\
	.data_size = sizeof(struct kprobe_data),\
	.maxactive = 8,\
	.kp.symbol_name = #name,\
}

static struct kretprobe dwc3_kret_probes[] = {
	ENTRY(__dwc3_set_mode),
	ENTRY(dwc3_core_soft_reset),
	ENTRY_EXIT(dwc3_core_init),
	ENTRY(xhci_endpoint_init),
};

int dwc3_kretprobe_init(void)
{
	int ret;
	int i;

	for (i = 0; i < ARRAY_SIZE(dwc3_kret_probes); i++) {
		ret = register_kretprobe(&dwc3_kret_probes[i]);
		if (ret < 0) {
			pr_err("register_kretprobe failed, returned %d\n", ret);
			return ret;
		}
	}

	return 0;
}

void dwc3_kretprobe_exit(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(dwc3_kret_probes); i++)
		unregister_kretprobe(&dwc3_kret_probes[i]);
}

MODULE_SOFTDEP("pre:dwc3-exynos-usb");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DesignWare USB3 EXYNOS Glue Layer function handler");
