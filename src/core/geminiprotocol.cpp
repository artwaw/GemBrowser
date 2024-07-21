#include "geminiprotocol.h"
#include "toolkitclass.h"

#include <QSslCertificate>
#include <QSslConfiguration>
#include <QStandardPaths>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

GeminiProtocol::GeminiProtocol(QObject *parent) : QObject{parent} {
    _port = 1965;
    connect(&socket,&QSslSocket::readyRead,this,&GeminiProtocol::gotPage);
    connect(&socket,&QSslSocket::errorOccurred,this,&GeminiProtocol::_error);
    connect(&socket,&QSslSocket::encrypted,this,&GeminiProtocol::verifySSL);
    socket.setPeerVerifyMode(QSslSocket::QueryPeer);
    QSslConfiguration config = socket.sslConfiguration();
    config.setProtocol(QSsl::TlsV1_2OrLater);
    socket.setSslConfiguration(config);
    QString dataPath = ToolkitClass::dataPath();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","ssl");
    db.setDatabaseName(dataPath+"data.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr,tr("Can't open data file!"),tr("Data file cannot be opened: %1. It is critical, program will terminate.").arg(db.databaseName()));
        qTerminate();
    }
    QSqlQuery query(db);
    query.exec("create table if not exists ssl(idx integer primary key,digest text, uri text, expiry datetime, port integer);");
}

GeminiProtocol::~GeminiProtocol() {
    QSqlDatabase db = QSqlDatabase::database("ssl",true);
    if (db.isOpen()) {
        db.close();
    }
}

void GeminiProtocol::setPort(const int port) {
    _port = port;
}

void GeminiProtocol::fetchPage(const QString &uri) {
    if (uri.isEmpty()) { qDebug() << "uri empty"; return; }
    QString query = uri;
    QStringList parts = query.remove("gemini://").split('/',Qt::SkipEmptyParts);
    _uri = uri;
    if (socket.state()==QSslSocket::ConnectedState||socket.state()==QSslSocket::ConnectingState) {
        socket.close();
    }
    socket.connectToHostEncrypted(parts.at(0),_port);
    socket.write(_uri.toUtf8());
}

void GeminiProtocol::gotPage() {
    _page=socket.readAll();
    emit newPage();
    emit status(socket.error());
}

void GeminiProtocol::_error() {
    emit error(socket.error());
}

void GeminiProtocol::verifySSL() {
    QSqlDatabase db = QSqlDatabase::database("ssl",true);
    QSqlQuery query(db);
    QSslCertificate cert = socket.peerCertificate();
    QString q = QString("select from ssl (digest, expiry) where uri=%1 and port=%2").arg(_uri.remove("gemini://").split('/').first(),_port);
    query.exec(q);
    if (query.size()>0) {
        while (query.next()) {
            //if (query.value(0)==cert.digest(QCryptographicHash::Sha512))&&()
            qDebug() << query.value(0).toString() << query.value(1).toString();
        }
    } else {
        q = QString("insert into ssl(digest, expiry, uri, port) values (%1,%2,%3,%4);");
        query.exec(q);
    }
}
