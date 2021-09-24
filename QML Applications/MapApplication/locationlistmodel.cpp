#include "locationlistmodel.hpp"

LocationListModel::LocationListModel(QObject *parent) : QAbstractListModel(parent)
{

}

bool LocationListModel::addLocation(const QGeoCoordinate &coord, int angle, const QString &name)
{
    auto it =
            std::find_if(mLocations.begin(), mLocations.end(),
                         [&](Location const &obj) { return obj.name() == name; });
    if (it != mLocations.end()) {
        // append
        int row = it - mLocations.begin();
        QModelIndex ix = index(row);
        //      QGeoCoordinate c = ix.data(AssetRole).value<QGeoCoordinate>();
        //      int a = ix.data(AngleRole).toInt();
        Data data{coord, angle};
        bool result = setData(ix, QVariant::fromValue(data), LocationRole);
        //      if (result)
        //        model->appendNode(c, a);
        qDebug() << "Location Added";
        return result;
    }
    return false;
}

bool LocationListModel::createLocation(const QGeoCoordinate &coord, const QColor &color, const QString &name)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    Location loc;
    loc.setName(name);
    loc.setLocation(coord);
    loc.setColor(color);
    mLocations << loc;
    endInsertRows();
    return true;
}

int LocationListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mLocations.count();
}

QVariant LocationListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= 0 && index.row() < rowCount()) {
        const Location &it = mLocations[index.row()];
        if (role == NameRole)
            return it.name();
        else if (role == LocationRole)
            return QVariant::fromValue(it.location());
        else if (role == HistoryRole) {
            QVariantList history_list;
            QList<QGeoCoordinate> coords = it.getHistory();
            for (const QGeoCoordinate &coord : coords) {
                history_list << QVariant::fromValue(coord);
            }
            history_list << QVariant::fromValue(it.location());
            return history_list;
        } else if (role == ColorRole) {
            return it.color();
        } else if (role == AngleRole) {
            return it.angle();
        }
    }
    return QVariant();
}

QHash<int, QByteArray> LocationListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "nameData";
    roles[LocationRole] = "locationData";
    roles[HistoryRole] = "historyData";
    roles[AngleRole] = "angleData";
    roles[ColorRole] = "colorData";
    return roles;
}

bool LocationListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    if (index.row() >= 0 && index.row() < rowCount()) {
        if (role == LocationRole) {
            const Data &data = value.value<Data>();
            QGeoCoordinate newLoc(data.coord);
            mLocations[index.row()].setLocation(newLoc);
            mLocations[index.row()].setAngle(data.angle);
            emit dataChanged(index, index, QVector<int>{LocationRole});
            return true;
        }
    }
    return false;
}
