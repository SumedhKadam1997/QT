#include "csvwriter.hpp"

CSVWriter::CSVWriter(QObject *parent) : QObject(parent)
{
    this->homeLocation = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << this->homeLocation;
}

void CSVWriter::writeCSV()
{
//        QFile file(homeLocation + "/scorecard" + QDateTime::currentDateTime().toString("ddMMyy_hhmm") + ".csv");
    QFile file(homeLocation + "/scorecard.csv");
    if (!file.open(QFile::ReadWrite | QFile::Truncate)) {
        qDebug() << "Cannot open file : " << file.errorString();
    } else {
        QTextStream out(&file);
        QString player1;
        QString player2;
        QString player3;
        QString player4;
        out << "Poona Golf Course Scorecard" << "\n";
        out << "Date and Time" << "," << QDateTime::currentDateTime().toString() << "\n";
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
            player1.append(score);
            player1.append(",");
        }
        for (const auto &score : m_player2Score) {
            player2.append(score);
            player2.append(",");
        }
        for (const auto &score : m_player3Score) {
            player3.append(score);
            player3.append(",");
        }
        for (const auto &score : m_player4Score) {
            player4.append(score);
            player4.append(",");
        }
        out << player1 << "\n";
        out << player2 << "\n";
        out << player3 << "\n";
        out << player4 << "\n";
    }
    file.close();
}

void CSVWriter::readCSV()
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

QStringList CSVWriter::player1Score() const
{
    return m_player1Score;
}

QStringList CSVWriter::player2Score() const
{
    return m_player2Score;
}

QStringList CSVWriter::player3Score() const
{
    return m_player3Score;
}

QStringList CSVWriter::player4Score() const
{
    return m_player4Score;
}

void CSVWriter::setPlayer1Score(QStringList player1Score)
{
    if (m_player1Score == player1Score)
        return;

    m_player1Score = player1Score;
    emit player1ScoreChanged(m_player1Score);
}

void CSVWriter::setPlayer2Score(QStringList player2Score)
{
    if (m_player2Score == player2Score)
        return;

    m_player2Score = player2Score;
    emit player2ScoreChanged(m_player2Score);
}

void CSVWriter::setPlayer3Score(QStringList player3Score)
{
    if (m_player3Score == player3Score)
        return;

    m_player3Score = player3Score;
    emit player3ScoreChanged(m_player3Score);
}

void CSVWriter::setPlayer4Score(QStringList player4Score)
{
    if (m_player4Score == player4Score)
        return;

    m_player4Score = player4Score;
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

