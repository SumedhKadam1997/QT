#ifndef CSVWRITER_HPP
#define CSVWRITER_HPP

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <qdatetime.h>

class CSVWriter : public QObject
{
    Q_OBJECT
    QString homeLocation;
    QStringList Player1Score;
    QStringList Player2Score;
    QStringList Player3Score;
    QStringList Player4Score;

public:
    explicit CSVWriter(QObject *parent = nullptr);
    Q_INVOKABLE void writeCSV();
    void readCSV();
    Q_INVOKABLE void getPlayer1Score();
    Q_INVOKABLE void setPlayer1Score(const qint8 &, const QString &);

signals:

    void Player1ScoreChanged();
    void Player2ScoreChanged();
    void Player3ScoreChanged();
    void Player4ScoreChanged();
};

#endif // CSVWRITER_HPP
