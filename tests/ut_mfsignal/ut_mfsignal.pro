### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

include(../common_top.pri)

TARGET = ut_mfsignal

TEST_SOURCES = $$FMSRCDIR/daemon/mfsignalhandler.cpp

SOURCES += ut_mfsignal.cpp \
    $$TEST_SOURCES

HEADERS += ut_mfsignal.h \
    $$FMSRCDIR/daemon/mfsignalhandler.h

include(../common_bot.pri)
