#ifndef VIDEOFILTER_HPP
#define VIDEOFILTER_HPP

#include <QObject>
#include <QAbstractVideoFilter>

class MyVideoFilterRunnable : public QVideoFilterRunnable
{
public:
    QVideoFrame run(QVideoFrame* input, const QVideoSurfaceFormat& surfaceFormat, RunFlags flags)
    {
        if (!input->isValid())
        {
            return *input;
        }
        return *input;
    }
};

class MyVideoFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    QVideoFilterRunnable *createFilterRunnable() Q_DECL_OVERRIDE
    {
        return new MyVideoFilterRunnable;
    }
};



#endif // VIDEOFILTER_HPP
