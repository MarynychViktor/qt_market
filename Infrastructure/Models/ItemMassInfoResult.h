#ifndef ITEMMASSINFORESULT_H
#define ITEMMASSINFORESULT_H

#include <QString>
#include <QHash>
#include <memory>

using namespace std;

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

        int getMinNotMyOffer();
        int getMyMinOffer();
    };

    ItemMassInfoResult(
            QString classId,
            QString instanceId,
            QString name,
            QString photo,
            QString quality,
            shared_ptr<ItemMassInfoResult::OrderOffers> orderOffers,
            shared_ptr<ItemMassInfoResult::TradeOffers> tradeOffers
        );
    ~ItemMassInfoResult();

    QString classId;
    QString instanceId;
    QString name;
    QString photo;
    QString quality;
    shared_ptr<OrderOffers> orderOffers;
    shared_ptr<TradeOffers> tradeOffers;
};

#endif // ITEMMASSINFORESULT_H
