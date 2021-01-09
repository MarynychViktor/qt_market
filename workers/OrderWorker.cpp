//
// Created by marinich_v on 05.01.21.
//

#include "OrderWorker.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include "../consts.h"
#include "../Exceptions/AppException.h"
#include "../Services/Logger.h"
#include "../Exceptions/NotFoundException.h"

OrderWorker::OrderWorker(QObject *parent) : Worker(parent) {
    isStopRequested = false;
}

void OrderWorker::start() {
    if (isStopRequested) {
        emit quit();
        return;
    }

    emit started();
    Logger::info("Order worker started");
    initializeServices();
    QElapsedTimer timer;

    try {
        timer.start();
        auto orders = marketClient->getOrders();

        if (orders.isEmpty()) {
            Logger::debug("No orders. Exit...");
            emit finished();
            return;
        }

        QList<QString> combinedOrderIds;

        for (const auto& order : orders) {
            if (order->isActive()) {
                combinedOrderIds.append(QString("%1_%2").arg(order->classId, order->instanceId));
                ordersMappedWithId.insert(QString("%1_%2").arg(order->classId, order->instanceId), order);
            }
        }

        if (combinedOrderIds.isEmpty()) {
            Logger::debug("No active orders. Exit...");
            emit finished();
            return;
        }

        orderedProducts = marketClient->getMassInfo(combinedOrderIds);

        for (const auto& order : orderedProducts) {
            auto product = productForOrder(order);
            auto orderOffers = order->orderOffers;

            if (orderOffers->getMaxOffer() < product->maxAllowedOrderPrice) {
                if (
                    orderOffers->myOffer < product->maxAllowedOrderPrice ||
                    orderOffers->myOffer > orderOffers->getMaxOffer() + 1
                ) {
                    int price = orderOffers->getMaxOffer() + 1;
                    marketClient->updateOrder(product->classId, product->instanceId, price);
                }
            } else if (orderOffers->myOffer != DEFAULT_ORDER_PRICE) {
                marketClient->updateOrder(product->classId, product->instanceId, DEFAULT_ORDER_PRICE);
            }
        }

        emit ordersChanged(combinedOrderIds);
    } catch (AppException& e) {
        Logger::error(e.getMessage());
    } catch (std::exception &e) {
        Logger::error(QString("----------------------Std exception fired: %1").arg(e.what()));
    }

    Logger::info(QString("Order worker finished in %1s").arg(QString::number(timer.elapsed() / 1000.0)));
    emit finished();
}

void OrderWorker::initializeServices()
{
    auto serviceLocator = ServiceLocator::Instance();
    marketClient = serviceLocator->GetService<MarketHttpClient>();
    productManager = serviceLocator->GetService<ProductManager>();
    ordersMappedWithId.clear();
}

shared_ptr<Product> OrderWorker::productForOrder(shared_ptr<ItemMassInfoResult> order)
{
    shared_ptr<Product> product;

    try {
        product = productManager->findByClassAndInstanceIds(order->classId, order->instanceId);
    } catch (NotFoundException& e) {
        product = Product::fromItemMassInfo(order);
        productManager->addProduct(product);
    }

    return product;
}


void OrderWorker::requestStop() {
    isStopRequested = true;
}