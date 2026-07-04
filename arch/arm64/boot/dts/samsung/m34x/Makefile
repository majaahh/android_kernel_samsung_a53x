# SPDX-License-Identifier: GPL-2.0

# SM-M346B
dtbo-y += \
    device/m34x/m34x_eur_open_w00_r00.dtbo \
    device/m34x/m34x_eur_open_w00_r01.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
