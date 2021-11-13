#include "database.hpp"

Database::Database(QObject *parent) : QObject(parent)
{
    this->dbconnect();
}

Database::~Database()
{
    if(db.open()) {
        db.close();
    }
}

void Database::dbconnect()
{
    if(!QFile(DATABASE_NAME).exists()){
        this->restoredb();
        qDebug() << "Database Restored";
    } else {
        this->opendb();
        qDebug() <<"Database Openeed";
    }
}

bool Database::opendb()
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

void Database::getBasePathfromDB()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM basePath");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            m_basePath.append(QVariant::fromValue(QGeoCoordinate(query.value(3).toDouble(), query.value(4).toDouble())));
        }
        emit basePathChanged();
    }
}

bool Database::restoredb()
{
    if(this->opendb()){
        return (this->createtables()) ? true : false;
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

void Database::closedb()
{
    db.close();
}

bool Database::createtables()
{
    bool books = createBasePathTable();

    if (books) {
        return true;
    } else {
        return false;
    }
}

bool Database::createBasePathTable()
{
//    INSERT INTO basePath (startName, endName, latitude, longitude) VALUES ("hole1", "hole2", 18.555784129677242, 73.8843211442432)
    QSqlQuery basePathQuery;
    if(!basePathQuery.exec("CREATE TABLE basePath (id INTEGER PRIMARY KEY, startName varchar(50), endName varchar(50), latitude DOUBLE, longitude DOUBLE)")) {
        qDebug() << "Database: error in creating basePath table ";
        qDebug() << basePathQuery.lastError().text();
        return false;
    } else {
        qDebug() << "basePath Table successfully created";
//        QSqlQuery query;
//        query.prepare("INSERT INTO basePath (startName, endName, latitude, longitude)"
//                            "VALUES ('hole1', 'hole2', 18.555784129677242, 73.8843211442432)");
//        query.bindValue(":name", "ADMIN");
//        query.bindValue(":age", 20);
//        query.bindValue(":email", "admin@verolt.com");
//        query.bindValue(":gender", "Male");
//        query.bindValue(":role", "admin");

//        if(!query.exec()){
//            qDebug() << "error while inserting admin";
//            qDebug() << query.lastError().text();
//            return false;
//        } else {
            return true;
//        }
    }
}



const QVariantList &Database::basePath() const
{
    return m_basePath;
}

void Database::setBasePath(const QVariantList &newBasePath)
{
    if (m_basePath == newBasePath)
        return;
    m_basePath = newBasePath;
    emit basePathChanged();
}
