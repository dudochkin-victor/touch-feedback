### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

include(check.pri)

FMSRCDIR = ../../src
INCLUDEPATH += $$FMSRCDIR/daemon $$FMSRCDIR/lib
#DEPENDPATH = $$INCLUDEPATH
CONFIG += 
QT += testlib
TEMPLATE = app
# DEFINES += QT_NO_DEBUG_OUTPUT
target.path = $$[QT_INSTALL_LIBS]/libmeegofeedback-tests
INSTALLS += target

QMAKE_CXXFLAGS += -Werror
QMAKE_LFLAGS += "-Wl,--as-needed"

support_files.files =
support_files.path = $$[QT_INSTALL_LIBS]/libmeegofeedback-tests
INSTALLS += support_files

