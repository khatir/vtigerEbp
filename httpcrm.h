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

signals:

public slots:

private:

    QNetworkAccessManager qnam;
    QNetworkRequest req;

};

#endif // HTTPCRM_H
