#include "photofetcher.h"

PhotoFetcher::PhotoFetcher(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &PhotoFetcher::parsePhoto);
}

const QString &PhotoFetcher::photoName() const
{
    return m_photoName;
}

void PhotoFetcher::setPhotoName(const QString &newPhotoName)
{
    if (m_photoName == newPhotoName)
        return;
    m_photoName = newPhotoName;
    emit photoNameChanged();
}

void PhotoFetcher::getPhoto()
{
    manager->get(QNetworkRequest(QUrl("https://picsum.photos/200/300")));
}

void PhotoFetcher::parsePhoto(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << "Parsing Photo";
        QByteArray photo = reply->readAll();
        m_photoName.clear();
        m_photoName.append("data:image/png;base64,");
        m_photoName.append(QString::fromLatin1(photo.toBase64().data()));
        emit photoNameChanged();
    }
}
