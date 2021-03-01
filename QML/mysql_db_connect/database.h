#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>


class database : public QObject
{
    Q_OBJECT

public:
    database();

    bool opendb();
};

#endif // DATABASE_H
