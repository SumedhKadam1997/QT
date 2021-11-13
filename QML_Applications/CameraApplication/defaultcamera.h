#ifndef DEFAULTCAMERA_H
#define DEFAULTCAMERA_H

#include <QObject>
#include "icameracontext.h"
#include <QFileSystemWatcher>

class DefaultCamera : public ICameraContext
{
    Q_OBJECT
    QFileSystemWatcher fileWatcher;
public:
    DefaultCamera();

    void scanCameras() override;
    void setIds() override;
    Q_INVOKABLE void setActiveId(const QString &camera) override;

};

#endif // DEFAULTCAMERA_H
