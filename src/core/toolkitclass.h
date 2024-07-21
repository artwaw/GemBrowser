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
