### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

QMAKE_CLEAN += \
    *.gcov \
    *.gcno \
    *.gcda \


