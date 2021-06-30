#include <QtTest>
#include <QObject>
#include "csvparser.h"
#include <QFile>


class CSVTest : public QObject {
    Q_OBJECT
    QString in = "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\C++ Applications\\data.csv";
    QString out = "C:\\Users\\uxoriousghost\\Desktop\\QT-QML\\C++ Applications\\result.csv";
    CSVParser parse{3, in, out};
public:

private slots:
    void initTestCase();
    void argCountTest();
    void inPathCheck();
    void outPathCheck();
    void openInPath();
    void openOutPath();
    void checkFirstNum();
    void checkSecondNum();
    void checkThirdString();
    void checkSumofDigits();
    void checkSum();
    void checkParse();
    void cleanupTestCase();
};

void CSVTest::initTestCase()
{

}

void CSVTest::argCountTest() {
    QCOMPARE(parse.checkArgCount(), 3);
}

void CSVTest::inPathCheck()
{
//    QCOMPARE(parse.checkInPathExists(), true);
    QVERIFY2(QFile(in).exists(), "File does not exists");
}

void CSVTest::outPathCheck()
{
//    QCOMPARE(parse.checkOutPathExists(), true);
    QVERIFY2(QFile(out).exists(), "File does not exists");
}

void CSVTest::openInPath()
{
    QCOMPARE(parse.openInPath(), true);
}

void CSVTest::openOutPath()
{
    QCOMPARE(parse.openOutPath(), true);
}

void CSVTest::checkFirstNum()
{
    QCOMPARE(parse.checkFirstNumber(), true);
}

void CSVTest::checkSecondNum()
{
    QCOMPARE(parse.checkSecondNumber(), true);
}

void CSVTest::checkThirdString()
{
    QCOMPARE(parse.checkThirdString(), true);
}

void CSVTest::checkSumofDigits()
{
    QCOMPARE(parse.getSumofDigits("123ab"), 6);
}

void CSVTest::checkSum()
{
    QCOMPARE(parse.calculateSum(),1503219572);
}

void CSVTest::checkParse()
{
    QCOMPARE(parse.parser(),true);
}

void CSVTest::cleanupTestCase()
{

}

QTEST_APPLESS_MAIN(CSVTest)

#include "test.moc"
