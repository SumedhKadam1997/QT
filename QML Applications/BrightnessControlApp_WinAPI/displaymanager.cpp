#include "displaymanager.hpp"

DisplayManager::DisplayManager(QObject *parent) : QObject(parent)
{

}

void DisplayManager::changeBrightness()
{
    HMONITOR hMonitor = NULL;
    HWND hWnd = NULL;
    DWORD cPhysicalMonitors;
    LPPHYSICAL_MONITOR pPhysicalMonitors = NULL;
    DWORD pdwMonitorCapabilities = NULL, pdwSupportedColorTemperatures = 0;
//    unsigned long int bright = 0;
    DWORD minBrightnessLevel = 0 , maxBrightnessLevel = 0, currentBrightnessLevel = 0 ;

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
    std::wcout << "GetPhysicalMonitors : " << bSuccess << std::endl;

    if (bSuccess)
    {
//        qDebug() << "Handle Success";
        // Allocate the array of PHYSICAL_MONITOR structures.
        pPhysicalMonitors = (LPPHYSICAL_MONITOR)malloc(
            cPhysicalMonitors* sizeof(PHYSICAL_MONITOR));
        std::wcout << pPhysicalMonitors << std::endl;

        if (pPhysicalMonitors != NULL)
        {
            // Get the array.
            BOOL monitor;
            bSuccess = GetPhysicalMonitorsFromHMONITOR(
                hMonitor, cPhysicalMonitors, pPhysicalMonitors);
            std::wcout << "cPhysicalMonitors : " << bSuccess << std::endl;
            HANDLE handle = pPhysicalMonitors[0].hPhysicalMonitor;
            GetMonitorCapabilities(handle, &pdwMonitorCapabilities, &pdwSupportedColorTemperatures);
            std::wcout << "Monitor Capabilities : " << pdwMonitorCapabilities << std::endl;
            monitor = GetMonitorBrightness(handle, &minBrightnessLevel, &currentBrightnessLevel, &maxBrightnessLevel);
            if (monitor == false) {
                std::cout << "Getting Brightness Failed" << std::endl;
                return;
            }
//            std::wcout << "Getting Brightness Success : " << monitor << std::endl;
//            std::wcout << "Brightness Level : " << maxBrightnessLevel << std::endl;
            DWORD newBrightnessLevel = maxBrightnessLevel - 70;

           // Use the monitor handles (not shown).
//            unsigned long num = 0 ;
//            DWORD number = static_cast<DWORD>(num);
            monitor = SetMonitorBrightness(handle, newBrightnessLevel);
            if (monitor == false) {
                std::cout << "Setting Brightness Failed" << std::endl;
                return;
            }
            SaveCurrentMonitorSettings(handle);
            // Close the monitor handles.
            bSuccess = DestroyPhysicalMonitors(
                cPhysicalMonitors,
                pPhysicalMonitors);
            std::wcout << "bSuccess : " << bSuccess << std::endl;

            // Free the array.
            free(pPhysicalMonitors);
        }
    }
}
