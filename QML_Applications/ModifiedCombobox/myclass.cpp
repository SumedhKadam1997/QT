#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject{parent} {
  _data << new MyData("Sumedh");
  _data << new MyData("Kadam");
  m_name << "Sumedh"
         << "kadam";
}

QList<MyData *> MyClass::data() { return _data; }

void MyClass::setData(QList<MyData *> newData) {
  _data = newData;
  emit dataChanged();
}

const QStringList &MyClass::name() const { return m_name; }

void MyClass::setName(const QStringList &newName) {
  if (m_name == newName) return;
  m_name = newName;
  emit nameChanged();
}
