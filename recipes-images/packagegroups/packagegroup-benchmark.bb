DESCRIPTION = "Benchmark tools used on i2SOM boards"
LICENSE = "MIT"

inherit packagegroup

RDEPENDS_${PN} = " \
    bonnie++ \
    hdparm \
    iozone3 \
    iperf \
    iperf3 \
    lmbench \
    rt-tests \
    evtest \
    perf \
    stress \
    ${@bb.utils.contains("DISTRO_FEATURES", "systemd", "systemd-analyze", "",d)} \
"
