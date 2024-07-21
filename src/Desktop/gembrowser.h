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

#ifndef GEMBROWSER_H
#define GEMBROWSER_H

#include <QMainWindow>
#include <QLabel>

#include "configfile.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GemBrowser;
}
QT_END_NAMESPACE

class GemBrowser : public QMainWindow
{
    Q_OBJECT

public:
    GemBrowser(QWidget *parent = nullptr);
    ~GemBrowser();

private:
    Ui::GemBrowser *ui;
    ConfigFile *cfg;
    int prevTab = -1;
    QStringList tabs;
    QLabel *_statusCode;
    QLabel *_statusText;
    QLabel *_helper;

    QString getTabName(QString &query) const { return query.remove("gemini://").split('/').first(); };

private slots:
    void newTab();
    void closeTab(const int idx);
    void tabOrderChanged() {};
    void updateStatus(const int code, const QString &desc);
    void updateHistory(const QString &uri);
    void request(const QString &uri = QString());

signals:
    void reloadSettings();

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // GEMBROWSER_H
