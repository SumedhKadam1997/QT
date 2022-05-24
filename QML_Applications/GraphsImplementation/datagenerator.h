#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QDebug>
#include <QObject>
#include <QTimer>

class DataGenerator : public QObject {
  Q_OBJECT
  QTimer *posTimer;
  QTimer *thicknessTimer;
  Q_PROPERTY(
      int position READ position WRITE setPosition NOTIFY positionChanged)
  Q_PROPERTY(
      int thickness READ thickness WRITE setThickness NOTIFY thicknessChanged)
 public:
  explicit DataGenerator(QObject *parent = nullptr);

  int thickness() const;
  void setThickness(int newThickness);

  int position() const;
  void setPosition(int newPosition);

  void updatePosition();
  void incrementPosition();
  void decrementPosition();

 signals:

  void thicknessChanged();
  void positionChanged();

 private:
  int m_thickness = 0;
  int m_position = 0;
  bool posForward = true;
};

#endif  // DATAGENERATOR_H
