#ifndef SCREENGRABBER_H
#define SCREENGRABBER_H

#include <QQuickImageProvider>

class ScreenGrabber : public QQuickImageProvider
{
public:
    ScreenGrabber();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // SCREENGRABBER_H
