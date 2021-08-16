#include "displaymanager.hpp"

const QString brightness = QStringLiteral("$brightness = %1;");
DisplayManager::DisplayManager(QObject *parent) : QObject(parent)
{
    this->getCurrentBrightnessWinAPI();
}

void DisplayManager::getCurrentBrightnessWinAPI()
{
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
            monitor = GetMonitorBrightness(handle, &minBrightnessLevel, &currBrightnessLevel, &maxBrightnessLevel);
            if (monitor == false) {
                std::cout << "Getting Brightness Failed" << std::endl;
                DestroyPhysicalMonitors(
                            cPhysicalMonitors,
                            pPhysicalMonitors);
                // Free the array.
                free(pPhysicalMonitors);
                return;
            }
            setCurrentBrightnessLevel(static_cast<double>(currBrightnessLevel));
            emit currentBrightnessLevelChanged();
        }
    }
}

void DisplayManager::changeBrightnessWinAPI(const unsigned long & brightnessValue)
{
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
//            monitor = GetMonitorBrightness(handle, &minBrightnessLevel, &currBrightnessLevel, &maxBrightnessLevel);
//            if (monitor == false) {
//                std::cout << "Getting Brightness Failed" << std::endl;
//                DestroyPhysicalMonitors(
//                            cPhysicalMonitors,
//                            pPhysicalMonitors);
//                // Free the array.
//                free(pPhysicalMonitors);
//                return;
//            }
//            setCurrentBrightnessLevel(static_cast<double>(currBrightnessLevel));
//            emit currentBrightnessLevelChanged();

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


void DisplayManager::changeBrightnessQProcess(const double & brightnessValue) {
    qDebug() << "Process Started";
    brightnessProcess.start("powershell", QStringList() <<"/c" << brightness.arg(brightnessValue) <<"$delay = 5;" <<
                            "$myMonitor = Get-WmiObject -Namespace root\\wmi -Class WmiMonitorBrightnessMethods;" <<
                            "$myMonitor.wmisetbrightness($delay, $brightness)");
    brightnessProcess.waitForFinished();
    qDebug() << "Process Finished";
//    QString StdOut = brightnessProcess.readAllStandardOutput();
    //        qDebug() << StdOut;
    //    brightnessProcess.start("powershell", QStringList() << "/c" << "C:\\Users\\User\\Desktop\\QT-QML\\QML Applications\\BrightnessControlApp_WinAPI\\brightnessScript.ps1");
    //    brightnessProcess.waitForFinished();
}

double DisplayManager::currentBrightnessLevel() const
{
    return m_currentBrightnessLevel;
}

void DisplayManager::setCurrentBrightnessLevel(double newCurrentBrightnessLevel)
{
    if (m_currentBrightnessLevel == newCurrentBrightnessLevel)
        return;
    m_currentBrightnessLevel = newCurrentBrightnessLevel;
    emit currentBrightnessLevelChanged();
}
