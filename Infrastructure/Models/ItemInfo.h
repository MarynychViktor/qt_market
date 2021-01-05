#ifndef ITEMINFO_H
#define ITEMINFO_H

#include "OfferInfo.h"

#include <QJsonValue>
#include <QString>
#include <QList>


class ItemInfo
{
public:
    QString classId;
    QString instanceId;
    QString ourMarketInstanceId;
    QString name;
    QString marketName;
    QString marketHashName;
    QString rarity;
    QString quality;
    QString type;
    QString mtype;
    QString hash;
    int minPrice;
    QList<OfferInfo> sellOffers;
    QList<OfferInfo> buyOffers;
    int getMyTradePrice();
    int getMinTradePrice();
    int getMyBuyOffer();
    int getMaxBuyOffer();


    ItemInfo(
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
    );

    QString toString();

};

#endif // ITEMINFO_H
