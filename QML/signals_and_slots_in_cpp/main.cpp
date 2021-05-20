#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "my_class.h"
#include "my_other_class.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
//These pionters are of classes derived from abstract classes
    my_derived_class * myderivedclass = new my_derived_class();
    my_other_derived_class * myotherderivedclass = new my_other_derived_class();
//connect signal from myclass to slot of myotherclass
    QObject::connect(myderivedclass, &my_derived_class::mysignal, myotherderivedclass, &my_other_derived_class::func);
    myderivedclass->emit_signal();
    QObject::disconnect(myderivedclass, &my_derived_class::mysignal, myotherderivedclass, &my_other_derived_class::func);
    myderivedclass->emit_signal();
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}

