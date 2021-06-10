#ifndef GALLERYMODEL_H
#define GALLERYMODEL_H

#include <QSqlQueryModel>
#include <QObject>
#include <QVariant>

class GalleryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    GalleryModel();

    enum Roles {
        IdRole = Qt::UserRole + 1,
        PhotoRole,
        NameRole,
        DateRole
    };
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;

public slots:
    void updateModel();
};

#endif // GALLERYMODEL_H
