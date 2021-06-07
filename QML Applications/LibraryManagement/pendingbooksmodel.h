#ifndef PENDINGBOOKSMODEL_H
#define PENDINGBOOKSMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class pendingBooksModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit pendingBooksModel(QObject *parent = nullptr);


    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        EmailRole
    };

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString query);
    int getId(int row);


};

#endif // PENDINGBOOKSMODEL_H
