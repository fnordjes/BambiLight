#include "screeninfo.h"

ScreenInfo::ScreenInfo(QObject *parent) :
    QObject(parent),
    m_screens(QGuiApplication::screens())
{
}

QQmlListProperty<QScreen *> ScreenInfo::screens()
{
    return QQmlListProperty<QScreen*>(this, this,
                                      &ScreenInfo::appendScreen,
                                      &ScreenInfo::screenCount,
                                      &ScreenInfo::screen,
                                      &ScreenInfo::clearScreens);
}

void ScreenInfo::appendScreen(QScreen* s)
{
    m_screens.append(s);
}

int ScreenInfo::screenCount()
{
    return m_screens.count();
}

QScreen *ScreenInfo::screen(int index)
{
    Q_ASSERT_X(m_screens.count() > index && index >= 0, __FUNCTION__, "Index is out of bounds");

    return m_screens.at(index);
}

void ScreenInfo::clearScreens()
{
    m_screens.clear();
}


void ScreenInfo::appendScreen(QQmlListProperty<QScreen*>* list, QScreen* p)
{
    reinterpret_cast< ScreenInfo* >(list->data)->appendScreen(p);
}

void ScreenInfo::clearScreens(QQmlListProperty<QScreen*>* list)
{
    reinterpret_cast< ScreenInfo* >(list->data)->clearScreens();
}

QScreen* ScreenInfo::screen(QQmlListProperty<QScreen*>* list, int i)
{
    return reinterpret_cast< ScreenInfo* >(list->data)->screen(i);
}

int ScreenInfo::screenCount(QQmlListProperty<QScreen*>* list) {
    return reinterpret_cast< ScreenInfo* >(list->data)->screenCount();
}
