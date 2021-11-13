#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class database : public QObject
{
    Q_OBJECT


#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "gallery.db"

public:
    explicit database(QObject *parent = nullptr);
    ~database();

    void dbconnect();
    bool opendb();

    QString photoName;

private:
    QSqlDatabase db;
    bool restoredb();
    void closedb();
    bool createtables();
    bool createPhotoTable();
    bool createMemberTable();


public slots:
    QString loginFunc(QString email);
    QString checkUser(QString email);
    QString generateHash(QString password);
    bool addPhotoData(QString name, QString email);
    bool addMember(QString name, qint32 age, QString email, QString password, QString gender);
    bool checkName(QString name);
    bool delMember(QString name);
    bool delPhotoData();
    void populateNames(QString name);
    void clearNames();
};

#endif // DATABASE_H
