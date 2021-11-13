#include "librariansmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


LibrariansModel::LibrariansModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant LibrariansModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> LibrariansModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[IdRole] = "id";
        roles[NameRole] = "name";
        roles[AgeRole] = "age";
        roles[EmailRole] = "email";
        roles[PasswordRole] = "password";
        roles[GenderRole] = "gender";

        return roles;
}


void LibrariansModel::updateModel(QString name)
{
    if(name == "") {
        this->setQuery("SELECT id, name, age, email, password, gender FROM member WHERE role = 'librarian'");
        qDebug() << "Librarians Model updated! NULL";
    } else {
        this->setQuery("SELECT id, name, age, email, password, gender FROM member WHERE role = 'librarian' AND name LIKE '" + name + "%'");
        qDebug() << "Librarians Model updated!";
    }
}

int LibrariansModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
