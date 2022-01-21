#ifndef SECONDACTIVITY_HPP
#define SECONDACTIVITY_HPP

#include <QObject>
#include <QtAndroid>

class SecondActivity : public QObject
{
    Q_OBJECT

//    static SecondActivity *m_instance;
public:
    explicit SecondActivity(QObject *parent = nullptr);
//    static SecondActivity *instance() { return m_instance; }

    Q_INVOKABLE void startSecondActivity();
    void activityReceiver(int requestCode, int resultCode, const QAndroidJniObject &data);

signals:
    void receiveFromActivityResult(const QString &message);

};

#endif // SECONDACTIVITY_HPP
