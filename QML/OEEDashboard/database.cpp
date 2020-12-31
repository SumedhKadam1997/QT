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

void database::setprodprop(mainproperties *obj)
{
    QSqlQuery query;
    if(!query.exec("SELECT production_count FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("production_count");
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
    if(!query.exec("SELECT rejection_count FROM OeeData ORDER BY ID DESC LIMIT 1")){
        qDebug() << "Database: error in accessing production count";
        qDebug() << query.lastError().text();
    } else {
        int fieldNo = query.record().indexOf("rejection_count");
        while (query.next()) {
            int rejection_count = query.value(fieldNo).toInt();


            obj->setrejection_count(rejection_count);
            qDebug() << "Sumedh " << obj->m_rejection_count << "Sahil " << rejection_count;
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


