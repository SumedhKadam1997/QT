#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
//#include "location.hpp"
//#include "locationmodel.hpp"
#include "assetlistmodel.hpp"
#include <QTimer>
#include <QSslSocket>


//int main(int argc, char *argv[])
//{
//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);
////    qmlRegisterType<LocationModel>("Location", 1, 0, "LocationModel");
////    qmlRegisterType<Location>("Location", 1, 0, "Location");

//    QQmlApplicationEngine engine;
////    engine.rootContext()->setContextProperty("loc", new Location());
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();
//}
#include <random>

struct TestStruct {
  QGeoCoordinate coord;
  int angle;
};
static TestStruct append_random_coordinate() {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::normal_distribution<> dist1(0, .1);
  std::uniform_int_distribution<> dist2(0, 360);
  return TestStruct{QGeoCoordinate(dist1(rng), dist1(rng)), dist2(rng)};
}

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  AssetListModel model;
  qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();

  QGeoCoordinate center(18.555921723127565, 73.88648464933829);
  model.createAsset(center, QColor("red"), "testing_name1");
  model.createAsset(center, QColor("blue"), "testing_name2");

  QGeoCoordinate pos1{center};
  QGeoCoordinate pos2{center};
  QQmlApplicationEngine engine;
  model.register_objects("assetmodel", "nodemodel", engine.rootContext());
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, [&model, &pos1, &pos2]() {
    TestStruct t1 = append_random_coordinate();
    pos1 = QGeoCoordinate{0.00001 + pos1.latitude(),
                          0.00001 + pos1.longitude()};
    model.addAsset(pos1, t1.angle, "testing_name1");
    TestStruct t2 = append_random_coordinate();
    pos2 = QGeoCoordinate{t2.coord.latitude() + pos2.latitude(),
                          t2.coord.longitude() + pos2.longitude()};
    model.addAsset(pos2, t2.angle, "testing_name2");
  });
  timer.start(1000);

  return app.exec();
}
