#include "properties.h"

properties::properties(QObject * parent) : QObject(parent),
    m_firstname("FIRSTNAME"),
    m_lastname("LASTNAME"),
    m_email("sumedhk@smartleaven.in"),
    m_age(23),
    m_gender("MALE")
{

}

QString properties::firstname() const
{
    return m_firstname;
}

QString properties::lastname() const
{
    return m_lastname;
}

QString properties::email() const
{
    return m_email;
}

qint16 properties::age() const
{
    return m_age;
}

QString properties::gender() const
{
    return m_gender;
}

void properties::setFirstname(QString firstname)
{
    if (m_firstname == firstname)
        return;

    m_firstname = firstname;
    emit firstnameChanged(m_firstname);
}

void properties::setLastname(QString lastname)
{
    if (m_lastname == lastname)
        return;

    m_lastname = lastname;
    emit lastnameChanged(m_lastname);
}

void properties::setEmail(QString email)
{
    if (m_email == email)
        return;

    m_email = email;
    emit emailChanged(m_email);
}

void properties::setAge(qint16 age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}

void properties::setGender(QString gender)
{
    if (m_gender == gender)
        return;

    m_gender = gender;
    emit genderChanged(m_gender);
}
