#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "database.h"
#include "loginproperties.h"
#include "booksmodel.h"
#include "studentsmodel.h"
#include "librariansmodel.h"
#include "pendingbooksmodel.h"
#include "issuedbooksmodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("myLogin", loginProperties::getInstance());
    engine.rootContext()->setContextProperty("db", new database());
    engine.rootContext()->setContextProperty("allbooksmodel", new BooksModel);
    engine.rootContext()->setContextProperty("allstudentsmodel",new StudentsModel());
    engine.rootContext()->setContextProperty("alllibrariansmodel",new LibrariansModel());
    engine.rootContext()->setContextProperty("allpendingmodel",new pendingBooksModel());
    engine.rootContext()->setContextProperty("allissuedmodel",new issuedBooksModel());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
