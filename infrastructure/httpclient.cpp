#include "httpclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

HttpClient::HttpClient()
{
    manager = new QNetworkAccessManager();
}

void HttpClient::get(QString path, HttpResponseHandler handler)
{
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));
    QObject::connect(reply, &QNetworkReply::finished, [handler, reply]() {
        handler(reply);
        reply->deleteLater();
    });
}
