#include "itemmassinforesult.h"

ItemMassInfoResult::ItemMassInfoResult(QString classId, QString instanceId, ItemMassInfoResult::OrderOffers *orderOffers, ItemMassInfoResult::TradeOffers *tradeOffers)
    : classId(classId), instanceId(instanceId), orderOffers(orderOffers), tradeOffers(tradeOffers)
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

int ItemMassInfoResult::TradeOffers::getMinOffer()
{

}

