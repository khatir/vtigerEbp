#include <QCoreApplication>
#include <QDebug>
#include "httpcrm.h"
#include "operation.h"


void createOrUpdate(QString teleop,QString id,QString moduleName,QString attributes) ;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //HttpCRM *http = new HttpCRM() ;
     //http->setUrl("http://192.168.1.14/vtigercrm/webservice.php");
    // http->startRequest();

     // SIMULATION Script easy
     QString idLead = "10x133" ;
     QString attributes = "{\"firstname\":\"Tuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\",\"lastname\":\"Turlut\",\"company\":\"Vtiger\"}" ;
     QString username = "admin" ;

     createOrUpdate(username,idLead,"Leads",attributes);

    return a.exec();
}

/* exemple de fonction appelé par une script easy */
void createOrUpdate(QString username,QString id,QString moduleName, QString attributes)
{

    Operation* op = new Operation();
    HttpCRM* http = new HttpCRM(username,moduleName);

    op->getChallenge(http);
    op->login(http);
    if( id == "")
        op->create(http,attributes);
    else
        op->update(http,id,attributes);

    qDebug() << QString::fromStdString(http->entity["id"].asString())  ;

}
