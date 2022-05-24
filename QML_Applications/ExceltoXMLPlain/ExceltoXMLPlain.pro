TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/include

LIBS += -L"$$PWD/lib" -lAspose.Cells

SOURCES += \
        main.cpp
