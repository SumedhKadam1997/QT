#ifndef PHOTOFETCHER_H
#define PHOTOFETCHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class PhotoFetcher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString photoName READ photoName WRITE setPhotoName NOTIFY photoNameChanged)
public:
    explicit PhotoFetcher(QObject *parent = nullptr);

    const QString &photoName() const;
    void setPhotoName(const QString &newPhotoName);

    Q_INVOKABLE void getPhoto();
    void parsePhoto(QNetworkReply *reply);

signals:

    void photoNameChanged();
private:
    QString m_photoName;
    QNetworkAccessManager *manager;
};

#endif // PHOTOFETCHER_H
