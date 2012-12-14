#include "httpcrm.h"


HttpCRM::HttpCRM(QObject *parent) :
    QObject(parent)
{

}

HttpCRM::HttpCRM(QString username)
{
    /* Initialisation des parametres */
    this->username = username;

    QSettings settings ("C:/Users/Kenny/Desktop/ebp.ini",QSettings::IniFormat);
    QString url = settings.value("url").toString();

    req = QNetworkRequest(QUrl(url)) ;
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
}

void HttpCRM::post( QByteArray data)
{
    connect(&qnam, SIGNAL(finished(QNetworkReply *)),
         this, SLOT(httpFinished(QNetworkReply *)));

    qnam.post(req,data) ;
}

void HttpCRM::httpFinished(QNetworkReply*  r)
{
    qDebug("HttpCRM::httpFinished enter");
    QString data = (QString) r->readAll();
    qDebug() <<data ;

    //emit getChallenge();
}



/*

void HttpCRM::startRequest()
{

}


void HttpCRM::startRequest()
{
    etat = "login" ;
    qDebug("HttpCRM::startRequest");

    QByteArray postData;
        postData.append("operation=getchallenge&");
        postData.append("username=admin");

    qnam.post(req,postData) ;

    qDebug("HttpCRM::httpFinished launch1");
    connect(&qnam, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(httpFinished(QNetworkReply *)));


    qDebug("HttpCRM::httpFinished launch2");
}

void HttpCRM::httpFinished(QNetworkReply*  r)
{
    qDebug("HttpCRM::httpFinished enter");
    QString data = (QString) r->readAll();
    qDebug() <<data ;

    if( etat == "login" )
    {
        Json::Value root;   // will contains the root value after parsing.
        Json::Reader reader;

        bool parsingSuccessful = reader.parse(data.toStdString(),root) ;

       // data =( QString) root.asCString() ;
        std::string temp = root["result"]["token"].asString() ;
        qDebug() <<  QString::fromStdString(temp) ;
        QString token = QString::fromStdString(temp) +  "UgHo2O2SVVjeoGKL" ;
        qDebug() << token ;

        hashAccess = QString(QCryptographicHash::hash(token.toAscii() ,QCryptographicHash::Md5).toHex()) ;
        qDebug() << hashAccess ;


        QByteArray postData;
            postData.append("operation=login&");
            postData.append("username=admin&");
            postData.append("accessKey=" + hashAccess );

        QNetworkRequest req = QNetworkRequest(url) ;
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

        etat = "action" ;
        qnam.post(req,postData) ;

    }
    else if( etat == "action" )
    {
        Json::Value root;   // will contains the root value after parsing.
        Json::Reader reader;

        bool parsingSuccessful = reader.parse(data.toStdString(),root) ;

       // data =( QString) root.asCString() ;
        std::string temp = root["result"]["sessionName"].asString() ;
        QString sessionName =  QString::fromStdString(temp) ;
        qDebug() << sessionName ;


        QByteArray postData;
        postData.append("operation=describe&");
        postData.append("elementType=Contacts&");
            postData.append("sessionName=" + sessionName );

        QNetworkRequest req = QNetworkRequest(url) ;
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

        etat = "popo" ;
        qnam.post(req,postData) ;
    }else if( etat == "popo" )
    {

        QFile file("C:/Users/Kenny/Desktop/Qt.txt");
        // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&file);
        // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
        flux.setCodec("UTF-8");
        // Écriture des différentes lignes dans le fichier
        flux << data;
    }



}


void HttpCRM::setUrl(QString url)
{
    this->url = QUrl(url);
}
*/



