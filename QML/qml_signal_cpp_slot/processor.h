#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>

class processor : public QObject
{
    Q_OBJECT
public:
    explicit processor(QObject *parent = 0);

public slots:
    void onMenuClicked(const QString &str);
};

#endif // PROCESSOR_H
