#include "gembrowser.h"
#include "prefsdialog.h"
#include "./ui_gembrowser.h"

#include <QFontDatabase>
#include <QFile>

GemBrowser::GemBrowser(QWidget *parent):QMainWindow(parent), ui(new Ui::GemBrowser) {
    ui->setupUi(this);
    cfg = new ConfigFile(this);
    parser = new GeminiParser(this,cfg);
    connect(ui->address,&QLineEdit::editingFinished,this,[=](){
        request(ui->address->text());
    });
    connect(&connector,&GeminiProtocol::newPage,this,[=](){
        parser->parsePage(connector.lastPage());
        ui->textBrowser->setDocument(parser->getPage());
    });
    connect(&connector,&GeminiProtocol::error,this,[=](int code){
        if (code!=1) { //1 = remote host closed connection. That is expected per Gemini specs.
            ui->statusbar->showMessage(connector.errorStr());
        }
    });
    connect(ui->actionPreferences,&QAction::triggered,this,[=](){
        PrefsDialog *prefs = new PrefsDialog(this,cfg);
        connect(prefs,&PrefsDialog::clearCache,parser,&GeminiParser::clearCache);
        connect(prefs,&PrefsDialog::reloadCache,parser,&GeminiParser::reloadCache);
        connect(prefs,&PrefsDialog::reloadPage,this,[=](){
            QFile file(parser->cache()+"/gem.gmi");
            if (cfg->getGeneral().cacheGems&&file.exists()&&file.open(QIODevice::ReadOnly)) {
                parser->parsePage(file.readAll());
                file.close();
                ui->textBrowser->setDocument(parser->getPage());
            } else {
                request(ui->address->text());
            }
        });
        prefs->setCacheSize(parser->cacheSize());
        connect(prefs,&PrefsDialog::finished,this,[=](){
            prefs->deleteLater();
        });
        prefs->open();
    });
    connect(ui->actionQuit,&QAction::triggered,this,&GemBrowser::close);

}

GemBrowser::~GemBrowser()
{
    delete ui;
}

void GemBrowser::request(const QString &uri) {
    if (uri.isEmpty()) { return; }
    QString query;
    query=uri;
    if (!uri.startsWith("gemini://",Qt::CaseInsensitive)) {
        query.prepend("gemini://");
    }
    if (!uri.endsWith('/')) {
        query.append('/');
    }
    connector.fetchPage(query);
}
