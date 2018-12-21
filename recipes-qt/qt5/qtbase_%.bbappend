FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

RDEPENDS_qtbase_append = " tslib-conf tslib-calibrate"

PACKAGECONFIG_MULTIMEDIA_append = " alsa"
PACKAGECONFIG_DEFAULT_append = " tslib"

PACKAGECONFIG_GL = "gles2 eglfs"

PACKAGECONFIG_FONTS = "fontconfig"

#this is necessary for qtquickcontrols-qmlplugins
PACKAGECONFIG_append = " accessibility"

#input devices
PACKAGECONFIG_append = " libinput"

# support database
PACKAGECONFIG_DEFAULT_append = " sql-sqlite sql-sqlite2"

QT_QPA_DEFAULT_PLATFORM ??= "eglfs"

# Set default QT_QPA_PLATFORM for all i2SOM boards
do_configure_prepend() {
        # adapt qmake.conf to our needs
        sed -i 's!load(qt_config)!!' ${S}/mkspecs/linux-oe-g++/qmake.conf

        # Insert QT_QPA_PLATFORM into qmake.conf
        cat >> ${S}/mkspecs/linux-oe-g++/qmake.conf <<EOF

QT_QPA_DEFAULT_PLATFORM = ${QT_QPA_DEFAULT_PLATFORM}

load(qt_config)

EOF
}
