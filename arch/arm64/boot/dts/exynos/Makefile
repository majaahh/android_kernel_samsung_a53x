# SPDX-License-Identifier: GPL-2.0
dtb-$(CONFIG_ARCH_EXYNOS) += s5e8825.dtb

# a25x - SM-A256B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/a25x/a25x_eur_open_w00_r00.dtbo \
    device/a25x/a25x_eur_open_w00_r01.dtbo \
    device/a25x/a25x_eur_open_w00_r02.dtbo \
    device/a25x/a25x_eur_open_w00_r04.dtbo \
    device/a25x/a25x_eur_open_w00_r05.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
