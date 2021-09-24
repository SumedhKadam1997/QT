#include "location.hpp"

Location::Location()
{

}

QString Location::name() const
{
    return mName;
}

void Location::setName(const QString &name)
{
    mName = name;
}

QGeoCoordinate Location::location() const
{
    return mlocation;
}

void Location::setLocation(const QGeoCoordinate &location)
{
    if (location.isValid()) {
        appendHistory(location);
        mlocation = location;
    }
}

QList<QGeoCoordinate> Location::getHistory() const
{
    return history;
}

void Location::appendHistory(const QGeoCoordinate &location)
{
    history << location;
}

QColor Location::color() const
{
    return mColor;
}

void Location::setColor(const QColor &color)
{
    mColor = color;
}

int Location::angle() const
{
    return mAngle;
}

void Location::setAngle(const int &angle)
{
    mAngle = angle;
}
