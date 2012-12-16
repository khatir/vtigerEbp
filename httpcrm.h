#ifndef HTTPCRM_H
#define HTTPCRM_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCryptographicHash>

#include <QDebug>
#include <QT>
#include <QSettings>
#include <QEventLoop>


#include "json/reader.h"
#include "json/value.h"


class HttpCRM : public QObject
{
    Q_OBJECT
public:
    explicit HttpCRM(QObject *parent = 0);
    HttpCRM(QString username);
    QByteArray post(QByteArray data);

    void getChallenge(QByteArray data);
    void login(QByteArray data);
    void create(QByteArray data);

    QString username;
    QString hashAccess ;
    QString sessionName;
    QString userID;

    /* Enum Entity : objectTypeId utilisé par les WS pour identifier le type d'entié */
    enum Entity {
        Campaigns	=	1	,
        Vendors	=	2	,
        Faq	=	3	,
        Quotes	=	4	,
        PurchaseOrder	=	5	,
        SalesOrder	=	6	,
        Invoice	=	7	,
        PriceBooks	=	8	,
        Calendar	=	9	,
        Leads	=	10	,
        Accounts	=	11	,
        Contacts	=	12	,
        Potentials	=	13	,
        Products	=	14	,
        Documents	=	15	,
        Emails	=	16	,
        HelpDesk	=	17	,
        Events	=	18	,
        Users	=	19	,
        Groups	=	20	,
        Currency	=	21	,
        DocumentFolders	=	22	,
        CompanyDetails	=	23	,
        ServiceContracts	=	24	,
        Services	=	25	,
        PBXManager	=	26	,
        Assets	=	27	,
        ProjectMilestone	=	28	,
        ProjectTask	=	29	,
        Project	=	30
      };

signals:

public slots:

private:

    QNetworkAccessManager qnam;
    QNetworkRequest req;

};

#endif // HTTPCRM_H
