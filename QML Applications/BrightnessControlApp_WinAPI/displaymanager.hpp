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
#include <physicalmonitorenumerationapi.h>
#include <highlevelmonitorconfigurationapi.h>

class DisplayManager : public QObject
{
    Q_OBJECT
public:
    explicit DisplayManager(QObject *parent = nullptr);
    void changeBrightness();

signals:

};

#endif // DISPLAYMANAGER_HPP
