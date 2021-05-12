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

    Q_PROPERTY(bool db_open READ db_open WRITE setDb_open NOTIFY db_openChanged)
public:
    database();
    ~ database();

    void dbconnect();
    bool opendb();

    bool db_open() const;

private:
    QSqlDatabase db;

private:
    bool restoredb();
    void closedb();
    bool createtable();

    bool m_db_open;

public slots:

    bool insertdb(const QString &first_name, const QString &email, const QString &username, const QString &password, const QString &gender);

    QString login_func(QString name);
    QString check_user(QString name);

    QString generate_hash(QString password);

    void setDb_open(bool db_open);
signals:
    void db_openChanged(bool db_open);
};

#endif // DATABASE_H
