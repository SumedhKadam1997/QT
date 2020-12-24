#include <QApplication>
#include <QQmlApplicationEngine>
#include <database.h>
#include <mainproperties.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qmlRegisterType<database>("Database",1 ,0,"Database");
    database db;
    db.dbconnect();

    mainproperties *prop = new mainproperties();


    QQmlApplicationEngine engine;
//    QQmlContext *context = new QQmlContext(engine.rootContext());
//    context->setContextProperty("myProp", prop);


    engine.rootContext()->setContextProperty("myProp", prop);

    db.setprodprop(prop);
    db.setrejprop(prop);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
