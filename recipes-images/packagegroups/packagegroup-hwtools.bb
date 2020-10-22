DESCRIPTION = "Hardware development tools used on i2SOM boards"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

RDEPENDS_${PN} = " \
    usbutils \
    ethtool \
    i2c-tools \
    devmem2 \
    iw \
    bc \
    libdrm-tests \
    e2fsprogs-mke2fs \
    e2fsprogs-tune2fs \
    e2fsprogs-resize2fs \
    parted \
    mmc-utils \
    mtd-utils \
    mtd-utils-ubifs \
    mtd-utils-misc \
    iproute2 \
    ${@bb.utils.contains("MACHINE_FEATURES", "can", "can-utils", "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "resistivetouch", "tslib-conf tslib-calibrate tslib-tests", "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "pci", "pciutils", "", d)} \
"
