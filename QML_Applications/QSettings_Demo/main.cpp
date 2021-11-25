#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStandardPaths>
#include <QSettings>
#include <QFile>

class Demo : public QObject {
    Q_OBJECT
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString filename = "vegoConfig.ini";
public:
    Demo(){
        QFile file(path + "/" + filename);
        if (!file.exists()) {
            this->createSettings();
        } else {
            this->readSettings();
        }
        file.close();
    }
    ~Demo() {

    }

    void createSettings() {
        qDebug() << path;
        QSettings settings(path + "/" + filename, QSettings::IniFormat);
        if (settings.status() == QSettings::NoError) {
            //General Data
            settings.setValue("APPLICATION_NAME", "VeGO");
            settings.setValue("ORGANISATION_NAME", "VEROLT ENGINEERING");
            settings.setValue("DEVELOPERS", "Sumedh Kadam, Pavan Myana");
            settings.setValue("WEB_ADDRESS", "hmi.verolt.com");
            //Grouped Data
            settings.setValue("LANG/Programming_Language", "C++");
            settings.setValue("LANG/Framework", "Qt Framework");
            // Emergency Data
            settings.setValue("Emergency/SOS_NUMBER", "9421463288");
            // MQTT Data
            settings.setValue("MQTT/MQTT_BROKER_HOSTNAME", "broker.hivemq.com");
            settings.setValue("MQTT/MQTT_BROKER_PORT_NO", 1883);
            settings.sync();
        } else {
            qDebug() << settings.status();
        }
        this->readSettings();
    }

    void readSettings() {
        qDebug() << "Reading Settings";
        QSettings settings(path + "/" + filename, QSettings::IniFormat);
        qDebug() << settings.value("MQTT/MQTT_BROKER_HOSTNAME").toString();
    }

};

#include "main.moc"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Demo demo;

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
