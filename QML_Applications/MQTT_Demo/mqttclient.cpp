#include "mqttclient.hpp"

MqttClient::MqttClient(QObject *parent) : QObject(parent)
{
    m_client = new QMqttClient(this);
//    this->connectHost();
//    m_client = new QMqttClient(this);
//    m_client->setHostname("broker.hivemq.com");
//    m_client->setPort(1883);
//    m_client->setWillQoS(2);
//    m_client->connectToHost();
//    this->subscribeTopics();
    connect(m_client, &QMqttClient::connected, this, &MqttClient::brokerConnected);
//    connect(m_client, &QMqttClient::stateChanged, this, &MqttClient::stateChanged);
    connect(m_client, &QMqttClient::disconnected, this, &MqttClient::brokerDisconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &MqttClient::handleMessages);
//    connect(m_client, &QMqttClient::pingResponseReceived, this, &MqttClient::pingResponseReceived);
}

void MqttClient::connectHost() {
//    this->getBrokerDetails();
//    m_client = new QMqttClient(this);
    m_client->setHostname("broker.hivemq.com");
    m_client->setPort(1883);
    m_client->setWillQoS(2);
    m_client->connectToHost();
    this->subscribeTopics();
}

void MqttClient::disconnectHost() {
    m_client->disconnectFromHost();
}

void MqttClient::publishMessage(const QString& topic, const QString &newMessage)
{
    if (this->checkConnection()) {
        m_client->publish(QMqttTopicName(topic), newMessage.toUtf8());
        qDebug() << "Publish: " << newMessage;
    } else {
        this->brokerDisconnected();
        m_client->publish(QMqttTopicName(topic), newMessage.toUtf8());
        qDebug() << "Publish: " << newMessage;
    }
}

void MqttClient::subscribeTopics()
{
    for (int i = 0; i < m_TopicsList.count(); ++i) {
        m_client->subscribe(m_TopicsList[i]);
    }
//    emit topicsSubscribed();
}

void MqttClient::handleMessages(const QByteArray &message, const QMqttTopicName &topic)
{
    qDebug() << "Topic Name: " << topic;
    qDebug() << "Message Received: " << message;
}

bool MqttClient::checkConnection()
{
    qDebug() << "Checking MQTT Connection!";
    if (m_client->state() == QMqttClient::Connected) {
        qDebug() << "Client Connected";
        return true;
    } else if (m_client->state() == QMqttClient::Disconnected) {
        qDebug() << "Client Disconnected";
        return false;
    } else {
        qDebug() << m_client->state();
        return false;
    }
}

void MqttClient::brokerConnected()
{
    qDebug() << "Broker Connected";
    this->subscribeTopics();
}

void MqttClient::brokerDisconnected()
{
    qDebug() << Q_FUNC_INFO << " : Client is Disconnected from broker.";
//    qDebug() << "Attempting to reconnect";
//    m_client->connectToHost();
//    if (m_client->state() == QMqttClient::Connected) {
//        qDebug() << "Client Connected";
//    } else if (m_client->state() == QMqttClient::Disconnected) {
//        qDebug() << "Client cannot connect";
//    }
}
