#ifndef PAINT_AND_PRINT_H
#define PAINT_AND_PRINT_H

//#include <QtWidgets>
#include <QObject>
#include <QPainter>
#include <QtQuick/QQuickPaintedItem>


class paint_and_print : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit paint_and_print(QQuickItem *parent = 0);
//    Q_INVOKABLE void printImage(QString imgImageSource);
    void paint(QPainter *painter) override;

};

#endif // PAINT_AND_PRINT_H
