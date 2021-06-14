#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QQueue>
#include <QtConcurrent>
#include <QThreadPool>
#include <QDateTime>


quint64 process_line(QString &line){
    quint64 sum = 0;
    QString number;
    QStringList list = line.split(",");
    for(int i = 0; i < list.length(); ++i) {
        for( int j = 0; j < list[i].length(); ++j) {
            if (i == 2) {
                int thirdNumber = 0;
                if (list[i][j] > 47 && list[i][j] < 58) {
                    QString third;
                    third.push_back(list[i][j]);
                    qint16 num = third.toInt();
                    thirdNumber += num;
                }
                sum += thirdNumber;
            } else if (list[i][j] > 47 && list[i][j] < 58) {
                number.push_back(list[i][j]);
            }
        }
        sum = sum + number.toULongLong();
        number.clear();
    }
    return sum;
}

void readLine(QTextStream *intext, QQueue<QString> *queue) {
    qDebug() << "Reading data from input file";
    while (!intext->atEnd()) {
        QString line = intext->readLine();
        queue->enqueue(line);
    }
}

void writeLine(QTextStream *outtext, QQueue<QString> *queue) {
    qDebug() << "Writing data to output file";
    while (!queue->isEmpty()){
        QString line = queue->dequeue();
        *outtext << process_line(line) << "\r\n";
    }
}

void getString() {
    qDebug() <<  "Running";
}

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    if(argc == 0 || argc == 1) {
        qDebug() << "--help";
        qDebug() << "Pass two arguments";
        qDebug() << "First Argument : Filepath of the input csv file";
        qDebug() << "Second Argument : Filepath of the output csv file";
    }

    if(!QFile(argv[1]).exists()){
        qDebug() << "Argument 1 Filepath Does not exists";
    }

    QFile infile(argv[1]);
    if (!infile.open(QIODevice::ReadOnly)) {
        qDebug() << infile.errorString();
        return 1;
    }
    QTextStream *in = new QTextStream(&infile);

    QFile outfile(argv[2]);
    if (!outfile.open(QIODevice::WriteOnly)) {
        qDebug() << outfile.errorString();
        delete in;
        return 1;
    }
    QTextStream *out = new QTextStream(&outfile);

    QQueue<QString> *queue = new QQueue<QString>;

    QThreadPool myPool;
    myPool.setMaxThreadCount(10);

    QFuture<void> future = QtConcurrent::run(&myPool, readLine, in, queue);
    for(int i = 0; i < 100; ++i) {
        qDebug() << "Waiting for first thread to enqueue";
    }
    QFuture<void> future2 = QtConcurrent::run(&myPool, writeLine, out, queue);
//    QDateTime currentDate;
//    while (future.isRunning()) {
//        qDebug() << currentDate.currentDateTime();
//    }

    future.waitForFinished();

//    while (future2.isRunning()) {
//        qDebug() << currentDate.currentDateTime();
//    }
    future2.waitForFinished();
    delete in;
    delete out;
    delete queue;
//    return a.exec();

}
