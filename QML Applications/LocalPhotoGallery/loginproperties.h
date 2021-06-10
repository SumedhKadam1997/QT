#ifndef LOGINPROPERTIES_H
#define LOGINPROPERTIES_H

#include <QObject>
#include <QDateTime>
#include <QRandomGenerator>

class loginProperties : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool loginState READ getloginState WRITE setLoginState NOTIFY loginStateChanged)
    Q_PROPERTY(QString Myname READ Myname WRITE setMyname NOTIFY MynameChanged)
    Q_PROPERTY(QString MyEmail READ MyEmail WRITE setMyEmail NOTIFY MyEmailChanged)
    Q_PROPERTY(QString MyAge READ MyAge WRITE setMyAge NOTIFY MyAgeChanged)

    bool m_loginState = false;
    QString m_Myname;
    QString m_MyEmail;
    QString m_MyAge;

public:
    explicit loginProperties(QObject *parent = nullptr);
    static loginProperties *getInstance();

    Q_INVOKABLE bool getloginState() const;
    QString Myname() const;
    QString MyEmail() const;
    QString MyAge() const;

public slots:
    void setLoginState(bool loginState);
    void setMyname(QString Myname);
    void setMyEmail(QString MyEmail);
    void setMyAge(QString MyAge);
    QString getRandomString(int length);

signals:
    void loginStateChanged(bool loginState);
    void MynameChanged(QString Myname);
    void MyEmailChanged(QString MyEmail);
    void MyAgeChanged(QString MyAge);
};

#endif // LOGINPROPERTIES_H
