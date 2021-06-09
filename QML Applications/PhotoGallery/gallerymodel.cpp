#include "gallerymodel.h"
#include "database.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QBuffer>
#include <QImage>
#include <QIODevice>
#include <QPainter>

GalleryModel::GalleryModel()
{
    this->updateModel();
}

//QVariant GalleryModel::data(const QModelIndex &index, int role) const
//{
//    QVariant value = QSqlQueryModel::data(index, role);
//    qDebug()<<"Role Assigned"<<role<<"And QVariant Type"<< value;
//    qDebug() << index.column();
//    if(/*role == Qt::DecorationRole ||  */index.column() == 0) {
//        QString photo("data:image/png;base64,");
//        QByteArray outByteArray;
//        outByteArray = record(index.row()).value(1).toByteArray();
//        photo.append(QString::fromLatin1(outByteArray.toBase64().data()));
//        return photo;
//    } else {
//    int columnId = role - Qt::UserRole - 1;
//    QModelIndex modelIndex = this->index(index.row(), columnId);

//    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
//    }
//}

QVariant GalleryModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    int columnIdx = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnIdx);
    value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    if(roleNames().value(role) == "filename") {
        qDebug() << roleNames().value(role);
        //        return QImage::fromData(value.toByteArray());
        QByteArray outByteArray;
        QString photo("data:image/png;base64,");
        outByteArray = value.toByteArray();
        photo.append(QString::fromLatin1(outByteArray.toBase64().data()));
        return photo;
    } else {
        return value;
    }
}

//QVariant GalleryModel::data(const QModelIndex &index, int role) const
//{
//    int columnId = role - Qt::UserRole - 1;
//    qDebug() << "Column ID : " << columnId;
//    qDebug() << index.column();
//    QString photo("data:image/png;base64,");
//    QByteArray outByteArray;
//    outByteArray = record(index.row()).value(0).toByteArray();
//    photo.append(QString::fromLatin1(outByteArray.toBase64().data()));
//    return photo;
//    QModelIndex modelIndex = this->index(index.row(), columnId);

////    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);

//}

QHash<int, QByteArray> GalleryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[PhotoRole] = "photo";
    roles[NameRole] = "filename";
    roles[DateRole] = "date";
    return roles;
}

void GalleryModel::updateModel()
{
    //        this->setQuery("SELECT photo FROM photos");
    this->setQuery("SELECT id, filename, photo, date FROM photos ORDER BY id DESC");
    qDebug() << "Photos Model updated!";
}


