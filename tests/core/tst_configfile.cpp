#include <QtTest>
#include <QFile>
#include <QFileInfo>
#include <QFontDatabase>

#include "configfile.h"

class TestConfigFile : public QObject
{
    Q_OBJECT

public:
    TestConfigFile();
    ~TestConfigFile();

    ConfigFile *cfg;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void FileReadWrite();
    void ConfigGeneralDefaults();
    void ConfigVisualDefaults();
    void ConfigTLSDefaults();
    void ConfigBrowsingDefaults();
    void ConfigSetupDefaults();
    void AlterGeneralData_init();
    void AlterGeneralData();
    void AlterGeneralData_cleanup();
    void AlterVisualData_init();
    void AlterVisualData();
    void AlterVisualData_cleanup();
    void AlterTLSData_init();
    void AlterTLSData();
    void AlterTLSData_cleanup();
    void AlterBrowsingData_init();
    void AlterBrowsingData();
    void AlterBrowsingData_cleanup();
    void AlterSetupData_init();
    void AlterSetupData();
    void AlterSetupData_cleanup();
};

TestConfigFile::TestConfigFile() {}

TestConfigFile::~TestConfigFile() {}

void TestConfigFile::initTestCase() {
    cfg = new ConfigFile(this);
    cfg->defaults(ConfigFile::All);
    QVERIFY2(cfg->status()==ConfigFile::OK,qPrintable(cfg->statusText()));
}

void TestConfigFile::cleanupTestCase() {
    QString fname = cfg->getConfigPath();
    delete cfg;
    QFile::remove(fname);
}

void TestConfigFile::FileReadWrite() {
    QFile f(cfg->getConfigPath());
    QVERIFY2(f.exists(),qPrintable(QDir().absoluteFilePath(f.fileName())+cfg->statusText()));
    QFileInfo info(f);
    QVERIFY2(info.isFile(),qPrintable(QDir().absoluteFilePath(f.fileName())+cfg->statusText()));
    QVERIFY2(info.size()>0,qPrintable(QDir().absoluteFilePath(f.fileName())+cfg->statusText()));
    QVERIFY2(info.isReadable(),qPrintable(QDir().absoluteFilePath(f.fileName())+cfg->statusText()));
    QVERIFY2(info.isWritable(),qPrintable(QDir().absoluteFilePath(f.fileName())+cfg->statusText()));
}

void TestConfigFile::ConfigGeneralDefaults() {
    ConfigFile::generalStruct gen = cfg->getGeneral();
    QCOMPARE(gen.saveHistory,false);
    QCOMPARE(gen.allGems,false);
    QCOMPARE(gen.forDays,false);
    QCOMPARE(gen.days,30);
    QCOMPARE(gen.cacheGems,true);
    QCOMPARE(gen.cacheImages,false);
}

void TestConfigFile::ConfigVisualDefaults() {
    ConfigFile::visualStruct vis;
    for (auto idx=0;idx<8;++idx) {
        vis = cfg->getVisual(idx);
        QCOMPARE(vis.override,false);
        QCOMPARE(vis.txtClr,idx==1?"#00F":"#000");
        QCOMPARE(vis.underline,idx==1?true:false);
        QCOMPARE(vis.italic,idx==2?true:false);
        QCOMPARE(vis.bold,(idx>2&&idx<6)?true:false);
        QCOMPARE(vis.txtBg,"#fff");
        QCOMPARE(vis.ident,idx==2?15:0);
        QCOMPARE(vis.font,idx==6?QFontDatabase::font("Courier New","Normal",12).toString():QFontDatabase::systemFont(QFontDatabase::GeneralFont).toString());
        QCOMPARE(vis.ffamily,idx==6?QFontDatabase::font("Courier New","Normal",12).family():QFontDatabase::systemFont(QFontDatabase::GeneralFont).family());
        QCOMPARE(vis.fontSize,13);
    }
}

void TestConfigFile::ConfigTLSDefaults() {
    QSKIP("Not implemented yet!");
}

void TestConfigFile::ConfigBrowsingDefaults() {
    ConfigFile::browsingStruct bro = cfg->getBrowse();
    QCOMPARE(bro.externalOption,ConfigFile::OsOption);
    QCOMPARE(bro.home,"medusae.space");
    QCOMPARE(bro.newTab,true);
}

void TestConfigFile::ConfigSetupDefaults() {
    QCOMPARE(cfg->getSetup().geo,QSize(800,450));
    QCOMPARE(cfg->getSetup().pos,QPoint(12,74));
    QCOMPARE(cfg->getSetup().tabs,QStringList());
}

void TestConfigFile::AlterGeneralData_init() {
    const ConfigFile::generalStruct gen = {
        .saveHistory = true,
        .allGems = true,
        .forDays = true,
        .days = 13,
        .cacheGems = false,
        .cacheImages = true
    };
    cfg->alterGeneral(gen);
}

void TestConfigFile::AlterGeneralData() {
    ConfigFile::generalStruct gen = cfg->getGeneral();
    QCOMPARE(gen.saveHistory,true);
    QCOMPARE(gen.allGems,true);
    QCOMPARE(gen.forDays,true);
    QCOMPARE(gen.days,13);
    QCOMPARE(gen.cacheGems,false);
    QCOMPARE(gen.cacheImages,true);
}

void TestConfigFile::AlterGeneralData_cleanup() {
    cfg->defaults(ConfigFile::General);
}

void TestConfigFile::AlterVisualData_init() {
    const ConfigFile::visualStruct vis = {
        .override = true,
        .txtClr = "abc",
        .underline = true,
        .italic = true,
        .bold = true,
        .txtBg = "xyz",
        .ident = 42,
        .ffamily = "family",
        .font = "font",
        .fontSize = 42
    };
    for (auto x=0;x<8;++x) {
        cfg->alterVisual(x,vis);
    }
}

void TestConfigFile::AlterVisualData() {
    ConfigFile::visualStruct vis;
    for (auto x=0;x<8;++x) {
        vis = cfg->getVisual(x);
        QCOMPARE(vis.override,true);
        QCOMPARE(vis.txtClr,"abc");
        QCOMPARE(vis.underline,true);
        QCOMPARE(vis.bold,true);
        QCOMPARE(vis.italic,true);
        QCOMPARE(vis.txtBg,"xyz");
        QCOMPARE(vis.ident,42);
        QCOMPARE(vis.ffamily,"family");
        QCOMPARE(vis.font,"font");
        QCOMPARE(vis.fontSize,42);
    }
}

void TestConfigFile::AlterVisualData_cleanup() {
    cfg->defaults(ConfigFile::Visual);
}

void TestConfigFile::AlterTLSData_init() {
    QSKIP("Not implementet yet");
}

void TestConfigFile::AlterTLSData() {
    QSKIP("Not implementet yet");
}

void TestConfigFile::AlterTLSData_cleanup() {
    QSKIP("Not implementet yet");
}

void TestConfigFile::AlterBrowsingData_init() {
    const ConfigFile::browsingStruct bro = {
        .newTab = false,
        .externalOption = ConfigFile::Ignore,
        .home = "Gemini calls home"
    };
    cfg->alterBrowsing(bro);
}

void TestConfigFile::AlterBrowsingData() {
    ConfigFile::browsingStruct bro = cfg->getBrowse();
    QCOMPARE(bro.newTab,false);
    QCOMPARE(bro.externalOption,ConfigFile::Ignore);
    QCOMPARE(bro.home,"Gemini calls home");
}

void TestConfigFile::AlterBrowsingData_cleanup() {
    cfg->defaults(ConfigFile::Browse);
}

void TestConfigFile::AlterSetupData_init() {
    cfg->setGeo(QSize(850,720));
    cfg->setPos(QPoint(100,100));
    cfg->setTabs({"medusae.space","gemini.tabs"});
}

void TestConfigFile::AlterSetupData() {
    QCOMPARE(cfg->getSetup().geo,QSize(850,720));
    QCOMPARE(cfg->getSetup().pos,QPoint(100,100));
    QCOMPARE(cfg->getSetup().tabs,QStringList({"medusae.space","gemini.tabs"}));
}

void TestConfigFile::AlterSetupData_cleanup() {
    cfg->defaults(ConfigFile::Setup);
}

QTEST_MAIN(TestConfigFile)

#include "tst_configfile.moc"
