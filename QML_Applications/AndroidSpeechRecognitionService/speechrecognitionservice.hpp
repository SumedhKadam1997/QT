#ifndef SPEECHRECOGNITIONSERVICE_HPP
#define SPEECHRECOGNITIONSERVICE_HPP

#include <QObject>
#include <QtAndroid>
#include <QAndroidIntent>

class SpeechRecognitionService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString speechString READ speechString WRITE setSpeechString NOTIFY speechStringChanged)
    Q_PROPERTY(bool wakeWordDetected READ wakeWordDetected WRITE setWakeWordDetected NOTIFY wakeWordDetectedChanged)
public:
    explicit SpeechRecognitionService(QObject *parent = nullptr);
    static SpeechRecognitionService *getInstance();

    Q_INVOKABLE void startSpeechService(const QString &name);
    Q_INVOKABLE void stopSpeechService();

    const QString &speechString() const;
    void setSpeechString(const QString &newSpeechString);

    const bool &wakeWordDetected() const;
    void setWakeWordDetected(bool newWakeWordDetected);

signals:
    void speechStringReceived(const QString &message);
    void isWakeWordDetected(bool isDetected);

    void speechStringChanged();
    void wakeWordDetectedChanged();

private:
    static SpeechRecognitionService *m_instance;
    QString m_speechString;
    bool m_wakeWordDetected;
};

#endif // SPEECHRECOGNITIONSERVICE_HPP
