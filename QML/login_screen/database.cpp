#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QCryptographicHash>


database::database()
{

}

database::~database()
{
    if(db.open()) {
        db.close();
    }
}
void database::dbconnect()
{
    if(!QFile(DATABASE_NAME).exists()){
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
    db.setDatabaseName(DATABASE_NAME);


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
    if(!query.exec("CREATE TABLE members (id INTEGER PRIMARY KEY, first_name varchar(50), email varchar(150), username varchar(50), password varchar(120), gender varchar(50))")){
        qDebug() << "Database: error in creating table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        QSqlQuery query;
        query.prepare("INSERT INTO members (first_name, email, username, password, gender)"
                      "VALUES (:first_name, :email, :username, :password, :gender)");
        query.bindValue(":first_name", "ADMIN");
        query.bindValue(":email", "admin@verolt.com");
        query.bindValue(":username", "ADMIN");
        query.bindValue(":password", generate_hash("admin"));
        query.bindValue(":gender", "Male");
        if(!query.exec()){
            qDebug() << "error while inserting";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Data Succesfully Inserted!";
            return true;
        }
        return true;
    }
}

bool database::insertdb(const QString &first_name, const QString &email, const QString &username, const QString &password, const QString &gender)
{    
    QSqlQuery query;
    query.prepare("INSERT INTO members (first_name, email, username, password, gender)"
                      "VALUES (:first_name, :email, :username, :password, :gender)");
    query.bindValue(":first_name", first_name);
    query.bindValue(":email", email);
    query.bindValue(":username", username);
    query.bindValue(":password", generate_hash(password));
    query.bindValue(":gender", gender);

    if(!query.exec()){
        qDebug() << "error while inserting";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Data Succesfully Inserted!";
        return true;
    }
}

QString database::login_func(QString email)
{
    QString login_result;
    QSqlQuery query;
    query.prepare("SELECT password FROM members WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            login_result = query.value(0).toString();
        }
    }
    return login_result;
}

QString database::check_user(QString email)
{
    QString login_result;
    QSqlQuery query;
    query.prepare("SELECT email FROM members WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            login_result = query.value(0).toString();
        }
    }
    return login_result;
}

QString database::generate_hash(QString password)
{
    QString hash = QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex());
    return hash;
}
