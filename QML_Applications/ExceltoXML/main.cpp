#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Aspose.Cells.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    // Load the XLS.
    intrusive_ptr<Aspose::Cells::IWorkbook> wkb = Aspose::Cells::Factory::CreateIWorkbook(new String("C:\\Users\\UxoriousGhost-WorkPC\\Downloads\\HMI Settings List R1 SR24 2A (October 20 2021).xlsx"));

    // Save in XML format.
    wkb->Save(new String("C:\\Users\\UxoriousGhost-WorkPC\\Downloads\\convertedFile.xml"), Aspose::Cells::SaveFormat::SaveFormat_SpreadsheetML);


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
