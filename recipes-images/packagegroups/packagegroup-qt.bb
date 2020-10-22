DESCRIPTION = "Qt for i2SOM boards"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

RDEPENDS_${PN} = " \
    qtbase \
    qtbase-examples \
    qtserialbus \
    qtserialport \
    qtwebsockets \
    qttranslations \
    qtwayland \
    qtwayland-examples \
"
