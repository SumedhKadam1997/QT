#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QTimer>
#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioRecorder>
#include <QAudioEncoderSettings>
#include <QStandardPaths>

class AudioManager : public QObject
{
    Q_OBJECT
    QFile destinationFile;
    QAudioFormat format;
    QAudioInput * audioInput;
    QTimer *timer;
    QAudioRecorder *audioRecorder;
    QAudioEncoderSettings audioSettings;
    const QDir location = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
    QString savePath = location.path();
public:
    explicit AudioManager(QObject *parent = nullptr);
    Q_INVOKABLE void start();
    void stop();
public slots:
    void handleStateChanged(QAudio::State);

signals:

};

#endif // AUDIOMANAGER_HPP
