#include "httpclient.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QByteArray SyncHttpClient::get(QString path)
{
    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    QObject::connect(reply, &QNetworkReply::finished, [&loop]() {
        loop.exit();
    });

    loop.exec();
    auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

    if (statusCode.toInt() > 299) {
        throw new std::runtime_error(reply->errorString().toStdString());
    }

    QByteArray response = reply->readAll();
    reply->deleteLater();
    loop.deleteLater();

    return response;
}

QByteArray SyncHttpClient::post(QString path, QByteArray data)
{
    QEventLoop loop;
    QNetworkRequest request{QUrl(path)};
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = manager->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [&loop]() {
        loop.exit();
    });

    loop.exec();
    auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

    if (statusCode.toInt() > 299) {
        throw new std::runtime_error(reply->errorString().toStdString());
    }

    QByteArray response = reply->readAll();
    reply->deleteLater();
    loop.deleteLater();

    return response;
}
