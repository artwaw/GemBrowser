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

#include "gembrowser.h"
#include "prefsdialog.h"
#include "./ui_gembrowser.h"
#include "gemwidget.h"

#include <QFontDatabase>
#include <QFile>

GemBrowser::GemBrowser(QWidget *parent):QMainWindow(parent), ui(new Ui::GemBrowser) {
    ui->setupUi(this);
    cfg = new ConfigFile(this);
    if (!cfg->getSetup().geo.isEmpty()) { resize(cfg->getSetup().geo); };
    if (!cfg->getSetup().pos.isNull()) { move(cfg->getSetup().pos); };
    connect(ui->address,&QLineEdit::returnPressed,this,[=](){request(); });
    connect(ui->actionPreferences,&QAction::triggered,this,[=](){
        PrefsDialog *prefs = new PrefsDialog(this,cfg);
        connect(prefs,&PrefsDialog::finished,this,[=](){
            prefs->deleteLater();
        });
        prefs->open();
    });
    connect(ui->actionQuit,&QAction::triggered,this,&GemBrowser::close);
    connect(ui->content,&QTabWidget::tabCloseRequested,this,&GemBrowser::closeTab);
    connect(ui->content,&QTabWidget::tabBarDoubleClicked,this,&GemBrowser::newTab);
    connect(ui->homeBtn,&QToolButton::clicked,this,[=](){ request(cfg->getBrowse().home); });
    _statusCode = new QLabel();
    ui->statusbar->insertPermanentWidget(0,_statusCode);
    _statusText = new QLabel();
    ui->statusbar->insertPermanentWidget(1,_statusText);
    _helper = new QLabel();
    ui->statusbar->insertPermanentWidget(2,_helper);
    ui->address->setText(cfg->getBrowse().home);
    ui->address->setFocus();
    newTab();
}

GemBrowser::~GemBrowser()
{
    delete ui;
}

void GemBrowser::newTab() {
    ui->content->setUpdatesEnabled(false);
    GemWidget *newBrowser = new GemWidget(this,cfg);
    connect(newBrowser,&GemWidget::newStatus,this,&GemBrowser::updateStatus);
    connect(newBrowser,&GemWidget::pageVisited,this,&GemBrowser::updateHistory);
    ui->content->addTab(newBrowser,cfg->getBrowse().home);
    ui->content->setUpdatesEnabled(true);
    newBrowser->getSite(cfg->getBrowse().home);
}

void GemBrowser::closeTab(const int idx) {
    if (idx>0) {
        ui->content->removeTab(idx);
    }
}

void GemBrowser::closeEvent(QCloseEvent *event) {
    cfg->setGeo(size());
    cfg->setPos(pos());
    QMainWindow::closeEvent(event);
}

void GemBrowser::updateStatus(const int code,const QString &desc) {
    if (code==-1) { return; }
    _statusCode->setText(QString::number(code));
    _statusText->setText(desc);
}

void GemBrowser::updateHistory(const QString &uri) {

}

void GemBrowser::request(const QString &uri) {
    qobject_cast<GemWidget *>(ui->content->currentWidget())->getSite(uri.isEmpty()?ui->address->text():uri);
}
