#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "photofetcher.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    PhotoFetcher photoFetcher;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("photoFetcher", &photoFetcher);
    const QUrl url(u"qrc:/PhotofromNet/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
