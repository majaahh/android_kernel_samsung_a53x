# SPDX-License-Identifier: GPL-2.0

# SM-A336B
dtbo-y += \
    a33x_eur_open_w00_r00.dtbo \
    a33x_eur_open_w00_r01.dtbo \
    a33x_eur_open_w00_r02.dtbo \
    a33x_eur_open_w00_r03.dtbo \
    a33x_eur_open_w00_r04.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
