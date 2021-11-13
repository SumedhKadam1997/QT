#include "sqlmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

SqlModel::SqlModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel();
    this->totalValues();
}

void SqlModel::totalValues()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(rowid) FROM student");
    if(!query.exec()){
        qDebug() << "error retrieve date";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            remainder = query.value(0).toUInt();
            qDebug() << remainder;
        }
    }
}

QVariant SqlModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QVariant SqlModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("ID");
        } else if (section == 1) {
            return QString("Name");
        } else if (section == 2) {
            return QString("Email");
        } else if (section == 3) {
            return QString("DOB");
        } else if (section == 4) {
            return QString("House Number");
        } else if (section == 5) {
            return QString("Street Name");
        } else if (section == 6) {
            return QString("City");
        }  else if (section == 6) {
            return QString("City");
        }
    }
    return QVariant();
}

QHash<int, QByteArray> SqlModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "ROWID";
    roles[NameRole] = "name";
    roles[EmailRole] = "email";
    roles[DOBRole] = "dob";
    roles[HouseNumRole] = "house_number";
    roles[StreetNameRole] = "street_name";
    roles[CityRole] = "city";
    return roles;
}

//void SqlModel::fetchMore(const QModelIndex &parent)
//{
//    if (parent.isValid())
//        return;
//    int itemsToFetch = qMin(100, remainder);

//    if (itemsToFetch <= 0)
//        return;
////    beginRemoveRows(parent, first, last);
//    beginInsertRows(parent, 0, 10);
//    endInsertRows();
//    emit updateSignal();
//}

void SqlModel::updateModel()
{
    this->setQuery("SELECT student.rowid, name, email, dob, house_number, street_name, city FROM student JOIN address ON student.address_id = address.ROWID");
    qDebug() << "DB Model updated!";
}
