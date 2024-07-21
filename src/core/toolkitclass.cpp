#include "toolkitclass.h"

#include <QStandardPaths>
#include <QDir>

QString ToolkitClass::dataPath() {
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir dir(dataPath);
    if (!dir.exists()) {
        dir.mkpath(dataPath);
    }
    if (!dataPath.endsWith('/')) { dataPath.append('/'); }
    return dataPath;
}

QString ToolkitClass::configPath() {
    QString cfgPath = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir dir(cfgPath);
    if (!dir.exists()) {
        dir.mkpath(cfgPath);
    }
    if (!cfgPath.endsWith('/')) { cfgPath.append('/'); }
    return cfgPath;
}
