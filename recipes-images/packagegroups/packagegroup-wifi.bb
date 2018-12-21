DESCRIPTION = "i2SOM boards wifi software"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

RDEPENDS_${PN} = " \
    wpa-supplicant \
    wireless-tools \
    iw \
    hostapd \
"
