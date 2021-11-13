#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class database : public QObject
{
    Q_OBJECT


#define DATABASE_HOSTNAME   "localhost"
#define DATABASE_NAME       "library.db"

public:
    explicit database(QObject *parent = nullptr);
    ~database();

    void dbconnect();
    bool opendb();

private:
    QSqlDatabase db;
    bool restoredb();
    void closedb();
    bool createtables();
    bool createBooksTable();
    bool createMemberTable();
    bool createIssuedBooksTable();
    bool createPendingBooksTable();


public slots:
    QString loginFunc(QString email);
    QString checkUser(QString email);
    QString generateHash(QString password);
    bool addBook(QString name, qint32 isbn, QString author, QString publication, qint64 quantity);
    bool addPendingBook(QString bookName);
    bool addMember(QString name, qint32 age, QString email, QString password, QString gender, QString role, QString department = "NULL", QString semester = "NULL");
    bool checkName(QString name);
    bool checkBook(QString table, QString book);
    bool delMember(QString name);
    bool delBook(QString table, QString book, QString email);
    bool issueBook(QString book, QString email, QString date);
};

#endif // DATABASE_H
