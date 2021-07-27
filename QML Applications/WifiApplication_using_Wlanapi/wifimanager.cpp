#include "wifimanager.hpp"

WifiManager::WifiManager()
{
    status = WlanOpenHandle(
                WLAN_API_VERSION_2_0,
                NULL,
                &negVersion,
                &hClientHandle);
    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Handle Open Failed";
    } else {
        qDebug() << "Wifi Handle Opened";
    }

    status = WlanEnumInterfaces(hClientHandle, NULL, &pInterfaceList);

    if (status != ERROR_SUCCESS) {
        qDebug() << "WLanEnumInterfaces failed";
        if (hClientHandle != NULL) {
            WlanCloseHandle(hClientHandle,NULL);
        }

        if (pInterfaceList != NULL) {
            WlanFreeMemory(pInterfaceList);
        }
        return;
    }

    interfaceGuid = pInterfaceList->InterfaceInfo[0].InterfaceGuid;
}

WifiManager::~WifiManager()
{
    if (hClientHandle != NULL) {
        WlanCloseHandle(hClientHandle,NULL);
    }
    if (pInterfaceList != NULL) {
        WlanFreeMemory(pInterfaceList);
    }
    if (pBssList != NULL) {
        WlanFreeMemory(pBssList);
    }
    if (pProfileList != NULL) {
        WlanFreeMemory(pProfileList);
    }
}

void WifiManager::setProfile(const WCHAR * profileName, const WCHAR * password)
{
    WCHAR profileBuffer[WCN_API_MAX_BUFFER_SIZE] = {0};

    WCHAR WCNConnectionProfileTemplate[] =
            L"<?xml version=\"1.0\" ?>"
            L""
            L"<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">"
            L"    <name>%s</name>"
            L""
            L"    <SSIDConfig>"
            L"        <SSID>"
            L"            <name>%s</name>"
            L"        </SSID>"
            L"    </SSIDConfig>"
            L"    "
            L"    <connectionType>ESS</connectionType>"
            L"    <connectionMode>auto</connectionMode>"
            L""
            L"    <MSM>"
            L"        <security>"
            L"            <authEncryption>"
            L"                <authentication>WPA2PSK</authentication>"
            L"                <encryption>AES</encryption>"
            L"            </authEncryption>"
            L""
            L""
            L"            <sharedKey>"
            L"                <keyType>passPhrase</keyType>"
            L"                <protected>false</protected>"
            L"                <keyMaterial>%s</keyMaterial>"
            L"            </sharedKey>"
            L""
            L"        </security>"
            L"    </MSM>"
            L"</WLANProfile>";

    swprintf_s(profileBuffer, WCNConnectionProfileTemplate, profileName, profileName, password);

    status = WlanSetProfile(hClientHandle, &interfaceGuid, 0, profileBuffer, NULL, true, NULL, &dwReason);

    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Profile Failed";
    } else {
        qDebug() << "Wifi Profile Saved";
    }
}

void WifiManager::scanWifiNetwork()
{
    status = WlanScan(hClientHandle, &interfaceGuid, NULL, NULL, NULL);
    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Scan Failed";
    } else {
        qDebug() << "Wifi Scan Successfull";
    }
}

void WifiManager::getAvailableWifiList()
{
    status = WlanGetAvailableNetworkList(hClientHandle, &interfaceGuid, WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_ADHOC_PROFILES, NULL, &pBssList);
    if (status != ERROR_SUCCESS) {
        qDebug() << "Available Wifi List Failed";
    } else {
        qDebug() << "Available Wifi List Success";
    }
    qDebug() << pBssList->dwNumberOfItems;

    for (unsigned int j = 0; j < pBssList->dwNumberOfItems; j++) {
        pBssEntry = (WLAN_AVAILABLE_NETWORK *) &pBssList->Network[j];
        wprintf(L"Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);
        std::cout << "Profile[" << j << "] ";
        for (quint8 k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
            std::cout << pBssEntry->dot11Ssid.ucSSID[k];
        }
        std::cout << std::endl;
    }
    std::cout << "END" << std::endl;
}

void WifiManager::getProfileList()
{
    status = WlanGetProfileList (hClientHandle, &interfaceGuid, NULL, &pProfileList);
    if (status != ERROR_SUCCESS) {
        qDebug() << "Profile List Failed";
    } else {
        qDebug() << "Profile List Success";
    }
    for (unsigned int j = 0; j <= pProfileList->dwNumberOfItems; j++) {
        pProfile = (WLAN_PROFILE_INFO *) &pProfileList->ProfileInfo[j];
//        wprintf(L"Profile Name[%u]:  %ws\n", j, pProfile->strProfileName);
        std::wcout << "Profile Name[" << j << "] : " << pProfile->strProfileName << std::endl;
    }
    if (pProfileList == NULL) {
        WlanFreeMemory(pProfileList);
    }
}

void WifiManager::deleteProfile(const WCHAR * profileName)
{
    pProfileName = profileName;

    status = WlanDeleteProfile(hClientHandle, &interfaceGuid, pProfileName, NULL);

    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Profile Delete Failed";
    } else {
        qDebug() << "Wifi Profile Deleted";
    }
}

void WifiManager::connectWifi(const WCHAR * profileName)
{
    pConnectionParameters.strProfile = profileName;
    pConnectionParameters.pDot11Ssid = NULL;
    pConnectionParameters.pDesiredBssidList = NULL;
    pConnectionParameters.dwFlags = WLAN_CONNECTION_HIDDEN_NETWORK;
    pConnectionParameters.wlanConnectionMode = wlan_connection_mode_profile;
    pConnectionParameters.dot11BssType = dot11_BSS_type_any;
    status = WlanConnect(hClientHandle, &interfaceGuid, &pConnectionParameters, NULL);

    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Connect Failed";
    } else {
        qDebug() << "Wifi Connected";
    }
}

void WifiManager::disconnectWifi()
{
    status = WlanDisconnect(hClientHandle, &interfaceGuid, NULL);

    if (status != ERROR_SUCCESS) {
        qDebug() << "Wifi Disconnect Failed";
    } else {
        qDebug() << "Wifi Disconnected";
    }
}
