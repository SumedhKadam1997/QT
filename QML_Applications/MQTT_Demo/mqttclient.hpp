#ifndef MQTTCLIENT_HPP
#define MQTTCLIENT_HPP

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>
#include <QtMqtt/QMqttTopicName>

class MqttClient : public QObject
{
    Q_OBJECT
    QMqttClient *m_client = new QMqttClient();

public:
    explicit MqttClient(QObject *parent = nullptr);

signals:

};

#endif // MQTTCLIENT_HPP
