# SPDX-License-Identifier: GPL-2.0
dtb-$(CONFIG_ARCH_EXYNOS) += s5e8825.dtb

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
