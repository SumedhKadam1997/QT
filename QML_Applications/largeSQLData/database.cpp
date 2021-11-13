#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

database::database(QObject *parent) : QObject(parent)
{
    this->opendb();
}

database::~database()
{
    if(db.open()) {
        db.close();
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

void database::closedb()
{
    db.close();
}
