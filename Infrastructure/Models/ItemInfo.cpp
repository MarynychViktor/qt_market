#include "ItemInfo.h"
#include <QString>
#include <utility>


int ItemInfo::getMyTradePrice()
{
    int myTradePrice = 0;

    for(auto sellOffer : sellOffers) {
        if (sellOffer.myCount > 0) {
            if (myTradePrice == -1) {
                myTradePrice = sellOffer.price;
            } else {
                myTradePrice = sellOffer.price > myTradePrice ? myTradePrice : sellOffer.price;
            }
        }
    }

    return myTradePrice;
//    get { return Offers.Where(o => o.MyCount > 0).DefaultIfEmpty().Min(o => (long?) o?.Price); }
}

ItemInfo::ItemInfo(
    QString classId,
    QString instanceId,
    QString ourMarketInstanceId,
    QString name,
    QString marketName,
    QString marketHashName,
    QString rarity,
    QString quality,
    QString type,
    QString hash,
    int minPrice,
    QList<OfferInfo> sellOffers,
    QList<OfferInfo> buyOffers
) {
    this->classId = std::move(classId);
    this->instanceId = std::move(instanceId);
    this->name = std::move(name);
    this->marketName = std::move(marketName);
    this->ourMarketInstanceId = std::move(ourMarketInstanceId);
    this->marketHashName = std::move(marketHashName);
    this->rarity = std::move(rarity);
    this->quality = std::move(quality);
    this->type = std::move(type);
    this->hash = std::move(hash);
    this->minPrice = minPrice;
    this->sellOffers = std::move(sellOffers);
    this->buyOffers = std::move(buyOffers);
}

QString ItemInfo::toString()
{
    auto baseItem = QString("ClassId: %1\n InstanceId: %2\n Name: %3\n Market Name: %4\n Our market instanceId: %5\n Market hash name %6\n Rarity: %7\n Quality: %8\n Type: %9\n Hash: %10\n Min Price: %11").arg(
                classId,
                instanceId,
                name,
                marketName,
                ourMarketInstanceId,
                marketHashName,
                rarity,
                quality,
                type,
                hash,
                QString::number(minPrice)
            );
    auto sellOfferStr = QString("\n\tSell offers:");
    if (sellOffers.empty()) {
        sellOfferStr += "EMPTY";
    } else {
        for(auto sellOffer : sellOffers) {
            sellOfferStr += QString("\n\t\t") + sellOffer.toString();
        }
    }

    auto buyOfferStr = QString("\n\tBuy offers:");
    if (buyOffers.empty()) {
        buyOfferStr += "EMPTY";
    } else {
        for(auto buyOffer : buyOffers) {
            buyOfferStr += QString("\t\t") + buyOffer.toString();
        }
    }

    return baseItem + sellOfferStr + buyOfferStr;
}
