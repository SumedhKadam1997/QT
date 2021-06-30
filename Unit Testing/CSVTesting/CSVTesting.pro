QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    csvparser.cpp \
    test.cpp

HEADERS += \
    csvparser.h
