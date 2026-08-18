# SPDX-License-Identifier: GPL-2.0
dtbo-$(CONFIG_SEC_A26XS_PROJECT) += \
    a26xs/a26xs_ltn_open_w00_r00.dtbo \
    a26xs/a26xs_ltn_open_w00_r02.dtbo \
    a26xs/a26xs_ltn_open_w00_r04.dtbo \
    a26xs/a26xs_ltn_open_w00_r05.dtbo

targets += dtbs
always-y := $(dtbo-y)

dtbs: $(addprefix $(obj)/, $(dtbo-y))

clean-files := *.dtbo*
