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

#ifndef HISTORYCLASS_H
#define HISTORYCLASS_H

#include <QObject>
#include <QSqlTableModel>

class HistoryClass : public QObject
{
    Q_OBJECT
public:
    explicit HistoryClass(QObject *parent = nullptr);
    ~HistoryClass();
    QSqlTableModel *getModel() { return _mdl; };
    int getSize() const { return _mdl->rowCount(); };
    QStringList getUrls() const;
    int getVisits(const QString &url = QString()) const;
    QDate getLastVisit(const QString &url) const;
    QString getLastUrl() const;
    QStringList getUrlsFromDay(const QDate &day) const;

public slots:
    void add(const QString &url);
    void remove(const QString &url);
    void clear();

signals:

private:
    const QString dbname = "history";
    const QString tableName = dbname;
    const QString tableQuery = "create table if not exists "+tableName+"(idx integer primary key, url text unique, lastVisit datetime not null default current_timestamp, totalVisits integer default 0);";
    QSqlTableModel *_mdl;
};

#endif // HISTORYCLASS_H
