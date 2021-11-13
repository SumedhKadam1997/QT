#ifndef NAVBACKENDJSON_HPP
#define NAVBACKENDJSON_HPP

#include <QObject>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QGeoCoordinate>

class NavBackendJSON : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList basePath READ basePath WRITE setBasePath NOTIFY basePathChanged)
    Q_PROPERTY(QVariantList navPath READ navPath WRITE setNavPath NOTIFY navPathChanged)
    QVariantList m_basePath;

    QVariantList m_navPath;

public:
    explicit NavBackendJSON(QObject *parent = nullptr);

    const QVariantList &basePath() const;
    void setBasePath(const QVariantList &newBasePath);
    Q_INVOKABLE bool getBasePathfromJSON(const QString &);

    const QVariantList &navPath() const;
    void setNavPath(const QVariantList &newNavPath);

signals:

    void basePathChanged();
    void navPathChanged();
};

#endif // NAVBACKENDJSON_HPP
