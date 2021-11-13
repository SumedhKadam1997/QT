#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>
#include <QDebug>

class Player : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString membershipID READ membershipID WRITE setMembershipID NOTIFY membershipIDChanged)
    Q_PROPERTY(QString handicap READ handicap WRITE setHandicap NOTIFY handicapChanged)
    Q_PROPERTY(QStringList score READ score WRITE setScore NOTIFY scoreChanged)

    QString m_name = "Sumedh";
    QString m_membershipID;
    QString m_handicap;
    QStringList m_score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

public:
    explicit Player(QObject *parent = nullptr);

    Player(const QString & name, const QString & memID, const QString & handicap);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &membershipID() const;
    void setMembershipID(const QString &newMembershipID);

    const QString &handicap() const;
    void setHandicap(const QString &newHandicap);

    const QStringList &score() const;
    void setScore(const QStringList &newScore);

signals:
    void nameChanged();
    void membershipIDChanged();
    void handicapChanged();
    void scoreChanged();
};

#endif // PLAYER_HPP
