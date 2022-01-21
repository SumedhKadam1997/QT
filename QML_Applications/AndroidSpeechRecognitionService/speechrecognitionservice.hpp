#ifndef SPEECHRECOGNITIONSERVICE_HPP
#define SPEECHRECOGNITIONSERVICE_HPP

#include <QObject>
#include <QtAndroid>
#include <QAndroidIntent>

class SpeechRecognitionService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString speechString READ speechString WRITE setSpeechString NOTIFY speechStringChanged)
public:
    explicit SpeechRecognitionService(QObject *parent = nullptr);
    static SpeechRecognitionService *instance() { return m_instance; }

    Q_INVOKABLE void sendToService(const QString &name);

    const QString &speechString() const;
    void setSpeechString(const QString &newSpeechString);

signals:
    void messageFromService(const QString &message);

    void speechStringChanged();

private:
    static SpeechRecognitionService *m_instance;
    QString m_speechString;
};

#endif // SPEECHRECOGNITIONSERVICE_HPP
