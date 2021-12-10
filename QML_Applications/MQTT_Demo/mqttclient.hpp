#ifndef MQTTCLIENT_HPP
#define MQTTCLIENT_HPP

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>
#include <QtMqtt/QMqttTopicName>

class MqttClient : public QObject
{
    Q_OBJECT
    QMqttClient *m_client;
    QString m_messageReceived;
    const QStringList m_TopicsList = {"hmi.verolt.vego/BMD/speed",
                                      "hmi.verolt.vego/BMD/emergency",
                                      "hmi.verolt.vego/BMD/driveMode",
                                      "hmi.verolt.vego/BMD/changeDriveMode",
                                      "hmi.verolt.vego/BMD/navigationStatus",
                                      "hmi.verolt.vego/BMD/navigation",
                                      "hmi.verolt.vego/BMD/endTrip"
                                     };

public:
    explicit MqttClient(QObject *parent = nullptr);

    Q_INVOKABLE void publishMessage(const QString &, const QString &);
    Q_INVOKABLE void connectHost();
    Q_INVOKABLE void disconnectHost();
    void subscribeTopics();
    void handleMessages(const QByteArray &, const QMqttTopicName &);
    bool checkConnection();

    void brokerConnected();
    void brokerDisconnected();

signals:

};

#endif // MQTTCLIENT_HPP
