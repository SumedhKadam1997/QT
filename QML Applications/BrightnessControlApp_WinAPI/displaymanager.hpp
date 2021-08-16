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
//#include <WmiMonitorBrightnessMethods>

//using namespace root\\wmi;

class DisplayManager : public QObject
{
    Q_OBJECT
    QProcess brightnessProcess;
    Q_PROPERTY(double currentBrightnessLevel READ currentBrightnessLevel WRITE setCurrentBrightnessLevel NOTIFY currentBrightnessLevelChanged)
    double m_currentBrightnessLevel;

    HMONITOR hMonitor = NULL;
    HWND hWnd = NULL;
    DWORD cPhysicalMonitors;
    LPPHYSICAL_MONITOR pPhysicalMonitors = NULL;
    DWORD minBrightnessLevel = 0 , maxBrightnessLevel = 0, currBrightnessLevel = 0;

public:
    explicit DisplayManager(QObject *parent = nullptr);
    void getCurrentBrightnessWinAPI();
    Q_INVOKABLE void changeBrightnessWinAPI(const unsigned long & brightnessValue);
    Q_INVOKABLE void changeBrightnessQProcess(const double & brightnessValue);

    double currentBrightnessLevel() const;
    void setCurrentBrightnessLevel(double newCurrentBrightnessLevel);

signals:

    void currentBrightnessLevelChanged();
};

#endif // DISPLAYMANAGER_HPP
