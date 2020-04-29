
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIRFILE=\\\"$$PWD/file\\\" \
           INPUTDIRFILESHOW=\\\"$$PWD/file_show\\\"

HEADERS +=     \ \
    test_cp.h \
    test_move.h \
    test_rle.h \
    test_save.h \
    test_showtrimmedfromstart.h\
    ../app/text/_text.h

SOURCES += main.cpp \
    ../app/cp.cpp \
    ../app/load.cpp \
    ../app/move.cpp \
    ../app/rle.cpp \
    ../app/save.cpp \
    ../app/showtrimmedfromstart.cpp \
    ../app/text/append_line.cpp \
    ../app/text/cp_swap.cpp \
    ../app/text/create_text.cpp \
    ../app/text/move_cursor.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/remove_all.cpp \
    ../app/text/rle_line.cpp

INCLUDEPATH += ../app\

