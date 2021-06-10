#include "gallerymodel.h"
#include "database.h"
#include <QtDebug>
#include <QImage>

GalleryModel::GalleryModel()
{
    this->updateModel();
}


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


