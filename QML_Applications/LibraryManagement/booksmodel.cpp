#include "booksmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

BooksModel::BooksModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel("");
}

QVariant BooksModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> BooksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[ISBNRole] = "ISBN";
    roles[AuthorRole] = "author";
    roles[PublicationRole] = "publication";
    roles[QuantityRole] = "quantity";
    return roles;
}

void BooksModel::updateModel(QString bookname)
{
    if(bookname == "") {
        this->setQuery("SELECT * FROM books ORDER BY name");
        qDebug() << "Books Model updated! NULL";
    } else {
        this->setQuery("SELECT * FROM books WHERE name LIKE '" + bookname + "%' ORDER BY name");
        qDebug() << "Books Model updated!";
    }
}

int BooksModel::getId(int row)
{
    return this->data(this->index(row,0), IdRole).toInt();
}
