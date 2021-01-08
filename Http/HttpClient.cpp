#include "HttpClient.h"
#include "../Exceptions/TimeoutException.h"
#include "../Exceptions/MarketException.h"
#include "MarketRequestInterceptor.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <Services/Logger.h>

QByteArray SyncHttpClient::get(const QString& path)
{
    return MarketRequestInterceptor::requestWithQuota([path, this](){
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
            throw TimeoutException(QString("TimeoutException: Response for %1 not returned in %2").arg(path, QString::number(timeout)));
        }

        auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute).toInt();

        if (statusCode > 299) {
            throw MarketException(
                    QString("HttpPost request failed with code %1 , path: %2, error: %3").arg(QString::number(statusCode), path, reply->errorString()),
                    statusCode
            );
        }

        QByteArray response = reply->readAll();
        reply->deleteLater();
        loop.deleteLater();

        return response;
    });
}

QByteArray SyncHttpClient::post(const QString& path, const QByteArray& data)
{
    return MarketRequestInterceptor::requestWithQuota([path, data, this](){
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
            throw TimeoutException(QString("TimeoutException: Response for %1 not returned in %2").arg(path, QString::number(timeout)));
        }

        auto statusCode = reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute).toInt();

        if (statusCode > 299) {
            throw MarketException(
                    QString("HttpPost request failed with code %1 , path: %2, error: %3").arg(QString::number(statusCode), path, reply->errorString()),
                    statusCode
            );
        }

        QByteArray response = reply->readAll();
        reply->deleteLater();
        loop.deleteLater();

        return response;
    });
}

QByteArray SyncHttpClient::request(const function<QByteArray()>& handler) {
    int retryCount = 0;

    while(true) {
        try {
            auto response = handler();
            if (retryCount > 0) {
                Logger::debug(QString("Retry succeed on %1 retry attempt").arg(QString::number(retryCount + 1)));
            } else {
                Logger::debug(QString("Request succeed immediately"));
            }
            return response;
        } catch (MarketException& e) {
            if ((e.statusCode == 429 || e.statusCode == 430) && retryCount <=5) {
                retryCount++;
                Logger::debug(QString("Retrying %1 of 5").arg(QString::number(retryCount)));
            } else {
                Logger::debug(QString("Throwing eeeeeee"));
                throw e;
            }
        }
    }
}

