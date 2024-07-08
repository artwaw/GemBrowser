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
