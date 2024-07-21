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

#include "geminiparser.h"

#include <QTextCursor>
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include <QFileInfoList>

GeminiParser::GeminiParser(QObject *parent, ConfigFile *cfg) : QObject(parent) {
    if (cfg == nullptr) { qFatal("cfg is null in parser"); return; }
    _cfg = cfg;
    _txt = new QTextDocument(this);
    reloadCache();
    connect(&conn,&GeminiProtocol::newPage,this,[this](){
        parsePage(conn.lastPage());
    });
    connect(&conn,&GeminiProtocol::error,this,[this](const int code){
        if (code == 1) { return; }
        emit status(code,conn.errorStr());
    });
    connect(&conn,&GeminiProtocol::status,this,[this](const int code){
        emit status(code,conn.errorStr());
    });
}

GeminiParser::~GeminiParser() {
    delete _txt;
}

QTextDocument* GeminiParser::getPage() const {
    return _txt;
}

QTextCharFormat GeminiParser::getStyle(const int item) const {
    ConfigFile::visualStruct vis = _cfg->getVisual(item);
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QVariant(vis.txtClr).value<QColor>()));
    fmt.setBackground(QBrush(QVariant(vis.txtBg).value<QColor>()));
    fmt.setFontFamilies({vis.ffamily});
    fmt.setFont(QFont(vis.font));
    fmt.setFontItalic(vis.italic);
    fmt.setFontUnderline(vis.underline);
    fmt.setFontWeight(vis.bold?700:400);
    fmt.setFontPointSize(vis.fontSize);
    return fmt;
}

QTextBlockFormat GeminiParser::getFormat(const int item) const {
    QTextBlockFormat fmt;
    fmt.setLeftMargin(_cfg->getVisual(item).ident);
    if (item==GeminiParser::itemPreformat) {
        fmt.setNonBreakableLines(true);
    }
    return fmt;
}

QPair<int,QString> GeminiParser::cacheSize() const {
    QDir dir(cacheFolder);
    QFileInfoList infoList = dir.entryInfoList(QDir::Files|QDir::NoDotAndDotDot);
    QPair<int,QString> ret;
    for (auto x=0;x<infoList.size();++x) {
        ret.first = ret.first + infoList.at(x).size();
    }
    int power = 0;
    while (ret.first>1024) {
        ++power;
        ret.first=ret.first/1024;
    }
    ret.second = units.value(power);
    return ret;
}

QStringList GeminiParser::findLines(const QString &text) const {
    QStringList ret;
    int lastPos = 0;
    for (auto pos=0;pos<text.size();++pos) {
        if (text.at(pos)==QChar::LineFeed) {
            ret.append(text.sliced(lastPos,(pos-lastPos)));
            lastPos = pos+1;
        }
    }
    return ret;
}

void GeminiParser::reloadCache() {
    cacheFolder = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
}

void GeminiParser::clearCache() {
    QDir dir(cacheFolder);
    dir.removeRecursively();
    dir.mkpath(cacheFolder);
}

void GeminiParser::loadPage(const QString &uri) {
    conn.fetchPage(uri);
}

void GeminiParser::parsePage(const QByteArray &content) {
    if (content.isEmpty()) { return; }
    if (_cfg->getGeneral().cacheGems) {
        QFile file(cacheFolder+"/gem.gmi");
        if (file.open(QIODevice::WriteOnly)) {
            file.write(content);
            file.close();
        } else {
            if (file.exists()) {
                file.remove();
            }
        }
    }
    QStringList _lines = findLines(content);
    if (_lines.size()==0) { return; }
    QString statusLine = _lines.takeFirst().remove(QChar::CarriageReturn);
    _code = statusLine.sliced(0,2).toInt(); statusLine.remove(0,2);
    emit status(_code,statusLine);
    emit gotPage();
    if (_code!=20) {
        if (_code<10&&_code>69) {
            _txt->clear();
            _txt->setPlainText(tr("Server responded with non-standard status code: %1.\nThat's all I know.").arg(_code));
            return;
        }
        if (_code==10||(_code>11&&_code<20)) {
            emit input();
            return;
        }
        if (_code==11) {
            emit sensitiveInput();
            return;
        }
        if (_code>20&&_code<30) {
            _txt->clear();
            _txt->setPlainText(tr("Server responded with an undefined 'success' code %1.").arg(_code));
            return;
        }
        if (_code>29&&_code<40) {
            emit redirection(content);
        }
        if (_code>39&&_code<50) {
            _txt->clear();
            QString msg;
            if (_code==40) {
                msg = tr("An unspecified condition exists on the server that is preventing the content from being served.\n");
            } else if (_code==41) {
                msg = tr("Server unavailable.\nThe server is unavailable due to overload or maintenance. (cf HTTP 503)\n");
            } else if (_code==42) {
                msg = tr("A CGI process, or similar system for generating dynamic content, died unexpectedly or timed out.\n");
            } else if (_code==43) {
                msg = tr("A proxy request failed because the server was unable to successfully complete a transaction with the remote host. (cf HTTP 502, 504).\n");
            } else if (_code==44) {
                msg = tr("The server is requesting us to slow down queries.\nYou can either wait for the page to refresh (see timer on the status bar) or choose a different site.\n");
            } else {
                msg = tr("Unspecified error condition.\nError code: %1").arg(_code);
            }
            if (!content.isEmpty()) {
                msg.append(tr("Server returned this data which might provide more context: %1").arg(content));
            } else {
                msg.append(tr("Server didn't return any data that might provide further context."));
            }
            _txt->setPlainText(msg);
            return;
        }
        if (_code>49&&_code<60) {
            _txt->clear();
            QString msg;
            if (_code==50) {
                msg = tr("General permanent failure.\n");
            } else if (_code==51) {
                msg = tr("The requested resource could not be found (you can't find things at Area 51) and no further information is available. It may exist in the future, it may not. Who knows?\n");
            } else if (_code==52) {
                msg = tr("The resource requested is no longer available and will not be available again.\n");
            } else if (_code==53) {
                msg = tr("The request was for a resource at a domain not served by the server and the server does not accept proxy requests.\n");
            } else if (_code==59) {
                msg = tr("The server was unable to parse the client's request, presumably due to a malformed request, or the request violated the contraints listed in the Request section.\n");
            } else {
                msg = tr("Non-standard permanent failure code: %1.\n").arg(_code);
            }
            if (!content.isEmpty()) {
                msg.append(tr("Server returned this data which might provide more context: %1").arg(content));
            } else {
                msg.append(tr("Server didn't return any data that might provide further context."));
            }
            _txt->setPlainText(msg);
            return;
        }
        if (_code>59&&_code<70) {
            _txt->clear();
            _txt->setPlainText(tr("Certificate error: %1.\nServer says: %2").arg(_code).arg(content.isEmpty()?tr("Nothing, no response."):content));
            return;
        }
        return;
    }
    if ((!statusLine.contains("text/gemini",Qt::CaseInsensitive)&&(!statusLine.contains("text/plain",Qt::CaseInsensitive)))) {
        emit error(tr("Incorrect meta. Expected \"gemini/text\" or \"text/plain\", got %1").arg(statusLine));
        return;
    }
    _txt->clear();
    QTextCursor crs(_txt);
    QString cnt;
    for (auto x=0;x<_lines.size();++x) {
        crs.insertBlock();
        crs.movePosition(QTextCursor::NextBlock);
        cnt.clear();
        if (_lines.at(x).startsWith("=>")) {
            crs.setCharFormat(getStyle(GeminiParser::itemLink));
            crs.setBlockFormat(getFormat(GeminiParser::itemLink));
            QStringList link = _lines.at(x).split(" ");
            cnt = "<a href=\""+link.at(1);
            if (link.size()>2) {
                cnt.append(" title=\""+link.at(2)+"\"");
            }
            cnt.append("\">");
            if (link.at(1).contains("://")) {
                cnt.append("("+link.at(1).split("://").first()+")");
            }
            if (link.size()>2) {
                for (auto y=2; y<link.size();++y) {
                    cnt.append(link.at(y)+" ");
                }
            }
            cnt.append("</a><br>");
            crs.insertHtml(cnt);
            continue;
        }
        if (_lines.at(x).startsWith("```")) {
            crs.setCharFormat(getStyle(GeminiParser::itemPreformat));
            crs.setBlockFormat(getFormat(GeminiParser::itemPreformat));
            int y = x+1;
            while ((!_lines.at(y).contains("```"))&&y<_lines.size()) {
                cnt.append(QChar::LineFeed);
                cnt.append(_lines.at(y));
                ++y;
            }
            y<_lines.size() ? x = y+1 : x = y;
            crs.insertText(cnt);
            continue;
        }
        if (_lines.at(x).startsWith("### ")) {
            cnt.append("<h3>"+_lines.at(x).sliced(3)+"</h3><br>");
            crs.setCharFormat(getStyle(GeminiParser::itemheading3));
            crs.setBlockFormat(getFormat(GeminiParser::itemheading3));
            crs.insertHtml(cnt);
            continue;
        }
        if (_lines.at(x).startsWith("## ")) {
            cnt.append("<h2>"+_lines.at(x).sliced(2)+"</h2><br>");
            crs.setCharFormat(getStyle(GeminiParser::itemheading2));
            crs.setBlockFormat(getFormat(GeminiParser::itemheading2));
            crs.insertHtml(cnt);
            continue;
        }
        if (_lines.at(x).startsWith("# ")) {
            cnt.append("<h1>"+_lines.at(x).sliced(1)+"</h1><br>");
            crs.setCharFormat(getStyle(GeminiParser::itemHeading1));
            crs.setBlockFormat(getFormat(GeminiParser::itemHeading1));
            crs.insertHtml(cnt);
            continue;
        }
        if (_lines.at(x).startsWith(">")) {
            crs.setCharFormat(getStyle(GeminiParser::itemQuote));
            crs.setBlockFormat(getFormat(GeminiParser::itemQuote));
            crs.insertText(_lines.at(x).sliced(_lines.at(x).size()>1?2:1));
            continue;
        }
        crs.setCharFormat(getStyle(GeminiParser::itemText));
        crs.setBlockFormat(getFormat(GeminiParser::itemText));
        crs.insertText(_lines.at(x)+QChar::LineFeed);
    }
}
