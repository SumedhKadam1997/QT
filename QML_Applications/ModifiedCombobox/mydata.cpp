#include "mydata.h"

MyData::MyData(QString name, QObject *parent) : QObject{parent} {
  m_name = name;
}

const QString &MyData::name() const { return m_name; }

void MyData::setName(const QString &newName) {
  if (m_name == newName) return;
  m_name = newName;
  emit nameChanged();
}
