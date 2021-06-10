#ifndef PHOTOSMODEL_H
#define PHOTOSMODEL_H

#include <QSqlQueryModel>
#include <QObject>

class PhotosModel : public QSqlQueryModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        PhotoNameRole,
        EmailRole
    };

    explicit PhotosModel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString query);
    int getId(int row);
};

#endif // PHOTOSMODEL_H
