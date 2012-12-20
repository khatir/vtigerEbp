#include "vtigerebp.h"
#include "httpcrm.h"
#include "operation.h"

//----------------------------------------------------------------------------
VTIGEREBPSHARED_EXPORT std::string __stdcall createOrUpdate(QString username, QString id, QString moduleName, QString attributes)
//std::string VTIGEREBPSHARED_EXPORT createOrUpdate(QString username, QString id, QString moduleName, QString attributes)
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
//----------------------------------------------------------------------------
VTIGEREBPSHARED_EXPORT int __stdcall one(int i){
    return i+1;
}
//----------------------------------------------------------------------------
