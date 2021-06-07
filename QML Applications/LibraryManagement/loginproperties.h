#ifndef LOGINPROPERTIES_H
#define LOGINPROPERTIES_H

#include <QObject>

class loginProperties : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool loginState READ getloginState WRITE setLoginState NOTIFY loginStateChanged)
    Q_PROPERTY(QString loaderName READ getLoaderName WRITE setLoaderName NOTIFY loaderNameChanged)
    Q_PROPERTY(QString Myname READ Myname WRITE setMyname NOTIFY MynameChanged)
    Q_PROPERTY(QString MyEmail READ MyEmail WRITE setMyEmail NOTIFY MyEmailChanged)
    Q_PROPERTY(QString MyAge READ MyAge WRITE setMyAge NOTIFY MyAgeChanged)
    Q_PROPERTY(QString MyDept READ MyDept WRITE setMyDept NOTIFY MyDeptChanged)
    Q_PROPERTY(QString MySem READ MySem WRITE setMySem NOTIFY MySemChanged)

    bool m_loginState = false;
    QString m_loaderName;
    QString m_Myname;
    QString m_MyEmail;    
    QString m_MyAge;
    QString m_MyDept;
    QString m_MySem;

public:
    explicit loginProperties(QObject *parent = nullptr);
    static loginProperties *getInstance();

    Q_INVOKABLE bool getloginState() const;
    QString getLoaderName() const;    
    QString Myname() const;
    QString MyEmail() const;    
    QString MyAge() const;
    QString MyDept() const;
    QString MySem() const;

public slots:
    void setLoginState(bool loginState);
    void setLoaderName(QString loaderName);    
    void setMyname(QString Myname);
    void setMyEmail(QString MyEmail);    
    void setMyAge(QString MyAge);
    void setMyDept(QString MyDept);
    void setMySem(QString MySem);

signals:
    void loginStateChanged(bool loginState);
    void loaderNameChanged(QString loaderName);
    void MynameChanged(QString Myname);
    void MyEmailChanged(QString MyEmail);
    void MyAgeChanged(QString MyAge);
    void MyDeptChanged(QString MyDept);
    void MySemChanged(QString MySem);
};

#endif // LOGINPROPERTIES_H
