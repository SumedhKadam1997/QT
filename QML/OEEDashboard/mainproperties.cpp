#include "mainproperties.h"
#include <database.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


database db;

mainproperties::mainproperties()
{

}

qint64 mainproperties::production_count() const
{
    return m_production_count;
}

qint64 mainproperties::rejection_count() const
{
    return m_rejection_count;
}

qint64 mainproperties::stop_time() const
{
    return m_stop_time;
}

qint64 mainproperties::breakdown_time() const
{
    return m_breakdown_time;
}

qint64 mainproperties::run_time() const
{
    return m_run_time;
}

qint64 mainproperties::oee() const
{
    return m_oee;
}

qint64 mainproperties::ava() const
{
    return m_ava;
}

qint64 mainproperties::perf() const
{
    return m_perf;
}

qint64 mainproperties::qua() const
{
    return m_qua;
}

void mainproperties::setProduction_count(qint64 production_count)
{
    if (m_production_count == production_count)
        return;

    m_production_count = production_count;
    emit production_countChanged(m_production_count);
}

void mainproperties::setrejection_count(qint64 rejection_count)
{
    if (m_rejection_count == rejection_count)
        return;

    m_rejection_count = rejection_count;
    emit rejection_countChanged(m_rejection_count);
}

void mainproperties::setStop_time(qint64 stop_time)
{
    if (m_stop_time == stop_time)
        return;

    m_stop_time = stop_time;
    emit stop_timeChanged(m_stop_time);
}

void mainproperties::setBreakdown_time(qint64 breakdown_time)
{
    if (m_breakdown_time == breakdown_time)
        return;

    m_breakdown_time = breakdown_time;
    emit breakdown_timeChanged(m_breakdown_time);
}

void mainproperties::setRun_time(qint64 run_time)
{
    if (m_run_time == run_time)
        return;

    m_run_time = run_time;
    emit run_timeChanged(m_run_time);
}

void mainproperties::setOee(qint64 oee)
{
    if (m_oee == oee)
        return;

    m_oee = oee;
    emit oeeChanged(m_oee);
}

void mainproperties::setAva(qint64 ava)
{
    if (m_ava == ava)
        return;

    m_ava = ava;
    emit avaChanged(m_ava);
}

void mainproperties::setPerf(qint64 perf)
{
    if (m_perf == perf)
        return;

    m_perf = perf;
    emit perfChanged(m_perf);
}

void mainproperties::setQua(qint64 qua)
{
    if (m_qua == qua)
        return;

    m_qua = qua;
    emit quaChanged(m_qua);
}

void mainproperties::setSatish(qint64 satish)
{
    if (m_satish == satish)
        return;

    m_satish = satish;
    emit satishChanged(m_satish);
}

qint64 mainproperties::satish() const
{
    return m_satish;
}
