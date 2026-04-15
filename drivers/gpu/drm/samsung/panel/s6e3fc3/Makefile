# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the Linux kernel panel device drivers.
#

subdir-ccflags-y += -I$(srctree)/$(src)/../oled_common

ifeq ($(CONFIG_SEC_A25),y)
mcd-panel-s6e3fc3_a25x-y += s6e3fc3.o s6e3fc3_a25x.o
obj-$(CONFIG_USDM_PANEL_S6E3FC3) += mcd-panel-s6e3fc3_a25x.o
endif

ifeq ($(CONFIG_SEC_M34),y)
mcd-panel-s6e3fc3_m34x-y += s6e3fc3.o s6e3fc3_m34x.o
obj-$(CONFIG_USDM_PANEL_S6E3FC3) += mcd-panel-s6e3fc3_m34x.o
endif
