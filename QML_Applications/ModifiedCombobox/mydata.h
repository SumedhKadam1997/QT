#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>

class MyData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
 public:
  explicit MyData(QString name, QObject *parent = nullptr);

  const QString &name() const;
  void setName(const QString &newName);

 signals:
  void nameChanged();

 private:
  QString m_name;
};

#endif  // MYDATA_H
