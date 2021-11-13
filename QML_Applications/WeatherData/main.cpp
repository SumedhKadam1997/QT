#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "weatherinfo.hpp"
#include "fulldayforecast.hpp"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qmlRegisterType<WeatherInfo>("WeatherInfo", 1, 0, "WeatherInfo");
    qmlRegisterType<FullDayForecast>("ForecastWeather", 1, 0, "ForecastWeather");

    QGuiApplication app(argc, argv);

//    FullDayForecast weather;
//    weather.getHourlyWeatherData();

//    WeatherInfo weather;
//    weather.getWeatherData();

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
