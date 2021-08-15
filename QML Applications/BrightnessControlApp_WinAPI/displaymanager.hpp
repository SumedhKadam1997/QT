//#pragma comment(lib,"Dxva2.lib")
#ifndef DISPLAYMANAGER_HPP
#define DISPLAYMANAGER_HPP

#include <iostream>
#include <QObject>
#include <objbase.h>
#include <wtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <winuser.h>
#include <QDebug>
#include <QProcess>
#include <physicalmonitorenumerationapi.h>
#include <highlevelmonitorconfigurationapi.h>

class DisplayManager : public QObject
{
    Q_OBJECT
    QProcess brightnessProcess;
    Q_PROPERTY(unsigned long currentBrightnessLevel READ currentBrightnessLevel WRITE setCurrentBrightnessLevel NOTIFY currentBrightnessLevelChanged)
    unsigned long m_currentBrightnessLevel;

public:
    explicit DisplayManager(QObject *parent = nullptr);
    Q_INVOKABLE void changeBrightnessWinAPI(const unsigned long & brightnessValue);
    void changeBrightnessQProcess(const int & brightnessValue);

    unsigned long currentBrightnessLevel() const;
    void setCurrentBrightnessLevel(unsigned long newCurrentBrightnessLevel);

signals:

    void currentBrightnessLevelChanged();
};

#endif // DISPLAYMANAGER_HPP
