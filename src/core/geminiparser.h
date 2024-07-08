#ifndef GEMINIPARSER_H
#define GEMINIPARSER_H

#include <QObject>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextBlockFormat>

#include "configfile.h"

class GeminiParser : public QObject
{
    Q_OBJECT
public:
    explicit GeminiParser(QObject *parent = nullptr,ConfigFile *cfg = nullptr);
    ~GeminiParser();
    QTextDocument* getPage() const;
    int getStatus() const { return _code; };
    QTextCharFormat getStyle(const int item) const;
    QTextBlockFormat getFormat(const int item) const;
    QString cache() const { return cacheFolder; }
    QPair<int,QString> cacheSize() const;

    enum ItemType {
        itemText = 0,
        itemLink = 1,
        itemQuote = 2,
        itemHeading1 = 3,
        itemheading2 = 4,
        itemheading3 = 5,
        itemPreformat = 6,
        itemList = 7
    };

public slots:
    void parsePage(const QByteArray &content);
    void reloadCache();
    void clearCache();

signals:
    void error(const QString &reason);
    void sensitiveInput();
    void input();
    void redirection(const QString &target);

private:
    QTextDocument* _txt;
    ConfigFile *_cfg;
    int _code = -1;
    QTextCharFormat _defCharFormat;
    QTextBlockFormat _defBlockFormat;
    QStringList findLines(const QString &text) const;
    QString cacheFolder;
    const QMap<int,QString> units = {
        {0,"Bytes"},
        {1,"kB"},
        {2,"MB"},
        {3,"GB"},//I sincerily doubt we'll get here but...
        {4,"TB"}
    };
};

#endif // GEMINIPARSER_H
