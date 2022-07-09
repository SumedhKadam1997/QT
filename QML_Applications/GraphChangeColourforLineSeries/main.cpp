#include "datagenerator.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  DataGenerator dg;

  engine.rootContext()->setContextProperty("dg", &dg);
  const QUrl url(u"qrc:/GraphChangeColourforLineSeries/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
