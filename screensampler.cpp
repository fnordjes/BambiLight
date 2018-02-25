#include "screensampler.h"

#include "screengrabber.h"

#include <QDebug>
#include <QElapsedTimer>

ScreenSampler::ScreenSampler(QObject *parent) : QObject(parent)
{
}

QColor ScreenSampler::sampleScreen(int screenId, int x, int y) const
{
    ScreenGrabber sg;
    QSize actualSize;

    QElapsedTimer t;
    t.start();

    QImage img = sg.requestImage(QString::number(screenId), &actualSize, QSize(16,9));

    qDebug() << t.elapsed();
    qDebug() << QColor(img.pixel(x,y));
    return  QColor(img.pixel(x,y));
}
