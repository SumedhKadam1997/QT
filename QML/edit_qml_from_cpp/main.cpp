#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "my_class.h"
#include <QQmlComponent>
#include <QtQuick>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //    Getting the ApplicationWindow from the qml
    //    QObject *firstRootItem = engine.rootObjects().first();
    my_class* myclass = new my_class();
    QQmlComponent component(&engine, url);
    QObject *object = component.create();
    //    Connecting qml signal to slot in C++
    QObject::connect(object, SIGNAL(menuClicked(QString)), myclass, SLOT(onMenuClicked(QString)));
    return app.exec();
}

