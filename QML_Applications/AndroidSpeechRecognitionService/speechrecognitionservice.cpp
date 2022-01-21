#include "speechrecognitionservice.hpp"
#include <QAndroidJniEnvironment>
#include <QAndroidIntent>
#include <QDebug>

SpeechRecognitionService *SpeechRecognitionService::m_instance = nullptr;

static void receivedFromAndroidService(JNIEnv *env, jobject /*thiz*/, jstring value)
{
    emit SpeechRecognitionService::instance()->messageFromService(env->GetStringUTFChars(value, nullptr));
}

SpeechRecognitionService::SpeechRecognitionService(QObject *parent)
    : QObject{parent}
{
    m_instance = this;

    JNINativeMethod methods[] {{"sendToQt", "(Ljava/lang/String;)V", reinterpret_cast<void *>(receivedFromAndroidService)}};
    QAndroidJniObject javaClass("org/qtproject/example/SpeechRecognitionService");

    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
    QObject::connect(SpeechRecognitionService::instance(), &SpeechRecognitionService::messageFromService, [](const QString &message) {
        qDebug() << "Message from Android Service : " << message;
        SpeechRecognitionService::instance()->setSpeechString(message);
    });
}

void SpeechRecognitionService::sendToService(const QString &name)
{
    QAndroidIntent serviceIntent(QtAndroid::androidActivity().object(),
                                        "org/qtproject/example/SpeechRecognitionService");
    serviceIntent.putExtra("name", name.toUtf8());
    QAndroidJniObject result = QtAndroid::androidActivity().callObjectMethod(
                "startService",
                "(Landroid/content/Intent;)Landroid/content/ComponentName;",
                serviceIntent.handle().object());
}

const QString &SpeechRecognitionService::speechString() const
{
    return m_speechString;
}

void SpeechRecognitionService::setSpeechString(const QString &newSpeechString)
{
    if (m_speechString == newSpeechString)
        return;
    m_speechString = newSpeechString;
    emit speechStringChanged();
}
