#ifndef PREFSDIALOG_H
#define PREFSDIALOG_H

#include <QDialog>

#include "configfile.h"

namespace Ui {
class PrefsDialog;
}

class PrefsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrefsDialog(QWidget *parent = nullptr, ConfigFile *cfg = nullptr);
    ~PrefsDialog();
    void setCacheSize(const QPair<int,QString> &cacheSize);

private:
    Ui::PrefsDialog *ui;
    ConfigFile *_cfg;
    ConfigFile::generalStruct iGeneral;
    QList<ConfigFile::visualStruct> iVisual,tmp;
    ConfigFile::browsingStruct iBrowse;
    int lastStyle = -1;

    void readSettings();
    void writeSettings();
    bool verifyVisual(const int idx);

private slots:
    void verifyData();
    void clearHistory();
    void updateHistorySettings();
    void loadStyle(const int idx, const bool save = true);

public slots:
    void reloadSettings();

signals:
    void settingsChanged();
    void rebuildHistory();
    void reloadPage();
    void clearCache();
    void reloadCache();
};

#endif // PREFSDIALOG_H
