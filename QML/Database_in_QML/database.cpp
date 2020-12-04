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
    if(!query.exec("CREATE TABLE members (id INTEGER PRIMARY KEY, first_name varchar(50), last_name varchar(50), email varchar(150), gender varchar(50), age INTEGER)")){
        qDebug() << "Database: error in creating table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return true;
}

bool database::insertdb(const QString &first_name, const QString &last_name, const QString &email, const QString &gender, const qint32 &age)
{
    if(this->opendb()){
        QSqlQuery query;
        query.prepare("INSERT INTO members (first_name, last_name, email, gender, age)"
                      "VALUES (:first_name, :last_name, :email, :gender, :age)");
        query.bindValue(":first_name", first_name);
        query.bindValue(":last_name", last_name);
        query.bindValue(":email", email);
        query.bindValue(":gender", gender);
        query.bindValue(":age", age);

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

//QSqlQueryModel *database::selectall()
//{
//    QSqlQuery query;
//    QSqlQueryModel *model = new QSqlQueryModel(this);
//    query.prepare(" select * from members");
//    if(!query.exec()){
//        qDebug() << "Error in retrieving data";
//    }else{
//        model->setQuery(query);
//        return model;
//    }
//}

