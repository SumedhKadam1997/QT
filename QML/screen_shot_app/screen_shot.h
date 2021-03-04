#ifndef SCREEN_SHOT_H
#define SCREEN_SHOT_H

#include <QObject>
#include <QQuickView>


class screen_shot : public QObject
{
    Q_OBJECT


public:
    explicit screen_shot(QQuickView *parent = 0);

public slots:
    void capture(QString const &path) const;

private:
    QQuickView *currentView_;
};

#endif // SCREEN_SHOT_H
