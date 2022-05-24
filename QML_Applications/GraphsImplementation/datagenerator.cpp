#include "datagenerator.h"

#include <QRandomGenerator>

DataGenerator::DataGenerator(QObject *parent) : QObject{parent} {
  qDebug() << "Constructor";
  posTimer = new QTimer();
  thicknessTimer = new QTimer();
  posTimer->setInterval(1000 / 5);
  thicknessTimer->setInterval(1000 / 5);
  connect(posTimer, &QTimer::timeout, this, &DataGenerator::updatePosition);
  connect(thicknessTimer, &QTimer::timeout, [this] {
    this->setThickness(QRandomGenerator::global()->bounded(100));
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
  if (posForward) {
    incrementPosition();
  } else {
    decrementPosition();
  }
}

void DataGenerator::incrementPosition() {
  if (m_position < 50) {
    posForward = true;
    this->setPosition(++m_position);
  } else {
    posForward = false;
  }
}

void DataGenerator::decrementPosition() {
  if (m_position > 0) {
    posForward = false;
    setPosition(--m_position);
  } else {
    posForward = true;
  }
}
