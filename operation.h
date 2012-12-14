#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include "httpcrm.h"

class Operation : public QObject
{
    Q_OBJECT
public:
    explicit Operation(QObject *parent = 0);


    void launch() ;

    
signals:
    void getChallenge() ;

public slots:
    void login();
    void create();
    
};

#endif // OPERATION_H
