#include "httpclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

void HttpClient::get(QString path, function<void(QNetworkReply*)> handler)
{
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    QObject::connect(reply, &QNetworkReply::finished, [handler, reply]() {
        handler(reply);
        reply->deleteLater();
    });
}
