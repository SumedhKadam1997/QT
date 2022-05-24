#include "candlestickseries.hpp"

CandleStickSeries::CandleStickSeries(QQuickItem *parent)
    : QQuickPaintedItem{parent} {}

void CandleStickSeries::paint(QPainter *painter) {
  QPen pen(m_color, 2);
  painter->setPen(pen);
  painter->setRenderHints(QPainter::Antialiasing, true);
  painter->drawLine(45, 10, 45, 330);
  painter->drawLine(0, 280, 700, 280);
}

void CandleStickSeries::append_view(QQmlListProperty<CandleStick> *list,
                                    CandleStick *stick) {
  CandleStickSeries *candleStickSeries =
      qobject_cast<CandleStickSeries *>(list->object);
  if (candleStickSeries) {
    stick->setParentItem(candleStickSeries);
    candleStickSeries->m_sticks.append(stick);
  }
}

QQmlListProperty<CandleStick> CandleStickSeries::sticks() {
  return QQmlListProperty<CandleStick>(this, nullptr,
                                       &CandleStickSeries::append_view, nullptr,
                                       nullptr, nullptr, nullptr, nullptr);
}
