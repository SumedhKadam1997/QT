#include "chartview.hpp"

ChartView::ChartView(QQuickItem *parent) : QQuickPaintedItem{parent} {}

void ChartView::paint(QPainter *p) {}

const QColor &ChartView::color() const { return m_color; }

void ChartView::setColor(const QColor &newColor) {
  if (m_color == newColor) return;
  m_color = newColor;
  emit colorChanged();
}

void ChartView::append_view(QQmlListProperty<LineSeries> *list,
                            LineSeries *series) {
  ChartView *chart = qobject_cast<ChartView *>(list->object);
  if (chart) {
    series->setParentItem(chart);
    chart->m_lineseries.append(series);
  }
}

QQmlListProperty<LineSeries> ChartView::lineseries() {
  return QQmlListProperty<LineSeries>(this, nullptr, &ChartView::append_view,
                                      nullptr, nullptr, nullptr, nullptr,
                                      nullptr);
}

const QString &ChartView::title() const { return m_title; }

void ChartView::setTitle(const QString &newTitle) {
  if (m_title == newTitle) return;
  m_title = newTitle;
  emit titleChanged();
}
