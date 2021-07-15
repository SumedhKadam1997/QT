#ifndef MYTRANSLATOR_H
#define MYTRANSLATOR_H

#include <QObject>
#include <QGuiApplication>
#include <QTranslator>
#include <QDebug>
#include "MyLanguage.h"

class MyTranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)
    QGuiApplication * app;
    QTranslator mTranslator;

public:
    MyTranslator(QGuiApplication * mApp) : app(mApp) {}
    QString getEmptyString() {
        return "";
    };

public slots:
    void changeLanguage(int lang) {
        switch(lang){
        case MyLanguage::JAP:
            mTranslator.load("MultiLingualApp_JAP", ":/languages");
            app->installTranslator(&mTranslator);
            qDebug() << "JAPANESE";
            break;
        case MyLanguage::HIN:
            mTranslator.load("MultiLingualApp_HIN", ":/languages");
            app->installTranslator(&mTranslator);
            qDebug() << "HINDI";
            break;
        default:
            app->removeTranslator(&mTranslator);
            break;
        }
        emit languageChanged();
    }
signals:
    void languageChanged();
};


#endif // MYTRANSLATOR_H
