#include <QCoreApplication>
#include <QDebug>
#include "workerthread.h"
class Worker : public QObject
{
    Q_OBJECT
public:
    void doWork() {
        for (int i = 0; i < 99; i++) {
            qDebug() << "WORLD" << i;
        }
    }
};

void startWorkinThread(){
    WorkerThread workthread;
    Worker worker;
    worker.moveToThread(&workthread);
    workthread.start();
    worker.doWork();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    startWorkinThread();
    return a.exec();
}
