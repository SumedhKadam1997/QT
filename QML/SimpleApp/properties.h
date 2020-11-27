#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QObject>

class Properties : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(qint16 age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString gender READ gender WRITE setGender NOTIFY genderChanged)

public:
    explicit Properties(QObject *parent = nullptr);

    QString firstname() const;

    QString lastname() const;

    QString username() const;

    qint16 age() const;

    QString gender() const;

public slots:

    void setFirstname(QString firstname);

    void setLastname(QString lastname);

    void setUsername(QString username);

    void setAge(qint16 age);

    void setGender(QString gender);

signals:

    void firstnameChanged(QString firstname);

    void lastnameChanged(QString lastname);

    void usernameChanged(QString username);

    void ageChanged(qint16 age);

    void genderChanged(QString gender);



private:

    QString m_firstname;
    QString m_lastname;
    QString m_username;
    qint16 m_age;
    QString m_gender;
};

#endif // PROPERTIES_H
