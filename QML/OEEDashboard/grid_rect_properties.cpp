#include "grid_rect_properties.h"

grid_rect_properties::grid_rect_properties()
{

}

double grid_rect_properties::oee() const
{
    return m_oee;
}

double grid_rect_properties::ava() const
{
    return m_ava;
}

double grid_rect_properties::perf() const
{
    return m_perf;
}

double grid_rect_properties::qua() const
{
    return m_qua;
}

double grid_rect_properties::total_count() const
{
    return m_total_count;
}

double grid_rect_properties::reject_count() const
{
    return m_reject_count;
}

double grid_rect_properties::shift() const
{
    return m_shift;
}

double grid_rect_properties::stop_time() const
{
    return m_stop_time;
}

double grid_rect_properties::breakdown_time() const
{
    return m_breakdown_time;
}

double grid_rect_properties::runtime() const
{
    return m_runtime;
}

double grid_rect_properties::ideal_cycle() const
{
    return m_ideal_cycle;
}

double grid_rect_properties::actual_cycle() const
{
    return m_actual_cycle;
}

void grid_rect_properties::setOee(double oee)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_oee, oee))
        return;

    m_oee = oee;
    emit oeeChanged(m_oee);
}

void grid_rect_properties::setAva(double ava)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_ava, ava))
        return;

    m_ava = ava;
    emit avaChanged(m_ava);
}

void grid_rect_properties::setPerf(double perf)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_perf, perf))
        return;

    m_perf = perf;
    emit perfChanged(m_perf);
}

void grid_rect_properties::setQua(double qua)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_qua, qua))
        return;

    m_qua = qua;
    emit quaChanged(m_qua);
}

void grid_rect_properties::setTotal_count(double total_count)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_total_count, total_count))
        return;

    m_total_count = total_count;
    emit total_countChanged(m_total_count);
}

void grid_rect_properties::setReject_count(double reject_count)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_reject_count, reject_count))
        return;

    m_reject_count = reject_count;
    emit reject_countChanged(m_reject_count);
}

void grid_rect_properties::setShift(double shift)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_shift, shift))
        return;

    m_shift = shift;
    emit shiftChanged(m_shift);
}

void grid_rect_properties::setStop_time(double stop_time)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_stop_time, stop_time))
        return;

    m_stop_time = stop_time;
    emit stop_timeChanged(m_stop_time);
}

void grid_rect_properties::setBreakdown_time(double breakdown_time)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_breakdown_time, breakdown_time))
        return;

    m_breakdown_time = breakdown_time;
    emit breakdown_timeChanged(m_breakdown_time);
}

void grid_rect_properties::setRuntime(double runtime)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_runtime, runtime))
        return;

    m_runtime = runtime;
    emit runtimeChanged(m_runtime);
}

void grid_rect_properties::setIdeal_cycle(double ideal_cycle)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_ideal_cycle, ideal_cycle))
        return;

    m_ideal_cycle = ideal_cycle;
    emit ideal_cycleChanged(m_ideal_cycle);
}

void grid_rect_properties::setActual_cycle(double actual_cycle)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_actual_cycle, actual_cycle))
        return;

    m_actual_cycle = actual_cycle;
    emit actual_cycleChanged(m_actual_cycle);
}
