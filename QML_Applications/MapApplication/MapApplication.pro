QT += core quick location opengl concurrent sql network sensors

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

ANDROID_EXTRA_LIBS += \
    $$PWD/LIBS/x86/libcrypto_1_1.so \
    $$PWD/LIBS/x86/libssl_1_1.so \
    $$PWD/LIBS/arm/libcrypto_1_1.so \
    $$PWD/LIBS/arm/libssl_1_1.so \
    $$PWD/LIBS/arm64/libcrypto_1_1.so \
    $$PWD/LIBS/arm64/libssl_1_1.so \
    $$PWD/LIBS/x86_64/libcrypto_1_1.so \
    $$PWD/LIBS/x86_64/libssl_1_1.so


SOURCES += \
        assetitem.cpp \
        assetlistmodel.cpp \
#        location.cpp \
#        locationlistmodel.cpp \
    database.cpp \
        main.cpp \
    navbackend.cpp \
    navbackendjson.cpp

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
    assetitem.hpp \
    assetlistmodel.hpp \
#    location.hpp \
#    locationlistmodel.hpp \
 \#    nodemodel.hpp
    database.hpp \
    navbackend.hpp \
    navbackendjson.hpp

#RESOURCES += \ libs.qrc
#    qrc:/openssl/android_openssl/latest/x86_64/libcrypto_1_1.so \
#    qrc:/openssl/android_openssl/latest/x86_64/libssl_1_1.so \
#    qrc:/openssl/android_openssl/latest/x86/libcrypto_1_1.so \
#    qrc:/openssl/android_openssl/latest/x86/libssl_1_1.so \

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

