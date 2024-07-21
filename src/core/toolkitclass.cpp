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
