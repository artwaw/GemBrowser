#ifndef GEMBROWSER_H
#define GEMBROWSER_H

#include <QMainWindow>
#include "geminiprotocol.h"
#include "geminiparser.h"
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
    GeminiProtocol connector;
    GeminiParser *parser;

private slots:
    void request(const QString &uri);

signals:
    void reloadSettings();
};
#endif // GEMBROWSER_H
