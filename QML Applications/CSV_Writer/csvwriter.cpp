#include "csvwriter.hpp"

CSVWriter::CSVWriter(QObject *parent) : QObject(parent)
{

}

void CSVWriter::writeCSV()
{
    QString documentLoc = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << documentLoc;
    QFile file(documentLoc + "/data.csv");
//    QFile file("C:\\Users\\User\\Desktop\\data.csv");
    if (!file.open(QFile::ReadWrite | QFile::Truncate)) {
            qDebug() << "Cannot open file : " << file.errorString();
    } else {
        QTextStream out(&file);
        out << "value1" << "," << "value2" << "," << "value3"<< "," << "value4" << "," << "value5" << "," << "value6" << "\n";
        out << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "," << "value2" << "\n";
    }
    file.close();
}

void CSVWriter::readCSV()
{
    QString documentLoc = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << documentLoc;
    QFile file(documentLoc + "/data.csv");
//    QFile file("C:\\Users\\User\\Desktop\\data.csv");
    if (!file.open(QFile::ReadOnly)) {
            qDebug() << "Cannot open file : " << file.errorString();
    } else {
        qDebug() << file.readAll();
    }
    file.close();
}
