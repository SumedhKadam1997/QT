#include "paint_and_print.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QImage>

paint_and_print::paint_and_print(QQuickItem *parent):
    QQuickPaintedItem(parent)
{
//    QQuickPaintedItem(parent)
}

void paint_and_print::paint(QPainter *painter)
{
    QImage img("://images//pics//insert.png");
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->setBrush(QColor("red"));
    painter->setOpacity(0.5);
    painter->drawImage(QPoint(0,0),img);
    painter->drawText(QPoint(10,10),"HELLO WORLD");
}

//void paint_and_print::printImage(QString imgImageSource = "C:\\Users\\uxoriousghost\\Desktop")
//{
//    QPrinter printer;
//    QPrintDialog *dlg = new QPrintDialog(&printer,0);
//    if(dlg->exec() == QDialog::Accepted) {
//        QImage img(imgImageSource);
//        QPainter painter(&printer);
//        painter.drawImage(QPoint(0,0),img);
//        painter.end();
//    }
//}
