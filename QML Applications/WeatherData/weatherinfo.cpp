#include "weatherinfo.hpp"

WeatherInfo::WeatherInfo(QObject *parent) : QObject(parent)
{
    connect(&WeatherNAM, &QNetworkAccessManager::finished, this, &WeatherInfo::processWeatherData);
}

void WeatherInfo::getWeatherData()
{
    //    WeatherNAM.get(QNetworkRequest(WeatherURL + CURRENTWEATHER + "Pune"+ UNIT + APPIDP));
    WeatherNAM.get(QNetworkRequest(WeatherURL + LATLONG + UNIT + APPIDP));
    //    WeatherNAM.get(QNetworkRequest(WeatherURL + CITYFORECAST + "Pune" + UNIT + APPIDP));
    //    WeatherNAM.get(QNetworkRequest(WeatherURL + DAILYFORECAST + "Pune" + UNIT + APPIDQ));
}

void WeatherInfo::processWeatherData(QNetworkReply * reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        weatherJSON = QJsonDocument::fromJson(reply->readAll());

        QJsonObject weatherData = weatherJSON.object();

        qDebug() << weatherJSON;
        setCityName(weatherData.value(QStringLiteral("name")).toString());
        qDebug() << "City Name" << cityName();

        QJsonObject temporaryobj;
        QJsonValue  weatherValue;

        double visibile = weatherData.value(QStringLiteral("visibility")).toDouble() / 1000;

        setVisibility(QString::number(visibile));
        qDebug() << "Visibility" << visibility();
        if (weatherData.contains(QStringLiteral("sys"))) {
            weatherValue = weatherData.value(QStringLiteral("sys"));
            temporaryobj = weatherValue.toObject();

            weatherValue = temporaryobj.value(QStringLiteral("sunrise"));
            timestamp.setTime_t(weatherValue.toInt());
            setSunrise(timestamp.time().toString());

            qDebug() << "Sunrise" << sunrise();

            weatherValue = temporaryobj.value(QStringLiteral("sunset"));
            timestamp.setTime_t(weatherValue.toInt());
            setSunset(timestamp.time().toString());

            qDebug() << "Sunset" << sunset();
        }

        if (weatherData.contains("wind")) {
            weatherValue = weatherData.value("wind");
            temporaryobj = weatherValue.toObject();

            weatherValue = temporaryobj.value("speed");
            setWindSpeed(QString::number(weatherValue.toDouble()));

            qDebug() << "Wind Speed" << windSpeed();

            weatherValue = temporaryobj.value("deg");
            setWindDirection(QString::number(weatherValue.toDouble()));
            qDebug() << "Wind Direction" << windDirection();
        }

        if (weatherData.contains(QStringLiteral("weather"))) {
            weatherValue = weatherData.value(QStringLiteral("weather"));
            weatherValue = weatherValue.toArray().at(0);
            temporaryobj = weatherValue.toObject();

            weatherValue = temporaryobj.value(QStringLiteral("description"));
            setCloudDesc(weatherValue.toString());
            qDebug() << "Cloud Desc" << cloudDesc();

            weatherValue = temporaryobj.value(QStringLiteral("icon"));
            setCloudIcon(weatherValue.toString());
            qDebug() << "CLoud Icon" << cloudIcon();
        }

        if (weatherData.contains(QStringLiteral("main"))) {
            weatherValue = weatherData.value(QStringLiteral("main"));
            temporaryobj = weatherValue.toObject();

            weatherValue = temporaryobj.value(QStringLiteral("temp"));
            setCurrentTemp(QString::number(weatherValue.toDouble()));
            qDebug() << "Current Temp" << currentTemp();

            weatherValue = temporaryobj.value(QStringLiteral("temp_min"));
            setMinTemp(QString::number(weatherValue.toDouble()));
            qDebug() << "Min Temp" << minTemp();

            weatherValue = temporaryobj.value(QStringLiteral("temp_max"));
            setMaxTemp(QString::number(weatherValue.toDouble()));
            qDebug() << "Max Temp" << maxTemp();

            weatherValue = temporaryobj.value(QStringLiteral("feels_like"));
            setFeelsLike(QString::number(weatherValue.toDouble()));
            qDebug() << "Feels Like" << feelsLike();

            weatherValue = temporaryobj.value(QStringLiteral("humidity"));
            setHumidity(QString::number(weatherValue.toInt()));
            qDebug() << "Humidity" << humidity();

            weatherValue = temporaryobj.value(QStringLiteral("pressure"));
            setPressure(QString::number(weatherValue.toInt()));
            qDebug() << "Pressure" << pressure();
        }
    }
}

const QString &WeatherInfo::currentTemp() const
{
    return m_currentTemp;
}

void WeatherInfo::setCurrentTemp(const QString &newCurrentTemp)
{
    if (m_currentTemp == newCurrentTemp)
        return;
    m_currentTemp = newCurrentTemp;
    emit currentTempChanged();
}

const QString &WeatherInfo::maxTemp() const
{
    return m_maxTemp;
}

void WeatherInfo::setMaxTemp(const QString &newMaxTemp)
{
    if (m_maxTemp == newMaxTemp)
        return;
    m_maxTemp = newMaxTemp;
    emit maxTempChanged();
}

const QString &WeatherInfo::minTemp() const
{
    return m_minTemp;
}

void WeatherInfo::setMinTemp(const QString &newMinTemp)
{
    if (m_minTemp == newMinTemp)
        return;
    m_minTemp = newMinTemp;
    emit minTempChanged();
}

const QString &WeatherInfo::feelsLike() const
{
    return m_feelsLike;
}

void WeatherInfo::setFeelsLike(const QString &newFeelsLike)
{
    if (m_feelsLike == newFeelsLike)
        return;
    m_feelsLike = newFeelsLike;
    emit feelsLikeChanged();
}

const QString &WeatherInfo::windSpeed() const
{
    return m_windSpeed;
}

void WeatherInfo::setWindSpeed(const QString &newWindSpeed)
{
    if (m_windSpeed == newWindSpeed)
        return;
    m_windSpeed = newWindSpeed;
    emit windSpeedChanged();
}

const QString &WeatherInfo::humidity() const
{
    return m_humidity;
}

void WeatherInfo::setHumidity(const QString &newHumidity)
{
    if (m_humidity == newHumidity)
        return;
    m_humidity = newHumidity;
    emit humidityChanged();
}

const QString &WeatherInfo::visibility() const
{
    return m_visibility;
}

void WeatherInfo::setVisibility(const QString &newVisibility)
{
    if (m_visibility == newVisibility)
        return;
    m_visibility = newVisibility;
    emit visibilityChanged();
}

const QString &WeatherInfo::pressure() const
{
    return m_pressure;
}

void WeatherInfo::setPressure(const QString &newPressure)
{
    if (m_pressure == newPressure)
        return;
    m_pressure = newPressure;
    emit pressureChanged();
}

const QString &WeatherInfo::cityName() const
{
    return m_cityName;
}

void WeatherInfo::setCityName(const QString &newCityName)
{
    if (m_cityName == newCityName)
        return;
    m_cityName = newCityName;
    emit cityNameChanged();
}

const QString &WeatherInfo::cloudIcon() const
{
    return m_cloudIcon;
}

void WeatherInfo::setCloudIcon(const QString &newCloudIcon)
{
    if (m_cloudIcon == newCloudIcon)
        return;
    m_cloudIcon = newCloudIcon;
    emit cloudIconChanged();
}

const QString &WeatherInfo::cloudDesc() const
{
    return m_cloudDesc;
}

void WeatherInfo::setCloudDesc(const QString &newCloudDesc)
{
    if (m_cloudDesc == newCloudDesc)
        return;
    m_cloudDesc = newCloudDesc;
    emit cloudDescChanged();
}

const QString &WeatherInfo::windDirection() const
{
    return m_windDirection;
}

void WeatherInfo::setWindDirection(const QString &newWindDirection)
{
    if (m_windDirection == newWindDirection)
        return;
    m_windDirection = newWindDirection;
    emit windDirectionChanged();
}

const QString &WeatherInfo::sunrise() const
{
    return m_sunrise;
}

void WeatherInfo::setSunrise(const QString &newSunrise)
{
    if (m_sunrise == newSunrise)
        return;
    m_sunrise = newSunrise;
    emit sunriseChanged();
}

const QString &WeatherInfo::sunset() const
{
    return m_sunset;
}

void WeatherInfo::setSunset(const QString &newSunset)
{
    if (m_sunset == newSunset)
        return;
    m_sunset = newSunset;
    emit sunsetChanged();
}
