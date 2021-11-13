#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QFile>
#include <QTextStream>

class WifiManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString allScanned READ allScanned WRITE setAllScanned NOTIFY allScannedChanged)
    Q_PROPERTY(QString allAvailable READ allAvailable WRITE setAllAvailable NOTIFY allAvailableChanged)
    QProcess wifiProcess;
    QString m_allScanned;
    QString m_allAvailable;

public:
    explicit WifiManager(QObject *parent = nullptr);

    Q_INVOKABLE void scanNetworks();
    Q_INVOKABLE void allAvailableNetworks();
    Q_INVOKABLE void connectNetwork(const QString &SSID);
    Q_INVOKABLE void addWifiProfile(const QString &name, const QString &pass);

    const QString &allScanned() const;
    void setAllScanned(const QString &newAllScanned);

    const QString &allAvailable() const;
    void setAllAvailable(const QString &newAllAvailable);

signals:

    void allScannedChanged();
    void allAvailableChanged();
};

#endif // WIFIMANAGER_H
