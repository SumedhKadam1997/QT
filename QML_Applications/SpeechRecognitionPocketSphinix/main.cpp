#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAndroid>
#include <QQmlContext>
//#include "qspeechrecognition.h"
#include <QLoggingCategory>
#include <QDir>
//#include <pocketsphinx.h>
#include <vosk_api.h>


const QVector<QString> permissions({"android.permission.WRITE_EXTERNAL_STORAGE",
                                    "android.permission.RECORD_AUDIO"
                                   });

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.asr=true \n qt.speech.asr.*=true"));

#if defined (Q_OS_ANDROID)
    //Request required permissions at runtime
    for(const QString &permission : permissions){
        auto result = QtAndroid::checkPermission(permission);
        if(result == QtAndroid::PermissionResult::Denied){
            auto resultHash = QtAndroid::requestPermissionsSync(QStringList({permission}));
            if(resultHash[permission] == QtAndroid::PermissionResult::Denied)
                return 0;
        }
    }
#endif

    QQmlApplicationEngine engine;

//    VoskModel model;

//    VoskRecognizer recognizer;

    engine.rootContext()->setContextProperty("homeDir", QDir::home().absolutePath());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
