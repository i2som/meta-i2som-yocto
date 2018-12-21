DESCRIPTION = "Userland softwareservices found in all i2SOM boards"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

RDEPENDS_${PN} = " \
    gdbserver \
    perf \
    strace \
    openssh \
    openssh-sftp-server \
    rsync \
    htop \
    crda \
    kbd \
    kbd-keymaps \
"
