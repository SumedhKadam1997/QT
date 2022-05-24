#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "candlestick.hpp"
#include "candlestickseries.hpp"
#include "datagenerator.h"
#include "lineseries.hpp"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QApplication app(argc, argv);

  qmlRegisterType<LineSeries>("verolt.charts", 1, 0, "Lineseries");
  qmlRegisterType<CandleStick>("verolt.charts", 1, 0, "CandleStick");
  qmlRegisterType<CandleStickSeries>("verolt.charts", 1, 0,
                                     "CandleStickSeries");

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
