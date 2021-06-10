#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QImage>
#include <QVariant>
#include <QString>
#include <QQuickItem>
#include <QQuickPaintedItem>

#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "photos.db"


class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~ Database();
    static Database *getInstance();

    void dbConnect();
    bool openDb();

private:
    QSqlDatabase db;

private:
    bool restoreDb();
    void closeDb();
    bool createTable();
public slots:
    bool insertPhoto(QString filename, QVariant photo, QString dateTime);
    QStringList getPhotos();
    QString getPhoto();
};

#endif // DATABASE_H
