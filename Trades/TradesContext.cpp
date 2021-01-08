//
// Created by julia on 08.01.2021.
//

#include <Infrastructure/DI/ServiceLocator.h>
#include <Services/ProductManager.h>
#include "TradesContext.h"

TradesContext::TradesContext(QObject* parent) : QObject(parent) {}

void TradesContext::updateTradeIds(QList<QString> ids) {
    auto serviceLocator = ServiceLocator::Instance();
    auto productManager = serviceLocator->GetService<ProductManager>();
    snapshot = productManager->getProductsByIds(ids);
    emit tradesChanged();
}
