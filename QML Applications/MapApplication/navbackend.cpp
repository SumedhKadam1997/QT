#include "navbackend.hpp"

NavBackend::NavBackend(QObject *parent) : QObject(parent)
{
    m_path.append(QVariant::fromValue(QGeoCoordinate(18.553925347073736, 73.88799441883614)));
    m_path.append(QVariant::fromValue(QGeoCoordinate(18.554925347073736, 73.88899441883614)));
    m_path.append(QVariant::fromValue(QGeoCoordinate(18.553886123883544, 73.8856200551377)));
    m_path.append(QVariant::fromValue(QGeoCoordinate(18.554803765002095, 73.88614125106714)));
    m_path.append(QVariant::fromValue(QGeoCoordinate(18.555784129677242, 73.8843211442432)));
}
const QVariantList &NavBackend::path() const
{
    return m_path;
}

void NavBackend::setPath(const QVariantList &newPath)
{
    if (m_path == newPath)
        return;
    m_path = newPath;
    emit pathChanged();
}
