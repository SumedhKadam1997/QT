#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <QGeoCoordinate>
#include <QObject>

class Location : public QObject {
  Q_OBJECT
  Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
  Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
  Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
public:
  Location(QObject *parent = 0);

  Q_SIGNAL void longitudeChanged();
  Q_SIGNAL void latitudeChanged();
  Q_SIGNAL void coordinateChanged();

  double longitude() const;
  void setLongitude(double longitude);

  double latitude() const;
  void setLatitude(double latitude);

  QGeoCoordinate coordinate() const;
  void setCoordinate(const QGeoCoordinate &coordinate);

private:
  QGeoCoordinate m_coordinate;
};

#endif // LOCATION_HPP
