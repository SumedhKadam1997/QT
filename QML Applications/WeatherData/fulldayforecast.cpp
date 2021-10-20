#include "fulldayforecast.hpp"

FullDayForecast::FullDayForecast(QObject *parent) : QObject(parent)
{
    this->getHourlyWeatherData();
    connect(&WeatherNAM, &QNetworkAccessManager::finished, this, &FullDayForecast::processHourlyWeatherData);
}

void FullDayForecast::getHourlyWeatherData()
{
    WeatherNAM.get(QNetworkRequest(WeatherOnecallURL + LATLONGONECALL + EXCLUDE + UNIT + APPIDP));
}

void FullDayForecast::processHourlyWeatherData(QNetworkReply * reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        weatherJSON = QJsonDocument::fromJson(reply->readAll());

        QJsonObject weatherData = weatherJSON.object();
        QJsonValue weatherValue;
        QJsonValue weatherValue2;
        QJsonObject temporaryobj;
        QJsonObject temporaryobj2;
        QJsonArray weatherArray;
        double windSpeed;
        int windDirection;
        double temperature;
        QString cloudIcon;
        m_dayWeatherList.clear();
        if (weatherData.contains("hourly")) {
            weatherValue = weatherData.value(QStringLiteral("hourly"));
            weatherArray = weatherValue.toArray();
            for (int i = 0; i <= weatherArray.size(); ++i) {
                if (i == 0 || i == 5 || i == 10 || i == 18) {
                    weatherValue = weatherArray.at(i);
                    temporaryobj = weatherValue.toObject();
                    qDebug() << "----------------------";
                    weatherValue2 = temporaryobj.value("wind_speed");
                    windSpeed = weatherValue2.toDouble();
                    qDebug() << windSpeed;
                    weatherValue2 = temporaryobj.value("wind_deg");
                    windDirection = weatherValue2.toInt();
                    qDebug() << windDirection;
                    weatherValue2 = temporaryobj.value("weather");
                    temporaryobj2 = weatherValue2.toArray().at(0).toObject();
                    weatherValue2 = temporaryobj2.value("icon");
                    cloudIcon = weatherValue2.toString();
                    qDebug() << cloudIcon;
                    weatherValue2 = temporaryobj.value("temp");
                    temperature = weatherValue2.toDouble();
                    qDebug() << temperature;
                    m_dayWeatherList.append(new WeatherInfo(windSpeed, temperature, cloudIcon, windDirection));
                }
            }
        }
    }
}

const QList<WeatherInfo *> &FullDayForecast::dayWeatherList() const
{
    return m_dayWeatherList;
}

void FullDayForecast::setDayWeatherList(const QList<WeatherInfo *> &newDayWeatherList)
{
    if (m_dayWeatherList == newDayWeatherList)
        return;
    m_dayWeatherList = newDayWeatherList;
    emit dayWeatherListChanged();
}
