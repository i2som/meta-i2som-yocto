#
# Copyright (C) 2017 i2SOM Team.
#

SUMMARY = "Initram system files"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


SRC_URI = " \
    file://updatesys.sh \
    file://preupdate \
"

S = "${WORKDIR}"

inherit update-rc.d

INITSCRIPT_PARAMS = "start 100 2 3 4 5 ."
INITSCRIPT_NAME = "preupdate"

do_install() {
        install -m 0755 -d ${D}${sysconfdir}/init.d
        install -m 0755 ${WORKDIR}/preupdate ${D}${sysconfdir}/init.d/preupdate
        install -m 0755 ${WORKDIR}/updatesys.sh ${D}${sysconfdir}
}

# Do not create debug/devel packages
PACKAGES = "${PN}"

#FILES_${PN} = "/ "

RDEPENDS_${PN}_append_am335x = " \
    cryptsetup \
    rng-tools \
"
