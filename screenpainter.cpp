#include <QDebug>
#include <QElapsedTimer>
#include <QGuiApplication>
#include <QTimer>

#include <screengrabber.h>

#include "screenpainter.h"

ScreenPainter::ScreenPainter(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_screenId(0),
    m_repaintTimer(new QTimer(this))
{  
    // TODO configure fps
    m_repaintTimer->setInterval(100);
    connect(m_repaintTimer, SIGNAL(timeout()), this, SLOT(update()));
    m_repaintTimer->start();

    const QList<QScreen*> screens = QGuiApplication::screens();
    foreach (QScreen* screen, screens) {
        m_availableScreens << QVariant::fromValue(screen);
    }
}

void ScreenPainter::paint(QPainter *painter)
{
#ifdef QT_DEBUG
    static int count = 0;
    static int lastPaint = 0;
    count++;
    static QElapsedTimer timer;
    if (!timer.isValid()) {
        timer.start();
    }
#endif

    QSize actualSize;
    ScreenGrabber sg;
    const QPixmap pic = sg.requestPixmap(QString::number(m_screenId), &actualSize, this->size().toSize());
    painter->drawPixmap(QPoint(0,0), pic);
    setPaintedWidth(pic.width());
    setPaintedHeight(pic.height());

#ifdef QT_DEBUG
    if (timer.elapsed() - lastPaint >= 10000) {
//        qDebug() << "my size" << this->size() << "real size" << actualSize;
//        qDebug() << count/10 << "fps";
        count = 0;
        lastPaint = timer.elapsed();
    }
#endif
}
