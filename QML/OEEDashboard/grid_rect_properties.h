#ifndef GRID_RECT_PROPERTIES_H
#define GRID_RECT_PROPERTIES_H

#include <QObject>

class grid_rect_properties: public QObject
{
    Q_OBJECT

    Q_PROPERTY(double oee READ oee WRITE setOee NOTIFY oeeChanged)
    Q_PROPERTY(double ava READ ava WRITE setAva NOTIFY avaChanged)
    Q_PROPERTY(double perf READ perf WRITE setPerf NOTIFY perfChanged)
    Q_PROPERTY(double qua READ qua WRITE setQua NOTIFY quaChanged)
    Q_PROPERTY(double total_count READ total_count WRITE setTotal_count NOTIFY total_countChanged)
    Q_PROPERTY(double reject_count READ reject_count WRITE setReject_count NOTIFY reject_countChanged)
    Q_PROPERTY(double shift READ shift WRITE setShift NOTIFY shiftChanged)
    Q_PROPERTY(double stop_time READ stop_time WRITE setStop_time NOTIFY stop_timeChanged)
    Q_PROPERTY(double breakdown_time READ breakdown_time WRITE setBreakdown_time NOTIFY breakdown_timeChanged)
    Q_PROPERTY(double runtime READ runtime WRITE setRuntime NOTIFY runtimeChanged)
    Q_PROPERTY(double ideal_cycle READ ideal_cycle WRITE setIdeal_cycle NOTIFY ideal_cycleChanged)
    Q_PROPERTY(double actual_cycle READ actual_cycle WRITE setActual_cycle NOTIFY actual_cycleChanged)

    double m_oee;
    double m_ava;
    double m_perf;
    double m_qua;
    double m_total_count;
    double m_reject_count;
    double m_shift;
    double m_stop_time;
    double m_breakdown_time;
    double m_runtime;
    double m_ideal_cycle;
    double m_actual_cycle;

public:
    grid_rect_properties();
    double oee() const;
    double ava() const;
    double perf() const;
    double qua() const;
    double total_count() const;
    double reject_count() const;
    double shift() const;
    double stop_time() const;
    double breakdown_time() const;
    double runtime() const;
    double ideal_cycle() const;
    double actual_cycle() const;

public slots:
    void setOee(double oee);
    void setAva(double ava);
    void setPerf(double perf);
    void setQua(double qua);
    void setTotal_count(double total_count);
    void setReject_count(double reject_count);
    void setShift(double shift);
    void setStop_time(double stop_time);
    void setBreakdown_time(double breakdown_time);
    void setRuntime(double runtime);
    void setIdeal_cycle(double ideal_cycle);
    void setActual_cycle(double actual_cycle);

signals:
    void oeeChanged(double oee);
    void avaChanged(double ava);
    void perfChanged(double perf);
    void quaChanged(double qua);
    void total_countChanged(double total_count);
    void reject_countChanged(double reject_count);
    void shiftChanged(double shift);
    void stop_timeChanged(double stop_time);
    void breakdown_timeChanged(double breakdown_time);
    void runtimeChanged(double runtime);
    void ideal_cycleChanged(double ideal_cycle);
    void actual_cycleChanged(double actual_cycle);
};

#endif // GRID_RECT_PROPERTIES_H
