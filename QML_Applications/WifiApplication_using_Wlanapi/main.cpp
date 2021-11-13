#include <QCoreApplication>
#include <wifimanager.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WifiManager wifi;

    //    wifi.scanWifiNetwork();
    //        wifi.getProfileList();
    //    wifi.getAvailableWifiList();
    //        wifi.setProfile(L"UXORIOUSGHOST-MOBILE", L"qwerty12345");
    //    wifi.disconnectWifi();
    //    wifi.connectWifi(L"JioFi3_1F79D0");
    //        wifi.deleteProfile(L"UXORIOUSGHOST-MOBILE");

    return a.exec();
}
