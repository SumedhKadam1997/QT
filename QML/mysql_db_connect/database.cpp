#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

database::database()
{

}

bool database::opendb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("db4free.net");
    db.setPort(3306);
    db.setUserName("uxoriousghost");
    db.setPassword("12345678");
    db.setDatabaseName("oeedata");


    if(db.open()){
        qDebug() << "Databases Opennned! ";
        return true;
    } else {
        qDebug() << "Databases Cannot be Opened! ";

        return false;
    }
}
