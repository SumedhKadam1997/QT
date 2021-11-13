#include "cameraproperties.h"

CameraProperties::CameraProperties(QObject *parent) : QObject(parent)
{

}

QString CameraProperties::activeCamId() const
{
    return m_activeCamId;
}

QString CameraProperties::activeCamera() const
{
    return m_activeCamera;
}

void CameraProperties::setActiveCamId(QString activeCamId)
{
    if (m_activeCamId == activeCamId)
        return;

    m_activeCamId = activeCamId;
    emit activeCamIdChanged(m_activeCamId);
}

void CameraProperties::setactiveCamera(QString activeCamera)
{
    if (m_activeCamera == activeCamera)
        return;

    m_activeCamera = activeCamera;
    emit activeCameraChanged(m_activeCamera);
}
