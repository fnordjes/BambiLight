#ifndef SCREENPAINTER_H
#define SCREENPAINTER_H

#include <QPainter>
#include <QQuickPaintedItem>
#include <QScreen>

class ScreenPainter : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int paintedWidth READ paintedWidth WRITE setPaintedWidth NOTIFY paintedWidthChanged)
    Q_PROPERTY(int paintedHeight READ paintedHeight WRITE setPaintedHeight NOTIFY paintedHeightChanged)
    Q_PROPERTY(int screenId READ screenId WRITE setScreenId NOTIFY screenIdChanged)
    Q_PROPERTY(QVariantList availableScreens READ availableScreens NOTIFY availableScreensChanged)

public:
    ScreenPainter(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    int paintedWidth() const
    {
        return m_paintedWidth;
    }

    int paintedHeight() const
    {
        return m_paintedHeight;
    }

    int screenId() const
    {
        return m_screenId;
    }

    QVariantList availableScreens() const
    {
        return m_availableScreens;
    }

public slots:
    void setPaintedWidth(int paintedWidth)
    {
        if (m_paintedWidth == paintedWidth)
            return;

        m_paintedWidth = paintedWidth;
        emit paintedWidthChanged(m_paintedWidth);
    }

    void setPaintedHeight(int paintedHeight)
    {
        if (m_paintedHeight == paintedHeight)
            return;

        m_paintedHeight = paintedHeight;
        emit paintedHeightChanged(m_paintedHeight);
    }

    void setScreenId(int screenId)
    {
        if (m_screenId == screenId)
            return;

        m_screenId = screenId;
        emit screenIdChanged(m_screenId);
    }

signals:
    void paintedWidthChanged(int paintedWidth);

    void paintedHeightChanged(int paintedHeight);

    void screenIdChanged(int screenId);

    void availableScreensChanged(QVariantList availableScreens);

private:
    int m_paintedWidth;
    int m_paintedHeight;
    int m_screenId;
    QVariantList m_availableScreens;

    QTimer* m_repaintTimer;
};

#endif // SCREENPAINTER_H
