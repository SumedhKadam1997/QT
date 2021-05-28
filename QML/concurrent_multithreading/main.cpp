#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList str = {"jacob", "sunny", "john"};
    std::function<QString(const QString&)> processStr = [](const QString &str) -> QString
    {
        qDebug() << "Scaling string in thread" << QThread::currentThread();
        return str.toUpper();
    };
//    QFuture<QString> future = QtConcurrent::mapped(str, processStr);
    QFuture<QSet<QString>> future = QtConcurrent::mappedReduced(str, processStr, &QSet<QString>::insert);
    future.waitForFinished();
    qDebug() << future.results();
    return 0;
};
