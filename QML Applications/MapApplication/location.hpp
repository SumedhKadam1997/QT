#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <QGeoCoordinate>
#include <QColor>
#include <QDebug>

class Location
{
    QString mName;
    QGeoCoordinate mlocation;
    QList<QGeoCoordinate> history;
    QColor mColor;
    int mAngle;

public:
    Location();

    QString name() const;
    void setName(const QString &);

    QGeoCoordinate location() const;
    void setLocation(const QGeoCoordinate &);

    QList<QGeoCoordinate> getHistory() const;
    void appendHistory(const QGeoCoordinate &);

    QColor color() const;
    void setColor(const QColor &);

    int angle() const;
    void setAngle(const int &);
};

#endif // LOCATION_HPP
