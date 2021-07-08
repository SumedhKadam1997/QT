#ifndef ICAMERACONTEXT_H
#define ICAMERACONTEXT_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QCamera>
#include <QCameraInfo>
#include <cameraproperties.h>

class ICameraContext : public CameraProperties
{
    Q_OBJECT

public:
    explicit ICameraContext(QObject *parent = nullptr) {};
    virtual void scanCameras() = 0;
    virtual void setIds() = 0;
    virtual void setActiveId(const QString &camera) = 0;
protected:
    QList<QCameraInfo> allAvailableCameras;

signals:
    void scanCamerasComplete();

};

#endif // ICAMERACONTEXT_H
