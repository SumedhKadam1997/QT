#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <QObject>


class My_class : public QObject
{
    Q_OBJECT
public:
    explicit My_class(QObject *parent = nullptr);

signals:
    void sendToQml(int count);

public slots:
    void receiveFromQml()
    {
        // We increase the counter and send a signal with its value
        ++m_counter;
        emit sendToQml(m_counter);
    }

private:
    int m_counter {0};
};

#endif // MY_CLASS_H
