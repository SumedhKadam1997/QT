#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

QThread * MyThread::getThread()
{
    QThread *mythread = new QThread();
    return mythread;
}
