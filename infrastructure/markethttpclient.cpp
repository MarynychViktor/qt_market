#include "markethttpclient.h"

#include <QStringBuilder>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>

#include <infrastructure/models/traderesponse.h>

#include <infrastructure/helpers/stringhelper.h>

const QString MarketHttpClient::API_ENDPOINT  = "https://market.csgo.com/api";

void MarketHttpClient::getTrades(std::function<void(QList<TradeResponse*>)> onTrades, function<void(QNetworkReply*)> onError)
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

void MarketHttpClient::getItemInfo(QString classId, QString instanceId, std::function<void (ItemInfo *)> onResponse, function<void(QNetworkReply*)> onError)
{
        auto path = QString("%1/ItemInfo/%2_%3/ru/?key=%5").arg(API_ENDPOINT, classId, instanceId, settings->apiKey);
        httpClient->get(path, [onResponse](QNetworkReply* reply) {
            QJsonDocument document;
            auto content = reply->readAll();
            auto itemResponse = document.fromJson(content);

            QList<OfferInfo> sellOffers;
            for(auto offerRef : itemResponse["offers"].toArray()) {
                auto offer = offerRef.toObject();

                sellOffers.push_back(
                    OfferInfo(
                         offer["price"].toString().toDouble(),
                         offer["count"].toString().toInt(),
                         offer["my_count"].toString().toInt()
                   )
                );
            }

            QList<OfferInfo> buyOffers;
            for(auto offerRef : itemResponse["buy_offers"].toArray()) {
                auto offer = offerRef.toObject();
                sellOffers.push_back(
                    OfferInfo(
                         offer["o_price"].toString().toDouble(),
                         offer["c"].toString().toInt(),
                         offer["my_count"].toString().toInt()
                   )
                );
            }

            auto itemInfo = new ItemInfo(
                itemResponse["classid"].toString(),
                itemResponse["instanceid"].toString(),
                itemResponse["our_market_instanceid"].toString(),
                itemResponse["name"].toString(),
                itemResponse["market_name"].toString(),
                itemResponse["market_hash_name"].toString(),
                itemResponse["rarity"].toString(),
                itemResponse["quality"].toString(),
                itemResponse["type"].toString(),
                itemResponse["hash"].toString(),
                itemResponse["min_price"].toString().toDouble(),
                sellOffers,
                buyOffers
            );

            onResponse(itemInfo);
        }, onError);
}

void MarketHttpClient::massSetPriceById(QHash<QString, int> newPrices, std::function<void ()> onSuccess, function<void (QNetworkReply *)> onError)
{
    auto path = QString("%1/MassSetPriceById/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    QUrlQuery query;

    newPrices.keyBegin();
    std::for_each(newPrices.keyBegin(), newPrices.keyEnd(), [&query, &newPrices](QString key) {
        query.addQueryItem(QString("list[%1]").arg(key), QString(newPrices.value(key)));
    });

    QByteArray data = query.toString(QUrl::FullyEncoded).toUtf8();

    httpClient->post(path, data, [onSuccess](QNetworkReply* reply) {
            onSuccess();
        }, [onError](QNetworkReply* reply) {
            onError(reply);
        });
}
