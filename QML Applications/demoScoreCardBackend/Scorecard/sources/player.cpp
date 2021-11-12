#include "player.hpp"

Player::Player(QObject *parent) : QObject(parent)
{

}

Player::Player(const QString &name, const QString &memID, const QString &handicap)
{
    this->setName(name);
    this->setMembershipID(memID);
    this->setHandicap(handicap);
}

const QString &Player::name() const
{
    return m_name;
}

void Player::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

const QString &Player::membershipID() const
{
    return m_membershipID;
}

void Player::setMembershipID(const QString &newMembershipID)
{
    if (m_membershipID == newMembershipID)
        return;
    m_membershipID = newMembershipID;
    emit membershipIDChanged();
}

const QString &Player::handicap() const
{
    return m_handicap;
}

void Player::setHandicap(const QString &newHandicap)
{
    if (m_handicap == newHandicap)
        return;
    m_handicap = newHandicap;
    emit handicapChanged();
}

const QStringList &Player::score() const
{
    return m_score;
}

void Player::setScore(const QStringList &newScore)
{
    qint16 total = 0;
    if (m_score == newScore)
        return;
    m_score = newScore;
    for (int i = 0; i < 18; ++i) {
        total += m_score[i].toInt();
    }
    qDebug() << "Score" << m_score;
    qDebug() << "Total:" << total;
    m_score[18] = QString::number(total);
    qDebug() << "Score" << m_score;
    emit scoreChanged();
}
