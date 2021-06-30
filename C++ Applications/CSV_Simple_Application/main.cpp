#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    if(argc == 0 || argc == 1) {
        qInfo() << "--help";
        qInfo() << "Pass two arguments";
        qInfo() << "First Argument : Filepath of the input csv file";
        qInfo() << "Second Argument : Filepath of the output csv file";
        return 1;
    }

    if(!QFile(argv[1]).exists()){
        qInfo() << "Argument 1 Filepath Does not exists";
        return 1;
    }

    QFile infile(argv[1]);
    if (!infile.open(QIODevice::ReadOnly)) {
        qInfo() << infile.errorString();
        return 1;
    }
    QTextStream in(&infile);

    QFile outfile(argv[2]);
    if (!outfile.open(QIODevice::WriteOnly)) {
        qInfo() << outfile.errorString();
        return 1;
    }
    QTextStream out(&outfile);
    quint32 firstNum = 0;
    quint16 secondNum = 0;
    quint16 thirdNum = 0;
    QString rawNum;
    QChar ch;
    qint64 lEpoch = QDateTime::currentMSecsSinceEpoch();
    qint64 cEpoch = lEpoch;

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
//            qInfo() << "Total " << (in.pos() / infile.size()) * 100 << " % of Data Processed";
            qInfo() << "Current Time is" << QDateTime::currentDateTime();
        }
    }
//    return a.exec();
}
