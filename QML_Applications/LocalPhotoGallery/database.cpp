#include "database.h"
#include "loginproperties.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QCryptographicHash>
#include <QGuiApplication>

database::database(QObject *parent) : QObject(parent)
{
    this->dbconnect();
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
        return (this->createtables()) ? true : false;
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



bool database::createtables()
{
    bool photo = createPhotoTable();
    bool member = createMemberTable();

    if (photo && member) {
        return true;
    } else {
        return false;
    }
}

bool database::createPhotoTable()
{
    QSqlQuery book_query;
    if(!book_query.exec("CREATE TABLE photoData (id INTEGER PRIMARY KEY, photoName varchar(50), email varchar(50))")) {
        qDebug() << "Database: error in creating PhotoData table ";
        qDebug() << book_query.lastError().text();
        return false;
    } else {
        qDebug() << "PhotoData Table successfully created";
        return true;
    }
}

bool database::createMemberTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE member (id INTEGER PRIMARY KEY, name varchar(50), age INTEGER, email varchar(150), password varchar(120), gender varchar(50))")){
        qDebug() << "Database: error in creating members table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Member Table successfully created";
        QSqlQuery query;
        query.prepare("INSERT INTO member (name, age, email, password, gender)"
                            "VALUES (:name, :age, :email, :password, :gender)");
        query.bindValue(":name", "ADMIN");
        query.bindValue(":age", 20);
        query.bindValue(":email", "admin@verolt.com");
        query.bindValue(":password", generateHash("admin"));
        query.bindValue(":gender", "Male");

        if(!query.exec()){
            qDebug() << "error while inserting admin";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Admin Succesfully Added!";
            return true;
        }
    }
}

QString database::loginFunc(QString email)
{
    QString passwordresult;
    QSqlQuery query;
    query.prepare("SELECT * FROM member WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while(query.next()) {
            loginProperties::getInstance()->setMyname(query.value(1).toString());
            loginProperties::getInstance()->setMyAge(query.value(2).toString());
            loginProperties::getInstance()->setMyEmail(query.value(3).toString());
            passwordresult = query.value(4).toString();
        }
    }
    return passwordresult;
}

QString database::checkUser(QString email)
{
    QString login_result;
    QSqlQuery query;
    query.prepare("SELECT email FROM member WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while(query.next()) {
            login_result = query.value(0).toString();
        }
    }
    return login_result;
}

QString database::generateHash(QString password)
{
    QString hash = QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex());
    return hash;
}

bool database::addPhotoData(QString name, QString email)
{
    QSqlQuery query;
    query.prepare("INSERT INTO photoData (photoName, email)"
                            "VALUES (:photoName, :email)");
    query.bindValue(":photoName", name);
    query.bindValue(":email", email);
    if(!query.exec()){
        qDebug() << "error while inserting books";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "PhotoData Succesfully Added!";
        return true;
    }
    return true;
}

bool database::addMember(QString name, qint32 age, QString email, QString password, QString gender)
{
    QSqlQuery query;
    query.prepare("INSERT INTO member (name, age, email, password, gender)"
                        "VALUES (:name, :age, :email, :password, :gender)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    query.bindValue(":email", email);
    query.bindValue(":password", generateHash(password));
    query.bindValue(":gender", gender);

    if(!query.exec()){
        qDebug() << "error while inserting member";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Member Succesfully Added!";
        return true;
    }
}

bool database::checkName(QString email)
{
    QString myEmail;
    QSqlQuery query;
    query.prepare("SELECT email FROM member WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            myEmail = query.value(0).toString();
        }
    }
    if (myEmail == email) {
        return true;
    } else {
        return false;
    }
}

bool database::delMember(QString email)
{
    QSqlQuery query;
    if(db.open()) {
        if(!query.exec("DELETE FROM member WHERE email = '" + email + "';")){
            qDebug() << "Database: error in book delete";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Member successfully deleted";
            return true;
        }
    } else {
        return false;
    }
}

bool database::delPhotoData()
{
    QDir imageDir = QGuiApplication::applicationDirPath() + "/Images";
    QStringList names = photoName.split(QLatin1Char(','));
    for(int i = 0; i < names.length(); ++i) {
        QString name = names[i].remove("'");
        name.append(".jpg");
        imageDir.remove(name);
    }
    QSqlQuery query;
    if(db.open()) {
        if(!query.exec("DELETE FROM photoData WHERE photoName IN (" + photoName + ")")){
            qDebug() << "Database: error in photoData delete";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Selected Photos successfully deleted";
            return true;
        }
    } else {
        return false;
    }
}

void database::populateNames(QString name)
{
    if(photoName.length() == 0) {
        photoName.push_back("'");
        photoName.push_back(name);
        photoName.push_back("'");

    } else {
        photoName.push_back(",");
        photoName.push_back("'");
        photoName.push_back(name);
        photoName.push_back("'");
    }
    qDebug() << photoName;
    qDebug() << name << "inside db";
}

void database::clearNames()
{
    photoName.clear();
    qDebug() << "List Cleared";
}
