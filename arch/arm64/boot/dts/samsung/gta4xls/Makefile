# SPDX-License-Identifier: GPL-2.0

# SM-P625
dtbo-y += \
    device/gta4xls/gta4xls_eur_open_w00_r00.dtbo \
    device/gta4xls/gta4xls_eur_open_w00_r02.dtbo \
    device/gta4xls/gta4xls_eur_open_w00_r03.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
