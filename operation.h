#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include "httpcrm.h"

class Operation : public QObject
{
    Q_OBJECT
public:
    explicit Operation(QObject *parent = 0);

    void getChallenge(HttpCRM* http) ;
    void login(HttpCRM* http);
    void create(HttpCRM* http, QString attributes);
    void update(HttpCRM* http, QString objectID, QString attributes);
    
signals:

public slots:
    
};

#endif // OPERATION_H
