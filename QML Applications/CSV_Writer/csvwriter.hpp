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
    Q_PROPERTY(QStringList player1Score READ player1Score WRITE setPlayer1Score NOTIFY player1ScoreChanged)
    Q_PROPERTY(QStringList player2Score READ player2Score WRITE setPlayer2Score NOTIFY player2ScoreChanged)
    Q_PROPERTY(QStringList player3Score READ player3Score WRITE setPlayer3Score NOTIFY player3ScoreChanged)
    Q_PROPERTY(QStringList player4Score READ player4Score WRITE setPlayer4Score NOTIFY player4ScoreChanged)

    QStringList m_player1Score = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    QStringList m_player2Score = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    QStringList m_player3Score = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    QStringList m_player4Score = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};

public:
    explicit CSVWriter(QObject *parent = nullptr);
    Q_INVOKABLE void writeCSV();
    void readCSV();
//    Q_INVOKABLE void getPlayer1Score();
//    Q_INVOKABLE void setPlayer1Score(const qint8 &index, const QString &score);

    QStringList player1Score() const;
    QStringList player2Score() const;
    QStringList player3Score() const;
    QStringList player4Score() const;

public slots:
    void setPlayer1Score(QStringList player1Score);
    void setPlayer2Score(QStringList player2Score);
    void setPlayer3Score(QStringList player3Score);
    void setPlayer4Score(QStringList player4Score);

signals:
    void player1ScoreChanged(QStringList player1Score);
    void player2ScoreChanged(QStringList player2Score);
    void player3ScoreChanged(QStringList player3Score);
    void player4ScoreChanged(QStringList player4Score);
};

#endif // CSVWRITER_HPP
