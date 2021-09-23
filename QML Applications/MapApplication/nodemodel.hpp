#ifndef NODEMODEL_HPP
#define NODEMODEL_HPP

#include "assetlistmodel.hpp"
#include <QAbstractListModel>
#include <QDebug>

class NodeModel : public QAbstractListModel {
  Q_OBJECT
public:
  using QAbstractListModel::QAbstractListModel;
  enum AirportsRoles { NodeRole = Qt::UserRole + 100, AngleRole };
  void appendNode(const QGeoCoordinate &coord, int angle) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mData << QVariant::fromValue(coord);
    mAngles << angle;
    endInsertRows();
  }
  int rowCount(const QModelIndex &parent = QModelIndex()) const override {
    Q_UNUSED(parent)
    return mData.count();
  }
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override {
    if (!index.isValid())
      return QModelIndex();
    if (index.row() >= 0 && index.row() < rowCount()) {
      if (role == NodeRole) {
        return mData[index.row()];
      } else if (role == AngleRole) {
        return mAngles[index.row()];
      }
    }
    return QModelIndex();
  }
  QHash<int, QByteArray> roleNames() const override {
    QHash<int, QByteArray> roles;
    roles[NodeRole] = "nodeData";
    roles[AngleRole] = "angleData";
    return roles;
  }

private:
  QVariantList mData;
  QVector<int> mAngles;
};

#endif // NODEMODEL_HPP
