#include "configfile.h"

#include <QFile>
#include <QDataStream>
#include <QBuffer>
#include <QDebug>
#include <QFontDatabase>
#include <QDir>

ConfigFile::ConfigFile(QObject *parent,const QString cfg_file) : QObject{parent} {
    if (!cfg_file.isEmpty()) {
        _fpath = cfg_file;
    }
    QString Path = _fpath;
    QDir dir(Path.remove(Path.split('/').last()));
    if (!dir.exists(dir.absolutePath())) {
        if (!dir.mkpath(dir.absolutePath())) {
            qWarning("Can't make path: %c",_fpath.data()->toLatin1());
        }
    }
    readSettings();
}

ConfigFile::~ConfigFile() {
    writeSettings();
}

void ConfigFile::alterGeneral(const generalStruct &gen) {
    _general = gen;
    emit configChanged();
}

void ConfigFile::alterVisual(const int idx, const visualStruct &vis) {
    if (idx<0||idx>8) { return; }
    _visual.replace(idx,vis);
    emit configChanged();
}

void ConfigFile::alterTLS(const tlsStruct &tlss) {
    Q_UNUSED(tlss)
    emit configChanged();
}

void ConfigFile::alterBrowsing(const browsingStruct &browse) {
    _browser = browse;
    emit configChanged();
}

void ConfigFile::setGeo(const QSize &_geo) {
    if (_geo.isEmpty()) { return; }
    setup.geo = _geo;
}

void ConfigFile::setPos(const QPoint &_pos) {
    if (_pos.isNull()) { return; }
    setup.pos = _pos;
}

void ConfigFile::readSettings() {
    QFile f(_fpath);
    if (!f.exists()||f.size()==0) {
        defaults(ConfigFile::All);
        writeSettings();
    }
    if (!f.open(QIODevice::ReadOnly)) {
        _status = ConfigFile::ReadError;
        _statusText = ConfigFile::statusReadErrorText+"/n"+f.errorString();
        emit error();
        return;
    }
    QBuffer buf;
    QByteArray dta;
    QDataStream raw(&f);
    raw >> dta;
    buf.setData(qUncompress(dta));
    buf.open(QIODevice::ReadOnly);
    QDataStream dStream(&buf);
    dStream >> _general.allGems;
    dStream >> _general.cacheGems;
    dStream >> _general.cacheImages;
    dStream >> _general.days;
    dStream >> _general.forDays;
    dStream >> _general.saveHistory;
    raw >> dta;
    buf.close();
    buf.setData(qUncompress(dta));
    buf.open(QIODevice::ReadOnly);
    visualStruct vis;
    _visual.clear();
    for (auto x=0;x<8;++x) {
        dStream >> vis.override;
        dStream >> vis.txtClr;
        dStream >> vis.underline;
        dStream >> vis.italic;
        dStream >> vis.bold;
        dStream >> vis.txtBg;
        dStream >> vis.ident;
        dStream >> vis.ffamily;
        dStream >> vis.font;
        dStream >> vis.fontSize;
        _visual.append(vis);
    }
//tls is empty, will be added here
    raw >> dta;
    buf.close();
    buf.setData(qUncompress(dta));
    buf.open(QIODevice::ReadOnly);
    dStream >> _browser.newTab;
    dStream >> _browser.externalOption;
    dStream >> _browser.home;
    buf.close();
    raw >> dta;
    buf.setData(qUncompress(dta));
    buf.open(QIODevice::ReadOnly);
    dStream >> setup.geo;
    dStream >> setup.pos;
    dStream >> setup.tabs;
    buf.close();
    f.close();
    emit configChanged();
}

void ConfigFile::writeSettings() {
    QFile f(_fpath);
    if (!f.open(QIODevice::WriteOnly)) {
        _status = ConfigFile::WriteError;
        _statusText = ConfigFile::statusWriteErrorText+"/n"+f.errorString();
        qWarning("Write settings error: %c",_statusText.data()->toLatin1());
        emit error();
        return;
    }
    QDataStream raw(&f);
    QBuffer buf;
    QDataStream dStream(&buf);
    buf.open(QIODevice::WriteOnly);
    QByteArray dta;
    dStream << _general.allGems;
    dStream << _general.cacheGems;
    dStream << _general.cacheImages;
    dStream << _general.days;
    dStream << _general.forDays;
    dStream << _general.saveHistory;
    dta = qCompress(buf.data(),9);
    raw << dta;
    buf.close();
    buf.buffer().clear();
    dta.clear();
    buf.open(QIODevice::WriteOnly);
    for (auto x=0;x<8;++x) {
        dStream << _visual.at(x).override;
        dStream << _visual.at(x).txtClr;
        dStream << _visual.at(x).underline;
        dStream << _visual.at(x).italic;
        dStream << _visual.at(x).bold;
        dStream << _visual.at(x).txtBg;
        dStream << _visual.at(x).ident;
        dStream << _visual.at(x).ffamily;
        dStream << _visual.at(x).font;
        dStream << _visual.at(x).fontSize;
    }
    dta = qCompress(buf.data(),9);
    raw << dta;
    buf.close();
//tls is empty, implementation comes here
    buf.buffer().clear();
    dta.clear();
    buf.open(QIODevice::WriteOnly);
    dStream << _browser.newTab;
    dStream << _browser.externalOption;
    dStream << _browser.home;
    dta = qCompress(buf.data(),9);
    raw << dta;
    buf.close();
    buf.buffer().clear();
    dta.clear();
    buf.open(QIODevice::WriteOnly);
    dStream << setup.geo;
    dStream << setup.pos;
    dStream << setup.tabs;
    dta = qCompress(buf.data(),9);
    raw << dta;
    buf.close();
    f.close();
}

void ConfigFile::defaults(const int type, const int section) {
    if (type==ConfigFile::General||type==ConfigFile::All) {
        _general.saveHistory = false;
        _general.allGems = false;
        _general.forDays = false;
        _general.days = 30;
        _general.cacheGems = true;
        _general.cacheImages = false;
    }
    if (type==ConfigFile::Visual||type==ConfigFile::All) {
        if (section==-1) {
            _visual.clear();
            for (auto x=0;x<8;++x) {
                _visual.append(visualStruct());
            }
            for (auto x=0;x<8;++x) {
                defSection(x);
            }
        } else {
            defSection(section);
        }
    }
    if (type==ConfigFile::TLS||type==ConfigFile::All) {
        // tls config comes here
    }
    if (type==ConfigFile::Browse||type==ConfigFile::All) {
        _browser.externalOption = ConfigFile::OsOption;
        _browser.home = "medusae.space";
        _browser.newTab = true;
    }
    if (type==ConfigFile::Setup||type==ConfigFile::All) {
        setup.geo =  QSize(800,450);
        setup.pos = QPoint(12,74);
        setup.tabs.clear();
    }
    writeSettings();
}

void ConfigFile::defSection(const int idx) {
    if (idx<0||idx>7) { return; };
    visualStruct vis;
    vis.override = false;
    vis.txtClr = idx==1?"#00F":"#000";
    vis.underline = idx==1?true:false;
    vis.italic = idx==2?true:false;
    vis.bold = (idx>2&&idx<6)?true:false;
    vis.txtBg = "#fff";
    vis.ident = idx==2?15:0;
    vis.font = idx==6?QFontDatabase::font("Courier New","Normal",12).toString():QFontDatabase::systemFont(QFontDatabase::GeneralFont).toString();
    vis.ffamily = idx==6?QFontDatabase::font("Courier New","Normal",12).family():QFontDatabase::systemFont(QFontDatabase::GeneralFont).family();
    vis.fontSize = 13;
    _visual.replace(idx,vis);
}
