#include "UpdateTradePricesJob.h"


#include "../consts.h"
#include "../Models/Product.h"
#include "../Infrastructure/Models/TradeResponse.h"

UpdateTradePricesJob::UpdateTradePricesJob(shared_ptr<MarketHttpClient> client,
                                           shared_ptr<ProductRepository> repository) : marketClient(client), repository(repository) {

}

UpdateTradePricesJob::~UpdateTradePricesJob()
{
}

void UpdateTradePricesJob::run()
{
   QList<shared_ptr<TradeResponse>> trades = marketClient->getTrades();

   QList<QString> combinedTradeIds;
   QMap<QString, shared_ptr<TradeResponse>> tradesMap;

   for (const auto& trade : trades) {
       if (trade->isOnSale()) {
           combinedTradeIds.append(QString("%1_%2").arg(trade->classId, trade->instanceId));
           tradesMap.insert(QString("%1_%2").arg(trade->classId, trade->instanceId), trade);
       }
   }

   auto tradesMassInfo = marketClient->getMassInfo(combinedTradeIds);

   QHash<QString, int> newPrices;

   for(auto tradeProductInfo : tradesMassInfo) {
       auto product = Product::fromItemMassInfo(tradeProductInfo);

       auto localProduct = repository->findByClassAndInstanceIds(product->classId, product->instanceId);
       if (localProduct == NULL) {
           repository->addProduct(product);
       } else {
           product = localProduct;
       }

       auto tradeOffers = tradeProductInfo->tradeOffers;

       // Check if there other offers except mine
       if (tradeOffers->getMinNotMyOffer() != PRICE_NOT_SET) {
           // Check if min foreign trade offer on market bigger than min trade price allowed for this product
           if (tradeOffers->getMinNotMyOffer() > product->minAllowedTradePrice) {
               if (tradeOffers->getMyMinOffer() > tradeOffers->getMinNotMyOffer() ||
                   tradeOffers->getMyMinOffer() < tradeOffers->getMinNotMyOffer() - 1) {
                   auto trade = tradesMap[QString("%1_%2").arg(tradeProductInfo->classId, tradeProductInfo->instanceId)];
                   newPrices.insert(trade->uiid, tradeOffers->getMinNotMyOffer() - 1);
               }
           } else if(tradeOffers->getMyMinOffer() != DEFAULT_TRADE_PRICE) {
               auto trade = tradesMap[QString("%1_%2").arg(tradeProductInfo->classId, tradeProductInfo->instanceId)];
               newPrices.insert(trade->uiid, DEFAULT_TRADE_PRICE);
           }
       } else {
           auto trade = tradesMap[QString("%1_%2").arg(tradeProductInfo->classId, tradeProductInfo->instanceId)];
           newPrices.insert(trade->uiid, product->minAllowedTradePrice * 2);
       }

   }

   if (!newPrices.isEmpty()) {
       marketClient->massSetPriceById(newPrices);
   }
}

