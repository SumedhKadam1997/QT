#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "screen_shot.h"
#include <QQmlContext>



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

//    qmlRegisterType<screenCapture>("Image", 1, 0, "ScreenCapture");
//    qmlRegisterType<saveAbleImage>("Image", 1, 0, "SaveAbleImage");


//    screen_shot *ss = new screen_shot();
//    QQmlApplicationEngine engine;
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QStringLiteral("qrc:/main.qml"));
    view.show();

    screen_shot screenClass(&view);
    view.rootContext()->setContextProperty("screenObject", &screenClass);

//    engine.rootContext()->setContextProperty("ss",ss);
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
