#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <QObject>
#include <QDebug>

class my_class : public QObject
{
    Q_OBJECT
public:
    explicit my_class(QObject *parent = 0);

public slots:
    void onMenuClicked(const QString &str)
    {
        qDebug() << str;
    }
};

#endif // MY_CLASS_H
