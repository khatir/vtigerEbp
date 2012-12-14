#include "operation.h"

Operation::Operation(QObject *parent) :
    QObject(parent)
{
}

/*
void Operation::getChallenge()
{
    qDebug() << " Operation::getChallenge " ;

    HttpCRM* http = new HttpCRM(username);

    QByteArray postData;
        postData.append("operation=getchallenge");
        postData.append("&username=" + username);

        qnam.post(req,postData) ;

    connect(&qnam, SIGNAL(finished(QNetworkReply *)),
            http, SLOT(httpFinished(QNetworkReply *)));
}
*/

void Operation::launch()
{

    qDebug() << " Operation::launch " ;

    QString username = "admin" ;

    QByteArray postData;
    postData.append("operation=getchallenge");
    postData.append("&username=" + username);


    HttpCRM* http = new HttpCRM(username);
    http->post(postData) ;

    emit getChallenge();
}


void Operation::login()
{
     qDebug() << " Operation::login " ;
}

void Operation::create()
{
     qDebug() << " Operation::create " ;
}
