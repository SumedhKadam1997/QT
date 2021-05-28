#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork() {
        for(int i = 0; i < 99; i++) {
            qDebug() << "Hello " << i;
        }
        emit resultReady();
    }

signals:
    void resultReady();
};

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller() {
        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &Worker::doWork);
        connect(worker, &Worker::resultReady, this, &Controller::handleResults);
        workerThread.start();
    }
    ~Controller() {
    }
    void emit_signal() {
        emit operate();
    }
public slots:
    void handleResults() {
        workerThread.quit();
        workerThread.wait();
    }
signals:
    void operate();
};
#endif // CONTROLLER_H
