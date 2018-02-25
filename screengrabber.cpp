#include "screengrabber.h"

#include <QGuiApplication>
#include <QScreen>

#include <QElapsedTimer>
#include <QDebug>

//struct Tracer
//{
//    Tracer(QString name) : name(name)
//    {
//        timer.start();
//    }
//    ~Tracer() {
//        qDebug() << name << timer.elapsed();
//    }
//    QString name;
//    QElapsedTimer timer;
//};

ScreenGrabber::ScreenGrabber()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

QPixmap ScreenGrabber::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    bool conversionOk = false;
    int screenId = id.toInt(&conversionOk);
    Q_ASSERT_X(conversionOk, __FUNCTION__, QStringLiteral("Cannot convert '%1' to screen id").arg(id).toStdString().c_str());

    QList<QScreen*> screens = QGuiApplication::screens();
    Q_ASSERT_X(screens.size() > screenId && screenId >= 0, __FUNCTION__, QStringLiteral("'%1' is not valid screen id").arg(screenId).toStdString().c_str());

    QScreen *screen = screens[screenId];
    QPixmap pixmap = screen->grabWindow(0);

    if (requestedSize.isValid()) {
        pixmap = pixmap.scaled(requestedSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    size->setWidth(pixmap.width());
    size->setHeight(pixmap.height());

    return pixmap;
}

QImage ScreenGrabber::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    return requestPixmap(id, size, requestedSize).toImage();
}
