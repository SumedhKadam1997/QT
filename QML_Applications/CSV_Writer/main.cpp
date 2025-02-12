#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "csvwriter.hpp"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    CSVWriter csv;
    csv.writeCSV();
    csv.readCSV();
//    csv.

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("csv", &csv);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
