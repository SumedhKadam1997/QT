#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include <mainproperties.h>

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "oee_database.db"
#define TABLE               "OeeData"
#define DBFILE              "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\QML\\OEEDashboard\\"


class database : public QObject
{
    Q_OBJECT
public:
    database();
    ~ database();

    void dbconnect();
    void setprodprop(mainproperties *obj);
    void setrejprop(mainproperties *obj);
//    void setprodprop();
private:
    QSqlDatabase db;

private:
    bool opendb();
    bool restoredb();
    void closedb();
    bool createtable();

public slots:

    bool insertdb(const qint64 &production_count, const qint64 &rejection_count, const qint64 &stop_time, const qint64 &breakdown_time, const qint64 &run_time, const qint64 &oee, const qint64 &ava, const qint64 &perf, const qint64 &qua);
};

#endif // DATABASE_H

