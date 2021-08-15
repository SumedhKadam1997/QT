#include "displaymanager.hpp"

static const QString setBrightness = QStringLiteral("$myMonitor.wmisetbrightness($delay, $brightness)");

DisplayManager::DisplayManager(QObject *parent) : QObject(parent)
{

}

void DisplayManager::changeBrightnessWinAPI(const unsigned long & brightnessValue)
{
    HMONITOR hMonitor = NULL;
    HWND hWnd = NULL;
    DWORD cPhysicalMonitors;
    LPPHYSICAL_MONITOR pPhysicalMonitors = NULL;
    //    DWORD pdwMonitorCapabilities = NULL, pdwSupportedColorTemperatures = 0;
    DWORD minBrightnessLevel = 0 , maxBrightnessLevel = 0;

    //    hWnd = GetDesktopWindow();
    hWnd = FindWindow(NULL, NULL);

    // Get the monitor handle.
    hMonitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY);
    // Get the number of physical monitors.
    bool bSuccess = GetNumberOfPhysicalMonitorsFromHMONITOR(
                hMonitor,
                &cPhysicalMonitors
                );
    std::wcout << "Monitor Handle Success" << std::endl;

    if (bSuccess)
    {
        // Allocate the array of PHYSICAL_MONITOR structures.
        pPhysicalMonitors = (LPPHYSICAL_MONITOR)malloc(
                    cPhysicalMonitors* sizeof(PHYSICAL_MONITOR));
        std::wcout << pPhysicalMonitors->szPhysicalMonitorDescription << std::endl;

        if (pPhysicalMonitors != NULL)
        {
            // Get the array.
            BOOL monitor;
            bSuccess = GetPhysicalMonitorsFromHMONITOR(
                        hMonitor, cPhysicalMonitors, pPhysicalMonitors);
            std::wcout << "cPhysicalMonitors : " << bSuccess << std::endl;
            HANDLE handle = pPhysicalMonitors[0].hPhysicalMonitor;
            //            GetMonitorCapabilities(handle, &pdwMonitorCapabilities, &pdwSupportedColorTemperatures);
            //            std::wcout << "Monitor Capabilities : " << pdwMonitorCapabilities << std::endl;
            monitor = GetMonitorBrightness(handle, &minBrightnessLevel, &m_currentBrightnessLevel, &maxBrightnessLevel);
            if (monitor == false) {
                std::cout << "Getting Brightness Failed" << std::endl;
                DestroyPhysicalMonitors(
                            cPhysicalMonitors,
                            pPhysicalMonitors);
                // Free the array.
                free(pPhysicalMonitors);
                return;
            }
            emit currentBrightnessLevelChanged();
            //            DWORD newBrightnessLevel = maxBrightnessLevel - 70;

            monitor = SetMonitorBrightness(handle, brightnessValue);
            if (monitor == false) {
                std::cout << "Setting Brightness Failed" << std::endl;
                DestroyPhysicalMonitors(
                            cPhysicalMonitors,
                            pPhysicalMonitors);
                // Free the array.
                free(pPhysicalMonitors);
                return;
            }
            SaveCurrentMonitorSettings(handle);
            // Close the monitor handles.
            DestroyPhysicalMonitors(
                        cPhysicalMonitors,
                        pPhysicalMonitors);
            // Free the array.
            free(pPhysicalMonitors);
        }
    }
}


void DisplayManager::changeBrightnessQProcess(const int & brightnessValue) {
    //    qDebug() << "Process Started";
    //    brightnessProcess.start("powershell", QStringList()<<"/c" << "$brightness = 50"<<"$delay = 5" <<
    //                            "$myMonitor = Get-WmiObject -Namespace root\\wmi -Class WmiMonitorBrightnessMethods" <<
    //                            "$myMonitor.wmisetbrightness($delay, $brightness)");
    //    brightnessProcess.waitForFinished();
    //    qDebug() << "Process Finished";
    //    QString StdOut = brightnessProcess.readAllStandardOutput();
    //    qDebug() << StdOut;
    brightnessProcess.start("cmd", QStringList() << "/c" << "powershell" << "C:\\Users\\User\\Desktop\\QT-QML\\QML Applications\\BrightnessControlApp_WinAPI\\brightnessScript.ps1");
    brightnessProcess.waitForFinished();
}

unsigned long DisplayManager::currentBrightnessLevel() const
{
    return m_currentBrightnessLevel;
}

void DisplayManager::setCurrentBrightnessLevel(unsigned long newCurrentBrightnessLevel)
{
    if (m_currentBrightnessLevel == newCurrentBrightnessLevel)
        return;
    m_currentBrightnessLevel = newCurrentBrightnessLevel;
    emit currentBrightnessLevelChanged();
}
