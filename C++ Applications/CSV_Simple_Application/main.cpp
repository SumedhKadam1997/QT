#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(argc == 0 || argc == 1) {
        qInfo() << "--help";
        qInfo() << "Pass two arguments";
        qInfo() << "First Argument : Filepath of the input csv file";
        qInfo() << "Second Argument : Filepath of the output csv file";
    }

    if(!QFile(argv[1]).exists()){
        qInfo() << "Argument 1 Filepath Does not exists";
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
    quint32 firstNum;
    quint16 secondNum;
    quint32 thirdNum;
    QString rawNum;
    QChar ch;

    while(!in.atEnd()) {
        in >> firstNum >> ch >>secondNum >> ch >> rawNum;
        for(auto &c : rawNum) {
            if(c.isDigit()) {
                thirdNum += c.digitValue();
            }
        }
        out << firstNum + secondNum + thirdNum << Qt::endl;
//        qInfo() << "Total " << in.pos() << "MB of Data Processer";
    }
    return a.exec();
}
