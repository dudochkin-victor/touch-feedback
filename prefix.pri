### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release


# Follow the prefix logic of the theming
!isEmpty(PREFIX) {
    MF_PREFIX = $$PREFIX
} else {
    exists($$[QMAKE_MKSPECS]/features/meegotouch_defines.prf) {
        load(meegotouch_defines)
        MF_PREFIX = $$M_PREFIX
    } else {
        MF_PREFIX = /usr
    }
}
