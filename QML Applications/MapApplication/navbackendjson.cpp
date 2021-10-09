#include "navbackendjson.hpp"

NavBackendJSON::NavBackendJSON(QObject *parent) : QObject(parent)
{

}

const QVariantList &NavBackendJSON::basePath() const
{
    return m_basePath;
}

void NavBackendJSON::setBasePath(const QVariantList &newBasePath)
{
    if (m_basePath == newBasePath)
        return;
    m_basePath = newBasePath;
    emit basePathChanged();
}

bool NavBackendJSON::getBasePathfromJSON(const QString & path)
{
    //    QFile file("C:/Users/User/Desktop/QT-QML/QML Applications/MapApplication/paths.json");
    QFile file(":/paths.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open json file";
        return false;
    }
    QTextStream fileText(&file);
    QString jsonString;
    jsonString = fileText.readAll();
    file.close();
    QByteArray jsonBytes = jsonString.toLocal8Bit();
    auto jsonDoc = QJsonDocument::fromJson(jsonBytes);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to create JSON doc.";
        return false;
    }
    if (!jsonDoc.isObject()) {
        qDebug() << "JSON is not an object.";
        return false;
    }
    QJsonObject jsonBaseObj = jsonDoc.object();
    QJsonArray jsonBaseArray = jsonBaseObj["paths"].toArray();

    for(int j = 0 ;j < jsonBaseArray.size() ; j++) {
        QJsonObject jsonPathObj =jsonBaseArray.at(j).toObject();
        if (path == "basePath") {
            QJsonArray jsonPathArray = jsonPathObj[path].toArray();
            qDebug() << jsonPathArray;
            m_basePath.clear();
            for(int k = 0 ;k < jsonPathArray.size() ; k++) {
                QJsonObject jsonObj =jsonPathArray.at(k).toObject();
                m_basePath.append(QVariant::fromValue(QGeoCoordinate(jsonObj["latitude"].toDouble(), jsonObj["longitude"].toDouble())));
                qDebug() << "From JSON" << jsonObj["latitude"].toDouble();
                qDebug() << "From JSON" << jsonObj["longitude"].toDouble();
                emit navPathChanged();
            }
            if (m_basePath.count() > 0) {
                return true;
            } else {
                return false;
            }
        } else if (path == "path1") {
            QJsonArray jsonPathArray = jsonPathObj[path].toArray();
            qDebug() << jsonPathArray;
            m_navPath.clear();
            for(int k = 0 ;k < jsonPathArray.size() ; k++) {
                QJsonObject jsonObj =jsonPathArray.at(k).toObject();
                m_navPath.append(QVariant::fromValue(QGeoCoordinate(jsonObj["latitude"].toDouble(), jsonObj["longitude"].toDouble())));
                qDebug() << "From JSON" << jsonObj["latitude"].toDouble();
                qDebug() << "From JSON" << jsonObj["longitude"].toDouble();
                emit navPathChanged();
            }
            if (m_navPath.count() > 0) {
                return true;
            } else {
                return false;
            }
        }
    }
}

const QVariantList &NavBackendJSON::navPath() const
{
    return m_navPath;
}

void NavBackendJSON::setNavPath(const QVariantList &newNavPath)
{
    if (m_navPath == newNavPath)
        return;
    m_navPath = newNavPath;
    emit navPathChanged();
}
