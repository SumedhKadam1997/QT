#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QImageWriter>
#include <QFile>
#include <QDebug>
#include "imageprocessor.hpp"
#include "videofilter.hpp"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyVideoFilter>("my.uri", 1, 0, "MyFilter");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("imgProcessor", new ImageProcessor());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
