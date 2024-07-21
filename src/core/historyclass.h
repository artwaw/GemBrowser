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
