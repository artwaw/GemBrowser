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

#ifndef GEMINIPARSER_H
#define GEMINIPARSER_H

#include <QObject>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextBlockFormat>

#include "configfile.h"
#include "geminiprotocol.h"

class GeminiParser : public QObject
{
    Q_OBJECT
public:
    explicit GeminiParser(QObject *parent = nullptr,ConfigFile *cfg = nullptr);
    ~GeminiParser();
    QTextDocument* getPage() const;
    int getStatus() const { return _code; };
    QTextCharFormat getStyle(const int item) const;
    QTextBlockFormat getFormat(const int item) const;
    QString cache() const { return cacheFolder; }
    QPair<int,QString> cacheSize() const;

    enum ItemType {
        itemText = 0,
        itemLink = 1,
        itemQuote = 2,
        itemHeading1 = 3,
        itemheading2 = 4,
        itemheading3 = 5,
        itemPreformat = 6,
        itemList = 7
    };

public slots:
    void reloadCache();
    void clearCache();
    void loadPage(const QString &uri);

signals:
    void error(const QString &reason);
    void sensitiveInput();
    void input();
    void redirection(const QString &target);
    void status(const int code,const QString &desc);
    void gotPage();

private:
    QTextDocument* _txt;
    ConfigFile *_cfg;
    int _code = -1;
    QTextCharFormat _defCharFormat;
    QTextBlockFormat _defBlockFormat;
    QStringList findLines(const QString &text) const;
    QString cacheFolder;
    const QMap<int,QString> units = {
        {0,"Bytes"},
        {1,"kB"},
        {2,"MB"},
        {3,"GB"},//I sincerily doubt we'll get here but...
        {4,"TB"}
    };
    GeminiProtocol conn;

    void parsePage(const QByteArray &content);
};

#endif // GEMINIPARSER_H
