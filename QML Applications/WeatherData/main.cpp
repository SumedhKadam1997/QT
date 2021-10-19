#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "weatherinfo.hpp"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    WeatherInfo weather;
    weather.getWeatherData();
//    qDebug() << "Sunrise : " << weather.epochToHumanReadableTime(1634605161);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
//    qDebug() << weather.cityName();
//    qDebug() << weather.sunrise();
//    qDebug() << weather.sunset();
//    qDebug() << weather.cloudDesc();
//    qDebug() << weather.cloudIcon();
//    qDebug() << weather.currentTemp();
//    qDebug() << weather.feelsLike();
//    qDebug() << weather.humidity();
//    qDebug() << weather.maxTemp();
//    qDebug() << weather.minTemp();
//    qDebug() << weather.pressure();
    engine.load(url);

    return app.exec();
}
