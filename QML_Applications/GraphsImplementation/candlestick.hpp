#ifndef CANDLESTICK_HPP
#define CANDLESTICK_HPP

#include <QDebug>
#include <QImage>
#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>

class CandleStick : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  Q_PROPERTY(bool isIncreasing READ isIncreasing WRITE setIsIncreasing NOTIFY
                 isIncreasingChanged)
  Q_PROPERTY(double upperLimit READ upperLimit WRITE setUpperLimit NOTIFY
                 upperLimitChanged)
  Q_PROPERTY(double lowerLimit READ lowerLimit WRITE setLowerLimit NOTIFY
                 lowerLimitChanged)
  Q_PROPERTY(int boltNumber READ boltNumber WRITE setBoltNumber NOTIFY
                 boltNumberChanged)
  Q_PROPERTY(double boltPositionValue READ boltPositionValue WRITE
                 setBoltPositionValue NOTIFY boltPositionValueChanged)
 public:
  explicit CandleStick(QQuickItem *parent = nullptr);

  void paint(QPainter *painter);

  const QColor &color() const;
  void setColor(const QColor &newColor);

  const QString &name() const;
  void setName(const QString &newName);

  double upperLimit() const;
  void setUpperLimit(double newUpperLimit);

  double lowerLimit() const;
  void setLowerLimit(double newLowerLimit);

  bool isIncreasing() const;
  void setIsIncreasing(bool newIsIncreasing);

  int boltNumber() const;
  void setBoltNumber(int newBoltNumber);

  double boltPositionValue() const;
  void setBoltPositionValue(double newBoltPositionValue);

 signals:
  void colorChanged();
  void chartCleared();
  void nameChanged();
  void upperLimitChanged();
  void lowerLimitChanged();
  void isIncreasingChanged();
  void boltNumberChanged();
  void boltPositionValueChanged();

 private:
  QColor m_color;
  QString m_name;
  double m_upperLimit = 10;
  double m_lowerLimit = 90;
  bool m_isIncreasing = true;
  int m_boltNumber;
  double m_boltPositionValue;
};

#endif  // CANDLESTICK_HPP
