#ifndef MYLANGUAGE_H
#define MYLANGUAGE_H

#include <QObject>
#include <QLocale>

class MyLanguage : public QObject
{
    Q_OBJECT
public:
    MyLanguage() {};
    enum E_Languages {
        ENG = QLocale::English,
        JAP = QLocale::Japanese,
        HIN = QLocale::Hindi
    };
    Q_ENUM(E_Languages)
};

#endif // MYLANGUAGE_H
