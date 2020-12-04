#include <QGuiApplication>
#include <QtSql>
#include <QtDebug>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <properties.h>
#include <database.h>
#include <dbmodel.h>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<database>("Database",1 ,0,"Database");
    database db;
    db.dbconnect();

    dbmodel *model = new dbmodel();

    properties property;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("mymodel", model);
    engine.rootContext()->setContextObject(&property);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
