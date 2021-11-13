#ifndef FULLDAYFORECAST_HPP
#define FULLDAYFORECAST_HPP

#include <QObject>
#include <QtNetwork>
#include <QJsonDocument>
#include <QTimer>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include "weatherinfo.hpp"

class FullDayForecast : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<WeatherInfo *> dayWeatherList READ dayWeatherList WRITE setDayWeatherList NOTIFY dayWeatherListChanged)
    QNetworkAccessManager WeatherNAM;
    QJsonDocument weatherJSON;
    QList<WeatherInfo *> m_dayWeatherList;

public:
    explicit FullDayForecast(QObject *parent = nullptr);
    void getHourlyWeatherData();
    void processHourlyWeatherData(QNetworkReply *);

    const QList<WeatherInfo *> &dayWeatherList() const;
    void setDayWeatherList(const QList<WeatherInfo *> &newDayWeatherList);

signals:

    void dayWeatherListChanged();
};

#endif // FULLDAYFORECAST_HPP
