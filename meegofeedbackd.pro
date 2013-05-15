### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release


TEMPLATE=subdirs
CONFIG += ordered

include(prefix.pri)

SUBDIRS=src \
    tests \
    meegofeedback-dummy

include(conf/conf.pri)
include(doc/doc.pri)

# "qmake -recursive TEST_BACKENDS=on" enables compiling of test dummy backends
# that are useful for testing.
contains( TEST_BACKENDS, on ) {
    SUBDIRS -= meegofeedback-dummy
    SUBDIRS += meegofeedback-dummy-audio meegofeedback-dummy-vibra
}

QMAKE_CLEAN += build-stamp \
    configure-stamp \
    artifacts/*.deb \
    tests/*/*.log.xml \
    tests/*/*.log \
    *.log.xml \
    *.log

QMAKE_DISTCLEAN += build-stamp \
    configure-stamp \
    artifacts/*.deb \
    tests/*/*.log.xml \
    tests/*/*.log \
    *.log.xml \
    *.log

check.target = check
check.CONFIG = recursive
QMAKE_EXTRA_TARGETS += check

check-xml.target = check-xml
check-xml.CONFIG = recursive
QMAKE_EXTRA_TARGETS += check-xml

#include(shared.pri)
#include(debian/deb.pri)

