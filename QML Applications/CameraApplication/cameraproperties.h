#ifndef CAMERAPROPERTIES_H
#define CAMERAPROPERTIES_H

#include <QObject>

class CameraProperties : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString activeCamId READ activeCamId WRITE setActiveCamId NOTIFY activeCamIdChanged)
    Q_PROPERTY(QString activeCamera READ activeCamera WRITE setactiveCamera NOTIFY activeCameraChanged)

    QString m_activeCamId;
    QString m_activeCamera = "FRONT";

public:
    explicit CameraProperties(QObject *parent = nullptr);

    QString activeCamId() const;
    QString activeCamera() const;

public slots:
    void setActiveCamId(QString activeCamId);
    void setactiveCamera(QString activeCamera);

signals:
    void activeCamIdChanged(QString activeCamId);
    void activeCameraChanged(QString activeCamera);
};

#endif // CAMERAPROPERTIES_H
