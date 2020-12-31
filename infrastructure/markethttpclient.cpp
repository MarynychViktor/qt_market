#include "markethttpclient.h"

#include <QStringBuilder>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>

#include <infrastructure/models/traderesponse.h>

const QString MarketHttpClient::API_ENDPOINT  = "https://market.csgo.com/api";

void MarketHttpClient::getTrades(std::function<void(QList<TradeResponse*>)> onTrades, QString lang)
{
    auto path = QString("%1/Trades/?key=%5").arg(API_ENDPOINT, settings->apiKey);
    httpClient->get(path, [onTrades](QNetworkReply* reply) -> void {
        QJsonDocument document;
        auto content = reply->readAll();
        auto tradesResponse = document.fromJson(content);
        QList<TradeResponse*> trades;
        qDebug() << tradesResponse;

        for(auto el : tradesResponse.array()) {
            trades.append(TradeResponse::fromJson(el));
        }

        onTrades(trades);
    });
}

