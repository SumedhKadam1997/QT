#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QDir>
#include <QObject>
#include <QStandardPaths>
#include <QTextStream>


void demoFunc() {
    qDebug() << "Just doing some fun!!";
}

class MyClass : public QObject {
    Q_OBJECT
    QString homeLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
public:

    MyClass() {
        connect(this, &MyClass::emergencyFileCreated, this, &MyClass::readEmergencyNumber);
    }

    void readEmergencyNumber()
    {
        QFile file(homeLocation + "/number.txt");
        if (!file.open(QFile::ReadOnly)) {
            qDebug() << "Read File: Cannot open file: " << file.errorString();
            createEmergencyNumber();
        } else {
            qDebug() << "Reading Emergency File";
            QString num;
            QTextStream in(&file);
            in >> num;
            qDebug() << "Num: " << num;
            //        this->setENumber(num);
            file.close();
        }
    }

    void createEmergencyNumber()
    {
        QFile file(homeLocation + "/number.txt");
        if (!file.open(QFile::ReadWrite | QFile::Truncate)) {
            qDebug() << "Create File: Cannot open file: " << file.errorString();
        } else {
            QTextStream out(&file);
            out << "9421463288";
            file.close();
            qDebug() << "Emergency File Created";
            emit emergencyFileCreated();
        }
    }
signals:
    void emergencyFileCreated();
};

#include "main.moc"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    MyClass obj;

    obj.readEmergencyNumber();

    demoFunc();

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
