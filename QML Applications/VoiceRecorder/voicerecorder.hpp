#ifndef VOICERECORDER_HPP
#define VOICERECORDER_HPP

#include <QObject>
#include <QUrl>
#include <QAudioRecorder>

class VoiceRecorder : public QObject
{
    Q_OBJECT
    QAudioRecorder * audioRecorder;
//    https://centralindia.api.cognitive.microsoft.com/sts/v1.0/
public:
    explicit VoiceRecorder(QObject *parent = nullptr);

    void record();

signals:

};

#endif // VOICERECORDER_HPP
