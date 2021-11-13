#include "wifimanager.h"

static const QString connectProfile = QStringLiteral("netsh wlan connect name=%1");
static const QString addProfile = QStringLiteral("netsh wlan add profile filename=%1");

WifiManager::WifiManager(QObject *parent) : QObject(parent)
{
    this->scanNetworks();
    this->allAvailableNetworks();
}

void WifiManager::scanNetworks()
{
    wifiProcess.start("powershell", QStringList()<<"/c"<<"netsh wlan show networks");
    wifiProcess.waitForFinished();
    setAllScanned(wifiProcess.readAllStandardOutput());
}

void WifiManager::allAvailableNetworks()
{
    wifiProcess.start("powershell", QStringList()<<"/c"<<"netsh wlan show profile");
    wifiProcess.waitForFinished();
    setAllAvailable(wifiProcess.readAllStandardOutput());
}

void WifiManager::connectNetwork(const QString &SSID)
{ 
    wifiProcess.start("powershell", QStringList()<<"/c"<<connectProfile.arg(SSID));
    wifiProcess.waitForFinished();
    QString StdOut = wifiProcess.readAllStandardOutput();
    qDebug() << StdOut;
}

void WifiManager::addWifiProfile(const QString &SSID, const QString &pass)
{
//    QString str;
    QFile xmlDoc("wifiProfile.xml");
    xmlDoc.open(QIODevice::WriteOnly);
    QTextStream outStream(&xmlDoc);
    char c='"';
    //    QXmlStreamWriter stream(&str);
    //    stream.setAutoFormatting(true);
    //    stream.writeStartDocument();
    //    stream.writeStartElement("bookmark");
    //    stream.writeAttribute("href", "http://qt-project.org/");
    //    stream.writeTextElement("title", "Qt Project");
    //    stream.writeEndElement(); // bookmark
    //    stream.writeEndDocument();
    outStream << "<?xml version=" << c << "1.0" << c << "?>\n";
    outStream << "<WLANProfile xmlns=" << c << "http://www.microsoft.com/networking/WLAN/profile/v1" << c << ">\n";
    outStream << "<name>";
    outStream << SSID;
    outStream << "</name>\n<SSIDConfig>\n<SSID>\n<hex>";
    outStream << SSID.toLatin1().toHex();
    outStream << "</hex>\n<name>";
    outStream << SSID;
    outStream << "</name>\n</SSID>\n</SSIDConfig>\n<connectionType>ESS</connectionType>\n<connectionMode>auto</connectionMode>\n<MSM>\n<security>\n<authEncryption>";
    outStream << "\n<authentication>WPA2PSK</authentication>\n<encryption>AES</encryption>\n<useOneX>false</useOneX>\n</authEncryption>\n<sharedKey>";
    outStream << "\n<keyType>passPhrase</keyType>\n<protected>false</protected>\n<keyMaterial>";
    outStream << pass;
    outStream << "</keyMaterial>\n</sharedKey>\n</security>\n</MSM>\n";
    outStream << "<MacRandomization xmlns=" << c << "http://www.microsoft.com/networking/WLAN/profile/v3" << c << ">\n";
    outStream << "<enableRandomization>false</enableRandomization>\n</MacRandomization>\n</WLANProfile>";
    xmlDoc.close();
//    outStream << str;
    wifiProcess.start("powershell", QStringList()<<"/c"<<addProfile.arg("wifiProfile.xml"));
}

const QString &WifiManager::allScanned() const
{
    return m_allScanned;
}

void WifiManager::setAllScanned(const QString &newAllScanned)
{
    if (m_allScanned == newAllScanned)
        return;
    m_allScanned = newAllScanned;
    emit allScannedChanged();
}

const QString &WifiManager::allAvailable() const
{
    return m_allAvailable;
}

void WifiManager::setAllAvailable(const QString &newAllAvailable)
{
    if (m_allAvailable == newAllAvailable)
        return;
    m_allAvailable = newAllAvailable;
    emit allAvailableChanged();
}
