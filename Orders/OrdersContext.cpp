//
// Created by julia on 08.01.2021.
//

#include <Infrastructure/DI/ServiceLocator.h>
#include <Services/ProductManager.h>
#include "OrdersContext.h"

OrdersContext::OrdersContext(QObject *parent) : QObject(parent) {
}

void OrdersContext::updateOrderIds(QList<QString> orderIds) {
    auto serviceLocator = ServiceLocator::Instance();
    auto productManager = serviceLocator->GetService<ProductManager>();

    updateSnapshot(productManager->getProductsByIds(orderIds));
    emit ordersChanged();
    return;


    QList<QString> addedProductIds;
    QList<QString> removedProductIds;

    for (const auto& itemId : snapshotIds) {
        if (!orderIds.contains(itemId)) {
            removedProductIds.append(itemId);
        }
    }
    for (const auto& orderId : orderIds) {
        if (!snapshotIds.contains(orderId)) {
            addedProductIds.append(orderId);
        }
    }

    if (!removedProductIds.isEmpty() || !addedProductIds.isEmpty()) {
        QList<QString> newProductIds;

        for (const auto& itemId : snapshotIds) {
            if (!removedProductIds.contains(itemId)) {
                newProductIds.append(itemId);
            }
        }

        newProductIds.append(addedProductIds);
        updateSnapshot(productManager->getProductsByIds(orderIds));

        if (!removedProductIds.isEmpty()) {
            emit ordersRemoved(removedProductIds);
        }

        if (!addedProductIds.isEmpty()) {
            emit ordersAdded(addedProductIds);
        }
        emit ordersChanged();
    }
}

void OrdersContext::updateSnapshot(const QList<shared_ptr<Product>> &products) {
    snapshot = products;
    for (const auto& item : snapshot) {
        snapshotIds.append(item->getCombinedId());
    }
}
