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
