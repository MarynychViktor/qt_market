//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_PRODUCTMANAGER_H
#define MARKET_QT_PRODUCTMANAGER_H

#include "../Models/Product.h"
#include <QObject>
#include "../Infrastructure/Repositories/ProductRepository.h"

using namespace std;

class ProductManager : public  QObject
{
    Q_OBJECT
public:
    explicit ProductManager(shared_ptr<ProductRepository>& repository, shared_ptr<MarketHttpClient>& marketClient);

    QList<shared_ptr<Product>> getProducts();
    shared_ptr<Product> findByClassAndInstanceIds(QString classId, QString instanceId);
    void addProduct(shared_ptr<Product> product);
    void updateMaxAllowedOrderPrice(shared_ptr<Product> product, int newPrice);
    void updateMinAllowedTradePrice(shared_ptr<Product> product, int newPrice);
signals:
    void productAdded(shared_ptr<Product> product);
    void maxAllowedOrderPriceUpdated(shared_ptr<Product> product, int oldPrice, int newPrice);
    void minAllowedTradePriceUpdated(shared_ptr<Product> product, int oldPrice, int newPrice);

private:
    shared_ptr<ProductRepository> mRepository;
    shared_ptr<MarketHttpClient> mMarketClient;
    QList<shared_ptr<Product>> mProducts;
    bool isInitialized = false;
};


#endif //MARKET_QT_PRODUCTMANAGER_H
