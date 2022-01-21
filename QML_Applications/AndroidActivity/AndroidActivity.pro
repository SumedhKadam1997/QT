QT += quick androidextras

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        secondactivity.cpp

RESOURCES += qml.qrc

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
    android/models/build.gradle \
    android/models/src/main/AndroidManifest.xml \
    android/models/src/main/assets/model-en-in/README \
    android/models/src/main/assets/model-en-in/am/final.mdl \
    android/models/src/main/assets/model-en-in/am/frame_subsampling_factor \
    android/models/src/main/assets/model-en-in/conf/mfcc.conf \
    android/models/src/main/assets/model-en-in/conf/model.conf \
    android/models/src/main/assets/model-en-in/graph/HCLG.fst \
    android/models/src/main/assets/model-en-in/graph/word_boundary.int \
    android/models/src/main/assets/model-en-in/graph/words.txt \
    android/models/src/main/assets/model-en-in/ivector/final.dubm \
    android/models/src/main/assets/model-en-in/ivector/final.ie \
    android/models/src/main/assets/model-en-in/ivector/final.mat \
    android/models/src/main/assets/model-en-in/ivector/global_cmvn.stats \
    android/models/src/main/assets/model-en-in/ivector/ivector.conf \
    android/models/src/main/assets/model-en-in/ivector/online_cmvn.conf \
    android/models/src/main/assets/model-en-in/ivector/splice.conf \
    android/models/src/main/assets/model-en-in/rescore/G.carpa \
    android/models/src/main/assets/model-en-in/rescore/G.fst \
    android/models/src/main/assets/model-en-us/README \
    android/models/src/main/assets/model-en-us/am/final.mdl \
    android/models/src/main/assets/model-en-us/conf/mfcc.conf \
    android/models/src/main/assets/model-en-us/conf/model.conf \
    android/models/src/main/assets/model-en-us/graph/Gr.fst \
    android/models/src/main/assets/model-en-us/graph/HCLr.fst \
    android/models/src/main/assets/model-en-us/graph/disambig_tid.int \
    android/models/src/main/assets/model-en-us/graph/phones/word_boundary.int \
    android/models/src/main/assets/model-en-us/ivector/final.dubm \
    android/models/src/main/assets/model-en-us/ivector/final.ie \
    android/models/src/main/assets/model-en-us/ivector/final.mat \
    android/models/src/main/assets/model-en-us/ivector/global_cmvn.stats \
    android/models/src/main/assets/model-en-us/ivector/online_cmvn.conf \
    android/models/src/main/assets/model-en-us/ivector/splice.conf \
    android/res/layout/main.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/settings.gradle \
#    android/src/org/qtproject/example/SecondActivity.java \
    android/src/org/qtproject/example/VoskActivity.java


ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    secondactivity.hpp
