#include "candlestick.hpp"

#include <QGraphicsItem>
CandleStick::CandleStick(QQuickItem *parent) : QQuickPaintedItem{parent} {}

void CandleStick::paint(QPainter *painter) {
  QPen pen(m_color, 2);
  painter->setPen(pen);
  painter->setRenderHints(QPainter::Antialiasing, true);
  painter->drawLine(0, upperLimit(), 20, upperLimit());
  painter->drawLine(10, upperLimit(), 10, lowerLimit());
  painter->drawLine(0, lowerLimit(), 20, lowerLimit());
  QImage img("qrc:/assets/triangleUp.png");
  if (isIncreasing()) {
    img.load(
        "C:\\Users\\UxoriousGhost-WorkPC\\Desktop\\QT-QML\\QML_"
        "Applications\\GraphsImplementation\\assets\\triangleUp.png");
  } else if (!isIncreasing()) {
    img.load(
        "C:\\Users\\UxoriousGhost-WorkPC\\Desktop\\QT-QML\\QML_"
        "Applications\\GraphsImplementation\\assets\\triangleDown.png");
  }
  if (!img.isNull()) {
    QRectF target(0.0, 40.0, 20.0, 20.0);
    painter->drawImage(target, img);
  } else {
    qDebug() << "Image Not Loaded";
  }
}

const QColor &CandleStick::color() const { return m_color; }

void CandleStick::setColor(const QColor &newColor) {
  if (m_color == newColor) return;
  m_color = newColor;
  update();
  emit colorChanged();
}

const QString &CandleStick::name() const { return m_name; }

void CandleStick::setName(const QString &newName) {
  if (m_name == newName) return;
  m_name = newName;
  emit nameChanged();
}

double CandleStick::upperLimit() const { return m_upperLimit; }

void CandleStick::setUpperLimit(double newUpperLimit) {
  if (qFuzzyCompare(m_upperLimit, newUpperLimit)) return;
  m_upperLimit = newUpperLimit;
  update();
  emit upperLimitChanged();
}

double CandleStick::lowerLimit() const { return m_lowerLimit; }

void CandleStick::setLowerLimit(double newLowerLimit) {
  if (qFuzzyCompare(m_lowerLimit, newLowerLimit)) return;
  m_lowerLimit = newLowerLimit;
  update();
  emit lowerLimitChanged();
}

bool CandleStick::isIncreasing() const { return m_isIncreasing; }

void CandleStick::setIsIncreasing(bool newIsIncreasing) {
  if (m_isIncreasing == newIsIncreasing) return;
  m_isIncreasing = newIsIncreasing;
  emit isIncreasingChanged();
}

int CandleStick::boltNumber() const { return m_boltNumber; }

void CandleStick::setBoltNumber(int newBoltNumber) {
  if (m_boltNumber == newBoltNumber) return;
  m_boltNumber = newBoltNumber;
  emit boltNumberChanged();
}

double CandleStick::boltPositionValue() const { return m_boltPositionValue; }

void CandleStick::setBoltPositionValue(double newBoltPositionValue) {
  if (qFuzzyCompare(m_boltPositionValue, newBoltPositionValue)) return;
  m_boltPositionValue = newBoltPositionValue;
  emit boltPositionValueChanged();
}
