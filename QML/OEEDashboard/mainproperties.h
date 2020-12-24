#ifndef MAINPROPERTIES_H
#define MAINPROPERTIES_H

#include <QObject>

class mainproperties: public QObject
{
    Q_OBJECT

    Q_PROPERTY(qint64 production_count READ production_count WRITE setProduction_count NOTIFY production_countChanged)
    Q_PROPERTY(qint64 rejection_count READ rejection_count WRITE setrejection_count NOTIFY rejection_countChanged)
    Q_PROPERTY(qint64 stop_time READ stop_time WRITE setStop_time NOTIFY stop_timeChanged)
    Q_PROPERTY(qint64 breakdown_time READ breakdown_time WRITE setBreakdown_time NOTIFY breakdown_timeChanged)
    Q_PROPERTY(qint64 run_time READ run_time WRITE setRun_time NOTIFY run_timeChanged)
    Q_PROPERTY(qint64 oee READ oee WRITE setOee NOTIFY oeeChanged)
    Q_PROPERTY(qint64 ava READ ava WRITE setAva NOTIFY avaChanged)
    Q_PROPERTY(qint64 perf READ perf WRITE setPerf NOTIFY perfChanged)
    Q_PROPERTY(qint64 qua READ qua WRITE setQua NOTIFY quaChanged)
    Q_PROPERTY(qint64 satish READ satish WRITE setSatish NOTIFY satishChanged)

public:

    mainproperties();
    qint64 production_count() const;
    qint64 rejection_count() const;
    qint64 stop_time() const;
    qint64 breakdown_time() const;
    qint64 run_time() const;
    qint64 oee() const;
    qint64 ava() const;
    qint64 perf() const;
    qint64 qua() const;
    qint64 satish() const;
public slots:
    void setProduction_count(qint64 production_count);
    void setrejection_count(qint64 rejection_count);

    void setStop_time(qint64 stop_time);

    void setBreakdown_time(qint64 breakdown_time);

    void setRun_time(qint64 run_time);

    void setOee(qint64 oee);

    void setAva(qint64 ava);

    void setPerf(qint64 perf);

    void setQua(qint64 qua);

    void setSatish(qint64 satish);

signals:
    void production_countChanged(qint64 production_count);
    void rejection_countChanged(qint64 rejection_count);
    void stop_timeChanged(qint64 stop_time);
    void breakdown_timeChanged(qint64 breakdown_time);
    void run_timeChanged(qint64 run_time);
    void oeeChanged(qint64 oee);
    void avaChanged(qint64 ava);
    void perfChanged(qint64 perf);
    void quaChanged(qint64 qua);

    void satishChanged(qint64 satish);

public:
    qint64 m_production_count;
    qint64 m_rejection_count;
    qint64 m_stop_time;
    qint64 m_breakdown_time;
    qint64 m_run_time;
    qint64 m_oee;
    qint64 m_ava;
    qint64 m_perf;
    qint64 m_qua;
    qint64 m_satish;

};

#endif // MAINPROPERTIES_H
