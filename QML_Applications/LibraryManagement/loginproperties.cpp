#include "loginproperties.h"

static loginProperties * s_instance = nullptr;

loginProperties::loginProperties(QObject *parent) : QObject(parent)
{

}

loginProperties *loginProperties::getInstance()
{
    if(!s_instance) s_instance = new loginProperties();

    return s_instance;
}

bool loginProperties::getloginState() const
{
    return m_loginState;
}

QString loginProperties::getLoaderName() const
{
    return m_loaderName;
}

QString loginProperties::Myname() const
{
    return m_Myname;
}

QString loginProperties::MyEmail() const
{
    return m_MyEmail;
}

QString loginProperties::MyAge() const
{
    return m_MyAge;
}

QString loginProperties::MyDept() const
{
    return m_MyDept;
}

QString loginProperties::MySem() const
{
    return m_MySem;
}

void loginProperties::setLoginState(bool loginState)
{
    if (m_loginState == loginState)
        return;

    m_loginState = loginState;
    emit loginStateChanged(m_loginState);
}

void loginProperties::setLoaderName(QString loaderName)
{
    if (m_loaderName == loaderName)
        return;

    m_loaderName = loaderName;
    emit loaderNameChanged(m_loaderName);
}

void loginProperties::setMyname(QString Myname)
{
    if (m_Myname == Myname)
        return;

    m_Myname = Myname;
    emit MynameChanged(m_Myname);
}

void loginProperties::setMyEmail(QString MyEmail)
{
    if (m_MyEmail == MyEmail)
        return;

    m_MyEmail = MyEmail;
    emit MyEmailChanged(m_MyEmail);
}

void loginProperties::setMyAge(QString MyAge)
{
    if (m_MyAge == MyAge)
        return;

    m_MyAge = MyAge;
    emit MyAgeChanged(m_MyAge);
}

void loginProperties::setMyDept(QString MyDept)
{
    if (m_MyDept == MyDept)
        return;

    m_MyDept = MyDept;
    emit MyDeptChanged(m_MyDept);
}

void loginProperties::setMySem(QString MySem)
{
    if (m_MySem == MySem)
        return;

    m_MySem = MySem;
    emit MySemChanged(m_MySem);
}
