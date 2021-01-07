#include <QApplication>
#include <QQmlApplicationEngine>
#include <database.h>
#include <mainproperties.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QQmlContext>
#include <qml_screen_properties.h>
#include <grid_rect_properties.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qmlRegisterType<database>("Database",1 ,0,"Database");
    database db;
    db.dbconnect();

    mainproperties *prop = new mainproperties();
    qml_properties *qml_prop = new qml_properties();
    grid_rect_properties *grid_prop = new grid_rect_properties();

    grid_prop->setOee(1);
    grid_prop->setPerf(1);
    grid_prop->setAva(1);
    grid_prop->setQua(1);
    grid_prop->setTotal_count(1);
    grid_prop->setReject_count(1);
    grid_prop->setShift(1);
    grid_prop->setStop_time(1);
    grid_prop->setBreakdown_time(1);
    grid_prop->setRuntime(1);
    grid_prop->setActual_cycle(1);
    grid_prop->setIdeal_cycle(1);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("myProp", prop);
    engine.rootContext()->setContextProperty("myQmlProp", qml_prop);
    engine.rootContext()->setContextProperty("myGridProp", grid_prop);

    db.setoeeprop(prop);
    db.setperfprop(prop);
    db.setavaprop(prop);
    db.setquaprop(prop);
    db.setprodprop(prop);
    db.setrejprop(prop);
    db.setshiftprop(prop);
    db.setstopprop(prop);
    db.setbreakprop(prop);
    db.setrunprop(prop);
    db.setidealprop(prop);
    db.setactualprop(prop);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
