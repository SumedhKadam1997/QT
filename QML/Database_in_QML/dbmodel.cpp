#include "dbmodel.h"
#include "database.h"
#include <QtDebug>


dbmodel::dbmodel(QObject *parent):
    QSqlQueryModel(parent)
{
    this->updateModel();
}

QVariant dbmodel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> dbmodel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[IdRole] = "id";
        roles[FNameRole] = "fname";
        roles[LNameRole] = "lname";
        roles[EmailRole] = "email";
        roles[GenderRole] = "gender";
        roles[AgeRole] = "age";
        return roles;
}

void dbmodel::updateModel()
{
    this->setQuery("select * from members");
    qDebug() << "Model updated!";
}

int dbmodel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
