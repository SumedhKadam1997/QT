#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include <iostream>
#include <objbase.h>
#include <wtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <wlanapi.h>
#include <WcnDevice.h>
#include <QDebug>

class WifiManager
{
    HANDLE hClientHandle = NULL;
    GUID interfaceGuid = {0};
    WLAN_INTERFACE_INFO_LIST* pInterfaceList = 0;
    WLAN_CONNECTION_PARAMETERS pConnectionParameters;
    DWORD negVersion = 0;
    DWORD dwReason;
    UINT status = ERROR_SUCCESS;
    LPCWSTR pProfileName;
    PWLAN_PROFILE_INFO_LIST pProfileList = NULL;
    PWLAN_PROFILE_INFO pProfile = NULL;
    PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;
    PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
public:
    WifiManager();
    ~WifiManager();

    void setProfile(const WCHAR * profileName, const WCHAR * password);
    void scanWifiNetwork();
    void getAvailableWifiList();
    void getProfileList();
    void deleteProfile(const WCHAR * profileName);
    void connectWifi(const WCHAR * profileName);
    void disconnectWifi();
};

#endif // WIFIMANAGER_HPP
