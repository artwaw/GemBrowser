#include "historyclass.h"
#include "toolkitclass.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>

HistoryClass::HistoryClass(QObject *parent) : QObject{parent} {
    QString dataPath = ToolkitClass::dataPath();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",dbname);
    db.setDatabaseName(dataPath+"data.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr,tr("Can't open data file!"),tr("Data file cannot be opened: %1. It is critical, program will terminate.").arg(db.databaseName()));
        qTerminate();
    }
    QSqlQuery query(db);
    query.exec(tableQuery);
    query.exec("vacuum;");
    _mdl = new QSqlTableModel(this,db);
    _mdl->setTable(tableName);
    _mdl->select();
}

HistoryClass::~HistoryClass() {
    _mdl->clear();
    delete _mdl;
    auto db = QSqlDatabase::database(dbname);
    if (db.isOpen()) {
        QSqlQuery query(db);
        query.exec("vacuum;");
        db.close();
    }
}

QStringList HistoryClass::getUrls() const {
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return QStringList(); }
    }
    QSqlQuery query(db);
    query.exec("select url from history;");
    QStringList ret;
    while (query.next()) { ret.append(query.value(0).toString());}
    return ret;
}

int HistoryClass::getVisits(const QString &url) const {
    if (url.isEmpty()) { return -1; }
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return -1; }
    }
    QSqlQuery query(db);
    query.exec("select totalVisits from "+tableName+" where url='"+url+"';");
    query.next();
    return query.value(0).toInt();
}

QDate HistoryClass::getLastVisit(const QString &url) const {
    if (url.isEmpty()) { return QDate(); }
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return QDate(); }
    }
    QSqlQuery query(db);
    query.exec("select lastVisit from "+tableName+" where url='"+url+"';");
    if (query.next()) { return query.value(0).toDate(); }
    else { return QDate(); }
}

QString HistoryClass::getLastUrl() const {
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return QString(); }
    }
    QSqlQuery query(db);
    query.exec("select url from "+tableName+" order by lastVisit desc limit 1;");
    if (query.next()) { return query.value(0).toString(); }
    else { return QString(); }
}

QStringList HistoryClass::getUrlsFromDay(const QDate &day) const {
    if (!day.isValid()) { return QStringList(); }
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return QStringList(); }
    }
    QSqlQuery query(db);
    query.exec("select url from "+tableName+" where lastVisit like '"+day.toString(Qt::ISODate)+"';");
    QStringList ret;
    while (query.next()) { ret.append(query.value(0).toString()); };
    return ret;
}

void HistoryClass::add(const QString &url) {
    if (url.isEmpty()) { return; }
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return; }
    }
    QSqlQuery query(db);
    query.exec("insert into "+tableName+" (url,totalVisits,lastVisit) values('"+url+"',1,current_timestamp) on conflict (url) do update set totalVisits=totalVisits+1, lastVisit = current_timestamp;");
    _mdl->select();
}

void HistoryClass::remove(const QString &url) {
    if (url.isEmpty()) { return; }
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return; }
    }
    QSqlQuery query(db);
    query.exec("delete from "+tableName+" where url='"+url+"';");
    _mdl->select();
}

void HistoryClass::clear() {
    auto db = QSqlDatabase::database(dbname);
    if (!db.isOpen()) {
        if (!db.open()) { return; }
    }
    QSqlQuery query(db);
    _mdl->clear();
    query.exec("drop table "+tableName+";");
    query.exec(tableQuery);
    query.exec("vacuum;");
    _mdl->setTable(tableName);
    _mdl->select();
}
