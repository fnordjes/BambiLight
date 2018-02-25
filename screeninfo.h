#ifndef SCREENINFO_H
#define SCREENINFO_H

#include <QObject>

#include <QGuiApplication>
#include <QQmlListProperty>
#include <QScreen>

class ScreenInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<QScreen*> screens READ screens)

public:
    explicit ScreenInfo(QObject *parent = nullptr);

    QQmlListProperty<QScreen*> screens();
    void appendScreen(QScreen*);
    int screenCount();
    QScreen* screen(int);
    void clearScreens();

signals:

public slots:

private:
    static void appendScreen(QQmlListProperty<QScreen*>*, QScreen*);
    static int screenCount(QQmlListProperty<QScreen*>*);
    static QScreen* screen(QQmlListProperty<QScreen*>*, int);
    static void clearScreens(QQmlListProperty<QScreen*>*);

    QList<QScreen*> m_screens;
};

#endif // SCREENINFO_H
