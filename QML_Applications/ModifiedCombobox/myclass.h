#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

#include "mydata.h"

class MyClass : public QObject {
  Q_OBJECT
  Q_PROPERTY(QList<MyData *> data READ data WRITE setData NOTIFY dataChanged)
  Q_PROPERTY(QStringList name READ name WRITE setName NOTIFY nameChanged)
 public:
  explicit MyClass(QObject *parent = nullptr);

  QList<MyData *> data();
  void setData(QList<MyData *> newData);

  const QStringList &name() const;
  void setName(const QStringList &newName);

  signals:
  void dataChanged();

      void nameChanged();

  private:
      QList<MyData *> _data;
      QStringList m_name;
};

#endif  // MYCLASS_H
