#ifndef LOCATIONLISTMODEL_HPP
#define LOCATIONLISTMODEL_HPP

#include <QAbstractListModel>
#include <QObject>
#include "location.hpp"


struct Data {
    QGeoCoordinate coord;
    int angle;
};
Q_DECLARE_METATYPE(Data)

class LocationListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Location> mLocations;
public:
    explicit LocationListModel(QObject *parent = nullptr);

    enum GeoCoordinateRoles {
        NameRole = Qt::UserRole + 1,
        LocationRole,
        HistoryRole,
        AngleRole,
        ColorRole
    };

    bool addLocation(const QGeoCoordinate &, int angle, const QString &);
    bool createLocation(const QGeoCoordinate &, const QColor &, const QString &);

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &, const QVariant &, int role) override;
};

#endif // LOCATIONLISTMODEL_HPP
