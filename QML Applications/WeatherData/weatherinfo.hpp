#ifndef WEATHERINFO_HPP
#define WEATHERINFO_HPP

#include <QObject>
#include <QtNetwork>
#include <QJsonDocument>
#include <QDate>
#include <QDateTime>
#include <QDebug>

/* Open Weather API URL for Forecast data */
const QString WeatherURL = "http://api.openweathermap.org/data/2.5/";

/* Parameters for Weather URL */
#define CURRENTWEATHER "weather?q="
#define LATLONG        "weather?lat=18.555432984399253&lon=73.88700187041067"
#define CITYFORECAST   "forecast?q="
#define DAILYFORECAST  "forecast/daily?q="
#define FORCASTDAYS    "&cnt=5"
#define UNIT           "&units=metric"
#define APPIDP         "&appid=425b1230718c386871a63f29d75f1907"
#define APPIDQ         "&appid=36496bad1955bf3365448965a42b9eac"

class WeatherInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cityName READ cityName WRITE setCityName NOTIFY cityNameChanged)
    Q_PROPERTY(QString currentTemp READ currentTemp WRITE setCurrentTemp NOTIFY currentTempChanged)
    Q_PROPERTY(QString maxTemp READ maxTemp WRITE setMaxTemp NOTIFY maxTempChanged)
    Q_PROPERTY(QString minTemp READ minTemp WRITE setMinTemp NOTIFY minTempChanged)
    Q_PROPERTY(QString feelsLike READ feelsLike WRITE setFeelsLike NOTIFY feelsLikeChanged)
    Q_PROPERTY(QString windSpeed READ windSpeed WRITE setWindSpeed NOTIFY windSpeedChanged)
    Q_PROPERTY(QString windDirection READ windDirection WRITE setWindDirection NOTIFY windDirectionChanged)
    Q_PROPERTY(QString humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(QString visibility READ visibility WRITE setVisibility NOTIFY visibilityChanged)
    Q_PROPERTY(QString pressure READ pressure WRITE setPressure NOTIFY pressureChanged)
    Q_PROPERTY(QString cloudIcon READ cloudIcon WRITE setCloudIcon NOTIFY cloudIconChanged)
    Q_PROPERTY(QString cloudDesc READ cloudDesc WRITE setCloudDesc NOTIFY cloudDescChanged)
    Q_PROPERTY(QString sunrise READ sunrise WRITE setSunrise NOTIFY sunriseChanged)
    Q_PROPERTY(QString sunset READ sunset WRITE setSunset NOTIFY sunsetChanged)
    QNetworkAccessManager WeatherNAM;
    QJsonDocument weatherJSON;
    QDateTime timestamp;

    QString m_currentTemp;
    QString m_maxTemp;
    QString m_minTemp;
    QString m_feelsLike;
    QString m_windSpeed;
    QString m_humidity;
    QString m_visibility;
    QString m_pressure;
    QString m_cityName;
    QString m_cloudIcon;
    QString m_cloudDesc;
    QString m_windDirection;

    QString m_sunrise;

    QString m_sunset;

public:
    explicit WeatherInfo(QObject *parent = nullptr);
    void getWeatherData();
    void processWeatherData(QNetworkReply *);

    const QString &currentTemp() const;
    void setCurrentTemp(const QString &newCurrentTemp);

    const QString &maxTemp() const;
    void setMaxTemp(const QString &newMaxTemp);

    const QString &minTemp() const;
    void setMinTemp(const QString &newMinTemp);

    const QString &feelsLike() const;
    void setFeelsLike(const QString &newFeelsLike);

    const QString &windSpeed() const;
    void setWindSpeed(const QString &newWindSpeed);

    const QString &humidity() const;
    void setHumidity(const QString &newHumidity);

    const QString &visibility() const;
    void setVisibility(const QString &newVisibility);

    const QString &pressure() const;
    void setPressure(const QString &newPressure);

    const QString &cityName() const;
    void setCityName(const QString &newCityName);

    const QString &cloudIcon() const;
    void setCloudIcon(const QString &newCloudIcon);

    const QString &cloudDesc() const;
    void setCloudDesc(const QString &newCloudDesc);

    const QString &windDirection() const;
    void setWindDirection(const QString &newWindDirection);

    const QString &sunrise() const;
    void setSunrise(const QString &newSunrise);

    const QString &sunset() const;
    void setSunset(const QString &newSunset);

signals:
    void currentTempChanged();
    void maxTempChanged();
    void minTempChanged();
    void feelsLikeChanged();
    void windSpeedChanged();
    void humidityChanged();
    void visibilityChanged();
    void pressureChanged();
    void cityNameChanged();
    void cloudIconChanged();
    void cloudDescChanged();
    void windDirectionChanged();
    void sunriseChanged();
    void sunsetChanged();
};

#endif // WEATHERINFO_HPP
