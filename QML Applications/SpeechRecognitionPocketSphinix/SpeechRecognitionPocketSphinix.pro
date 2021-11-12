QT += quick multimedia androidextras

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += qml.qrc \
    grammer.qrc

#INCLUDEPATH += C:\Users\User\Desktop

#LIBS += -L"/home/crazymax/svn/pocketsphinx-android/libs/armeabi-v7a" -lpocketsphinx_jni
LIBS += -L"C:\Users\User\Desktop" -lpocketsphinx_jni

#ANDROID_EXTRA_LIBS += \
#    $$PWD/LIBS/x86/libpocketsphinx_jni.so \
#    $$PWD/LIBS/armeabi-v7a/libpocketsphinx_jni.so \
#    $$PWD/LIBS/arm64-v8a/libpocketsphinx_jni.so \
#    $$PWD/LIBS/x86_64/libpocketsphinx_jni.so \

ANDROID_EXTRA_LIBS += $$PWD/LIBS/x86/libpocketsphinx_jni.so

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
