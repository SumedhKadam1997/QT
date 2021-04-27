#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <properties.h>

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "peoples.db"
#define TABLE               "members"
#define DBFILE              "C:\\Users\\uxoriousghost\\Desktop\\QML\\build-Database_in_QML-Desktop_Qt_5_15_1_MinGW_64_bit-Debug\\"


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

    bool insertdb(const QString &first_name, const QString &last_name, const QString &email, const QString &gender, const qint32 &age);
//    QSqlQueryModel *selectall();

};

#endif // DATABASE_H
