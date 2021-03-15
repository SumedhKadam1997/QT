#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>
#include <QVariant>

class printer : public QObject
{
    Q_OBJECT
public:
    printer();

public slots:
    Q_INVOKABLE void print(QString data);
    Q_INVOKABLE void printImage(QImage imgImageSource);
};

#endif // PRINTER_H
