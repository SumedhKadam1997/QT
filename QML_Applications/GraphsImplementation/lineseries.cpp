#include "lineseries.hpp"

#include <QGraphicsItem>
LineSeries::LineSeries(QQuickItem *parent) : QQuickPaintedItem{parent} {}

void LineSeries::paint(QPainter *painter) {
  QPen pen(m_color, 2);
  painter->setPen(pen);
  painter->setRenderHints(QPainter::Antialiasing, true);
  painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}

const QColor &LineSeries::color() const { return m_color; }

void LineSeries::setColor(const QColor &newColor) {
  if (m_color == newColor) return;
  m_color = newColor;
  emit colorChanged();
}

const QString &LineSeries::name() const { return m_name; }

void LineSeries::setName(const QString &newName) {
  if (m_name == newName) return;
  m_name = newName;
  emit nameChanged();
}
