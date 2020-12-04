#ifndef DBMODEL_H
#define DBMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include "database.h"

class dbmodel : public QSqlQueryModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        FNameRole,
        LNameRole,
        EmailRole,
        GenderRole,
        AgeRole
    };

    explicit dbmodel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;

public slots:
    void updateModel();
    int getId(int row);
};

#endif // DBMODEL_H
