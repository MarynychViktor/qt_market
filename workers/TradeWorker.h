//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_TRADEWORKER_H
#define MARKET_QT_TRADEWORKER_H


#include "Worker.h"
#include "../Infrastructure/Repositories/ProductRepository.h"

using namespace std;
class TradeWorker : public Worker {
    Q_OBJECT
public:
    TradeWorker(QObject *parent = nullptr);
    ~TradeWorker() {};
public slots:
    void start() override;
signals:
    void started();
    void finished();
    void quit();
    void error(QString err);
};


#endif //MARKET_QT_TRADEWORKER_H
