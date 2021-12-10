#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QDebug>

class Internet : public QObject {
    Q_OBJECT
public:

    bool checkInternet() {
        QNetworkAccessManager nam;
        QNetworkRequest req(QUrl("http://www.google.com"));
        QNetworkReply* reply = nam.get(req);
        QEventLoop loop;
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        if (reply->bytesAvailable()) {
            qDebug() << "Internet Connected!";
            return true;
        }
        else {
            qDebug() << "Internet Disconnected!";
            return false;
        }
    }
};

#include "main.moc"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    Internet i;
    i.checkInternet();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
