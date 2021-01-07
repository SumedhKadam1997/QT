#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include <mainproperties.h>

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "oee_database.db"
#define TABLE               "OeeData"
#define DBFILE              "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\PROJECT - OEEDashboard\\OEEDashboard\\"


class database : public QObject
{
    Q_OBJECT
public:
    database();
    ~ database();

    void dbconnect();
    void setoeeprop(mainproperties *obj);
    void setperfprop(mainproperties *obj);
    void setavaprop(mainproperties *obj);
    void setquaprop(mainproperties *obj);
    void setprodprop(mainproperties *obj);
    void setrejprop(mainproperties *obj);
    void setshiftprop(mainproperties *obj);
    void setstopprop(mainproperties *obj);
    void setbreakprop(mainproperties *obj);
    void setrunprop(mainproperties *obj);
    void setidealprop(mainproperties *obj);
    void setactualprop(mainproperties *obj);
private:
    QSqlDatabase db;

private:
    bool opendb();
    bool restoredb();
    void closedb();
    bool createtable();

public slots:

    bool insertdb(const qint64 &production_count, const qint64 &rejection_count, const qint64 &stop_time, const qint64 &breakdown_time, const qint64 &run_time, const qint64 &oee, const qint64 &ava, const qint64 &perf, const qint64 &qua);
    bool insert_machine_data(const qint32 &machine_number, const QDateTime &datetime, const qint32 &batch_number, const qint32 &air_pressure, const qint32 &lub_pressure, const qint32 &hyd_pressure, const qint32 &stroke_count);
    bool insert_prod_data(const qint32 &machine_id, const qint32 &prod_count, const qint32 &reject_count, const QDateTime &datetime, const qint32 &batch_number, const qint32 &run_time, const qint32 &stop_time, const qint32 &unplanned_time, const QString &notes);

};

#endif // DATABASE_H

