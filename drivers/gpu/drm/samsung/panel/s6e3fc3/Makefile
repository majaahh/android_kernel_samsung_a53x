# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the Linux kernel panel device drivers.
#

mcd-panel-s6e3fc3_a53x-y += s6e3fc3.o s6e3fc3_a53x.o
mcd-panel-s6e3fc3_a53x-$(CONFIG_EXTEND_LIVE_CLOCK) += s6e3fc3_aod.o
obj-$(CONFIG_EXYNOS_DECON_LCD_S6E3FC3) += mcd-panel-s6e3fc3_a53x.o
