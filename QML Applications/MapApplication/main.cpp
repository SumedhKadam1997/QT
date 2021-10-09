#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "assetlistmodel.hpp"
#include "navbackend.hpp"
#include "database.hpp"
#include "navbackendjson.hpp"
#include <QTimer>
#include <QSslSocket>

QString india = QString(QLocale::India);
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    AssetListModel model;
    Database db;
    db.getBasePathfromDB();
    NavBackendJSON navJSON;
    navJSON.getBasePathfromJSON("basePath");
    navJSON.getBasePathfromJSON("path1");

    //    NavBackend nav;

    QGeoCoordinate center(18.555921723127565, 73.88648464933829);
    model.createAsset(center, QColor("red"), "buggy");

    QGeoCoordinate pos1{center};
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("navJSON", & navJSON);
    engine.rootContext()->setContextProperty("db", &db);
    engine.rootContext()->setContextProperty("nav", new NavBackend());
    engine.rootContext()->setContextProperty("assetmodel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&model, &pos1]() {
        pos1 = QGeoCoordinate{0.00001 + pos1.latitude(),
                0.00001 + pos1.longitude()};
        model.addAsset(pos1, 50, "buggy");
    });
    //  timer.start(1000);

    return app.exec();
}
