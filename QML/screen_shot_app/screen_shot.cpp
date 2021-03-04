#include "screen_shot.h"


screen_shot::screen_shot(QQuickView *currentView) :
    QObject(0), currentView_(currentView)
{

}

void screen_shot::capture(const QString &path) const
{
    QImage img = currentView_->grabWindow();
    img.save(path);
}
