#
# Makefile for the stui Module
#

ccflags-y += -I$(srctree)/drivers/misc/tui/
ccflags-y += -I$(srctree)/drivers/misc/tzdev/include/tzdev
ccflags-y += -DUSE_TEE_CLIENT_API

tuihw-inf-objs := stui_inf.o

tuihw-objs := main.o
tuihw-objs += stui_core.o

ccflags-y += -DCONFIG_SOC_S5E8825
ccflags-y += -I$(srctree)/drivers/misc/tui/platforms/exynos8825
ccflags-y += -I$(srctree)/drivers/misc/tui/platforms/exynos8825/include
tuihw-objs += platforms/exynos8825/stui_hal_display.o
tuihw-objs += platforms/exynos8825/stui_hal_touch.o

ifdef CONFIG_SAMSUNG_TUI_LOWLEVEL
tuihw-objs += iwd_agent.o

ccflags-y += -I$(srctree)/drivers/misc
ccflags-y += -I$(srctree)/drivers/misc/tzdev/
ccflags-y += -DCONFIG_SAMSUNG_TUI_LOWLEVEL
endif

obj-$(CONFIG_SAMSUNG_TUI) += tuihw.o tuihw-inf.o
