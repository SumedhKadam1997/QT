#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QDateTime>
#include <QList>
#include <qqmllist.h>
#include <mainproperties.h>



database::database()
{

}

database::~database()
{

}

void database::dbconnect()
{
    if(!QFile(DBFILE DATABASE_NAME).exists()){
        this->restoredb();
        qDebug() << "Database Restored";
    } else {
        this->opendb();
        qDebug() <<"Database Openeed";

    }
}

void database::setoeeprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT oee FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("oee");
        while (query.next()) {
            int oee_num = query.value(fieldNo).toInt();
            obj->setOee(oee_num);
            qDebug() << "Sumedh " << obj->m_oee << "Sahil " << oee_num;
        }
    }
}

void database::setperfprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT perf FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("perf");
        while (query.next()) {
            int perf_num = query.value(fieldNo).toInt();


            obj->setPerf(perf_num);
            qDebug() << "Sumedh " << obj->m_perf << "Sahil " << perf_num;
        }
    }
}

void database::setavaprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT ava FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("ava");
        while (query.next()) {
            int ava_num = query.value(fieldNo).toInt();
            obj->setAva(ava_num);
            qDebug() << "Sumedh " << obj->m_ava << "Sahil " << ava_num;
        }
    }
}

void database::setquaprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT qua FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("qua");
        while (query.next()) {
            int qua_num = query.value(fieldNo).toInt();
            obj->setQua(qua_num);
            qDebug() << "Sumedh " << obj->m_qua << "Sahil " << qua_num;
        }
    }
}

void database::setprodprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT prod_count FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("prod_count");
        while (query.next()) {
            int production_count = query.value(fieldNo).toInt();
            obj->setProduction_count(production_count);
            qDebug() << "Sumedh " << obj->m_production_count << "Sahil " << production_count;
        }
    }
}

void database::setrejprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT reject_count FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("reject_count");
        while (query.next()) {
            int rejection_count = query.value(fieldNo).toInt();
            obj->setrejection_count(rejection_count);
            qDebug() << "Sumedh " << obj->m_rejection_count << "Sahil " << rejection_count;
        }
    }
}

void database::setshiftprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT shift FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("shift");
        while (query.next()) {
            int shift_num = query.value(fieldNo).toInt();
            obj->setShift(shift_num);
            qDebug() << "Sumedh " << obj->m_shift << "Sahil " << shift_num;
        }
    }
}

void database::setstopprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT stop_time FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("stop_time");
        while (query.next()) {
            int stop_time_num = query.value(fieldNo).toInt();
            obj->setStop_time(stop_time_num);
            qDebug() << "Sumedh " << obj->m_stop_time << "Sahil " << stop_time_num;
        }
    }
}

void database::setbreakprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT breakdown_time FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("breakdown_time");
        while (query.next()) {
            int breakdown_time_num = query.value(fieldNo).toInt();
            obj->setBreakdown_time(breakdown_time_num);
            qDebug() << "Sumedh " << obj->m_breakdown_time << "Sahil " << breakdown_time_num;
        }
    }
}

void database::setrunprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT run_time FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("run_time");
        while (query.next()) {
            int run_time_num = query.value(fieldNo).toInt();
            obj->setRun_time(run_time_num);
            qDebug() << "Sumedh " << obj->m_run_time << "Sahil " << run_time_num;
        }
    }
}

void database::setidealprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT ideal_cycle_time FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("ideal_cycle_time");
        while (query.next()) {
            int ideal_cycle_num = query.value(fieldNo).toInt();
            obj->setIdeal_time(ideal_cycle_num);
            qDebug() << "Sumedh " << obj->m_ideal_time << "Sahil " << ideal_cycle_num;
        }
    }
}

void database::setactualprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT actual_cycle_time FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("actual_cycle_time");
        while (query.next()) {
            int actual_cycle_num = query.value(fieldNo).toInt();
            obj->setActual_time(actual_cycle_num);
            qDebug() << "Sumedh " << obj->m_actual_time << "Sahil " << actual_cycle_num;
        }
    }
}


bool database::opendb()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DBFILE DATABASE_NAME);


    if(db.open()){
        qDebug() << "Databases Opennned! ";
        return true;
    } else {
        return false;
    }
}

bool database::restoredb()
{
    if(this->opendb()){
        return (this->createtable()) ? true : false;
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

void database::closedb()
{
    db.close();
}

bool database::createtable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE OeeData (id INTEGER PRIMARY KEY AUTOINCREMENT, production_count INTEGER, rejection_count INTEGER, stop_time INTEGER, breakdown_time INTEGER, run_time INTEGER, oee INTEGER, ava INTEGER, perf INTEGER, qua INTEGER)")){
        qDebug() << "Database: error in creating table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return true;
}

bool database::insertdb(const qint64 &production_count, const qint64 &rejection_count, const qint64 &stop_time, const qint64 &breakdown_time, const qint64 &run_time, const qint64 &oee, const qint64 &ava, const qint64 &perf, const qint64 &qua)
{
    if(this->opendb()){
        QSqlQuery query;
        query.prepare("INSERT INTO members (production_count, rejection_count, stop_time, breakdown_time, run_time, oee, ava, perf, qua)"
                      "VALUES (:production_count, :rejection_count, :stop_time, :breakdown_time, :run_time, :oee, :ava, :perf, :qua)");
        query.bindValue(":production_count", production_count);
        query.bindValue(":rejection_count", rejection_count);
        query.bindValue(":stop_time", stop_time);
        query.bindValue(":breakdown_time", breakdown_time);
        query.bindValue(":run_time", run_time);
        query.bindValue(":oee", oee);
        query.bindValue(":ava", ava);
        query.bindValue(":perf", perf);
        query.bindValue(":qua", qua);

        if(!query.exec()){
            qDebug() << "error while inserting";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Data Succesfully Inserted!";
            return true;
        }
    } else {
        qDebug() << "Failed to open the database";
        return false;
    }
}

bool database::insert_machine_data(const qint32 &machine_number, const QDateTime &datetime, const qint32 &batch_number, const qint32 &air_pressure, const qint32 &lub_pressure, const qint32 &hyd_pressure, const qint32 &stroke_count)
{
    if(this->opendb()){
        QSqlQuery query;
        query.prepare("INSERT INTO machine_data (machine_number, datetime, batch_number, air_pressure, lubrication_pressure, hydraulic_pressure, stroke_count)"
                      "VALUES (:machine_number, :datetime, :batch_number, :air_pressure, :lub_pressure, :hyd_pressure, :stroke_count)");
        query.bindValue(":machine_number", machine_number);
        query.bindValue(":datetime", datetime);
        query.bindValue(":batch_number", batch_number);
        query.bindValue(":air_pressure", air_pressure);
        query.bindValue(":lub_pressure", lub_pressure);
        query.bindValue(":hyd_pressure", hyd_pressure);
        query.bindValue(":stroke_count", stroke_count);

        if(!query.exec()){
            qDebug() << "error while inserting";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Data Succesfully Inserted!";
            return true;
        }
    } else {
        qDebug() << "Failed to open the database";
        return false;
    }
}

bool database::insert_prod_data(const qint32 &machine_id, const qint32 &prod_count, const qint32 &reject_count, const QDateTime &datetime, const qint32 &batch_number, const qint32 &run_time, const qint32 &stop_time, const qint32 &unplanned_time, const QString &notes)
{
    if(this->opendb()){
        QSqlQuery query;
        query.prepare("INSERT INTO production_data (machine_id, production_count, rejection_count, datetime, batch_number, run_time, stop_time, unplanned_stop_time, notes)"
                      "VALUES (:machine_id, :prod_count, :reject_count, :datetime, :batch_number, :run_time, :stop_time, :unplanned_time, :notes)");
        query.bindValue(":machine_id", machine_id);
        query.bindValue(":prod_count", prod_count);
        query.bindValue(":reject_count", reject_count);
        query.bindValue(":datetime", datetime);
        query.bindValue(":batch_number", batch_number);
        query.bindValue(":run_time", run_time);
        query.bindValue(":stop_time", stop_time);
        query.bindValue(":unplanned_time", unplanned_time);
        query.bindValue(":notes", notes);

        if(!query.exec()){
            qDebug() << "error while inserting";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Data Succesfully Inserted!";
            return true;
        }
    } else {
        qDebug() << "Failed to open the database";
        return false;
    }
}


