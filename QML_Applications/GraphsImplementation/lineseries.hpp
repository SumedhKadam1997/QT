#ifndef LINESERIES_HPP
#define LINESERIES_HPP

#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>

class LineSeries : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
 public:
  explicit LineSeries(QQuickItem *parent = nullptr);

  void paint(QPainter *painter);

  const QColor &color() const;
  void setColor(const QColor &newColor);

  const QString &name() const;
  void setName(const QString &newName);

 signals:
  void colorChanged();
  void chartCleared();
  void nameChanged();

 private:
  QColor m_color;
  QString m_name;
};

#endif  // LINESERIES_HPP
