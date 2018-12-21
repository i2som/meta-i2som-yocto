DESCRIPTION = "real-time test suite and tools "
LICENSE = "MIT"

inherit packagegroup

RDEPENDS_${PN} = " \
    rt-tests \
    hwlatdetect \
"
