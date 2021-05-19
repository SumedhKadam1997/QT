#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "my_list.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    my_list mylist;
    temp_list<QString> lst;

    QObject::connect(&mylist, &my_list::itemAdded, &lst, &temp_list<QString>::get_signal);
//
    lst.getItems();
    lst.appendItems("HELLO WORLD");
    lst.appendItems("HELLO WORLD");
    lst.getItems();
    lst.clear();
    lst.getItems();

//

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
