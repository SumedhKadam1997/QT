#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "displaymanager.hpp"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
//    DisplayManager dispMan;
//    dispMan.changeBrightnessWinAPI();
//    dispMan.changeBrightnessQProcess(20);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("display", new DisplayManager());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
