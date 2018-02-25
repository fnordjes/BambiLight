#include <screeninfo.h>
#include <screengrabber.h>
#include <screenpainter.h>
#include <screensampler.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("Quaz GmbH");
    QCoreApplication::setOrganizationDomain("quaz.com");
    QCoreApplication::setApplicationName("Bambi");

    QGuiApplication app(argc, argv);

    // setup settings
//    QSettings settings;
//    settings.setValue("screens", QGuiApplication::screens().size());

    // setup qml
    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("screen"), new ScreenGrabber);
    qmlRegisterType<ScreenPainter>("ScreenPainter", 1, 0, "ScreenPainter");
    qmlRegisterType<ScreenSampler>("ScreenSampler", 1, 0, "ScreenSampler");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
