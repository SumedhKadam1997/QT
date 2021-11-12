#include "speechtotext.hpp"

using google::cloud::speech::v1::StreamingRecognitionConfig;
using google::cloud::speech::v1::RecognitionConfig;
using google::cloud::speech::v1::Speech;
using google::cloud::speech::v1::StreamingRecognizeRequest;
using google::cloud::speech::v1::StreamingRecognizeResponse;

SpeechToText::SpeechToText(QObject *parent) : QObject(parent)
{

}

void SpeechToText::initialize()
{
    emit finished_initializing();
}

void SpeechToText::MicrophoneThreadMain(grpc::ClientReaderWriterInterface<StreamingRecognizeRequest,
                                        StreamingRecognizeResponse> *streamer)
{
    StreamingRecognizeRequest request;
    std::size_t size_read;
    while (time(0) - m_start_time <= TIME_RECOGNITION)
    {
        int chunk_size = 64 * 1024;
        if (audioDataBuffer.size() >= chunk_size)
        {
            QByteArray bytes_read = QByteArray(audioDataBuffer);
            size_read = std::size_t(bytes_read.size());

            // And write the chunk to the stream.
            request.set_audio_content(&bytes_read.data()[0], size_read);

            bool ok = streamer->Write(request);
            /*if (ok)
            {
                std::cout << "Sending " << size_read / 1024 << "k bytes." << std::endl;
            }*/

            audioDataBuffer.clear();
            audioDataBuffer.resize(0);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    qDebug() << "Out of speech recognition: " << end_date;

    emit out_of_speech_to_text();

    streamer->WritesDone();
}

void SpeechToText::StreamerThread(grpc::ClientReaderWriterInterface<StreamingRecognizeRequest,
                                      StreamingRecognizeResponse> *streamer)
{
    // Read responses.
    StreamingRecognizeResponse response;

    while (time(0) - m_start_time <= TIME_RECOGNITION)
    {
        if(streamer->Read(&response)) // Returns false when no more to read.
        {
            // Dump the transcript of all the results.
            if (response.results_size() > 0)
            {
                auto result = response.results(0);
                if (result.alternatives_size() > 0)
                {
                    auto alternative = result.alternatives(0);
                    auto transcript = QString::fromStdString(alternative.transcript());
                    if (result.is_final())
                    {
                        qDebug() << "Speech recognition: " << transcript;

                        emit finished_speech_to_text(transcript);
                    }
                }
            }
        }
    }
}

void SpeechToText::listen(const QByteArray &audioData)
{
    audioDataBuffer.append(audioData);
}

void SpeechToText::start_speech_to_text()
{
    qDebug() << "in start_speech_to_text: " << start_date;

    emit in_speech_to_text();

    m_start_time = time(0);
    audioDataBuffer.clear();
    audioDataBuffer.resize(0);

    StreamingRecognizeRequest request;

    auto *streaming_config   = request.mutable_streaming_config();
    RecognitionConfig *recognition_config = new RecognitionConfig();

    recognition_config->set_language_code("en-US");
    recognition_config->set_sample_rate_hertz(16000);
    recognition_config->set_encoding(RecognitionConfig::LINEAR16);
    streaming_config->set_allocated_config(recognition_config);

    // Create a Speech Stub connected to the speech service.
    auto creds = grpc::GoogleDefaultCredentials();
    auto channel = grpc::CreateChannel("speech.googleapis.com", creds);
    std::unique_ptr<Speech::Stub> speech(Speech::NewStub(channel));

    // Begin a stream.
    grpc::ClientContext context;
    auto streamer = speech->StreamingRecognize(&context);

    // Write the first request, containing the config only.
    streaming_config->set_interim_results(true);
    streamer->Write(request);

    // The microphone thread writes the audio content.
    std::thread microphone_thread(&SpeechToText::MicrophoneThreadMain, this, streamer.get());
    std::thread streamer_thread(&SpeechToText::StreamerThread, this, streamer.get());

    microphone_thread.join();
    streamer_thread.join();
}
