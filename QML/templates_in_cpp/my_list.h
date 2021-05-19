#ifndef MY_LIST_H
#define MY_LIST_H

#include <QObject>
#include <QList>
#include <QDebug>

class my_list : public QObject
{
    Q_OBJECT
public:
    my_list();
signals:
    void itemAdded();
    void cleared();
};

template<typename T>
class temp_list : public my_list
{
public:
    temp_list(){}
    void getItems(){
        qDebug() << mItems;
    }
    void appendItems(T item) {
        mItems.push_back(item);
        emit itemAdded();
    }
    void clear() {
        mItems.clear();
        emit cleared();
    }
    void get_signal() {
        qDebug() << "Item added";
    }
private:
    QList<T> mItems;
//    QVariantList mItems;
};

#endif // MY_LIST_H
