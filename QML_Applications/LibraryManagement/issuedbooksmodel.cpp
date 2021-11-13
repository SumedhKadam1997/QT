#include "issuedbooksmodel.h"
#include "loginproperties.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


issuedBooksModel::issuedBooksModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant issuedBooksModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> issuedBooksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[EmailRole] = "student_email";
    roles[DateRole] = "date";

    return roles;
}

void issuedBooksModel::updateModel(QString bookname)
{
    QString email = loginProperties::getInstance()->MyEmail();
    if(loginProperties::getInstance()->getLoaderName() == "student") {
        if(bookname == "") {
            this->setQuery("SELECT * FROM issued_books WHERE student_email = '" + email + "'");
            qDebug() << "Issued Books Model updated! NULL Student";
        } else {
            this->setQuery("SELECT * FROM issued_books WHERE name LIKE '" + bookname + "%' AND student_email = '" + email + "'");
            qDebug() << "Issued Books Model updated! Student";
        }
    } else if (loginProperties::getInstance()->getLoaderName() == "librarian") {
        if(bookname == "") {
            this->setQuery("SELECT * FROM issued_books");
            qDebug() << "Issued Books Model updated! NULL Librarian";
        } else {
            this->setQuery("SELECT * FROM issued_books WHERE name LIKE '" + bookname + "%'");
            qDebug() << "Issued Books Model updated! Librarian";
        }
    }
}

int issuedBooksModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
