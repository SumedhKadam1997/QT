#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QDebug>

class MyRunnable : public QRunnable
{
public:
    MyRunnable();
private:
    void run() override {
        qDebug() << "Hello I'm a task from runnable";
    }
};

#endif // MYRUNNABLE_H
