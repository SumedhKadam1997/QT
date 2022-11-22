#include <QApplication>
#include <QDateTime>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QRandomGenerator>
#include <QTimer>

class GraphData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QDateTime minDateTime READ minDateTime WRITE setMinDateTime NOTIFY
                 minDateTimeChanged)

 public:
  GraphData() {
    int currentDateTime = QDateTime::currentSecsSinceEpoch();
    currentDateTime += 360;
    m_minDateTime.setSecsSinceEpoch(currentDateTime);
    timer.setInterval(2000);
    connect(&timer, &QTimer::timeout, this, &GraphData::updateData);
    timer.start();
  }
  void updateData() {
    _value = QRandomGenerator::global()->bounded(50);
    qDebug() << "Time : " << QDateTime::currentSecsSinceEpoch()
             << "Value : " << _value;
    emit dataUpdated(QDateTime::currentMSecsSinceEpoch(), _value);
  }

  const QDateTime &minDateTime() const;
  void setMinDateTime(const QDateTime &newMinDateTime);

 signals:
  void dataUpdated(int timeInEpoch, int value);
  void dateTimeChanged(QDateTime &dateTime);

  void minDateTimeChanged();

 private:
  int _value;
  QTimer timer;
  QDateTime m_minDateTime;
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  GraphData data;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("graphData", &data);
  const QUrl url(u"qrc:/LiveDateTimeChart/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}

#include "main.moc"

const QDateTime &GraphData::minDateTime() const { return m_minDateTime; }

void GraphData::setMinDateTime(const QDateTime &newMinDateTime) {
  if (m_minDateTime == newMinDateTime) return;
  m_minDateTime = newMinDateTime;
  emit minDateTimeChanged();
}
