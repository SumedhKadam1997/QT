#include "voicerecorder.hpp"

VoiceRecorder::VoiceRecorder(QObject *parent) : QObject(parent)
{
    audioRecorder = new QAudioRecorder;

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    audioRecorder->setEncodingSettings(audioSettings);

    audioRecorder->setOutputLocation(QUrl::fromLocalFile("C:/Users/User/Desktop/test.amr"));
}

void VoiceRecorder::record()
{
    audioRecorder->record();
}
