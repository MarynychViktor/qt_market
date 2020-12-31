#ifndef ITEMINFO_H
#define ITEMINFO_H

#include "offerinfo.h"

#include <QJsonValue>
#include <QString>



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
    double minPrice;
    QList<OfferInfo> sellOffers;
    QList<OfferInfo> buyOffers;
    double getMyTradePrice();
    double getMinTradePrice();
    double getMyBuyOffer();
    double getMaxBuyOffer();

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
        double minPrice,
        QList<OfferInfo> sellOffers,
        QList<OfferInfo> buyOffers
    );

    QString toString();

};

#endif // ITEMINFO_H
