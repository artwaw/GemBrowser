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

#ifndef GEMWIDGET_H
#define GEMWIDGET_H

#include <QObject>
#include <QTextBrowser>
#include <QTimer>

#include "geminiparser.h"
#include "configfile.h"

/*!
 * \brief Simple extension of QTextBrowser, self contained with SSL socket to fetch the data and parser to render the page.
 *
 * \sa GeminiParser
 * \sa GeminiProtocol
 */
class GemWidget : public QTextBrowser
{
    Q_OBJECT
public:
    GemWidget(QWidget *parent = nullptr, ConfigFile *cfg = nullptr);
    QString getLastCode() const { return lastCode; }
    QString getLastStatus() const { return lastStatus; }
    void setConfig(ConfigFile *cfg) { _cfg = cfg; }

public slots:
    void getSite(const QString &url);

private:
    GeminiParser *parser;
    QString lastUri;
    QString lastCode,lastStatus;
    QTimer timer;
    int time;
    ConfigFile *_cfg;

    void startTimer() { time=0; timer.start(); }

private slots:
    void gotPage();

signals:
    /*!
     * \brief newStatus Status change notification signal.
     * \param code Gemini status code
     * \param txt Textual descripion of the status code/optional return from the server.
     */
    void newStatus(const int code, const QString &txt);
    /*!
     * \brief Signal emitted when the page is successfuly fetched, for the purpose of adding to the history.
     * \param uri Full address of the page.
     */
    void pageVisited(const QString &uri);
};

#endif // GEMWIDGET_H
