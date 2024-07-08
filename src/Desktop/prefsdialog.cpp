#include "prefsdialog.h"
#include "ui_prefsdialog.h"

#include <QSettings>
#include <QFontDatabase>

PrefsDialog::PrefsDialog(QWidget *parent, ConfigFile *cfg) : QDialog(parent), ui(new Ui::PrefsDialog) {
    ui->setupUi(this);
    if (cfg==nullptr) { qFatal("cfg is null in PrefsDialog!"); return; }
    _cfg = cfg;
    connect(ui->okBtn,&QPushButton::clicked,this,&PrefsDialog::verifyData);
    connect(ui->CancelBtn,&QPushButton::clicked,this,&PrefsDialog::reject);
    connect(ui->defaultsBtn,&QPushButton::clicked,this,[=](){
        cfg->defaults(ConfigFile::All);
        readSettings();
    });
    connect(ui->generalDefaults,&QPushButton::clicked,this,[=](){
        cfg->defaults(ConfigFile::General);
        readSettings();
    });
    connect(ui->visualDefaults,&QPushButton::clicked,this,[=](){
        cfg->defaults(ConfigFile::Visual,ui->styleItems->currentRow());
        readSettings();
    });
    connect(ui->clearHistoryBtn,&QPushButton::clicked,this,&PrefsDialog::clearHistory);
    connect(ui->saveHistoryBox,&QCheckBox::stateChanged,this,&PrefsDialog::updateHistorySettings);
    connect(ui->overrideBox,&QCheckBox::clicked,ui->itemOptionsGroup,&QGroupBox::setEnabled);
    connect(ui->styleItems,&QListWidget::currentRowChanged,this,[=](const int row){
        loadStyle(row);
    });
    connect(ui->clearCacheBtn,&QPushButton::clicked,this,&PrefsDialog::clearCache);
    ui->fontFamilyBox->addItems(QFontDatabase::families(QFontDatabase::Latin));
    readSettings();
    ui->saveHistoryBox->setChecked(iGeneral.saveHistory);
    iGeneral.allGems?ui->allGemsRadio->setChecked(true):ui->mainPageRadio->setChecked(true);
    ui->historyDays->setValue(iGeneral.days);
    iGeneral.forDays?ui->daysBtn->setChecked(true):ui->foreverBtn->setChecked(true);
    ui->styleItems->setCurrentRow(0);
    loadStyle(0,false);
    updateHistorySettings();
}

PrefsDialog::~PrefsDialog()
{
    delete ui;
}

void PrefsDialog::setCacheSize(const QPair<int,QString> &cacheSize) {
    ui->cacheSize->setValue(cacheSize.first);
    ui->cacheUnits->setText(cacheSize.second);
}

void PrefsDialog::verifyData() {
    writeSettings();
    if (iGeneral.saveHistory!=ui->saveHistoryBox->isChecked()||
        iGeneral.days!=ui->historyDays->value()||
        iGeneral.forDays!=ui->daysBtn->isChecked()) {
        emit rebuildHistory();
    }
    bool visual = false;
    for (auto x=0;x<iVisual.size();++x) {
        visual = visual||(iVisual.at(x).override!=ui->overrideBox->isChecked());
        visual = visual||(iVisual.at(x).bold!=ui->BoldBox->isChecked());
        visual = visual||(iVisual.at(x).italic!=ui->ItalicBox->isChecked());
        visual = visual||(iVisual.at(x).underline!=ui->underlineBox->isChecked());
        visual = visual||(iVisual.at(x).ffamily!=ui->fontFamilyBox->currentText());
        visual = visual||(iVisual.at(x).font!=ui->fontBox->currentText());
        visual = visual||(iVisual.at(x).ident!=ui->intednationBox->value());
        visual = visual||(iVisual.at(x).txtBg!=ui->textBgLine->text());
        visual = visual||(iVisual.at(x).txtClr!=ui->textClrLine->text());
    }
    if (visual) { emit reloadPage(); }
    if (iGeneral.cacheGems!=ui->cacheGems->isChecked()||
        iGeneral.cacheImages!=ui->cacheImages->isChecked()) {
        emit reloadCache();
    }
    accept();
}

void PrefsDialog::clearHistory() {
    emit rebuildHistory();
}

void PrefsDialog::updateHistorySettings() {
    ui->historyDetailsGroup->setEnabled(ui->saveHistoryBox->isChecked());
    ui->historyTimingGroup->setEnabled(ui->saveHistoryBox->isChecked());
}

void PrefsDialog::loadStyle(const int idx, const bool save) {
    if (save&&lastStyle>-1) {
        tmp[lastStyle].bold = ui->BoldBox->isChecked();
        tmp[lastStyle].ffamily = ui->fontFamilyBox->currentText();
        tmp[lastStyle].font = ui->fontBox->currentText();
        tmp[lastStyle].ident = ui->intednationBox->value();
        tmp[lastStyle].italic = ui->ItalicBox->isChecked();
        tmp[lastStyle].override = ui->overrideBox->isChecked();
        tmp[lastStyle].txtBg = ui->textBgLine->text();
        tmp[lastStyle].txtClr = ui->textClrLine->text();
        tmp[lastStyle].underline = ui->underlineBox->isChecked();
        tmp[lastStyle].fontSize = ui->fontSize->value();
    }
    lastStyle = idx;
    ui->fontBox->clear();
    ui->fontBox->addItems(QFontDatabase::styles(tmp.at(idx).ffamily));
    ui->BoldBox->setChecked(tmp.at(idx).bold);
    int fnt = ui->fontFamilyBox->findText(tmp.at(idx).ffamily);
    ui->fontFamilyBox->setCurrentIndex(fnt>-1?fnt:0);
    fnt = ui->fontBox->findText(tmp.at(idx).font);
    ui->fontBox->setCurrentIndex(fnt>-1?fnt:0);
    ui->intednationBox->setValue(tmp.at(idx).ident);
    ui->ItalicBox->setChecked(tmp.at(idx).italic);
    ui->overrideBox->setChecked(tmp.at(idx).override);
    ui->textBgLine->setText(tmp.at(idx).txtBg);
    ui->textClrLine->setText(tmp.at(idx).txtClr);
    ui->underlineBox->setChecked(tmp.at(idx).underline);
    ui->fontSize->setValue(tmp.at(idx).fontSize);
    ui->itemOptionsGroup->setEnabled(ui->overrideBox->isChecked());
}

void PrefsDialog::readSettings() {
    iGeneral = _cfg->getGeneral();
    iVisual.clear();
    for (auto x=0;x<8;++x) {
        iVisual.append(_cfg->getVisual(x));
    }
    tmp =iVisual;
    iBrowse = _cfg->getBrowse();
    ui->saveHistoryBox->setChecked(iGeneral.saveHistory);
    ui->allGemsRadio->setChecked(iGeneral.allGems);
    ui->daysBtn->setChecked(iGeneral.forDays);
    ui->historyDays->setValue(iGeneral.days);
    ui->cacheGems->setChecked(iGeneral.cacheGems);
    ui->cacheImages->setChecked(iGeneral.cacheImages);
}

void PrefsDialog::writeSettings() {
    _cfg->alterGeneral(iGeneral);
    for (auto x=0;x<tmp.size();++x) {
        _cfg->alterVisual(x,tmp.at(x));
    }
    _cfg->alterBrowsing(iBrowse);
}

void PrefsDialog::reloadSettings() {
    readSettings();
    loadStyle(0,false);
    updateHistorySettings();
}
