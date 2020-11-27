#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <properties.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Properties property;

    property.setFirstname("Sumedh");
    property.setLastname("Kadam");
    property.setUsername("UxoriousGhost");
    property.setAge(23);
    property.setGender("Male");

    QQmlApplicationEngine engine;

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
