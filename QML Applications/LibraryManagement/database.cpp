#include "database.h"
#include "loginproperties.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QCryptographicHash>

database::database(QObject *parent) : QObject(parent)
{
    this->dbconnect();
}

database::~database()
{
    if(db.open()) {
        db.close();
    }
}
void database::dbconnect()
{
    if(!QFile(DATABASE_NAME).exists()){
        this->restoredb();
        qDebug() << "Database Restored";
    } else {
        this->opendb();
        qDebug() <<"Database Openeed";
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

bool database::restoredb()
{
    if(this->opendb()){
        return (this->createtables()) ? true : false;
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

void database::closedb()
{
    db.close();
}



bool database::createtables()
{
    bool books = createBooksTable();
    bool admin = createMemberTable();
    bool issued = createIssuedBooksTable();
    bool pending = createPendingBooksTable();

    if (books && admin && issued && pending) {
        return true;
    } else {
        return false;
    }
}

bool database::createBooksTable()
{
    QSqlQuery book_query;
    if(!book_query.exec("CREATE TABLE books (id INTEGER PRIMARY KEY, name varchar(50), ISBN INTEGER, author varchar(50), publication varchar(50), quantity INTEGER)")) {
        qDebug() << "Database: error in creating books table ";
        qDebug() << book_query.lastError().text();
        return false;
    } else {
        qDebug() << "Books Table successfully created";
        return true;
    }
}

bool database::createMemberTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE member (id INTEGER PRIMARY KEY, name varchar(50), age INTEGER, email varchar(150), password varchar(120), gender varchar(50), role varchar(50), department varchar(50), semester varchar(50))")){
        qDebug() << "Database: error in creating members table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Member Table successfully created";
        QSqlQuery query;
        query.prepare("INSERT INTO member (name, age, email, password, gender, role)"
                            "VALUES (:name, :age, :email, :password, :gender, :role)");
        query.bindValue(":name", "ADMIN");
        query.bindValue(":age", 20);
        query.bindValue(":email", "admin@verolt.com");
        query.bindValue(":password", generateHash("admin"));
        query.bindValue(":gender", "Male");
        query.bindValue(":role", "admin");

        if(!query.exec()){
            qDebug() << "error while inserting admin";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Admin Succesfully Added!";
            QSqlQuery query;
            query.prepare("INSERT INTO member (name, age, email, password, gender, role)"
                                        "VALUES (:name, :age, :email, :password, :gender, :role)");
            query.bindValue(":name", "LIBRARIAN");
            query.bindValue(":age", 20);
            query.bindValue(":email", "library@verolt.com");
            query.bindValue(":password", generateHash("library"));
            query.bindValue(":gender", "Male");
            query.bindValue(":role", "librarian");

            if(!query.exec()){
                qDebug() << "error while inserting admin";
                qDebug() << query.lastError().text();
                return false;
            } else {
                qDebug() << "Librarian Succesfully Added!";
                return true;
            }
        }
    }
}

bool database::createIssuedBooksTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE issued_books (id INTEGER PRIMARY KEY, name varchar(50), student_email varchar(50), date varchar(50))")){
        qDebug() << "Database: error in creating members table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Issued Books Table successfully created";
        return true;
    }
}

bool database::createPendingBooksTable()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE pending_books (id INTEGER PRIMARY KEY, name varchar(50), student_email varchar(50))")){
        qDebug() << "Database: error in creating members table ";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Pending Books Table successfully created";
        return true;
    }
}

QString database::loginFunc(QString email)
{
    QString passwordresult;
    QSqlQuery query;
    query.prepare("SELECT * FROM member WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            loginProperties::getInstance()->setMyname(query.value(1).toString());
            loginProperties::getInstance()->setMyAge(query.value(2).toString());
            loginProperties::getInstance()->setMyEmail(query.value(3).toString());
            passwordresult = query.value(4).toString();
            loginProperties::getInstance()->setLoaderName(query.value(6).toString());
            if(loginProperties::getInstance()->getLoaderName() == "student") {
                loginProperties::getInstance()->setMyDept(query.value(7).toString());
                loginProperties::getInstance()->setMySem(query.value(8).toString());
            }
        }
    }
    return passwordresult;
}

QString database::checkUser(QString email)
{
    QString login_result;
    QSqlQuery query;
    query.prepare("SELECT email FROM member WHERE email = '" + email + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            login_result = query.value(0).toString();
        }
    }
    return login_result;
}

QString database::generateHash(QString password)
{
    QString hash = QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex());
    return hash;
}

bool database::addBook(QString name, qint32 isbn, QString author, QString publication, qint64 quantity)
{
    QSqlQuery book_query;
    book_query.prepare("INSERT INTO books (name, ISBN, author, publication, quantity)"
                            "VALUES (:name, :ISBN, :author, :publication, :quantity)");
    book_query.bindValue(":name", name);
    book_query.bindValue(":ISBN", isbn);
    book_query.bindValue(":author", author);
    book_query.bindValue(":publication", publication);
    book_query.bindValue(":quantity", quantity);
    if(!book_query.exec()){
        qDebug() << "error while inserting books";
        qDebug() << book_query.lastError().text();
        return false;
    } else {
        qDebug() << "Books Succesfully Added!";
        return true;
    }
    return true;
}

bool database::addPendingBook(QString bookName)
{
    QSqlQuery book_query;
    book_query.prepare("INSERT INTO pending_books (name, student_email)"
                            "VALUES (:name, :student_email)");
    book_query.bindValue(":name", bookName);
    book_query.bindValue(":student_email", loginProperties::getInstance()->MyEmail());
    if(!book_query.exec()){
        qDebug() << "error while inserting books";
        qDebug() << book_query.lastError().text();
        return false;
    } else {
        qDebug() << "Books Succesfully Added!";
        return true;
    }
    return true;
}

bool database::addMember(QString name, qint32 age, QString email, QString password, QString gender, QString role, QString department, QString semester)
{
    QSqlQuery query;
    query.prepare("INSERT INTO member (name, age, email, password, gender, role, department, semester)"
                        "VALUES (:name, :age, :email, :password, :gender, :role, :department, :semester)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    query.bindValue(":email", email);
    query.bindValue(":password", generateHash(password));
    query.bindValue(":gender", gender);
    query.bindValue(":role", role);
    query.bindValue(":department", department);
    query.bindValue(":semester", semester);

    if(!query.exec()){
        qDebug() << "error while inserting member";
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Member Succesfully Added!";
        return true;
    }
}

bool database::checkName(QString name)
{
    QString myname;
    QSqlQuery query;
    query.prepare("SELECT name FROM member WHERE name = '" + name + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            myname = query.value(0).toString();
        }
    }
    if (myname == name) {
        return true;
    } else {
        return false;
    }
}

bool database::checkBook(QString table, QString book)
{
    QString mybook;
    QSqlQuery query;
    query.prepare("SELECT name FROM " + table + " WHERE name = '" + book + "'");
    if(!query.exec()){
        qDebug() << "error retrieve ";
        qDebug() << query.lastError().text();
    } else {
        while (query.next()) {
            mybook = query.value(0).toString();
        }
    }
    if (mybook == book) {
        return true;
    } else {
        return false;
    }
}

bool database::delMember(QString name)
{
    QSqlQuery query;
    if(db.open()) {
        if(!query.exec("DELETE FROM member WHERE name = '" + name + "';")){
            qDebug() << "Database: error in book delete";
            qDebug() << query.lastError().text();
            return false;
        } else {
            qDebug() << "Member successfully deleted";
            return true;
        }
    } else {
        return false;
    }
}

bool database::delBook(QString table, QString book, QString email)
{
    if(table == "books") {
        QSqlQuery query;
        if(db.open()) {
            if(!query.exec("DELETE FROM books WHERE name = '" + book + "'")){
                qDebug() << "Database: error in book delete";
                qDebug() << query.lastError().text();
                return false;
            } else {
                qDebug() << "Book successfully deleted";
                return true;
            }
        } else {
            return false;
        }
    } else if (table == "pending_books") {
        QSqlQuery query;
//        QString email = loginProperties::getInstance()->MyEmail();
        if(db.open()) {
            if(!query.exec("DELETE FROM pending_books WHERE name = '" + book + "' AND student_email = '" + email +"'")){
                qDebug() << "Database: error in book delete";
                qDebug() << query.lastError().text();
                return false;
            } else {
                qDebug() << "Book successfully deleted";
                return true;
            }
        } else {
            return false;
        }
    } else if (table == "issued_books") {
        QSqlQuery query;
        QString email_ = loginProperties::getInstance()->MyEmail();
        if(db.open()) {
            if(!query.exec("DELETE FROM issued_books WHERE name = '" + book + "' AND student_email = '" + email_ +"'")){
                qDebug() << "Database: error in book delete";
                qDebug() << query.lastError().text();
                return false;
            } else {
                qDebug() << "Book successfully deleted";
                return true;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool database::issueBook(QString book, QString email, QString date)
{
    QSqlQuery book_query;
    book_query.prepare("INSERT INTO issued_books (name, student_email, date)"
                            "VALUES (:name, :student_email, :date)");
    book_query.bindValue(":name", book);
    book_query.bindValue(":student_email", email);
    book_query.bindValue(":date", date);

    if(!book_query.exec()){
        qDebug() << "error while inserting books";
        qDebug() << book_query.lastError().text();
        return false;
    } else {
        qDebug() << "Books Succesfully Added!";
        return true;
    }
    return true;
}
