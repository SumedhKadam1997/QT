#ifndef LIBRARIANSMODEL_H
#define LIBRARIANSMODEL_H

#include <QSqlQueryModel>
#include <QObject>

class LibrariansModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit LibrariansModel(QObject *parent = 0);


    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        AgeRole,
        EmailRole,
        PasswordRole,
        GenderRole
    };

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString name);
    int getId(int row);
};

#endif // LIBRARIANSMODEL_H
