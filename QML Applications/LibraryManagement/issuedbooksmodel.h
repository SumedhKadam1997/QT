#ifndef ISSUEDBOOKSMODEL_H
#define ISSUEDBOOKSMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class issuedBooksModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit issuedBooksModel(QObject *parent = nullptr);


    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        EmailRole,
        DateRole
    };

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString query);
    int getId(int row);
};

#endif // ISSUEDBOOKSMODEL_H
