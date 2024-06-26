#include "MarketHttpClient.h"
#include "../Exceptions/MarketException.h"
#include "../Services/Logger.h"

#include <QStringBuilder>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>
#include <cmath>


const QString MarketHttpClient::API_ENDPOINT  = "api url";

QList<shared_ptr<TradeResponse>> MarketHttpClient::getTrades()
{
    auto path = QString("%1/Trades/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    auto content = httpClient->get(path);
    auto tradesResponse = QJsonDocument::fromJson(content);

    QList<shared_ptr<TradeResponse>> trades;

    for(auto el : tradesResponse.array()) {
        trades.append(TradeResponse::fromJson(el));
    }

    return trades;
}

QList<shared_ptr<ItemMassInfoResult>> MarketHttpClient::getMassInfo(const QList<QString>& combinedIds)
{
    if (combinedIds.isEmpty()) {
        throw std::runtime_error("Please provide list of product combined ids");
    }

    auto endpointPath = QString("%1/MassInfo/1/1/0/2/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    QString listIds;

    for(const QString& combinedId : combinedIds) {
        if (listIds.length() == 0) {
            listIds = combinedId;
        } else {
            listIds += QString(",") + combinedId;
        }
    }
    listIds = QString("list=%1").arg(listIds);

    QByteArray rawResponse =  httpClient->post(endpointPath, listIds.toUtf8());
    QList<shared_ptr<ItemMassInfoResult>> massInfoResultList;

    auto massInfoDocument = QJsonDocument::fromJson(rawResponse);

    if (!massInfoDocument["success"].toBool()) {
        throw MarketException("Get mass info failed");
    }

    for (auto massInfoItemDocument : massInfoDocument["results"].toArray()) {
        auto massInfoItemObject = massInfoItemDocument.toObject();
        auto massInfoItemAdditionalObject = massInfoItemObject["info"].toObject();

        QHash<int, int> orderOffersHash;
        auto orderBuyOffersObject = massInfoItemObject["buy_offers"].toObject();

        for (auto orderBuyOffer : orderBuyOffersObject["offers"].toArray()) {
            auto orderBuyOfferArray = orderBuyOffer.toArray();
            orderOffersHash.insert(orderBuyOfferArray.at(0).toInt(), orderBuyOfferArray.at(1).toInt());
        }

        auto orderOffers = make_shared<ItemMassInfoResult::OrderOffers>(
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
                myTradeOffers.append(myTradeOffer.toInt());
            }
        }

        auto tradeOffers = make_shared<ItemMassInfoResult::TradeOffers>(
        tradeOffersObject["best_offer"].toInt(),
            myTradeOffers,
            tradeOffersHash
        );

        massInfoResultList.append(make_shared<ItemMassInfoResult>(ItemMassInfoResult(
                massInfoItemObject["classid"].toString(),
                massInfoItemObject["instanceid"].toString(),
                massInfoItemAdditionalObject["name"].toString(),
                massInfoItemAdditionalObject["image"].toString(),
                massInfoItemAdditionalObject["quality"].toString(),
                orderOffers,
                tradeOffers
        )));
    }

    return massInfoResultList;
}

shared_ptr<ItemInfo> MarketHttpClient::getItemInfo(const QString& classId, const QString& instanceId)
{
        auto path = QString("%1/ItemInfo/%2_%3/ru/?key=%5").arg(API_ENDPOINT, classId, instanceId, settings->apiKey);
        auto content = httpClient->get(path);
        auto itemResponse = QJsonDocument::fromJson(content);

        QList<OfferInfo> sellOffers;
        for (auto offerRef : itemResponse["offers"].toArray()) {
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
            buyOffers.push_back(
                OfferInfo(
                     (int)round(offer["o_price"].toString().toDouble() * 100),
                     offer["c"].toString().toInt(),
                     offer["my_count"].toString().toInt()
               )
            );
        }

        return make_shared<ItemInfo>(
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

    std::for_each(newPrices.keyBegin(), newPrices.keyEnd(), [&query, &newPrices](const QString& key) {
        query.addQueryItem(QString("list[%1]").arg(key), QString::number(newPrices[key]));
    });

    httpClient->post(path, query.toString().toUtf8());
}

QList<shared_ptr<OrderResponse>> MarketHttpClient::getOrders()
{
    auto path = QString("%1/GetOrders/1/?key=%2").arg(API_ENDPOINT, settings->apiKey);
    auto content = httpClient->get(path);
    auto ordersResponse = QJsonDocument::fromJson(content);

    if (!ordersResponse["success"].toBool()) {
        throw MarketException("Get orders failed");
    }

    QList<shared_ptr<OrderResponse>> orders;

    for (auto el : ordersResponse["Orders"].toArray()) {
        orders.append(OrderResponse::fromJson(el));
    }

    return orders;
}

void MarketHttpClient::updateOrder(QString classId, QString instanceId, int price)
{
    auto path = QString("%1/UpdateOrder/%2/%3/%4/?key=%5").arg(API_ENDPOINT, classId, instanceId, QString::number(price), settings->apiKey);
    auto content = httpClient->post(path, QByteArray());
}