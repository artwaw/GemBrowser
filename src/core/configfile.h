/*
This file is part of GemBrowser project.
GemBrowser is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
GemBrowser is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details (file LICENSE).
You should have received a copy of the GNU General Public License
along with GemBrowser.  If not, see <https://www.gnu.org/licenses/>.
SPDX: GPL-3.0-or-later
*/

#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include "toolkitclass.h"

#include <QObject>
#include <QSize>
#include <QPoint>

/*!
 * \brief The ConfigFile class - reading, writing and maintaing program settings. Source of truth.
 *
 * Internally settings are written to where the OS expects config to be saved, in binary and compressed format.
 *
 * This class doubles the work of QSettings but I ran into an issue with the arrays:
 * https://forum.qt.io/topic/157528/qsettings-array-increasing-the-size/
 * Since nobody was willing to explain (which is weird, those ppl are usually very
 * helpful) I was forced to write my own. I hate it, until Qt 6.7.2 arrays were working
 * just fine. But here it is, oh well.
 */
class ConfigFile : public QObject
{
    Q_OBJECT
public:
    struct visualStruct {
        bool override;
        QString txtClr;
        bool underline;
        bool italic;
        bool bold;
        QString txtBg;
        qreal ident;
        QString ffamily;
        QString font;
        int fontSize;
    };

    struct generalStruct {
        bool saveHistory;
        bool allGems;
        bool forDays;
        int days;
        bool cacheGems;
        bool cacheImages;
    };

    struct tlsStruct {};

    struct browsingStruct {
        bool newTab;
        int externalOption;
        QString home;
    };

    struct setupStruct {
        QSize geo;
        QPoint pos;
        QStringList tabs;
    };

    enum externalLinksOption {
        Ignore = -1,
        OsOption = 0,
        Custom = 1
    };

    enum defaultsType {
        All = 0,
        General = 1,
        Visual = 2,
        TLS = 3,
        Browse = 4,
        Setup = 5
    };

    enum status {
        OK = 0,
        ReadError = 1,
        WriteError = 2
    };

    explicit ConfigFile(QObject *parent = nullptr, const QString cfg_file = QString());
    ~ConfigFile();
    void alterGeneral(const generalStruct &gen);
    void alterVisual(const int idx, const visualStruct &vis);
    void alterTLS(const tlsStruct &tlss);
    void alterBrowsing(const browsingStruct &browse);
    void setGeo(const QSize &_geo);
    void setPos(const QPoint &_pos);
    void setTabs(const QStringList &_tabs) { setup.tabs = _tabs; };
    int status() const { return _status; };
    QString statusText() const { return _statusText; };
    QString getConfigPath() const { return _fpath; };
    generalStruct getGeneral() const { return _general; }
    visualStruct getVisual(const int idx =0) const { return _visual.at(idx); }
    tlsStruct getTLS() const { return _tls; };
    browsingStruct getBrowse() const { return _browser; };
    QSize getGeo() const { return setup.geo; };
    QPoint getPos() const { return setup.pos; }
    QStringList getTabs() const { return setup.tabs; }
    setupStruct getSetup() const { return setup; }

public slots:
    void readSettings();
    void writeSettings();
    void defaults(const int type = -1, const int section = -1);
    void defSection(const int idx = -1);

signals:
    void configChanged();
    void error();

private:
    QString _fpath = ToolkitClass::configPath()+"/gb.cfg";
    const QString statusOkText = tr("All good");
    const QString statusReadErrorText = tr("Error opening config file for reading. ");
    const QString statusWriteErrorText = tr("Error opening config file for writing. ");
    generalStruct _general;
    QList<visualStruct> _visual;
    tlsStruct _tls;
    browsingStruct _browser;
    setupStruct setup;
    int _status = ConfigFile::OK;
    QString _statusText = statusOkText;
};

#endif // CONFIGFILE_H
