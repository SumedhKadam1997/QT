#include "database.h"
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QBuffer>
#include <QIODevice>
#include <QPainter>
#include <QGraphicsObject>

static Database *s_instance = nullptr;

Database *Database::getInstance() {
    if(!s_instance) s_instance = new Database();
    return s_instance;
}

Database::Database(QObject *parent) : QObject(parent)
{
    this->dbConnect();
}

Database::~Database()
{
    if(db.open()) {
        db.close();
    }
}
void Database::dbConnect()
{
    if(!QFile(DATABASE_NAME).exists()){
        this->restoreDb();
        qDebug() << "Database Restored";
    } else {
        this->openDb();
        qDebug() <<"Database Openeed";
    }
}

bool Database::openDb()
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

bool Database::restoreDb()
{
    if(this->openDb()){
        return (this->createTable()) ? true : false;
    } else {
        qDebug() << "Failed to restore the Database";
        return false;
    }
    return false;
}

void Database::closeDb()
{
    db.close();
}

bool Database::createTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE photos (id INTEGER PRIMARY KEY, filename TEXT, photo BLOB, date TEXT)")) {
        qDebug() << "Database: error in creating table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Photos Table Created";
        return true;
    }
}

bool Database::insertPhoto(QString filename, QVariant photo, QString dateTime)
{
    QByteArray inByteArray;
    QImage inImage = qvariant_cast<QImage>(photo);
    QBuffer inBuffer(&inByteArray);
    inBuffer.open(QIODevice::WriteOnly);
    inImage.save(&inBuffer, "png");
    QSqlQuery query;
    query.prepare("INSERT INTO photos (filename, photo, date) VALUES (:filename, :photo, :date)");
    query.bindValue(":filename", filename);
    query.bindValue(":photo", inByteArray);
    query.bindValue(":date", dateTime);

    if(!query.exec()){
        qDebug() << "error while inserting";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Photo Succesfully Inserted!";
        return true;
    }
}

QStringList Database::getPhotos()
{
    QStringList photosList;
    QByteArray outByteArray;
    QSqlQuery query;
    if( !query.exec( "SELECT photo FROM photos ORDER BY id DESC" )) {
        qDebug() << "Error getting image from table:\n" << query.lastError();
    } else {
        while (query.next()) {
            QString photos("data:image/png;base64,");
            query.first();
            outByteArray = query.value(0).toByteArray();
            photos.append(QString::fromLatin1(outByteArray.toBase64().data()));
            photosList.append(photos);
        }
    }
    return photosList;
}

QString Database::getPhoto()
{
    QString photo("data:image/png;base64,");
    QByteArray outByteArray;
    QSqlQuery query;
    if( !query.exec( "SELECT photo FROM photos ORDER BY id DESC LIMIT 1" )) {
        qDebug() << "Error getting image from table:\n" << query.lastError();
    } else {
        query.first();
        outByteArray = query.value(0).toByteArray();
        photo.append(QString::fromLatin1(outByteArray.toBase64().data()));
    }
    return photo;
}

