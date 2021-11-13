#include "studentsmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


StudentsModel::StudentsModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant StudentsModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> StudentsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[IdRole] = "id";
        roles[NameRole] = "name";
        roles[AgeRole] = "age";
        roles[EmailRole] = "email";
        roles[PasswordRole] = "password";
        roles[GenderRole] = "gender";
        roles[RoleRole] = "role";
        roles[DepartmentRole] = "department";
        roles[SemesterRole] = "semester";

        return roles;
}


void StudentsModel::updateModel(QString studentname)
{
    if(studentname == "") {
        this->setQuery("SELECT * FROM member WHERE role = 'student'");
        qDebug() << "Students Model updated! NULL";
    } else {
        this->setQuery("SELECT * FROM member WHERE role = 'student' AND name LIKE '" + studentname + "%'");
        qDebug() << "Students Model updated!";
    }
}

int StudentsModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
