#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAndroid>
#include <QQmlContext>
//#include "qspeechrecognition.h"
#include <QLoggingCategory>
#include <QDir>


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

//    qmlRegisterUncreatableType<QSpeechRecognitionEngine>("QtSpeechRecognition", 0, 1,
//                                                         "SpeechRecognitionEngine", QLatin1String("Cannot create SpeechRecognitionEngine"));
//    qmlRegisterUncreatableType<QSpeechRecognitionGrammar>("QtSpeechRecognition", 0, 1,
//                                                          "SpeechRecognitionGrammar", QLatin1String("Cannot create SpeechRecognitionGrammar"));
//    qmlRegisterType<QSpeechRecognition>("QtSpeechRecognition", 0, 1, "SpeechRecognition");
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
