#ifndef SCOREINPUT_HPP
#define SCOREINPUT_HPP

#include <QObject>
#include "player.hpp"

class ScoreInput : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList hole       READ hole   WRITE setHole   NOTIFY holeChanged)
    Q_PROPERTY(QStringList par        READ par    WRITE setPar    NOTIFY parChanged)
    Q_PROPERTY(QList<Player *> playerList READ playerList WRITE setPlayerList NOTIFY playerListChanged)

    QStringList m_hole = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "Total"};
    QStringList m_par = {"4", "3", "4", "3", "4", "4", "5", "4", "4", "4", "4", "5", "3", "4", "4", "3", "4", "5", "71"};
    QList<Player *> m_playerList;

public:
    explicit ScoreInput(QObject *parent = nullptr);

    Q_INVOKABLE void addPlayer(const QString & name, const QString & memID, const QString & handicap);

    const QStringList &hole() const;
    void setHole(const QStringList &newHole);

    const QStringList &par() const;
    void setPar(const QStringList &newPar);

    const QList<Player *> &playerList() const;
    void setPlayerList(const QList<Player *> &newPlayerList);

signals:

    void holeChanged();
    void parChanged();
    void playerListChanged();
};

#endif // SCOREINPUT_HPP
