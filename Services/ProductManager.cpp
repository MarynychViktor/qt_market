//
// Created by marinich_v on 04.01.21.
//

#include "ProductManager.h"
#include "../Exceptions/NotFoundException.h"

ProductManager::ProductManager(shared_ptr<ProductRepository> repository)
    : mRepository(repository)
{
    mProducts = repository->getProducts();
    isInitialized = true;
}

QList<shared_ptr<Product>> ProductManager::getProducts() {
    return this->mProducts;
}

shared_ptr<Product> ProductManager::findByClassAndInstanceIds(QString classId, QString instanceId) {
    shared_ptr<Product> product;
    for(const auto& mProduct : mProducts) {
        if (mProduct->classId == classId && mProduct->instanceId == instanceId) {
            product = mProduct;
        }
    }

    if (product == nullptr) {
        throw NotFoundException(QString("Product with class id: %1 and instance id %2 not found").arg(classId, instanceId));
    }

    return product;
}

void ProductManager::addProduct(shared_ptr<Product> product) {
    try {
        findByClassAndInstanceIds(product->classId, product->instanceId);
        return;
    } catch (NotFoundException& e) {
    }

    mRepository->addProduct(product);
    mProducts.append(product);
}

void ProductManager::updateMaxAllowedOrderPrice(shared_ptr<Product> product, int newPrice) {
    auto mProduct = findByClassAndInstanceIds(product->classId, product->instanceId);
    mRepository->updateMaxAllowedOrderPrice(product, newPrice);
    mProduct->maxAllowedOrderPrice = newPrice;
}

void ProductManager::updateMinAllowedTradePrice(shared_ptr<Product> product, int newPrice) {
    auto mProduct = findByClassAndInstanceIds(product->classId, product->instanceId);
    mRepository->updateMinAllowedTradePrice(product, newPrice);
    mProduct->minAllowedTradePrice = newPrice;
}

QList<shared_ptr<Product>> ProductManager::getProductsByIds(QList<QList<QString>> ids) {
    QList<shared_ptr<Product>> products;

    for (const auto& keys : ids) {
        products.append(findByClassAndInstanceIds(keys.at(0), keys.at(1)));
    }

    return products;
}


QList<shared_ptr<Product>> ProductManager::getProductsByIds(QList<QString> combinedIds) {
    QList<shared_ptr<Product>> products;
    QList<QList<QString>> ids;

    for (const auto& combinedId : combinedIds) {
        QStringList keys = combinedId.split("_");
        ids.append({keys.at(0), keys.at(1)});
    }

    return getProductsByIds(ids);
}
