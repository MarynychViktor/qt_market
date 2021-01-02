#include "itemmassinforesult.h"
#include "consts.h"

ItemMassInfoResult::ItemMassInfoResult(QString classId, QString instanceId, QString name, QString photo, QString quality, ItemMassInfoResult::OrderOffers *orderOffers, ItemMassInfoResult::TradeOffers *tradeOffers)
    : classId(classId), instanceId(instanceId), name(name), photo(photo), quality(quality), orderOffers(orderOffers), tradeOffers(tradeOffers)
{
}

ItemMassInfoResult::~ItemMassInfoResult()
{
    delete orderOffers;
    delete tradeOffers;
}

ItemMassInfoResult::OrderOffers::OrderOffers(int best, int my, QHash<int, int> offers)
    : bestOffer(best), myOffer(my), offers(offers)
{
}

int ItemMassInfoResult::OrderOffers::getMaxOffer()
{

}

ItemMassInfoResult::TradeOffers::TradeOffers(int best, QList<int> my, QHash<int, int> offers)
    : bestOffer(best), myOffers(my), offers(offers)
{
}

int ItemMassInfoResult::TradeOffers::getMinNotMyOffer()
{
    int minOffer = PRICE_NOT_SET;

    std::for_each(offers.keyBegin(), offers.keyEnd(), [this, &minOffer](int price){
        if (!myOffers.contains(price)) {
            if (minOffer == PRICE_NOT_SET || minOffer > price ) {
                minOffer = price;
            }
        }
    });

    return minOffer;
}

int ItemMassInfoResult::TradeOffers::getMyMinOffer()
{
    int minOffer = PRICE_NOT_SET;

    for(auto myOffer : myOffers) {
        if (minOffer == PRICE_NOT_SET || minOffer > myOffer) {
            minOffer = myOffer;
        }
    }

    return minOffer;
}

