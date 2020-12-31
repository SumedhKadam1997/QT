#ifndef QML_SCREEN_PROPERTIES_H
#define QML_SCREEN_PROPERTIES_H

#include <QObject>

class qml_properties: public QObject
{
    Q_OBJECT

    Q_PROPERTY(double titlebar_height READ titlebar_height WRITE setTitlebar_height NOTIFY titlebar_heightChanged)
    Q_PROPERTY(double titlebar_width READ titlebar_width WRITE setTitlebar_width NOTIFY titlebar_widthChanged)
    Q_PROPERTY(double body_height READ body_height WRITE setBody_height NOTIFY body_heightChanged)
    Q_PROPERTY(double body_width READ body_width WRITE setBody_width NOTIFY body_widthChanged)

    double m_titlebar_height;
    double m_titlebar_width;
    double m_body_height;
    double m_body_width;

public:
    qml_properties();
    double titlebar_height() const;
    double titlebar_width() const;
    double body_height() const;
    double body_width() const;

public slots:
    void setTitlebar_height(double titlebar_height);
    void setTitlebar_width(double titlebar_width);
    void setBody_height(double body_height);
    void setBody_width(double body_width);

signals:
    void titlebar_heightChanged(double titlebar_height);
    void titlebar_widthChanged(double titlebar_width);
    void body_heightChanged(double body_height);
    void body_widthChanged(double body_width);
};

#endif // QML_SCREEN_PROPERTIES_H
