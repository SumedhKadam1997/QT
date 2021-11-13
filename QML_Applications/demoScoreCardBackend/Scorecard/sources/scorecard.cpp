#include "scorecard.hpp"

ScoreCard::ScoreCard(QObject *parent) : QObject(parent)
{

}

void ScoreCard::addScore(const int &playerIndex, const int &scoreIndex, const QString &score)
{
    switch (playerIndex) {
    case 0 : {
        if (scoreIndex > 17) {
            break;
        } else if (scoreIndex < 9) {
            m_player1Score[scoreIndex] = score;
            calcutaleOutTotal(playerIndex);
        } else if (scoreIndex >= 9) {
            m_player1Score[scoreIndex + 1] = score;
            calculateInTotal(playerIndex);
        }
    }
        calculateTotal(playerIndex);
        emit player1ScoreChanged();
        break;
    case 1 : {
        if (scoreIndex > 17) {
            break;
        } else if (scoreIndex < 9) {
            m_player2Score[scoreIndex] = score;
            calcutaleOutTotal(playerIndex);
        } else if (scoreIndex >= 9) {
            m_player2Score[scoreIndex + 1] = score;
            calculateInTotal(playerIndex);
        }
    }
        calculateTotal(playerIndex);
        emit player2ScoreChanged();
        break;
    case 2 : {
        if (scoreIndex > 17) {
            break;
        } else if (scoreIndex < 9) {
            m_player3Score[scoreIndex] = score;
            calcutaleOutTotal(playerIndex);
        } else if (scoreIndex >= 9) {
            m_player3Score[scoreIndex + 1] = score;
            calculateInTotal(playerIndex);
        }
    }
        calculateTotal(playerIndex);
        emit player3ScoreChanged();
        break;
    case 3 : {
        if (scoreIndex > 17) {
            break;
        } else if (scoreIndex < 9) {
            m_player4Score[scoreIndex] = score;
            calcutaleOutTotal(playerIndex);
        } else if (scoreIndex >= 9) {
            m_player4Score[scoreIndex + 1] = score;
            calculateInTotal(playerIndex);
        }
    }
        calculateTotal(playerIndex);
        emit player4ScoreChanged();
        break;
    }
}

void ScoreCard::calcutaleOutTotal(const int &playerIndex)
{
    switch (playerIndex) {
    case 0 : {
        qint16 total = 0;
        for (int i = 0; i < 9; ++i) {
            total += m_player1Score[i].toInt();
        }
        m_player1Score[9] = QString::number(total);
        m_player1Score[20] = QString::number(total);
    }
        emit player1ScoreChanged();
        break;
    case 1 : {
        qint16 total = 0;
        for (int i = 0; i < 9; ++i) {
            total += m_player2Score[i].toInt();
        }
        m_player2Score[9] = QString::number(total);
        m_player2Score[20] = QString::number(total);
    }
        emit player2ScoreChanged();
        break;
    case 2 : {
        qint16 total = 0;
        for (int i = 0; i < 9; ++i) {
            total += m_player3Score[i].toInt();
        }
        m_player3Score[9] = QString::number(total);
        m_player3Score[20] = QString::number(total);
    }
        emit player3ScoreChanged();
        break;
    case 3 : {
        qint16 total = 0;
        for (int i = 0; i < 9; ++i) {
            total += m_player4Score[i].toInt();
        }
        m_player4Score[9] = QString::number(total);
        m_player4Score[20] = QString::number(total);
    }
        emit player4ScoreChanged();
        break;
    }
}

void ScoreCard::calculateInTotal(const int &playerIndex)
{
    switch (playerIndex) {
    case 0 : {
        qint16 total = 0;
        for (int i = 10; i < 19; ++i) {
            total += m_player1Score[i].toInt();
        }
        m_player1Score[19] = QString::number(total);
    }
        emit player1ScoreChanged();
        break;
    case 1 : {
        qint16 total = 0;
        for (int i = 10; i < 19; ++i) {
            total += m_player2Score[i].toInt();
        }
        m_player2Score[19] = QString::number(total);
    }
        emit player2ScoreChanged();
        break;
    case 2 : {
        qint16 total = 0;
        for (int i = 10; i < 19; ++i) {
            total += m_player3Score[i].toInt();
        }
        m_player3Score[19] = QString::number(total);
    }
        emit player3ScoreChanged();
        break;
    case 3 : {
        qint16 total = 0;
        for (int i = 10; i < 19; ++i) {
            total += m_player4Score[i].toInt();
        }
        m_player4Score[19] = QString::number(total);
    }
        emit player4ScoreChanged();
        break;
    }
}

void ScoreCard::calculateTotal(const int &playerIndex)
{
    switch (playerIndex) {
    case 0 : {
        qint16 total = 0;
            total = m_player1Score[19].toInt() + m_player1Score[20].toInt();
        m_player1Score[21] = QString::number(total);
    }
        emit player1ScoreChanged();
        break;
    case 1 : {
        qint16 total = 0;
        total = m_player2Score[19].toInt() + m_player2Score[20].toInt();
        m_player2Score[21] = QString::number(total);
    }
        emit player2ScoreChanged();
        break;
    case 2 : {
        qint16 total = 0;
            total = m_player3Score[19].toInt() + m_player3Score[20].toInt();
        m_player3Score[21] = QString::number(total);
    }
        emit player3ScoreChanged();
        break;
    case 3 : {
        qint16 total = 0;
        total = m_player4Score[19].toInt() + m_player4Score[20].toInt();
        m_player4Score[21] = QString::number(total);
    }
        emit player4ScoreChanged();
        break;
    }
}

const QStringList &ScoreCard::hole() const
{
    return m_hole;
}

void ScoreCard::setHole(const QStringList &newHole)
{
    if (m_hole == newHole)
        return;
    m_hole = newHole;
    emit holeChanged();
}

const QStringList &ScoreCard::black() const
{
    return m_black;
}

void ScoreCard::setBlack(const QStringList &newBlack)
{
    if (m_black == newBlack)
        return;
    m_black = newBlack;
    emit blackChanged();
}

const QStringList &ScoreCard::blue() const
{
    return m_blue;
}

void ScoreCard::setBlue(const QStringList &newBlue)
{
    if (m_blue == newBlue)
        return;
    m_blue = newBlue;
    emit blueChanged();
}

const QStringList &ScoreCard::white() const
{
    return m_white;
}

void ScoreCard::setWhite(const QStringList &newWhite)
{
    if (m_white == newWhite)
        return;
    m_white = newWhite;
    emit whiteChanged();
}

const QStringList &ScoreCard::red() const
{
    return m_red;
}

void ScoreCard::setRed(const QStringList &newRed)
{
    if (m_red == newRed)
        return;
    m_red = newRed;
    emit redChanged();
}

const QStringList &ScoreCard::stroke() const
{
    return m_stroke;
}

void ScoreCard::setStroke(const QStringList &newStroke)
{
    if (m_stroke == newStroke)
        return;
    m_stroke = newStroke;
    emit strokeChanged();
}

const QStringList &ScoreCard::par() const
{
    return m_par;
}

void ScoreCard::setPar(const QStringList &newPar)
{
    if (m_par == newPar)
        return;
    m_par = newPar;
    emit parChanged();
}

const QStringList &ScoreCard::holeTime() const
{
    return m_holeTime;
}

void ScoreCard::setHoleTime(const QStringList &newHoleTime)
{
    if (m_holeTime == newHoleTime)
        return;
    m_holeTime = newHoleTime;
    emit holeTimeChanged();
}

const QStringList &ScoreCard::score() const
{
    return m_score;
}

void ScoreCard::setScore(const QStringList &newScore)
{
    if (m_score == newScore)
        return;
    m_score = newScore;
    emit scoreChanged();
}

const QStringList &ScoreCard::points() const
{
    return m_points;
}

void ScoreCard::setPoints(const QStringList &newPoints)
{
    if (m_points == newPoints)
        return;
    m_points = newPoints;
    emit pointsChanged();
}

const QStringList &ScoreCard::player1Score() const
{
    return m_player1Score;
}

void ScoreCard::setPlayer1Score(const QStringList &newPlayer1Score)
{
    if (m_player1Score == newPlayer1Score)
        return;
    m_player1Score = newPlayer1Score;
    emit player1ScoreChanged();
}

const QStringList &ScoreCard::player2Score() const
{
    return m_player2Score;
}

void ScoreCard::setPlayer2Score(const QStringList &newPlayer2Score)
{
    if (m_player2Score == newPlayer2Score)
        return;
    m_player2Score = newPlayer2Score;
    emit player2ScoreChanged();
}

const QStringList &ScoreCard::player3Score() const
{
    return m_player3Score;
}

void ScoreCard::setPlayer3Score(const QStringList &newPlayer3Score)
{
    if (m_player3Score == newPlayer3Score)
        return;
    m_player3Score = newPlayer3Score;
    emit player3ScoreChanged();
}

const QStringList &ScoreCard::player4Score() const
{
    return m_player4Score;
}

void ScoreCard::setPlayer4Score(const QStringList &newPlayer4Score)
{
    if (m_player4Score == newPlayer4Score)
        return;
    m_player4Score = newPlayer4Score;
    emit player4ScoreChanged();
}

const QString &ScoreCard::player1Name() const
{
    return m_player1Name;
}

void ScoreCard::setPlayer1Name(const QString &newPlayer1Name)
{
    if (m_player1Name == newPlayer1Name)
        return;
    m_player1Name = newPlayer1Name;
    emit player1NameChanged();
}

const QString &ScoreCard::player2Name() const
{
    return m_player2Name;
}

void ScoreCard::setPlayer2Name(const QString &newPlayer2Name)
{
    if (m_player2Name == newPlayer2Name)
        return;
    m_player2Name = newPlayer2Name;
    emit player2NameChanged();
}

const QString &ScoreCard::player3Name() const
{
    return m_player3Name;
}

void ScoreCard::setPlayer3Name(const QString &newPlayer3Name)
{
    if (m_player3Name == newPlayer3Name)
        return;
    m_player3Name = newPlayer3Name;
    emit player3NameChanged();
}

const QString &ScoreCard::player4Name() const
{
    return m_player4Name;
}

void ScoreCard::setPlayer4Name(const QString &newPlayer4Name)
{
    if (m_player4Name == newPlayer4Name)
        return;
    m_player4Name = newPlayer4Name;
    emit player4NameChanged();
}
