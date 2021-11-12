#include "scoreinput.hpp"

ScoreInput::ScoreInput(QObject *parent) : QObject(parent)
{
    this->m_playerList.clear();
//    this->addPlayer("Sumedh", "E0053", "5");
//    this->addPlayer("Pavan", "E0035", "5");
}

void ScoreInput::addPlayer(const QString &name, const QString &memID, const QString &handicap)
{
    m_playerList.append(new Player(name, memID, handicap));
    emit playerListChanged();
    qDebug() << "Player Added";
}

const QStringList &ScoreInput::hole() const
{
    return m_hole;
}

void ScoreInput::setHole(const QStringList &newHole)
{
    if (m_hole == newHole)
        return;
    m_hole = newHole;
    emit holeChanged();
}

const QStringList &ScoreInput::par() const
{
    return m_par;
}

void ScoreInput::setPar(const QStringList &newPar)
{
    if (m_par == newPar)
        return;
    m_par = newPar;
    emit parChanged();
}

const QList<Player *> &ScoreInput::playerList() const
{
    return m_playerList;
}

void ScoreInput::setPlayerList(const QList<Player *> &newPlayerList)
{
    if (m_playerList == newPlayerList)
        return;
    m_playerList = newPlayerList;
    emit playerListChanged();
}
