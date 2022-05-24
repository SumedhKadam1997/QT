#ifndef CANDLESTICKSERIES_HPP
#define CANDLESTICKSERIES_HPP

#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>

#include "candlestick.hpp"

class CandleStickSeries : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QQmlListProperty<CandleStick> sticks READ sticks)
 public:
  explicit CandleStickSeries(QQuickItem *parent = nullptr);

  void paint(QPainter *p);

  static void append_view(QQmlListProperty<CandleStick> *list,
                          CandleStick *stick);

  QQmlListProperty<CandleStick> sticks();

 signals:

 private:
  QList<CandleStick *> m_sticks;
  QColor m_color = "#555555";
};

#endif  // CANDLESTICKSERIES_HPP
