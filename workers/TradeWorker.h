//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_TRADEWORKER_H
#define MARKET_QT_TRADEWORKER_H


#include "Worker.h"
#include "../Infrastructure/Repositories/ProductRepository.h"
#include "../Jobs/UpdateTradePricesJob.h"
#include "../Services/ProductManager.h"

using namespace std;
class TradeWorker : public Worker {
    Q_OBJECT
public:
    TradeWorker(QObject *parent = nullptr);
    ~TradeWorker() {};
public slots:
    void start() override;

private:
    void prepareServices();
    void initializeTrades();
    shared_ptr<Product> productForTrade(shared_ptr<ItemMassInfoResult> tradeInfo);
    QMap<QString, shared_ptr<TradeResponse>> tradesMappedWithId;
    QList<shared_ptr<ItemMassInfoResult>> trades;
    shared_ptr<MarketHttpClient> marketClient;
    shared_ptr<ProductManager> productManager;

signals:
    void started();
    void finished();
    void quit();
    void error(QString err);
};


#endif //MARKET_QT_TRADEWORKER_H
