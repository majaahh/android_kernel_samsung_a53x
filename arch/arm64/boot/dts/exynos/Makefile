# SPDX-License-Identifier: GPL-2.0
dtb-$(CONFIG_ARCH_EXYNOS) += s5e8825.dtb

dtbo-$(CONFIG_ARCH_EXYNOS) += \
    samsung/a53x/a53x_eur_open_w00_r00.dtbo \
    samsung/a53x/a53x_eur_open_w00_r01.dtbo \
    samsung/a53x/a53x_eur_open_w00_r02.dtbo \
    samsung/a53x/a53x_eur_open_w00_r05.dtbo \
    samsung/a53x/a53x_eur_open_w00_r06.dtbo

dtbo-$(CONFIG_ARCH_EXYNOS) += \
    samsung/a53x/a53x_jpn_dcm_w00_r00.dtbo \
    samsung/a53x/a53x_jpn_dcm_w00_r01.dtbo \
    samsung/a53x/a53x_jpn_dcm_w00_r04.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always-y    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
