#include <QtTest>
#include <FunctionsAndDataStructures.h>

// add necessary includes here

class AppTest : public QObject
{
    Q_OBJECT

public:
    AppTest();
    ~AppTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
};

AppTest::AppTest()
{

}

AppTest::~AppTest()
{

}

void AppTest::initTestCase()
{

}

void AppTest::cleanupTestCase()
{

}

void AppTest::test_case1()
{

}

void AppTest::test_case2()
{

}

#include "tst_apptest.moc"

int runTest(int argc, char *argv[]) {

    AppTest t;
    return QTest::qExec(&t, argc, argv);
}

#define TESTING_MODE

#include "../MainProject/main.cpp"

