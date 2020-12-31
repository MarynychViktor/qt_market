#include "httpclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

void HttpClient::get(QString path, function<void(QNetworkReply*)> handler, function<void(QNetworkReply*)> onError)
{
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    QObject::connect(reply, &QNetworkReply::finished, [handler, reply, onError]() {
        auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

        if (statusCode.toInt() > 299) {
            if (onError != NULL) {
                onError(reply);
            }
        } else {
            handler(reply);
        }

        reply->deleteLater();
    });
}

void HttpClient::post(QString path, QByteArray data, function<void (QNetworkReply *)> handler, function<void (QNetworkReply *)> onError)
{
    QNetworkRequest request{QUrl(path)};
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = manager->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [handler, reply, onError]() {
        auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

        if (statusCode.toInt() > 299) {
            if (onError != NULL) {
                onError(reply);
            }
        } else {
            handler(reply);
        }

        reply->deleteLater();
    });
}
