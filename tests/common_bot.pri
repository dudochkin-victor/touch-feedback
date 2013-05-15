### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

contains( COV_OPTION, on ) {
    include(coverage.pri)
}
