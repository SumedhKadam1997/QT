#include "csvparser.h"


CSVParser::CSVParser(int argc, QString inFilePath, QString outFilePath) : argcount(argc), inPath(inFilePath), outPath(outFilePath) {

}

int CSVParser::checkArgCount() {
    return argcount;
}

QString CSVParser::checkInPath() {
    return inPath;
}

QString CSVParser::checkOutPath() {
    return outPath;
}

bool CSVParser::checkInPathExists() {
    if(!QFile(inPath).exists()){
        return false;
    } else {
        return true;
    }
}

bool CSVParser::checkOutPathExists() {
    if(!QFile(outPath).exists()){
        return false;
    } else {
        return true;
    }
}

bool CSVParser::checkFirstNumber()
{
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    }
    QTextStream in(&infile);
    while(!in.atEnd()) {
        in >> firstNum>> ch >>secondNum >> ch >> rawNum;
        if (firstNum >= 0 && firstNum <= 4294967295) {
        } else {
            return false;
        }
    }
    return true;
}

bool CSVParser::checkSecondNumber()
{
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    }
    QTextStream in(&infile);
    while(!in.atEnd()) {
        in >> firstNum>> ch >>secondNum >> ch >> rawNum;
        if (secondNum >= 0 && secondNum <= 65535) {
        } else {
            return false;
        }
    }
    return true;
}

bool CSVParser::checkThirdString()
{
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    }
    QTextStream in(&infile);
    while(!in.atEnd()) {
        in >> firstNum>> ch >>secondNum >> ch >> rawNum;
        if (rawNum.length() <= 5) {
        } else {
            return false;
        }
    }
    return true;
}

bool CSVParser::openInPath() {
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    } else {
        return true;
    }
}

bool CSVParser::openOutPath() {
    QFile outfile(outPath);
    if (!outfile.open(QIODevice::WriteOnly)) {
        qInfo() << outfile.errorString();
        return false;
    } else {
        return true;
    }
}

int CSVParser::getSumofDigits(QString num) {
    thirdNum = 0;
    for(auto &c : num) {
        if(c.isDigit()) {
            thirdNum += c.digitValue();
        }
    }
    return thirdNum;
}

quint64 CSVParser::calculateSum()
{
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    }
    QTextStream in(&infile);
    firstNum = 0;
    secondNum = 0;
    thirdNum = 0;
    in >> firstNum >> ch >>secondNum >> ch >> rawNum;
    for(auto &c : rawNum) {
        if(c.isDigit()) {
            thirdNum += c.digitValue();
        }
    }
    return firstNum + secondNum + thirdNum;
}

bool CSVParser::parser() {
    QFile infile(inPath);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return false;
    }
    QTextStream in(&infile);

    QFile outfile(outPath);
    if (!outfile.open(QIODevice::WriteOnly)) {
        qInfo() << outfile.errorString();
        return false;
    }
    QTextStream out(&outfile);

    QChar ch;
    qint64 lEpoch = QDateTime::currentMSecsSinceEpoch();
    qint64 cEpoch = lEpoch;
    firstNum = 0;
    secondNum = 0;
    thirdNum = 0;

    while(!in.atEnd()) {
        in >> firstNum >> ch >>secondNum >> ch >> rawNum;
        for(auto &c : rawNum) {
            if(c.isDigit()) {
                thirdNum += c.digitValue();
            }
        }
        out << firstNum + secondNum + thirdNum << Qt::endl;
        cEpoch = QDateTime::currentMSecsSinceEpoch();
        if((cEpoch - lEpoch) > 1000) {
            lEpoch = cEpoch;
            qInfo() << "Current Time is" << QDateTime::currentDateTime();
        }
    }
    return true;
}
