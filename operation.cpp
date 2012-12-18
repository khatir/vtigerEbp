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

void Operation::getChallenge(HttpCRM* http)
{
    qDebug() << " Operation::launch " ;

    QByteArray data;
    data.append("operation=getchallenge");
    data.append("&username=" + http->username);

    data = http->post(data) ;
    http->getChallenge(data);
}

void Operation::login(HttpCRM* http)
{
     qDebug() << " Operation::login " ;

     QByteArray data;
     data.append("operation=login");
     data.append("&username=admin");
     data.append("&accessKey=" + http->hashAccess );

     data = http->post(data) ;
     http->login(data);
}

void Operation::create(HttpCRM* http, QString attributes)
{
     qDebug() << " Operation::create " ;
     // ajout du userID
     Json::Value root;   // will contains the root value after parsing.
     Json::Reader reader;

     bool parsingSuccessful = reader.parse(attributes.toStdString(),root) ;
     root["assigned_user_id"] =  http->userID.toStdString()  ;

     QByteArray data;
     data.append("operation=create");
     data.append("&elementType=" + http->moduleName);
     data.append("&sessionName=" + http->sessionName );
     data.append("&element="+ QString::fromStdString(root.toStyledString()) );

     qDebug() << QString::fromStdString(root.toStyledString()) ;
     data = http->post(data) ;
     http->createOrUpdate(data);
}

void Operation::update(HttpCRM* http, QString objectID, QString attributes)
{
     qDebug() << " Operation::create " ;
     // ajout du userID
     Json::Value root;   // will contains the root value after parsing.
     Json::Reader reader;

     bool parsingSuccessful = reader.parse(attributes.toStdString(),root) ;
     root["assigned_user_id"] =  http->userID.toStdString()  ;
     root["id"] =  objectID.toStdString()  ;

     QByteArray data;
     data.append("operation=update");
     data.append("&sessionName=" + http->sessionName );
     data.append("&element="+ QString::fromStdString(root.toStyledString()) );

     qDebug() << QString::fromStdString(root.toStyledString()) ;
     data = http->post(data) ;
     http->createOrUpdate(data);
}
