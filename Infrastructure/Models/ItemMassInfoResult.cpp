#include "ItemMassInfoResult.h"
#include "../../consts.h"

ItemMassInfoResult::ItemMassInfoResult(QString classId, QString instanceId, QString name, QString photo, QString quality,
                                       shared_ptr<ItemMassInfoResult::OrderOffers> orderOffers, shared_ptr<ItemMassInfoResult::TradeOffers> tradeOffers)
    : classId(classId), instanceId(instanceId), name(name), photo(photo), quality(quality), orderOffers(orderOffers), tradeOffers(tradeOffers)
{
}

ItemMassInfoResult::~ItemMassInfoResult()
{
}

ItemMassInfoResult::OrderOffers::OrderOffers(int best, int my, QHash<int, int> offers)
    : bestOffer(best), myOffer(my), offers(offers)
{
}

int ItemMassInfoResult::OrderOffers::getMaxOffer()
{
    int maxOffer = PRICE_NOT_SET;
    for_each(offers.begin(), offers.end(), [this, &maxOffer](const int& price) {
        if (myOffer != price || myOffer == price && offers[price] > 1) {
            if (maxOffer < price) {
                maxOffer = price;
            }
        }
    });

    return maxOffer;
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

