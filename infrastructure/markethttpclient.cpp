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

QList<TradeResponse*> MarketHttpClient::getTrades()
{
    auto path = QString("%1/Trades/?key=%5").arg(API_ENDPOINT, settings->apiKey);
    auto content = httpClient->get(path);

    QJsonDocument document;
    auto tradesResponse = document.fromJson(content);
    QList<TradeResponse*> trades;

    for(auto el : tradesResponse.array()) {
        trades.append(TradeResponse::fromJson(el));
    }

    return trades;
}

QList<ItemMassInfoResult *> MarketHttpClient::getMassInfo(QList<QString> combinedIds)
{
    auto endpointPath = QString("%1/MassInfo/1/1/0/1/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    QString listIds;

    for(auto combinedId : combinedIds) {
        if (listIds.length() == 0) {
            listIds = combinedId;
        } else {
            listIds += QString(",") + combinedId;
        }
    }
    listIds = QString("list=%1").arg(listIds);

    QByteArray rawResponse =  httpClient->post(endpointPath, listIds.toUtf8());
    QList<ItemMassInfoResult*> massInfoResultList;
    QJsonDocument document;
    auto massInfoDocument = document.fromJson(rawResponse);

    if(!massInfoDocument["success"].toBool()) {
        throw new std::runtime_error("Response returned with non success code");
    }

    for(auto massInfoItemDocument : massInfoDocument["results"].toArray()) {
        auto massInfoItemObject = massInfoItemDocument.toObject();

        QHash<int, int> orderOffersHash;
        auto orderBuyOffersObject = massInfoItemObject["buy_offers"].toObject();

        for (auto orderBuyOffer : orderBuyOffersObject["offers"].toArray()) {
            auto orderBuyOfferArray = orderBuyOffer.toArray();
            orderOffersHash.insert(orderBuyOfferArray.at(0).toInt(), orderBuyOfferArray.at(1).toInt());
        }

        auto orderOffers = new ItemMassInfoResult::OrderOffers(
            orderBuyOffersObject["best_offer"].toInt(),
            orderBuyOffersObject["my_offer"].toInt(),
            orderOffersHash
        );

        QHash<int, int> tradeOffersHash;
        QList<int> myTradeOffers;

        auto tradeOffersObject = massInfoItemObject["sell_offers"].toObject();

        for (auto tradeOffer : tradeOffersObject["offers"].toArray()) {
            auto tradeOfferArray = tradeOffer.toArray();
            tradeOffersHash.insert(tradeOfferArray.at(0).toInt(), tradeOfferArray.at(1).toInt());
        }

        if (tradeOffersObject["my_offers"].isArray()) {
            for (auto myTradeOffer : tradeOffersObject["my_offers"].toArray()) {
                myTradeOffers.append(myTradeOffer.toBool());
            }
        }

        auto tradeOffers = new ItemMassInfoResult::TradeOffers(
            tradeOffersObject["best_offer"].toInt(),
            myTradeOffers,
            tradeOffersHash
        );

        massInfoResultList.append(new ItemMassInfoResult(
            massInfoItemObject["classid"].toString(),
            massInfoItemObject["instanceid"].toString(),
            orderOffers,
            tradeOffers
         ));
    }

    return massInfoResultList;
}

ItemInfo * MarketHttpClient::getItemInfo(QString classId, QString instanceId)
{
        auto path = QString("%1/ItemInfo/%2_%3/ru/?key=%5").arg(API_ENDPOINT, classId, instanceId, settings->apiKey);
        auto content = httpClient->get(path);
        QJsonDocument document;
        auto itemResponse = document.fromJson(content);

        QList<OfferInfo> sellOffers;
        for(auto offerRef : itemResponse["offers"].toArray()) {
            auto offer = offerRef.toObject();

            sellOffers.push_back(
               OfferInfo(
                  (int)round(offer["price"].toString().toDouble() * 100),
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
                     (int)round(offer["o_price"].toString().toDouble() * 100),
                     offer["c"].toString().toInt(),
                     offer["my_count"].toString().toInt()
               )
            );
        }

        return new ItemInfo(
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
            (int)round(itemResponse["min_price"].toString().toDouble()),
            sellOffers,
            buyOffers
        );
}

void MarketHttpClient::massSetPriceById(QHash<QString, int> newPrices)
{
    auto path = QString("%1/MassSetPriceById/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    QUrlQuery query;

    newPrices.keyBegin();
    std::for_each(newPrices.keyBegin(), newPrices.keyEnd(), [&query, &newPrices](QString key) {
        query.addQueryItem(QString("list[%1]").arg(key), QString(newPrices.value(key)));
    });

    QByteArray data = query.toString(QUrl::FullyEncoded).toUtf8();

    httpClient->post(path, data);
}
