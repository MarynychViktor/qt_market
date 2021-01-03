#include "httpclient.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

QByteArray SyncHttpClient::get(QString path)
{
    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(path)));

    QObject::connect(reply, &QNetworkReply::finished, [&loop]() {
        loop.exit();
    });

    QObject::connect(&timer, &QTimer::timeout, [&loop]() {
        loop.exit();
    });
    timer.start(timeout);
    loop.exec();

    if (timer.isActive()) {
        timer.stop();
    } else {
        throw new std::runtime_error("Timeout exception");
    }

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
    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    QNetworkRequest request{QUrl(path)};
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = manager->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [&loop]() {
        qDebug() << "Network reply finished";
        loop.exit();
    });
    QObject::connect(reply, &QNetworkReply::errorOccurred, [&loop]() {
        qDebug() << "Network reply error ocurred";
//        loop.exit();
    });
    timer.start(timeout);
    loop.exec();

    if (timer.isActive()) {
        timer.stop();
    } else {
        throw new std::runtime_error("Timeout exception");
    }

    auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute);

    if (statusCode.toInt() > 299) {
        throw new std::runtime_error(reply->errorString().toStdString());
    }

    QByteArray response = reply->readAll();
    reply->deleteLater();
    loop.deleteLater();

    return response;
}
