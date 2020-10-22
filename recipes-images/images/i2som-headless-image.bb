SUMMARY = "i2SOM's headless image"
DESCRIPTION = "no graphics support in this image"
LICENSE = "MIT"
inherit core-image

IMAGE_ROOTFS_SIZE ?= "8192"

IMAGE_INSTALL = " \
    mtd-utils \
    packagegroup-machine-base \
    packagegroup-core-boot \
    packagegroup-benchmark \
    packagegroup-userland \
    packagegroup-hwtools \
    packagegroup-rt \
    i2som-rc-local \
    ${@bb.utils.contains("COMBINED_FEATURES", "alsa", "packagegroup-audio", "", d)} \
    ${@bb.utils.contains("COMBINED_FEATURES", "wifi", "packagegroup-wifi", "", d)} \
    ${@bb.utils.contains("COMBINED_FEATURES", "bluetooth", "packagegroup-bluetooth", "", d)} \
    ${@bb.utils.contains("COMBINED_FEATURES", "3g", "packagegroup-3g", "", d)} \
    ntp \
    ntp-utils \
"
