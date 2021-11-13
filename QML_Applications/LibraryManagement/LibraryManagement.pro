QT += quick sql qml
QT += widgets
CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        booksmodel.cpp \
        database.cpp \
        issuedbooksmodel.cpp \
        librariansmodel.cpp \
        loginproperties.cpp \
        main.cpp \
        pendingbooksmodel.cpp \
        studentsmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    booksmodel.h \
    database.h \
    issuedbooksmodel.h \
    librariansmodel.h \
    loginproperties.h \
    pendingbooksmodel.h \
    studentsmodel.h
