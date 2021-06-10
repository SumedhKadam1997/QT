#include "photosmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

PhotosModel::PhotosModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant PhotosModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> PhotosModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[PhotoNameRole] = "photoName";
    roles[EmailRole] = "email";
    return roles;
}

void PhotosModel::updateModel(QString email)
{
    this->setQuery("SELECT * FROM photoData WHERE email = '" + email + "' ORDER BY id DESC");
    qDebug() << "PhotoData Model updated! NULL";
}

int PhotosModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
