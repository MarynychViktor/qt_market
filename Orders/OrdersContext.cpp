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
    snapshot = productManager->getProductsByIds(orderIds);
    emit ordersChanged();
}
