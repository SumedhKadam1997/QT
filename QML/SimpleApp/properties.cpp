#include "properties.h"

Properties::Properties(QObject *parent) : QObject(parent),
    m_firstname("FIRSTNAME"),
    m_lastname("LASTNAME"),
    m_username("UXORIOUSGHOST"),
    m_age(23),
    m_gender("MALE")
{

}

QString Properties::firstname() const
{
    return m_firstname;
}

QString Properties::lastname() const
{
    return m_lastname;
}

QString Properties::username() const
{
    return m_username;
}

qint16 Properties::age() const
{
    return m_age;
}

QString Properties::gender() const
{
    return m_gender;
}

void Properties::setFirstname(QString firstname)
{
    if (m_firstname == firstname)
        return;

    m_firstname = firstname;
    emit firstnameChanged(m_firstname);
}

void Properties::setLastname(QString lastname)
{
    if (m_lastname == lastname)
        return;

    m_lastname = lastname;
    emit lastnameChanged(m_lastname);
}

void Properties::setUsername(QString username)
{
    if (m_username == username)
        return;

    m_username = username;
    emit usernameChanged(m_username);
}

void Properties::setAge(qint16 age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}

void Properties::setGender(QString gender)
{
    if (m_gender == gender)
        return;

    m_gender = gender;
    emit genderChanged(m_gender);
}
