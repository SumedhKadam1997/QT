#ifndef BRIGHTNESSMANAGER_HPP
#define BRIGHTNESSMANAGER_HPP

#include <QObject>
#include <QProcess>
#include <QDebug>

class BrightnessManager : public QObject
{
    Q_OBJECT
    QProcess brightnessProcess;
public:
    explicit BrightnessManager(QObject *parent = nullptr);
    Q_INVOKABLE void setBrightness(double value);

signals:

};

#endif // BRIGHTNESSMANAGER_HPP
