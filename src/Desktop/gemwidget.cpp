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

#include "gemwidget.h"

GemWidget::GemWidget(QWidget *parent, ConfigFile *cfg):QTextBrowser(parent) {
    if (cfg==nullptr) {
        qFatal("cfg null in GemWidget");
        return;
    }
    _cfg = cfg;
    parser = new GeminiParser(this,cfg);
    setDocument(parser->getPage());
    timer.setTimerType(Qt::CoarseTimer);
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,[=](){ ++time; emit newStatus(time,lastStatus); });
    connect(parser,&GeminiParser::gotPage,&timer,&QTimer::stop);
    connect(parser,&GeminiParser::status,this,[this](const int code, const QString &desc){
        emit newStatus(code,desc);
    });
}

void GemWidget::getSite(const QString &uri) {
    if (uri.isEmpty()) { return; }
    QString query;
    query=uri;
    if (!uri.startsWith("gemini://",Qt::CaseInsensitive)) {
        query.prepend("gemini://");
    }
    if (!uri.endsWith('/')) {
        query.append('/');
    }
    parser->loadPage(query);
    lastUri = query;
    lastStatus = tr("Fetching page...");
    startTimer();
    emit newStatus(time,lastStatus);
}

void GemWidget::gotPage() {
//    parser->parsePage(conn.lastPage());
//    setDocument(parser->getPage());
    emit pageVisited(lastUri.remove("gemini://",Qt::CaseInsensitive));
    //emit newStatus(parser->getStatus()
}
