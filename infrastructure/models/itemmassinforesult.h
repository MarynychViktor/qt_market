#ifndef ITEMMASSINFORESULT_H
#define ITEMMASSINFORESULT_H

#include <QString>
#include <QHash>


class ItemMassInfoResult
{
public:
    class OrderOffers {
    public:
        OrderOffers(int best, int my, QHash<int, int> offers);
        int bestOffer;
        int myOffer;
        QHash<int, int> offers;

        int getMaxOffer();
    };

    class TradeOffers {
    public:
        TradeOffers(int best, QList<int> my, QHash<int, int> offers);
        int bestOffer;
        QList<int> myOffers;
        QHash<int, int> offers;

        int getMinOffer();
    };

    ItemMassInfoResult(QString classId, QString instanceId, ItemMassInfoResult::OrderOffers* orderOffers, ItemMassInfoResult::TradeOffers* tradeOffers);
    ~ItemMassInfoResult();

    QString classId;
    QString instanceId;


    OrderOffers* orderOffers;
    TradeOffers* tradeOffers;
};

#endif // ITEMMASSINFORESULT_H
