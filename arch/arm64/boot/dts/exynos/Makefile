# SPDX-License-Identifier: GPL-2.0
subdir-y += board/erd
subdir-y += board/univ

dtb-$(CONFIG_ARCH_EXYNOS) += s5e8825.dtb

# a25x - SM-A256B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/a25x/a25x_eur_open_w00_r00.dtbo \
    device/a25x/a25x_eur_open_w00_r01.dtbo \
    device/a25x/a25x_eur_open_w00_r02.dtbo \
    device/a25x/a25x_eur_open_w00_r04.dtbo \
    device/a25x/a25x_eur_open_w00_r05.dtbo

# a33x - SM-A336B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/a33x/a33x_eur_open_w00_r00.dtbo \
    device/a33x/a33x_eur_open_w00_r01.dtbo \
    device/a33x/a33x_eur_open_w00_r02.dtbo \
    device/a33x/a33x_eur_open_w00_r03.dtbo \
    device/a33x/a33x_eur_open_w00_r04.dtbo

# a53x - SC-53C
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/a53x/a53x_jpn_dcm_w00_r00.dtbo \
    device/a53x/a53x_jpn_dcm_w00_r01.dtbo \
    device/a53x/a53x_jpn_dcm_w00_r04.dtbo

# a53x - SM-A536B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/a53x/a53x_eur_open_w00_r00.dtbo \
    device/a53x/a53x_eur_open_w00_r01.dtbo \
    device/a53x/a53x_eur_open_w00_r02.dtbo \
    device/a53x/a53x_eur_open_w00_r05.dtbo \
    device/a53x/a53x_eur_open_w00_r06.dtbo

# gta4xls - SM-P625
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/gta4xls/gta4xls_eur_open_w00_r00.dtbo \
    device/gta4xls/gta4xls_eur_open_w00_r02.dtbo \
    device/gta4xls/gta4xls_eur_open_w00_r03.dtbo

# gta4xlswifi - SM-P620
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/gta4xlswifi/gta4xlswifi_eur_open_w00_r00.dtbo \
    device/gta4xlswifi/gta4xlswifi_eur_open_w00_r02.dtbo \
    device/gta4xlswifi/gta4xlswifi_eur_open_w00_r03.dtbo

# m33x - SM-M336B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/m33x/m33x_eur_open_w00_r00.dtbo \
    device/m33x/m33x_eur_open_w00_r01.dtbo \
    device/m33x/m33x_eur_open_w00_r02.dtbo

# m34x - SM-M346B
dtbo-$(CONFIG_ARCH_EXYNOS) += \
    device/m34x/m34x_eur_open_w00_r00.dtbo \
    device/m34x/m34x_eur_open_w00_r01.dtbo

targets += dtbs
DTB_LIST := $(dtb-y) $(dtbo-y)
always-y := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
