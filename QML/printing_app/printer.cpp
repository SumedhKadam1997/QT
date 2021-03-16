#include "printer.h"
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPixmap>
#include <QImage>
#include <QDebug>

printer::printer()
{

}

void printer::print(QString strImageSource)
{
    //    QImage img = qvariant_cast<QImage>(data);

    QPrinter printer;
    QPrintDialog *dlg = new QPrintDialog(&printer,0);
    if(dlg->exec() == QDialog::Accepted) {
        QImage img(strImageSource);
        QPainter painter(&printer);
        painter.drawImage(QPoint(0,0),img);
        painter.end();
        qDebug() << "Print successful.";

        //        QPainter painter(&printer);
        //        printer.setOutputFormat(QPrinter::NativeFormat);
        //        painter.drawImage(QPoint(0,0),img);
        //        painter.end();

        ////        QPrinter printer;
        //             printer.setOutputFormat(QPrinter::NativeFormat);
        //             QPainter painter;
        //             if (! painter.begin(&printer)) { // failed to open file
        //                 qWarning("failed to open file, is it writable?");
        ////                 return 1;
        //             }
        //             painter.drawImage(10, 10, img);
        //             if (! printer.newPage()) {
        //                 qWarning("failed in flushing page to disk, disk full?");
        ////                 return 1;
        //             }
        //             painter.drawText(10, 10, "Test 2");
        //             painter.end();
    }

}

//void printer::printImage(QImage imgImageSource)
//{
//    QPrinter printer;
//    QPrintDialog *dlg = new QPrintDialog(&printer,0);
//    if(dlg->exec() == QDialog::Accepted) {
//        QPainter painter(&printer);
//        painter.drawImage(QPoint(0,0),imgImageSource);
//        painter.end();
//    }
//}

void printer::printImage(QVariant var)
{
    QImage img = qvariant_cast<QImage>(var);
//    img.save("yay.png");
    QPrinter printer;
    QPrintDialog *dlg = new QPrintDialog(&printer,0);
    if(dlg->exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        painter.drawImage(QPoint(0,0),img);
        painter.end();
    }
}

