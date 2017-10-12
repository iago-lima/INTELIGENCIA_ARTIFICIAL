TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    grafo.cpp \
    state.cpp \
    node.cpp \
    action.cpp \
    dfs.cpp \
    bfs.cpp

HEADERS += \
    grafo.h \
    state.h \
    node.h \
    action.h \
    dfs.h \
    enum.h \
    bfs.h
