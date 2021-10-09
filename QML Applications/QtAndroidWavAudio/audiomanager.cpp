#include "audiomanager.hpp"

AudioManager::AudioManager(QObject *parent) : QObject(parent)
{
    destinationFile.setFileName(savePath + "/test.wav");
    qDebug() << destinationFile.fileName();
    destinationFile.open( QIODevice::WriteOnly | QIODevice::Truncate );
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setSampleType(QAudioFormat::SignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setCodec("audio/pcm");
    QAudioDeviceInfo devinfo(QAudioDeviceInfo::defaultInputDevice());
    if(!devinfo.isFormatSupported(format))
    {
        qDebug() <<"Default format not supported, try to use nearest format";
        format = devinfo.nearestFormat(format);
    }
    qDebug() << devinfo.nearestFormat(format);
    qDebug() << devinfo.supportedCodecs();
    audioInput = new QAudioInput(devinfo, format, this);
    //    audioInput->
    //    QFile file(savePath + ".mp3");
    //    file.open(QIODevice::ReadWrite);
    //    audioRecorder = new QAudioRecorder;
    //    this->audioSettings.setCodec("audio/amr");
    //    this->audioSettings.setQuality(QMultimedia::HighQuality);
    ////    this->audioRecorder->setAudioSettings(this->audioSettings);
    //    this->audioRecorder->setEncodingSettings(this->audioSettings);
    //    this->audioRecorder->setContainerFormat("amr");
    //    this->audioRecorder->setAudioInput(this->audioRecorder->defaultAudioInput());
    //    this->audioRecorder->setOutputLocation(QUrl::fromLocalFile(savePath));
    timer = new QTimer;
    timer->setInterval(5000);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AudioManager::stop);
    connect(audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));

    //    QTimer::singleShot(3000, this, &AudioManager::stop);
}

void AudioManager::start()
{
    //    qDebug() << this->audioRecorder->supportedAudioCodecs();
    //    qDebug() << this->audioRecorder->supportedContainers();
    //    this->audioRecorder->record();
    this->timer->start();
    audioInput->start(&destinationFile);
    qDebug() << "Recording Started";
}

void AudioManager::stop()
{
    //    this->audioRecorder->stop();
    this->audioInput->stop();
    destinationFile.close();
    delete audioInput;
    qDebug() << "Recording Stopped";
}

void AudioManager::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
    case QAudio::StoppedState:
        if (audioInput->error() != QAudio::NoError) {
            // Error handling
            qDebug() << audioInput->error();
        } else {
            // Finished recording
        }
        break;

    case QAudio::ActiveState:
        // Started recording - read from IO device
        break;

    default:
        // ... other cases as appropriate
        break;
    }
}
