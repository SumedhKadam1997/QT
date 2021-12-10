#ifndef WEATHERINFO_HPP
#define WEATHERINFO_HPP

#include <QObject>
#include <QtNetwork>
#include <QJsonDocument>
#include <QTimer>
#include <QDate>
#include <QDateTime>
#include <QDebug>

const QString WeatherURL = QStringLiteral("http://dataservice.accuweather.com/currentconditions/v1/204848?apikey=GAkCoyQccRrFtMk1iSoFYFGM4Fpl0GUT&details=true");
const QString WeatherOnecallURL = QStringLiteral("https://api.openweathermap.org/data/2.5/onecall");

#define CURRENTWEATHER "weather?q="
#define LATLONG        "weather?lat=18.555432984399253&lon=73.88700187041067"
#define LATLONGONECALL "?lat=18.520051273199986&lon=73.8593222175231"
#define CITYFORECAST   "forecast?q="
#define DAILYFORECAST  "forecast/daily?q="
#define EXCLUDE        "&exclude=current,minutely,daily,alerts"
#define FORCASTDAYS    "&cnt=24"
#define UNIT           "&units=metric"
#define APPIDP         "&appid=425b1230718c386871a63f29d75f1907"  // Presonal API Key
#define APPIDQ         "&appid=36496bad1955bf3365448965a42b9eac"  // QT's API Key

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
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)

    QNetworkAccessManager WeatherNAM;
    QJsonDocument weatherJSON;
    QDateTime timestamp;
    QTimer *timer;

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

    QString m_time;

public:
    explicit WeatherInfo(QObject *parent = nullptr);
    WeatherInfo(const QString &time, const QString & windSpeed, const double & temp, const QString & cloudIcon, const int & windDirection);

    void getWeatherData();
    void processWeatherData(QNetworkReply *);

    const QString &currentTemp() const;
    void setCurrentTemp(const QString &);

    const QString &maxTemp() const;
    void setMaxTemp(const QString &);

    const QString &minTemp() const;
    void setMinTemp(const QString &);

    const QString &feelsLike() const;
    void setFeelsLike(const QString &);

    const QString &windSpeed() const;
    void setWindSpeed(const QString &);

    const QString &humidity() const;
    void setHumidity(const QString &);

    const QString &visibility() const;
    void setVisibility(const QString &);

    const QString &pressure() const;
    void setPressure(const QString &);

    const QString &cityName() const;
    void setCityName(const QString &);

    const QString &cloudIcon() const;
    void setCloudIcon(const QString &);

    const QString &cloudDesc() const;
    void setCloudDesc(const QString &);

    const QString &windDirection() const;
    void setWindDirection(const QString &);

    const QString &sunrise() const;
    void setSunrise(const QString &);

    const QString &sunset() const;
    void setSunset(const QString &);

    const QString &time() const;
    void setTime(const QString &);

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
    void timeChanged();
};

#endif // WEATHERINFO_HPP
