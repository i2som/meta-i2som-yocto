DESCRIPTION = "Qt for i2SOM boards"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

RDEPENDS_${PN} = " \
    qtbase \
    qtserialbus \
    qtserialport \
    qtwebsockets \
    qttranslations \
"
