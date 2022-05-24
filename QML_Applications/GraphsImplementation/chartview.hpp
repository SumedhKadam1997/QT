#ifndef CHARTVIEW_HPP
#define CHARTVIEW_HPP

#include <QPainter>
#include <QQmlListProperty>
#include <QQuickPaintedItem>

#include "lineseries.hpp"

class ChartView : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  Q_PROPERTY(QQmlListProperty<LineSeries> lineseries READ lineseries)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
 public:
  explicit ChartView(QQuickItem *parent = nullptr);

  void paint(QPainter *p);

  const QColor &color() const;
  void setColor(const QColor &newColor);

  static void append_view(QQmlListProperty<LineSeries> *list,
                          LineSeries *slice);

  QQmlListProperty<LineSeries> lineseries();

  const QString &title() const;
  void setTitle(const QString &newTitle);

 signals:
  void colorChanged();
  void titleChanged();

 private:
  QColor m_color;
  QList<LineSeries *> m_lineseries;
  QString m_title;
};

#endif  // CHARTVIEW_HPP
