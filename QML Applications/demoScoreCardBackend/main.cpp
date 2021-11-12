#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Scorecard/sources/scoreinput.hpp"
#include "Scorecard/sources/player.hpp"
#include "Scorecard/sources/scorecard.hpp"
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

//    qmlRegisterType<ScoreInput>("Score", 1, 0, "Score");
//    qmlRegisterType<Player>("Player", 1, 0, "Player");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("scorecard"), new ScoreCard());
    engine.rootContext()->setContextProperty(QStringLiteral("scoreInput"), new ScoreInput());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
