# SPDX-License-Identifier: GPL-2.0
dtbo-$(CONFIG_SEC_A26XS_PROJECT) += \
    a26xs/a26xs_ltn_open_w00_r00.dtbo \
    a26xs/a26xs_ltn_open_w00_r02.dtbo \
    a26xs/a26xs_ltn_open_w00_r04.dtbo \
    a26xs/a26xs_ltn_open_w00_r05.dtbo

dtbo-$(CONFIG_SEC_A53X_PROJECT) += \
    a53x/a53x_eur_open_w00_r00.dtbo \
    a53x/a53x_eur_open_w00_r01.dtbo \
    a53x/a53x_eur_open_w00_r02.dtbo \
    a53x/a53x_eur_open_w00_r05.dtbo \
    a53x/a53x_eur_open_w00_r06.dtbo

targets += dtbs
always-y := $(dtbo-y)

dtbs: $(addprefix $(obj)/, $(dtbo-y))

clean-files := *.dtbo*
