#include "datagenerator.h"

#include <QRandomGenerator>

DataGenerator::DataGenerator(QObject *parent) : QObject{parent} {
  qDebug() << "Constructor";
  posTimer = new QTimer();
  thicknessTimer = new QTimer();
  posTimer->setInterval(1000);
  thicknessTimer->setInterval(1000);
  connect(posTimer, &QTimer::timeout, this, &DataGenerator::updatePosition);
  connect(thicknessTimer, &QTimer::timeout, [this] {
    this->setThickness(QRandomGenerator::global()->bounded(50));
  });
  posTimer->start();
  thicknessTimer->start();
}

int DataGenerator::thickness() const { return m_thickness; }

void DataGenerator::setThickness(int newThickness) {
  if (m_thickness == newThickness) return;
  m_thickness = newThickness;
  emit thicknessChanged();
}

int DataGenerator::position() const { return m_position; }

void DataGenerator::setPosition(int newPosition) {
  if (m_position == newPosition) return;
  m_position = newPosition;
  emit positionChanged();
}

void DataGenerator::updatePosition() {
  if (m_posForward) {
    incrementPosition();
  } else {
    decrementPosition();
  }
}

void DataGenerator::incrementPosition() {
  if (m_position < 50) {
    setPosForward(true);
    setPosition(++m_position);
    emit positionChanged();
  } else {
    setPosForward(false);
  }
}

void DataGenerator::decrementPosition() {
  if (m_position > 0) {
    setPosForward(false);
    setPosition(--m_position);
    emit positionChanged();
  } else {
    setPosForward(true);
  }
}

bool DataGenerator::posForward() const { return m_posForward; }

void DataGenerator::setPosForward(bool newPosForward) {
  if (m_posForward == newPosForward) return;
  m_posForward = newPosForward;
  emit posForwardChanged();
}
