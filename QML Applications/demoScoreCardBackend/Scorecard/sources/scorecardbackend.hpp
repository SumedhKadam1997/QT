#ifndef SCORECARDBACKEND_HPP
#define SCORECARDBACKEND_HPP

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QDateTime>

class ScorecardBackend : public QObject
{
    Q_OBJECT
    QString homeLocation;
    Q_PROPERTY(QString     player1      READ player1      WRITE setPlayer1      NOTIFY player1Changed)
    Q_PROPERTY(QString     player2      READ player2      WRITE setPlayer2      NOTIFY player2Changed)
    Q_PROPERTY(QString     player3      READ player3      WRITE setPlayer3      NOTIFY player3Changed)
    Q_PROPERTY(QString     player4      READ player4      WRITE setPlayer4      NOTIFY player4Changed)
    Q_PROPERTY(QStringList hole         READ hole         WRITE setHole         NOTIFY holeChanged)
    Q_PROPERTY(QStringList black        READ black        WRITE setBlack        NOTIFY blackChanged)
    Q_PROPERTY(QStringList blue         READ blue         WRITE setBlue         NOTIFY blueChanged)
    Q_PROPERTY(QStringList white        READ white        WRITE setWhite        NOTIFY whiteChanged)
    Q_PROPERTY(QStringList red          READ red          WRITE setRed          NOTIFY redChanged)
    Q_PROPERTY(QStringList stroke       READ stroke       WRITE setStroke       NOTIFY strokeChanged)
    Q_PROPERTY(QStringList par          READ par          WRITE setPar          NOTIFY parChanged)
    Q_PROPERTY(QStringList holeTime     READ holeTime     WRITE setHoleTime     NOTIFY holeTimeChanged)
    Q_PROPERTY(QStringList score        READ score        WRITE setScore        NOTIFY scoreChanged)
    Q_PROPERTY(QStringList points       READ points       WRITE setPoints       NOTIFY pointsChanged)
    Q_PROPERTY(QStringList player1Score READ player1Score WRITE setPlayer1Score NOTIFY player1ScoreChanged)
    Q_PROPERTY(QStringList player2Score READ player2Score WRITE setPlayer2Score NOTIFY player2ScoreChanged)
    Q_PROPERTY(QStringList player3Score READ player3Score WRITE setPlayer3Score NOTIFY player3ScoreChanged)
    Q_PROPERTY(QStringList player4Score READ player4Score WRITE setPlayer4Score NOTIFY player4ScoreChanged)

    QStringList m_player1Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player2Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player3Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player4Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_hole = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "Total"};
    QStringList m_black = {"416", "227", "437", "187", "379", "353", "511", "386", "304", "3236", "322", "384", "592", "209", "384", "384", "204", "389", "570", "3366", "3236", "6602", "71.4", "132"};
    QStringList m_blue = {"402", "208", "466", "171", "364", "332", "365", "365", "291", "3092", "302", "256", "492", "192", "334", "330", "186", "382", "553", "3127", "3092", "6219", "69.7", "130"};
    QStringList m_white = {"362", "186", "454", "154", "335", "314", "463", "349", "282", "2899", "297", "348", "465", "186", "299", "327", "182", "347", "515", "2966", "2899", "5895", "67.8", "124"};
    QStringList m_red = {"346", "183", "393", "140", "329", "301", "362", "312", "273", "2639", "288", "324", "458", "178", "294", "291", "169", "337", "499", "2838", "2639", "5477", "71.2", "121"};
    QStringList m_stroke = {"3", "7", "1", "15", "5", "11", "9", "13", "17", "-", "18", "6", "2", "14", "16", "12", "10", "8", "4", "-", "-", "-", "H'Cap", "Nett"};
    QStringList m_par = {"4", "3", "4", "3", "4", "4", "5", "4", "4", "4", "4", "5", "3", "4", "4", "3", "4", "5", "71"};
    QStringList m_holeTime = {"16", "11", "16", "11", "14", "15", "18", "15", "12", "128", "15", "15", "18", "11", "14", "15", "11", "15", "12", "132", "128", "260"};
    QStringList m_score = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    QStringList m_points = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    QString m_player1{"Sumedh"};
    QString m_player2{"Pavan"};
    QString m_player3{"Nitesh"};
    QString m_player4{"Sonali"};

public:
    explicit ScorecardBackend(QObject *parent = nullptr);
    Q_INVOKABLE void writeCSV();
    void readCSV();
//    Q_INVOKABLE void getPlayer1Score();
//    Q_INVOKABLE void setPlayer1Score(const qint8 &index, const QString &score);

    QStringList player1Score() const;
    QStringList player2Score() const;
    QStringList player3Score() const;
    QStringList player4Score() const;

    const QStringList &hole() const;
    void setHole(const QStringList &newHole);

    const QStringList &black() const;
    void setBlack(const QStringList &newBlack);

    const QStringList &blue() const;
    void setBlue(const QStringList &newBlue);

    const QStringList &white() const;
    void setWhite(const QStringList &newWhite);

    const QStringList &red() const;
    void setRed(const QStringList &newRed);

    const QStringList &stroke() const;
    void setStroke(const QStringList &newStroke);

    const QStringList &par() const;
    void setPar(const QStringList &newPar);

    const QStringList &holeTime() const;
    void setHoleTime(const QStringList &newHoleTime);

    const QStringList &score() const;
    void setScore(const QStringList &newScore);

    const QStringList &points() const;
    void setPoints(const QStringList &newPoints);

    const QString &player1() const;
    void setPlayer1(const QString &newPlayer1);

    const QString &player2() const;
    void setPlayer2(const QString &newPlayer2);

    const QString &player3() const;
    void setPlayer3(const QString &newPlayer3);

    const QString &player4() const;
    void setPlayer4(const QString &newPlayer4);

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
    void holeChanged();
    void blackChanged();
    void blueChanged();
    void whiteChanged();
    void redChanged();
    void strokeChanged();
    void parChanged();
    void holeTimeChanged();
    void scoreChanged();
    void pointsChanged();
    void player1Changed();
    void player2Changed();
    void player3Changed();
    void player4Changed();
};

#endif // SCORECARDBACKEND_HPP
