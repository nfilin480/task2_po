TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=\
    cp.cpp \
    load.cpp \
    main.cpp \
    move.cpp \
    rle.cpp \
    save.cpp \
    showtrimmedfromstart.cpp \
    text/append_line.cpp \
    text/cp_swap.cpp \
    text/create_text.cpp \
    text/move_cursor.cpp \
    text/process_forward.cpp \
    text/remove_all.cpp \
    text/rle_line.cpp


DISTFILES +=\
    input.txt

HEADERS +=\
    cp.h \
    load.h \
    move.h \
    rle.h \
    save.h \
    showtrimmedfromstart.h \
    text/_text.h \
    text/text.h
    
QMAKE_CFLAGS += -Wall -Wextra -Werror

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
