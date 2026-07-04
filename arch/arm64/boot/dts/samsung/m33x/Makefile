# SPDX-License-Identifier: GPL-2.0

# SM-M336B
dtbo-y += \
    m33x_eur_open_w00_r00.dtbo \
    m33x_eur_open_w00_r01.dtbo \
    m33x_eur_open_w00_r02.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
