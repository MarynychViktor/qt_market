//
// Created by marinich_v on 05.01.21.
//

#ifndef MARKET_QT_ORDERWORKER_H
#define MARKET_QT_ORDERWORKER_H


#include <QObject>
#include "Worker.h"
#include "../Http/MarketHttpClient.h"
#include "../Services/ProductManager.h"

class OrderWorker  : public Worker {
Q_OBJECT
public:
    OrderWorker(QObject *parent = nullptr);
    ~OrderWorker() = default;
public slots:
    void start() override;

signals:
    void ordersChanged(QList<QString> ids);

private:
    QMap<QString, shared_ptr<OrderResponse>> ordersMappedWithId;
    void initializeServices();
    shared_ptr<MarketHttpClient> marketClient;
    shared_ptr<ProductManager> productManager;
    QList<shared_ptr<ItemMassInfoResult>> orderedProducts;
    shared_ptr<Product> productForOrder(shared_ptr<ItemMassInfoResult> order);

signals:
    void started();
    void finished();
    void quit();
    void error(QString err);
};


#endif //MARKET_QT_ORDERWORKER_H
