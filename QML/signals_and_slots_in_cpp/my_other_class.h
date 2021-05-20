#ifndef MY_OTHER_CLASS_H
#define MY_OTHER_CLASS_H
#include <QObject>
#include <QDebug>


class my_other_class : public QObject
{
    Q_OBJECT
public:
    my_other_class();

    virtual void my_vir_func() = 0;
public slots:
    void func(){
        qDebug() << "Heyy! I'm from abstract class named my_other_class";
    }
};

class my_other_derived_class : public my_other_class
{
    Q_OBJECT
public:
    my_other_derived_class();

    void my_vir_func(){
        qDebug() << "Heyy! I'm derived from my_other_class";
    }
};

#endif // MY_OTHER_CLASS_H
