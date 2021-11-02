#include "csvwriter.hpp"

CSVWriter::CSVWriter(QObject *parent) : QObject(parent)
{
    this->homeLocation = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << this->homeLocation;
}

void CSVWriter::writeCSV()
{
    QFile file(homeLocation + "/data.csv");
    if (!file.open(QFile::ReadWrite | QFile::Truncate)) {
            qDebug() << "Cannot open file : " << file.errorString();
    } else {
        QTextStream out(&file);
        out << "Poona Golf Course Scorecard" << "\n";
        out << "Date and Time" << "," << QDateTime::currentDateTime().toString() << "\n";
        out << "Hole,1,2,3,4,5,6,7,8,9,Out, 10, 11, 12, 13, 14, 15, 16, 17, 18, In, Total" << "\n";
        out << "value1" << "," << "value2" << "," << "value3"<< "," << "value4" << "," << "value5" << "," << "value6" << "\n";
        out << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "\n";
    }
    file.close();
}

void CSVWriter::readCSV()
{
    QFile file(homeLocation + "/data.csv");
    if (!file.open(QFile::ReadOnly)) {
            qDebug() << "Cannot open file : " << file.errorString();
    } else {
        while (!file.atEnd()) {
                qDebug() << file.readLine();
        }
    }
    file.close();
}

void CSVWriter::getPlayer1Score()
{
    for (auto score : Player1Score) {
        qDebug() << score;
    }
}

void CSVWriter::setPlayer1Score(const qint8 & index, const QString & score)
{
    Player1Score.insert(index, score);
    emit Player1ScoreChanged();
}

