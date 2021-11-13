#ifndef SCORECARD_HPP
#define SCORECARD_HPP

#include <QObject>
#include <QDebug>

class ScoreCard : public QObject
{
    Q_OBJECT

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
    Q_PROPERTY(QString     player1Name  READ player1Name  WRITE setPlayer1Name  NOTIFY player1NameChanged)
    Q_PROPERTY(QString     player2Name  READ player2Name  WRITE setPlayer2Name  NOTIFY player2NameChanged)
    Q_PROPERTY(QString     player3Name  READ player3Name  WRITE setPlayer3Name  NOTIFY player3NameChanged)
    Q_PROPERTY(QString     player4Name  READ player4Name  WRITE setPlayer4Name  NOTIFY player4NameChanged)

    QStringList m_hole = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "Out", "10", "11", "12", "13", "14", "15", "16", "17", "18", "In", "Out", "Total", "Course Rating", "Slope Rating"};
    QStringList m_black = {"416", "227", "437", "187", "379", "353", "511", "386", "304", "3236", "322", "384", "592", "209", "384", "384", "204", "389", "570", "3366", "3236", "6602", "71.4", "132"};
    QStringList m_blue = {"402", "208", "466", "171", "364", "332", "365", "365", "291", "3092", "302", "256", "492", "192", "334", "330", "186", "382", "553", "3127", "3092", "6219", "69.7", "130"};
    QStringList m_white = {"362", "186", "454", "154", "335", "314", "463", "349", "282", "2899", "297", "348", "465", "186", "299", "327", "182", "347", "515", "2966", "2899", "5895", "67.8", "124"};
    QStringList m_red = {"346", "183", "393", "140", "329", "301", "362", "312", "273", "2639", "288", "324", "458", "178", "294", "291", "169", "337", "499", "2838", "2639", "5477", "71.2", "121"};
    QStringList m_stroke = {"3", "7", "1", "15", "5", "11", "9", "13", "17", "-", "18", "6", "2", "14", "16", "12", "10", "8", "4", "-", "-", "-", "H'Cap", "Nett"};
    QStringList m_par = {"4", "3", "4", "3", "4", "4", "5", "4", "4", "35", "4", "4", "5", "3", "4", "4", "3", "4", "5", "36", "35", "71", "", ""};
    QStringList m_holeTime = {"16", "11", "16", "11", "14", "15", "18", "15", "12", "128", "15", "15", "18", "11", "14", "15", "11", "15", "12", "132", "128", "260", "", ""};
    QStringList m_score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_points = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player1Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player2Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player3Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QStringList m_player4Score = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    QString m_player1Name;
    QString m_player2Name;
    QString m_player3Name;
    QString m_player4Name;

public:
    explicit ScoreCard(QObject *parent = nullptr);

    Q_INVOKABLE void addScore(const int &playerIndex, const int &scoreIndex, const QString &score);

    void calcutaleOutTotal(const int &playerIndex);
    void calculateInTotal(const int &playerIndex);
    void calculateTotal(const int &playerIndex);

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

    const QStringList &player1Score() const;
    void setPlayer1Score(const QStringList &newPlayer1Score);

    const QStringList &player2Score() const;
    void setPlayer2Score(const QStringList &newPlayer2Score);

    const QStringList &player3Score() const;
    void setPlayer3Score(const QStringList &newPlayer3Score);

    const QStringList &player4Score() const;
    void setPlayer4Score(const QStringList &newPlayer4Score);

    const QString &player1Name() const;
    void setPlayer1Name(const QString &newPlayer1Name);

    const QString &player2Name() const;
    void setPlayer2Name(const QString &newPlayer2Name);

    const QString &player3Name() const;
    void setPlayer3Name(const QString &newPlayer3Name);

    const QString &player4Name() const;
    void setPlayer4Name(const QString &newPlayer4Name);

signals:

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
    void player1ScoreChanged();
    void player2ScoreChanged();
    void player3ScoreChanged();
    void player4ScoreChanged();
    void player1NameChanged();
    void player2NameChanged();
    void player3NameChanged();
    void player4NameChanged();
};

#endif // SCORECARD_HPP
