#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

class MyRunnable : public QRunnable
{
public:
    MyRunnable();
    int SocketDescriptor;

protected:
    void run() override;
};

#endif // MYRUNNABLE_H
