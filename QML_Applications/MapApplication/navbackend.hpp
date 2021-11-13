#ifndef NAVBACKEND_HPP
#define NAVBACKEND_HPP

#include <QObject>
#include <QGeoCoordinate>
#include <QVariant>

class NavBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList path READ path WRITE setPath NOTIFY pathChanged)
    QVariantList m_path;

public:
    explicit NavBackend(QObject *parent = nullptr);
    const QVariantList &path() const;
    void setPath(const QVariantList &newPath);

signals:
    void pathChanged();
};

#endif // NAVBACKEND_HPP
