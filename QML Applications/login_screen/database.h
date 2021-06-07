#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "people.db"
#define TABLE               "members"


class database : public QObject
{
    Q_OBJECT
public:
    database();
    ~ database();

    void dbconnect();
    bool opendb();

private:
    QSqlDatabase db;

private:
    bool restoredb();
    void closedb();
    bool createtable();

public slots:

    bool insertdb(const QString &first_name, const QString &email, const QString &username, const QString &password, const QString &gender);
    QString login_func(QString name);
    QString check_user(QString name);
    QString generate_hash(QString password);
};

#endif // DATABASE_H
