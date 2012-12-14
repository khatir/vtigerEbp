#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include "json/value.h"

class Entity : public QObject
{
    Q_OBJECT
public:
    explicit Entity(QObject *parent = 0);

    Json::Value attributes ;

    enum Type
     {
        Campaign,
        Account,
        Lead,
        Contact,
        Potential,
        Event
     };
    
signals:
    
public slots:
    
};

#endif // ENTITY_H
