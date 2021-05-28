#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include "myrunnable.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
    QThreadPool *pool;
public:
    explicit MyServer(QObject *parent = nullptr);

    void startServer();
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // MYSERVER_H
