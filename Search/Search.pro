TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    state.cpp \
    node.cpp \
    action.cpp \
    dfs.cpp \
    bfs.cpp \
    ucs.cpp \
    graph.cpp

HEADERS += \
    state.h \
    node.h \
    action.h \
    dfs.h \
    enum.h \
    bfs.h \
    ucs.h \
    graph.h
