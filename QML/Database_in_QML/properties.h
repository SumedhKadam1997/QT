#ifndef PROPERTIES_H
#define PROPERTIES_H
#include<QObject>

class properties : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(qint16 age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString gender READ gender WRITE setGender NOTIFY genderChanged)

public:
    explicit properties(QObject *parent = nullptr);
    QString firstname() const;
    QString lastname() const;
    QString email() const;

    qint16 age() const;

    QString gender() const;

public slots:
    void setFirstname(QString firstname);
    void setLastname(QString lastname);
    void setEmail(QString email);
    void setAge(qint16 age);
    void setGender(QString gender);

signals:
    void firstnameChanged(QString firstname);
    void lastnameChanged(QString lastname);
    void emailChanged(QString email);
    void ageChanged(qint16 age);
    void genderChanged(QString gender);

public:
    QString m_firstname;
    QString m_lastname;
    QString m_email;
    qint16 m_age;
    QString m_gender;
};

#endif // PROPERTIES_H
