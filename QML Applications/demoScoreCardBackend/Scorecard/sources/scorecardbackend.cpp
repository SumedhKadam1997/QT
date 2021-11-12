#include "scorecardbackend.hpp"

ScorecardBackend::ScorecardBackend(QObject *parent) : QObject(parent)
{
    this->homeLocation = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << this->homeLocation;
}

void ScorecardBackend::writeCSV()
{
    QFile file(homeLocation + "/scorecard.csv");
    if (!file.open(QFile::ReadWrite | QFile::Truncate)) {
        qDebug() << "Cannot open file : " << file.errorString();
    } else {
        QTextStream out(&file);
        QString player1csv;
        QString player2csv;
        QString player3csv;
        QString player4csv;
        out << "Poona Golf Course Scorecard" << "\n";
        out << "Date and Time," << QDateTime::currentDateTime().toString() << "\n";
        out << "Hole, 1, 2, 3, 4, 5, 6, 7, 8, 9, Out, 10, 11, 12, 13, 14, 15, 16, 17, 18, In, Out, Total, Course Rating, Slope Rating" << "\n";
        out << "Black, 416, 227, 437, 187, 379, 353, 511, 386, 304, 3236, 322, 384, 592, 209, 384, 384, 204, 389, 570, 3366, 3236, 6602, 71.4, 132" << "\n";
        out << "Blue, 402, 208, 466, 171, 364, 332, 365, 365, 291, 3092, 302, 256, 492, 192, 334, 330, 186, 382, 553, 3127, 3092, 6219, 69.7, 130" << "\n";
        out << "White, 362, 186, 454, 154, 335, 314, 463, 349, 282, 2899, 297, 348, 465, 186, 299, 327, 182, 347, 515, 2966, 2899, 5895, 67.8, 124" << "\n";
        out << "Red, 346, 183, 393, 140, 329, 301, 362, 312, 273, 2639, 288, 324, 458, 178, 294, 291, 169, 337, 499, 2838, 2639, 5477, 71.2, 121" << "\n";
        out << "Stroke, 3, 7, 1, 15, 5, 11, 9, 13, 17, -, 18, 6, 2, 14, 16, 12, 10, 8, 4, -, -, -, H'Cap, Nett" << "\n";
        out << "Par, 4, 3, 4, 3, 4, 4, 5, 4, 4, 35, 4, 4, 5, 3, 4, 4, 3, 4, 5, 36, 35, 71" << "\n";
        out << "Hole Time, 16, 11, 16, 11, 14, 15, 18, 15, 12, 128, 15, 15, 18, 11, 14, 15, 11, 15, 12, 132, 128, 260" << "\n";
        out << "Score" << "\n";
        out << "Ponits" << "\n";
        for (const auto &score : m_player1Score) {
            player1csv.append(score);
            player1csv.append(",");
        }
        for (const auto &score : m_player2Score) {
            player2csv.append(score);
            player2csv.append(",");
        }
        for (const auto &score : m_player3Score) {
            player3csv.append(score);
            player3csv.append(",");
        }
        for (const auto &score : m_player4Score) {
            player4csv.append(score);
            player4csv.append(",");
        }
        out << m_player1 << "," << player1csv << "\n";
        out << m_player2 << "," << player2csv << "\n";
        out << m_player3 << "," << player3csv << "\n";
        out << m_player4 << "," << player4csv << "\n";
    }
    file.close();
    this->readCSV();
}

void ScorecardBackend::readCSV()
{
    QFile file(homeLocation + "/scorecard.csv");
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Cannot open file : " << file.errorString();
    } else {
        while (!file.atEnd()) {
            qDebug() << file.readLine();
        }
    }
    file.close();
}

QStringList ScorecardBackend::player1Score() const
{
    return m_player1Score;
}

QStringList ScorecardBackend::player2Score() const
{
    return m_player2Score;
}

QStringList ScorecardBackend::player3Score() const
{
    return m_player3Score;
}

QStringList ScorecardBackend::player4Score() const
{
    return m_player4Score;
}

void ScorecardBackend::setPlayer1Score(QStringList player1Score)
{
    if (m_player1Score == player1Score)
        return;

    m_player1Score = player1Score;
    qDebug() << m_player1Score;
    emit player1ScoreChanged(m_player1Score);
}

void ScorecardBackend::setPlayer2Score(QStringList player2Score)
{
    if (m_player2Score == player2Score)
        return;

    m_player2Score = player2Score;
    qDebug() << m_player2Score;
    emit player2ScoreChanged(m_player2Score);
}

void ScorecardBackend::setPlayer3Score(QStringList player3Score)
{
    if (m_player3Score == player3Score)
        return;

    m_player3Score = player3Score;
    qDebug() << m_player3Score;
    emit player3ScoreChanged(m_player3Score);
}

void ScorecardBackend::setPlayer4Score(QStringList player4Score)
{
    if (m_player4Score == player4Score)
        return;

    m_player4Score = player4Score;
    qDebug() << m_player4Score;
    emit player4ScoreChanged(m_player4Score);
}

//void CSVWriter::getPlayer1Score()
//{
//    qDebug() << "Scores from QStringList";
//    for (const auto &score : Player1Score) {
//        qDebug() << score;
//    }
//    qDebug() << "Scores From Property";
//    for (const auto &score : m_player1) {
//        qDebug() << score;
//    }
//}

//void CSVWriter::setPlayer1Score(const qint8 & index, const QString & score)
//{
//    Player1Score.insert(index, score);
//    emit Player1ScoreChanged();
//}


const QStringList &ScorecardBackend::hole() const
{
    return m_hole;
}

void ScorecardBackend::setHole(const QStringList &newHole)
{
    if (m_hole == newHole)
        return;
    m_hole = newHole;
    emit holeChanged();
}

const QStringList &ScorecardBackend::black() const
{
    return m_black;
}

void ScorecardBackend::setBlack(const QStringList &newBlack)
{
    if (m_black == newBlack)
        return;
    m_black = newBlack;
    emit blackChanged();
}

const QStringList &ScorecardBackend::blue() const
{
    return m_blue;
}

void ScorecardBackend::setBlue(const QStringList &newBlue)
{
    if (m_blue == newBlue)
        return;
    m_blue = newBlue;
    emit blueChanged();
}

const QStringList &ScorecardBackend::white() const
{
    return m_white;
}

void ScorecardBackend::setWhite(const QStringList &newWhite)
{
    if (m_white == newWhite)
        return;
    m_white = newWhite;
    emit whiteChanged();
}

const QStringList &ScorecardBackend::red() const
{
    return m_red;
}

void ScorecardBackend::setRed(const QStringList &newRed)
{
    if (m_red == newRed)
        return;
    m_red = newRed;
    emit redChanged();
}

const QStringList &ScorecardBackend::stroke() const
{
    return m_stroke;
}

void ScorecardBackend::setStroke(const QStringList &newStroke)
{
    if (m_stroke == newStroke)
        return;
    m_stroke = newStroke;
    emit strokeChanged();
}

const QStringList &ScorecardBackend::par() const
{
    return m_par;
}

void ScorecardBackend::setPar(const QStringList &newPar)
{
    if (m_par == newPar)
        return;
    m_par = newPar;
    emit parChanged();
}

const QStringList &ScorecardBackend::holeTime() const
{
    return m_holeTime;
}

void ScorecardBackend::setHoleTime(const QStringList &newHoleTime)
{
    if (m_holeTime == newHoleTime)
        return;
    m_holeTime = newHoleTime;
    emit holeTimeChanged();
}

const QStringList &ScorecardBackend::score() const
{
    return m_score;
}

void ScorecardBackend::setScore(const QStringList &newScore)
{
    if (m_score == newScore)
        return;
    m_score = newScore;
    emit scoreChanged();
}

const QStringList &ScorecardBackend::points() const
{
    return m_points;
}

void ScorecardBackend::setPoints(const QStringList &newPoints)
{
    if (m_points == newPoints)
        return;
    m_points = newPoints;
    emit pointsChanged();
}

const QString &ScorecardBackend::player1() const
{
    return m_player1;
}

void ScorecardBackend::setPlayer1(const QString &newPlayer1)
{
    if (m_player1 == newPlayer1)
        return;
    m_player1 = newPlayer1;
    emit player1Changed();
}

const QString &ScorecardBackend::player2() const
{
    return m_player2;
}

void ScorecardBackend::setPlayer2(const QString &newPlayer2)
{
    if (m_player2 == newPlayer2)
        return;
    m_player2 = newPlayer2;
    emit player2Changed();
}

const QString &ScorecardBackend::player3() const
{
    return m_player3;
}

void ScorecardBackend::setPlayer3(const QString &newPlayer3)
{
    if (m_player3 == newPlayer3)
        return;
    m_player3 = newPlayer3;
    emit player3Changed();
}

const QString &ScorecardBackend::player4() const
{
    return m_player4;
}

void ScorecardBackend::setPlayer4(const QString &newPlayer4)
{
    if (m_player4 == newPlayer4)
        return;
    m_player4 = newPlayer4;
    emit player4Changed();
}
