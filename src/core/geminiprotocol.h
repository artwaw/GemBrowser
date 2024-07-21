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

#ifndef GEMINIPROTOCOL_H
#define GEMINIPROTOCOL_H

#include <QObject>
#include <QSslSocket>

class GeminiProtocol : public QObject
{
    Q_OBJECT
public:
    explicit GeminiProtocol(QObject *parent = nullptr);
    ~GeminiProtocol();
    void setPort(const int port);
    QByteArray lastPage() const { return _page; };
    QString errorStr() const { return socket.errorString(); };

public slots:
    void fetchPage(const QString &uri);

signals:
    void newPage();
    void error(const int code);
    void status(const int code);

private:
    int _port;
    QSslSocket socket;
    QByteArray _page;
    QString _uri;

private slots:
    void gotPage();
    void _error();
    void verifySSL();
};

#endif // GEMINIPROTOCOL_H
