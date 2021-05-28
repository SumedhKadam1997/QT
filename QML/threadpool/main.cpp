#include <QCoreApplication>
#include <QThreadPool>
#include "myrunnable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyRunnable * runner = new MyRunnable();
    QThreadPool::globalInstance()->start(runner);

    return a.exec();
}
