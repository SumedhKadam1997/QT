#ifndef DATABASE_HPP
#define DATABASE_HPP

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "path.db"

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QGeoCoordinate>
//storing the coords in db and retrieving them and displaying on the mappolyline
class Database : public QObject
{
    Q_OBJECT
    QSqlDatabase db;
    Q_PROPERTY(QVariantList basePath READ basePath WRITE setBasePath NOTIFY basePathChanged)

public:
    explicit Database(QObject *parent = nullptr);
    ~Database();

    void dbconnect();
    bool opendb();
    Q_INVOKABLE void getBasePathfromDB();
    const QVariantList &basePath() const;
    void setBasePath(const QVariantList &newBasePath);

private:
    bool restoredb();
    void closedb();
    bool createtables();
    bool createBasePathTable();

    QVariantList m_basePath;

signals:

    void basePathChanged();
};

#endif // DATABASE_HPP
