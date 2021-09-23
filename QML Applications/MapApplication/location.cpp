#include "location.hpp"

Location::Location(QObject *parent) : QObject(parent), m_coordinate{0, 0} {

}

double Location::longitude() const {
    return m_coordinate.longitude();
}

void Location::setLongitude(double longitude) {
    if (m_coordinate.longitude() == longitude)
        return;
    m_coordinate.setLongitude(longitude);
    Q_EMIT longitudeChanged();
}

double Location::latitude() const {
    return m_coordinate.latitude();
}

void Location::setLatitude(double latitude) {
    if (m_coordinate.latitude() == latitude)
        return;
    m_coordinate.setLatitude(latitude);
    Q_EMIT latitudeChanged();
}

QGeoCoordinate Location::coordinate() const {
    return m_coordinate;
}

void Location::setCoordinate(const QGeoCoordinate &coordinate) {
    if (coordinate == m_coordinate)
        return;
    m_coordinate = coordinate;
    Q_EMIT coordinateChanged();
}

