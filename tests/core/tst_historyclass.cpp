#include <QtTest>
#include <QDate>
#include <QSqlQuery>
#include <QFile>

#include "historyclass.h"
#include "toolkitclass.h"

class TestHistoryClass : public QObject {
    Q_OBJECT

public:
    TestHistoryClass();
    ~TestHistoryClass();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAdd();
    void testModel();
    void testVisits();
    void testLastUrl();
    void testUrlsForDay_init();
    void testUrlsForDay();
    void testRemove();
    void testClear();

private:
    const QString conn = "history";
    HistoryClass *history;
};

TestHistoryClass::TestHistoryClass() {}

TestHistoryClass::~TestHistoryClass() {}

void TestHistoryClass::initTestCase() {
    history = new HistoryClass(this);
}

void TestHistoryClass::cleanupTestCase() {
    delete history;
    QString fname = ToolkitClass::dataPath()+"data.db";
    QFile::remove(fname);
}

void TestHistoryClass::testAdd() {
    history->add("test1");
    history->add("test 2");
    history->add("test 3");
    QString s = "Added 3 items, expected 3, got "+QString::number(history->getSize());
    QVERIFY2(history->getSize()==3,s.toLocal8Bit());
}

void TestHistoryClass::testModel() {
    QVERIFY2(history->getModel()!=nullptr,"Model not null");
    QVERIFY2(history->getModel()->tableName()==conn,"Table name "+history->getModel()->tableName().toLocal8Bit());
}

void TestHistoryClass::testVisits() {
    history->add("test1");
    history->add("test 3");
    history->add("test 3");
    QVERIFY2(history->getVisits("test1")==2,"test1 == 2");
    QVERIFY2(history->getVisits("test 2")==1,"test 2 == 1");
    QVERIFY2(history->getVisits("test 3")==3,"test 3 == 3");
}

void TestHistoryClass::testLastUrl() {
    QVERIFY2(history->getLastUrl()=="test1","Last url == test1");
}

void TestHistoryClass::testUrlsForDay_init() {
    auto db = QSqlDatabase::database(conn);
    QSqlQuery query(db);
    QDate date = QDate::currentDate();
    query.exec("update "+conn+" set lastVisit = date('"+date.addDays(-1).toString(Qt::ISODate)+"') where url = 'test1';");
    query.exec("update "+conn+" set lastVisit = date('"+date.addDays(-2).toString(Qt::ISODate)+"') where url = 'test 2';");
    query.exec("update "+conn+" set lastVisit = date('"+date.addDays(-3).toString(Qt::ISODate)+"') where url = 'test 3';");
}

void TestHistoryClass::testUrlsForDay() {
    QDate date = QDate::currentDate();
    QStringList res = history->getUrlsFromDay(date.addDays(-1));
    QVERIFY2(res.size()==1,"Day -1 size == 1");
    QVERIFY2(res.at(0)=="test1","day-1 == test1");
    res = history->getUrlsFromDay(date.addDays(-2));
    QVERIFY2(res.size()==1,"Day -2 size == 1");
    QVERIFY2(res.at(0)=="test 2","day-2 == test 2");
    res = history->getUrlsFromDay(date.addDays(-3));
    QVERIFY2(res.size()==1,"Day -3 size == 1");
    QVERIFY2(res.at(0)=="test 3","day-3 == test 3");
}

void TestHistoryClass::testRemove() {
    int cs = history->getSize();
    history->remove(history->getLastUrl());
    QVERIFY2(history->getSize()==cs-1,"Size -1 after remove");
}

void TestHistoryClass::testClear() {
    history->clear();
    QVERIFY2(history->getSize()==0,"Zero size after clear");
}

QTEST_GUILESS_MAIN(TestHistoryClass)

#include "tst_historyclass.moc"
