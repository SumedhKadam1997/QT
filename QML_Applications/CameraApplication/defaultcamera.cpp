#include "defaultcamera.h"

DefaultCamera::DefaultCamera()
{
    DefaultCamera::scanCameras();
    fileWatcher.addPath("/dev");
    QObject::connect(&fileWatcher, &QFileSystemWatcher::directoryChanged, this, &DefaultCamera::scanCameras, Qt::UniqueConnection);
    QObject::connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &DefaultCamera::scanCameras, Qt::UniqueConnection);
}

void DefaultCamera::scanCameras()
{
    allAvailableCameras = QCameraInfo::availableCameras();
    qDebug() << allAvailableCameras;
    DefaultCamera::setIds();
    emit scanCamerasComplete();
}

void DefaultCamera::setIds()
{
    if(allAvailableCameras.size() != 0) {
        if(allAvailableCameras.size() == 1) {
            setActiveCamId(allAvailableCameras[0].deviceName());
        } else if (allAvailableCameras.size() > 1) {
            if(activeCamera() == "FRONT") {
                setActiveCamId(allAvailableCameras[0].deviceName());
            } else if (activeCamera() == "BACK") {
                setActiveCamId(allAvailableCameras[1].deviceName());
            }
        }
    } else {
        qDebug() << "No Camera Found!!";
    }
}

void DefaultCamera::setActiveId(const QString &camera)
{
    if(camera == "FRONT") {
        setActiveCamId(allAvailableCameras[0].deviceName());
        qDebug() << "Front Camera Enabled";
    } else if (allAvailableCameras.size() == 2 && camera == "BACK") {
        setActiveCamId(allAvailableCameras[1].deviceName());
        qDebug() << "Back Camera Enabled";
    } else if (allAvailableCameras.size() == 0) {
        qDebug() << "No Camera Found!!";
    } else {
        qDebug() << "Back Camera Not Found";
    }
}
