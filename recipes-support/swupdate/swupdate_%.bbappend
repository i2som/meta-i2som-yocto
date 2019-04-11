# Copyright (C) 2017 i2SOM Team.

FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

do_install_append() {
	# Copy the 'progress' binary.
	install -d ${D}${bindir}/
	#install -m 0755 progress ${D}${bindir}/
}
