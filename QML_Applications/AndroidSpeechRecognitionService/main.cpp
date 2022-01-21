#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "speechrecognitionservice.hpp"
#include <QQmlContext>
#include <QtAndroid>

const QVector<QString> permissions({"android.permission.RECORD_AUDIO",
                                   "android.permission.WRITE_EXTERNAL_STORAGE"});

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

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

    SpeechRecognitionService *speechService = new SpeechRecognitionService(&app);
    engine.rootContext()->setContextProperty(QLatin1String("speechService"), speechService);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
