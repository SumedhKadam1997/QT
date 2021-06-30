#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class database : public QObject
{
    Q_OBJECT


#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "data.db"

public:
    explicit database(QObject *parent = nullptr);
    ~database();

    bool opendb();

private:
    QSqlDatabase db;
    void closedb();
};

#endif // DATABASE_H
