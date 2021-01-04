#include "httpclient.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

QByteArray SyncHttpClient::get(const QString& path)
{
    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    timer.start(timeout);
    loop.exec();

    if (timer.isActive()) {
        timer.stop();
    } else {
        throw std::runtime_error("Timeout exception");
    }

    auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

    if (statusCode.toInt() > 299) {
        throw std::runtime_error(reply->errorString().toStdString());
    }

    QByteArray response = reply->readAll();
    reply->deleteLater();
    loop.deleteLater();

    return response;
}

QByteArray SyncHttpClient::post(const QString& path, const QByteArray& data)
{
    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    QNetworkRequest request{QUrl(path)};
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = manager->post(request, data);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    timer.start(timeout);
    loop.exec();

    if (timer.isActive()) {
        timer.stop();
    } else {
        throw std::runtime_error("Timeout exception");
    }

    auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

    if (statusCode.toInt() > 299) {
        throw std::runtime_error(reply->errorString().toStdString());
    }

    QByteArray response = reply->readAll();
    reply->deleteLater();
    loop.deleteLater();

    return response;
}
