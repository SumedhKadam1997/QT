#ifndef SQLMODEL_H
#define SQLMODEL_H

#include <QSqlQueryModel>
#include <QObject>

class SqlModel : public QSqlQueryModel
{
    Q_OBJECT

    int remainder;
public:
    explicit SqlModel(QObject *parent = 0);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        EmailRole,
        DOBRole,
        HouseNumRole,
        StreetNameRole,
        CityRole
    };

    void totalValues();
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

protected:

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

public slots:

    void updateModel();
};

#endif // SQLMODEL_H
