#include "speechrecognitionservice.hpp"
#include <QAndroidJniEnvironment>
#include <QAndroidIntent>
#include <QDebug>

SpeechRecognitionService *SpeechRecognitionService::m_instance = nullptr;

SpeechRecognitionService *SpeechRecognitionService::getInstance() {
    return m_instance;
}

static void receiveSpeechString(JNIEnv *env, jobject thiz, jstring value)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    emit SpeechRecognitionService::getInstance()->speechStringReceived(env->GetStringUTFChars(value, nullptr));
}

static void receiveWakeWorkDetection(JNIEnv *env, jobject thiz, jboolean isDetected) {
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    emit SpeechRecognitionService::getInstance()->isWakeWordDetected(static_cast<bool>((isDetected == JNI_TRUE)));
}

SpeechRecognitionService::SpeechRecognitionService(QObject *parent)
    : QObject{parent}
{
    m_instance = this;

    JNINativeMethod methods[] {{"sendSpeechStringToQT", "(Ljava/lang/String;)V", reinterpret_cast<void *>(receiveSpeechString)},
                               {"sendWakeWordDetection", "(Z)V", reinterpret_cast<void *>(receiveWakeWorkDetection)}};
    QAndroidJniObject javaClass("org/qtproject/example/SpeechRecognitionService");

    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
    QObject::connect(SpeechRecognitionService::getInstance(), &SpeechRecognitionService::speechStringReceived, [](const QString &message) {
        qDebug() << "Message from Android Service : " << message;
        SpeechRecognitionService::getInstance()->setSpeechString(message);
    });
    QObject::connect(SpeechRecognitionService::getInstance(), &SpeechRecognitionService::isWakeWordDetected, [](bool isDetected) {
        qDebug() << "Message from Android Service : " << isDetected;
        SpeechRecognitionService::getInstance()->setWakeWordDetected(isDetected);
    });
}

void SpeechRecognitionService::startSpeechService(const QString &name)
{
    QAndroidIntent serviceIntent(QtAndroid::androidActivity().object(),
                                        "org/qtproject/example/SpeechRecognitionService");
    serviceIntent.putExtra("name", name.toUtf8());
    QAndroidJniObject result = QtAndroid::androidActivity().callObjectMethod(
                "startService",
                "(Landroid/content/Intent;)Landroid/content/ComponentName;",
                serviceIntent.handle().object());
}

void SpeechRecognitionService::stopSpeechService()
{
    QAndroidIntent serviceIntent(QtAndroid::androidActivity().object(),
                                        "org/qtproject/example/SpeechRecognitionService");
    QAndroidJniObject result = QtAndroid::androidActivity().callObjectMethod(
                "stopService",
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

const bool
&SpeechRecognitionService::wakeWordDetected() const
{
    return m_wakeWordDetected;
}

void SpeechRecognitionService::setWakeWordDetected(bool newWakeWordDetected)
{
    if (m_wakeWordDetected == newWakeWordDetected)
        return;
    m_wakeWordDetected = newWakeWordDetected;
    emit wakeWordDetectedChanged();
}
