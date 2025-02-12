#include "microphonerecorder.hpp"

MicrophoneRecorder::MicrophoneRecorder(QObject *parent) : QObject(parent)
{

}

void MicrophoneRecorder::listen(const QByteArray &audioData)
{
    emit microphone_data_raw(audioData);
}

void MicrophoneRecorder::start_listen()
{
    QAudioFormat qtFormat;

    // Get default audio input device
    QAudioDeviceInfo qtInfo = QAudioDeviceInfo::defaultInputDevice();

    // Set the audio format settings
    qtFormat.setCodec("audio/pcm");
    qtFormat.setByteOrder(QAudioFormat::Endian::LittleEndian);
    qtFormat.setChannelCount(1);
    qtFormat.setSampleRate(16000);
    qtFormat.setSampleSize(16);
    qtFormat.setSampleType(QAudioFormat::SignedInt);

    // Check whether the format is supported
    if (!qtInfo.isFormatSupported(qtFormat)) {
        qWarning() << "Default format is not supported";
        exit(3);
    }

    // Instantiate QAudioInput with the settings
    audioInput = new QAudioInput(qtFormat);

    // Start receiving data from audio input
    ioDevice = audioInput->start();

    // Listen to the received data for wake words
    QObject::connect(ioDevice, &QIODevice::readyRead, [=] {
        listen(ioDevice->readAll());
    });
}
