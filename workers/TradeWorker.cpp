//
// Created by marinich_v on 04.01.21.
//

#include "TradeWorker.h"
#include "../consts.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include "../Services/Logger.h"
#include "../Exceptions/TimeoutException.h"
#include "../Exceptions/MarketException.h"
#include <QDebug>
#include <memory>
#include <QElapsedTimer>

void TradeWorker::start() {
    emit started();
    Logger::info("Trade worker started");
    prepareServices();
    QElapsedTimer timer;

    try {
        timer.start();
        initializeTrades();

        if (trades.isEmpty()) {
            emit finished();
            return;
        }

        QHash<QString, int> newPrices;

        for(const auto& tradeInfo : trades) {
            auto product = productForTrade(tradeInfo);
            auto tradeOffers = tradeInfo->tradeOffers;
            auto trade = tradesMappedWithId[QString("%1_%2").arg(tradeInfo->classId, tradeInfo->instanceId)];

            // Check if there other offers except mine
            if (tradeOffers->getMinNotMyOffer() != PRICE_NOT_SET) {
                // Check if min foreign trade offer on market bigger than min trade price allowed for this product
                if (tradeOffers->getMinNotMyOffer() > product->minAllowedTradePrice) {
                    if (tradeOffers->getMyMinOffer() > tradeOffers->getMinNotMyOffer() ||
                        tradeOffers->getMyMinOffer() < tradeOffers->getMinNotMyOffer() - 1) {
                        newPrices.insert(trade->uiid, tradeOffers->getMinNotMyOffer() - 1);
                    }
                } else if(tradeOffers->getMyMinOffer() != DEFAULT_TRADE_PRICE) {
                    newPrices.insert(trade->uiid, DEFAULT_TRADE_PRICE);
                }
            } else {
                newPrices.insert(trade->uiid, product->minAllowedTradePrice * 2);
            }

        }

        if (!newPrices.isEmpty()) {
            marketClient->massSetPriceById(newPrices);
        }
    }  catch (TimeoutException& e) {
        Logger::error(e.getMessage());
    } catch (MarketException& e) {
        Logger::error(e.getMessage());
    }  catch (...) {
        Logger::error("Something went wrong");
        emit error(QString("Trade worker start failed"));
    }

    Logger::info(QString("Trade worker finished in %1s").arg(QString::number(timer.elapsed() / 1000.0)));
    emit finished();
}

TradeWorker::TradeWorker(QObject *parent)
    : Worker(parent)
{
}

void TradeWorker::initializeTrades()
{
    QList<shared_ptr<TradeResponse>> tradesResponse = marketClient->getTrades();
    QList<QString> combinedTradeIds;

    for (const auto& trade : tradesResponse) {
        if (trade->isOnSale()) {
            combinedTradeIds.append(QString("%1_%2").arg(trade->classId, trade->instanceId));
            tradesMappedWithId.insert(QString("%1_%2").arg(trade->classId, trade->instanceId), trade);
        }
    }

    trades = marketClient->getMassInfo(combinedTradeIds);
}

shared_ptr<Product> TradeWorker::productForTrade(shared_ptr<ItemMassInfoResult> trade)
{
    auto product = productManager->findByClassAndInstanceIds(trade->classId, trade->instanceId);

    if (product == nullptr) {
        product = Product::fromItemMassInfo(trade);
        productManager->addProduct(product);
    }

    return product;
}

void TradeWorker::prepareServices()
{
    auto serviceLocator = ServiceLocator::Instance();
    marketClient = serviceLocator->GetService<MarketHttpClient>();
    productManager = serviceLocator->GetService<ProductManager>();
    tradesMappedWithId.clear();
}


