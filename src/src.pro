### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

TEMPLATE = subdirs
SUBDIRS = lib daemon
CONFIG += ordered

check.target = check
check.CONFIG = recursive
QMAKE_EXTRA_TARGETS += check

check-xml.target = check-xml
check-xml.CONFIG = recursive
QMAKE_EXTRA_TARGETS += check-xml
