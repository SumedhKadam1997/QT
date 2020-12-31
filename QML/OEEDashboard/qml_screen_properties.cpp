#include "qml_screen_properties.h"

qml_properties::qml_properties()
{

}

double qml_properties::titlebar_height() const
{
    return m_titlebar_height;
}

double qml_properties::titlebar_width() const
{
    return m_titlebar_width;
}

double qml_properties::body_height() const
{
    return m_body_height;
}

double qml_properties::body_width() const
{
    return m_body_width;
}

void qml_properties::setTitlebar_height(double titlebar_height)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_titlebar_height, titlebar_height))
        return;

    m_titlebar_height = titlebar_height;
    emit titlebar_heightChanged(m_titlebar_height);
}

void qml_properties::setTitlebar_width(double titlebar_width)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_titlebar_width, titlebar_width))
        return;

    m_titlebar_width = titlebar_width;
    emit titlebar_widthChanged(m_titlebar_width);
}

void qml_properties::setBody_height(double body_height)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_body_height, body_height))
        return;

    m_body_height = body_height;
    emit body_heightChanged(m_body_height);
}

void qml_properties::setBody_width(double body_width)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_body_width, body_width))
        return;

    m_body_width = body_width;
    emit body_widthChanged(m_body_width);
}
