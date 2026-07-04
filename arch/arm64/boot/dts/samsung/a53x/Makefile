# SPDX-License-Identifier: GPL-2.0

# SC-53C
dtbo-y += \
    a53x_jpn_dcm_w00_r00.dtbo \
    a53x_jpn_dcm_w00_r01.dtbo \
    a53x_jpn_dcm_w00_r04.dtbo

# SM-A536B
dtbo-y += \
    a53x_eur_open_w00_r00.dtbo \
    a53x_eur_open_w00_r01.dtbo \
    a53x_eur_open_w00_r02.dtbo \
    a53x_eur_open_w00_r05.dtbo \
    a53x_eur_open_w00_r06.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
