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


#include "json/reader.h"
#include "json/value.h"


class HttpCRM : public QObject
{
    Q_OBJECT
public:
    explicit HttpCRM(QObject *parent = 0);
    HttpCRM(QString username);
    void post(QByteArray data);

signals:
    void doLogin();

public slots:
    void httpFinished(QNetworkReply* r);

private:

    QNetworkAccessManager qnam;
    QNetworkRequest req;

    QString username;
    QString sessionName;


    QString etat ;
    QString hashAccess ;
};

#endif // HTTPCRM_H
