#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include <QDebug>
#include <QObject>
#include <QReadWriteLock>

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() override {
        for (int i = 0; i < 99; i++) {
            qDebug() << "HELLO" << i;
        }
    }


    void read_file();

    QByteArray data;
    void write_file();
    QReadWriteLock lock;

    QByteArray readData()
    {
        QReadLocker locker(&lock);
        return data;
    }
};

#endif // WORKERTHREAD_H
