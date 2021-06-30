#ifndef CSVPARSER_H
#define CSVPARSER_H

//#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDateTime>


class CSVParser
{
    int argcount;
    QString inPath;
    QString outPath;
    quint64 firstNum = 0;
    quint16 secondNum = 0;
    quint16 thirdNum = 0;
    QString rawNum;
    QChar ch;
public:
    CSVParser(int argc, QString inFilePath, QString outFilePath);

    int checkArgCount();
    QString checkInPath();
    QString checkOutPath();
    bool checkInPathExists();
    bool checkOutPathExists();
    bool checkFirstNumber();
    bool checkSecondNumber();
    bool checkThirdString();
    bool openInPath();
    bool openOutPath();
    int getSumofDigits(QString num);
    quint64 calculateSum();
    bool parser();
};

#endif // CSVPARSER_H
