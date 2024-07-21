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

#ifndef TOOLKITCLASS_H
#define TOOLKITCLASS_H

#include <QObject>

class ToolkitClass : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    static QString dataPath();
    static QString configPath();

signals:
};

#endif // TOOLKITCLASS_H
