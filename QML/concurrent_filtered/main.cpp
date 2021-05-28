#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QtConcurrent>
#include <QFuture>
#include <QSet>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList strings = {"JACOB", "martin", "JACKSON", "peter"};
//    QFuture<QSet<QString>> future = QtConcurrent::filteredReduced(strings, &QString::isLower, &QSet<QString>::insert);
    QFuture<QString> future = QtConcurrent::filtered(strings, &QString::isLower);
    future.waitForFinished();
    qDebug() << future.results();

    return a.exec();
}
