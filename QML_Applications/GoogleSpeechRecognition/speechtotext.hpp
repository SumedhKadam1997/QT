#ifndef SPEECHTOTEXT_HPP
#define SPEECHTOTEXT_HPP

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QDateTime>

#include <thread>
#include <chrono>
#include <string>

#include <QtMultimedia>
#include <QtMultimedia/QAudioInput>
#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QIODevice>
#include <QtConcurrent>
#include <QMutex>

#include <grpc++/grpc++.h>
#include "google/cloud/speech/v1/cloud_speech.grpc.pb.h"

using google::cloud::speech::v1::StreamingRecognitionConfig;
using google::cloud::speech::v1::RecognitionConfig;
using google::cloud::speech::v1::Speech;
using google::cloud::speech::v1::StreamingRecognizeRequest;
using google::cloud::speech::v1::StreamingRecognizeResponse;

class SpeechToText : public QObject
{
    Q_OBJECT
public:
    explicit SpeechToText(QObject *parent = nullptr);

signals:
    void finished_initializing();
    void in_speech_to_text();
    void out_of_speech_to_text();
    void finished_speech_to_text(QString);

public slots:
    void initialize();
    void listen(const QByteArray &);
    void start_speech_to_text();

private:
    void MicrophoneThreadMain(grpc::ClientReaderWriterInterface<StreamingRecognizeRequest,
                                          StreamingRecognizeResponse> *);
    void StreamerThread(grpc::ClientReaderWriterInterface<StreamingRecognizeRequest,
                                          StreamingRecognizeResponse> *);

    QByteArray audioDataBuffer;
    int m_start_time;
};


#endif // SPEECHTOTEXT_HPP
