#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <QObject>
#include <QDebug>

class my_class : public QObject
{
    Q_OBJECT

public:
    my_class();

    virtual void func() = 0;
public slots:
    void emit_signal()
    {
        emit mysignal();
    }
signals:
    void mysignal();
};

class my_derived_class : public my_class
{
    Q_OBJECT
public:
    void func(){
        qDebug() << "Hey!! I'm derived from abstract class";
    }
};

#endif // MY_CLASS_
