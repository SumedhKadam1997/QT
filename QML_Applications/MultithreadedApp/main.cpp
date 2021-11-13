#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent>
#include <QThreadPool>
class FileParser {
    QString inPath = "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\C++ Applications\\data.csv";
    QString outPath = "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\C++ Applications\\result.csv";
    quint64 firstNum = 0;
    quint16 secondNum = 0;
    quint16 thirdNum = 0;
    QString rawNum;
    QChar ch;
public:
    bool parse(){
        QFile infile(inPath);
        if (!infile.open(QIODevice::ReadOnly)) {
            qInfo() << infile.errorString();
            return false;
        }
        QTextStream in(&infile);

        QFile outfile(outPath);
        if (!outfile.open(QIODevice::WriteOnly)) {
            qInfo() << outfile.errorString();
            return false;
        }
        QTextStream out(&outfile);

        QChar ch;
        qint64 lEpoch = QDateTime::currentMSecsSinceEpoch();
        qint64 cEpoch = lEpoch;
        firstNum = 0;
        secondNum = 0;
        thirdNum = 0;

        while(!in.atEnd()) {
            in >> firstNum >> ch >>secondNum >> ch >> rawNum;
            for(auto &c : rawNum) {
                if(c.isDigit()) {
                    thirdNum += c.digitValue();
                }
            }
            out << firstNum + secondNum + thirdNum << Qt::endl;
            cEpoch = QDateTime::currentMSecsSinceEpoch();
            if((cEpoch - lEpoch) > 1000) {
                lEpoch = cEpoch;
                qInfo() << "Current Time is" << QDateTime::currentDateTime();
            }
        }
        return true;
    }
};

class ConcurrentRun : public QObject {
    Q_OBJECT
    FileParser parser;
public:
    Q_INVOKABLE void run() {
        QFuture<void> future = QtConcurrent::run(std::bind(&FileParser::parse, &parser));
    }
};

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    ConcurrentRun runner;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("runner", &runner);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
