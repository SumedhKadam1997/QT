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

void loginProperties::setLoginState(bool loginState)
{
    if (m_loginState == loginState)
        return;

    m_loginState = loginState;
    emit loginStateChanged(m_loginState);
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

QString loginProperties::getRandomString(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString randomString;
    for(int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
