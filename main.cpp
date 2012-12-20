//#include <QCoreApplication>
//#include <QDebug>
#include "httpcrm.h"
#include "operation.h"



__declspec(dllexport) extern "C" std::string createOrUpdate(QString username, QString id, QString moduleName, QString attributes) ; //

//----------------------------------------------------------------------------------
/*
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
/*
     // SIMULATION Script easy
    QString teleop = "kenny" ;
    QString IdCampagne = "3391";

    QString idAccount = "3x3387";
    QString idContact = "4x3401"; //10x133" ; //Lead
    QString idAffaire = "5x3393";
    QString idEvent = "";

    //Compte
    QString attAccount = "{\"accountname\":\"BigBang Boom\", \"cf_632\":\"ebp_itool\", \"website\":\"www.universal.fr\", \"phone\":\"0470582858\"}" ;
    idAccount = createOrUpdate(teleop, idAccount, "Accounts", attAccount);

    //Contact
    QString attContact = "{\"salutation\":\"Mr.\", \"firstname\":\"Big\",\"lastname\":\"Bang\",\"leadsource\":\"Cold Call\",\"account_id\":\""+idAccount+"\"}" ;
    idContact = createOrUpdate(teleop, idContact, "Contacts", attContact);

    //Affaire
    //\"campaignid\":"+IdCampagne+", ne marche pas probleme access denied meme en mettant admin
    QString attAffaire = "{\"potentialname\":\"La super extra bonne affaire\", \"related_to\":\""+idAccount+"\", \"closingdate\":\"2012-12-23\", \"sales_stage\":\"Value Proposition\", \"amount\":\"75000.00\"}";//
    idAffaire = createOrUpdate(teleop, idAffaire, "Potentials", attAffaire);

    //Events
    QString attEvents="{\"contact_id\":\""+idContact+"\", \"activitytype\":\"Call\", \"subject\":\"Appeler le pere noel\", \"description\":\"pour lui rappeler d'être à l'heure\", \"eventstatus\":\"Planned\", \"priority\":\"High\",\"time_start\":\"15:35\", \"time_end\":\"15:45\", \"duration_hours\":\"1\", \"date_start\":\"2012-12-24\", \"due_date\":\"2013-01-03\" }";
    idEvent = createOrUpdate(teleop, idEvent, "Events", attEvents);
/
    return a.exec();
}
*/
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

/* exemple de fonction appelé par une script easy */
std::string createOrUpdate(QString username, QString id, QString moduleName, QString attributes)
{
    Operation* op = new Operation();
    HttpCRM* http = new HttpCRM(username, moduleName);

    op->getChallenge(http);
    op->login(http);
    if( id == "")
        op->create(http,attributes);
    else
        op->update(http,id,attributes);

    QString retValue = QString::fromStdString(http->entity["id"].asString());

    qDebug() << retValue;

    return retValue.toStdString();
}
//----------------------------------------------------------------------------------

