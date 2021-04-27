#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include<math.h>
RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
{
}
QSize RenderArea::minimumSizeHint() const {
    return QSize(100,100);
}
QSize RenderArea::sizeHint() const {
    return QSize(400,100);
}

void RenderArea::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);


    switch (mShape){
    case Astroid:
        mBackgroundColor = Qt::red;
        break;
    case Cycloid:
        mBackgroundColor = Qt::green;
        break;
    case HuygensCycloid:
        mBackgroundColor = Qt::blue;
        break;
    case HypoCycloid:
        mBackgroundColor = Qt::yellow;
        break;
    default:
        break;
    }
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    painter.drawRect(this->rect());

    int stepCount = 64;
    float intervalLength = 2 * M_PI;
    float step = intervalLength / stepCount;
    for (float t = 0; t < intervalLength; t += step){
        QPointF point = compute_astroid(t);

        QPoint pixel;
        pixel.setX(point.x());
        pixel.setY(point.y());
    }
}
