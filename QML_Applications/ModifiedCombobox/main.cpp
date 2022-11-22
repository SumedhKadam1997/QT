#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "myclass.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  MyClass myClass;
  engine.rootContext()->setContextProperty("myClass", &myClass);
  const QUrl url(u"qrc:/ModifiedCombobox/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
