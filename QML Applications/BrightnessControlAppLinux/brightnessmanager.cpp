#include "brightnessmanager.hpp"

const QString num = QStringLiteral("%1");

BrightnessManager::BrightnessManager(QObject *parent) : QObject(parent)
{

}

void BrightnessManager::setBrightness(double value)
{
    qDebug() << "Process Started";
    brightnessProcess.start("bash", QStringList() << "-c" << "qrc:/setBrightness.sh" << num.arg(value));
    brightnessProcess.waitForFinished();
    qDebug() << "Process FInished";
}
