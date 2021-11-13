#ifndef BOOKSMODEL_H
#define BOOKSMODEL_H

#include <QObject>
#include <QSqlQueryModel>
//#include <QSqlTableModel>

class BooksModel : public QSqlQueryModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ISBNRole,
        AuthorRole,
        PublicationRole,
        QuantityRole
    };

    explicit BooksModel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString query);
    int getId(int row);
};

#endif // BOOKSMODEL_H
