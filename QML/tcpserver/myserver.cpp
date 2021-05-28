#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}

void MyServer::startServer()
{
    if(this->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server Started";
    } else {
        qDebug() << "Server Did not start";
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    MyRunnable * runner = new MyRunnable();
    runner->setAutoDelete(true);
    runner->SocketDescriptor = handle;

    pool->start(runner);
}
