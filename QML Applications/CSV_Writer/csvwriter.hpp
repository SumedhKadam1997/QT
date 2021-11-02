#ifndef CSVWRITER_HPP
#define CSVWRITER_HPP

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>

class CSVWriter : public QObject
{
    Q_OBJECT
public:
    explicit CSVWriter(QObject *parent = nullptr);
    Q_INVOKABLE void writeCSV();
    void readCSV();

signals:

};

#endif // CSVWRITER_HPP
