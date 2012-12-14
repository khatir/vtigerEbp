#include <QCoreApplication>
#include <QDebug>
#include "httpcrm.h"
#include "operation.h"


void createOrUpdateLead(QString teleop,QString idLead,QString attributes) ;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //HttpCRM *http = new HttpCRM() ;
     //http->setUrl("http://192.168.1.14/vtigercrm/webservice.php");
    // http->startRequest();

     // SIMULATION Script easy
     QString idLead = "" ;
     QString attributes = "{\"firstname\":\"Toti\",\"lastname\":\"Turlut\",\"company\":\"Vtiger\"}" ;
     QString username = "admin" ;

     createOrUpdateLead(username,idLead,attributes);

    return a.exec();
}

/* exemple de fonction appelé par une script easy */
void createOrUpdateLead(QString username,QString idLead,QString attributes)
{

    Operation* op = new Operation();
    HttpCRM* http = new HttpCRM(username);

    op->getChallenge(http);
    op->login(http);
    op->create(http,attributes);

}
