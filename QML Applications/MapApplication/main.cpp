#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "assetlistmodel.hpp"
#include <QTimer>
#include <QSslSocket>
//#include <random>


int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  AssetListModel model;

  qDebug() << "Device supports OpenSSL: " << QSslSocket::supportsSsl();

  QGeoCoordinate center(18.555921723127565, 73.88648464933829);
  model.createAsset(center, QColor("red"), "testing_name1");

  QGeoCoordinate pos1{center};
  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("assetmodel", &model);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, [&model, &pos1]() {
    pos1 = QGeoCoordinate{0.00001 + pos1.latitude(),
                          0.00001 + pos1.longitude()};
    model.addAsset(pos1, 50, "testing_name1");
  });
//  timer.start(1000);

  return app.exec();
}
