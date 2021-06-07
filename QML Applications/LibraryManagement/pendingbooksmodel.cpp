#include "pendingbooksmodel.h"
#include "loginproperties.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


pendingBooksModel::pendingBooksModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant pendingBooksModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> pendingBooksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[EmailRole] = "student_email";
    return roles;
}

void pendingBooksModel::updateModel(QString bookname)
{
    QString email = loginProperties::getInstance()->MyEmail();
    if(loginProperties::getInstance()->getLoaderName() == "student") {
        if(bookname == "") {
            this->setQuery("SELECT * FROM pending_books WHERE student_email = '" + email + "'");
            qDebug() << "Pending Books Model updated! NULL Student";
        } else {
            this->setQuery("SELECT * FROM pending_books WHERE name LIKE '" + bookname + "%' AND student_email = '" + email + "'");
            qDebug() << "Pending Books Model updated! Student";
        }
    } else if (loginProperties::getInstance()->getLoaderName() == "librarian") {
        if(bookname == "") {
            this->setQuery("SELECT * FROM pending_books");
            qDebug() << "Pending Books Model updated! NULL librarian";
        } else {
            this->setQuery("SELECT * FROM pending_books WHERE name LIKE '" + bookname + "%'");
            qDebug() << "Pending Books Model updated! librarian";
        }
    }

}

int pendingBooksModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
