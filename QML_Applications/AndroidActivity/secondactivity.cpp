#include "secondactivity.hpp"
#include <QAndroidIntent>
#include <QDebug>

const int REQUEST_CODE = 123;
const jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
SecondActivity::SecondActivity(QObject *parent)
    : QObject{parent}
{
//    m_instance = this;
}

void SecondActivity::startSecondActivity()
{
    QAndroidIntent activityIntent(QtAndroid::androidActivity().object(),
                                  "org/qtproject/example/VoskActivity");
    qDebug() << "Hkkskdks";

    QtAndroid::startActivity(
            activityIntent.handle(), REQUEST_CODE,
            [this](int requestCode, int resultCode, const QAndroidJniObject &data) {
                activityReceiver(requestCode, resultCode, data);
            });
//    QtAndroid::startActivity(activityIntent.handle(), REQUEST_CODE);
    qDebug() << "Start Activity Finished";
}

void SecondActivity::activityReceiver(int requestCode, int resultCode, const QAndroidJniObject &data)
{
    if (requestCode == REQUEST_CODE) {
        if (resultCode == RESULT_OK) {
            const QAndroidJniObject key = QAndroidJniObject::fromString("message");
            const QAndroidJniObject message = data.callObjectMethod(
                    "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;", key.object());
            if (message.isValid())
                emit /*SecondActivity::instance()->*/receiveFromActivityResult(message.toString());
        } else {
            emit /*SecondActivity::instance()->*/receiveFromActivityResult("Rejected!");
        }
    }
}
