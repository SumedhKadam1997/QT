#include "processor.h"
#include <QDebug>


processor::processor(QObject *parent) : QObject(parent)
{

}

void processor::onMenuClicked(const QString &str)
{
    qDebug() << str;
}
