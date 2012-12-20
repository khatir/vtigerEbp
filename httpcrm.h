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
    HttpCRM(QString username,QString moduleName);
    QByteArray post(QByteArray data);

    void getChallenge(QByteArray data);
    void login(QByteArray data);
    void createOrUpdate(QByteArray data);

    QString username;
    QString AccessKey ;
    QString moduleName;
    QString hashAccess ;
    QString sessionName;
    QString userID;
    Json::Value entity;


    /* Enum Entity : objectTypeId utilisé par les WS pour identifier le type d'entié */
    enum Entity {
        Accounts = 3 ,
        Assets = 27 ,
        Calendar = 1 ,
        Campaigns = 17 ,
        Contacts = 4 ,
        Documents = 7 ,
        Emails = 8 ,
        Events = 18 ,
        Faq = 10 ,
        HelpDesk = 9 ,
        Invoice = 16 ,
        Leads = 2 ,
        ModComments = 26 ,
        PBXManager = 25 ,
        Potentials = 5 ,
        PriceBooks = 12 ,
        Products = 6 ,
        Project = 32 ,
        ProjectMilestone = 29 ,
        ProjectTask = 30 ,
        ProjectTeam = 31 ,
        PurchaseOrder = 14 ,
        Quotes = 13 ,
        SalesOrder = 15 ,
        ServiceContracts = 24 ,
        Services = 23 ,
        SMSNotifier = 28 ,
        Users = 19 ,
        Vendors = 11,
        // Les entités suivantes de sont pas des modules
        Groups = 20,
        Currency = 21,
        DocumentFolders = 22,
        CompanyDetails = 33

      };

signals:

public slots:

private:

    QNetworkAccessManager qnam;
    QNetworkRequest req;

};

#endif // HTTPCRM_H
