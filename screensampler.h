#ifndef SCREENSAMPLER_H
#define SCREENSAMPLER_H

#include <QColor>
#include <QObject>

class ScreenSampler : public QObject
{
    Q_OBJECT
public:
    explicit ScreenSampler(QObject *parent = nullptr);

    Q_INVOKABLE QColor sampleScreen(int screenId, int x, int y) const;

signals:

public slots:
};

#endif // SCREENSAMPLER_H
