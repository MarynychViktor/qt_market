//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_TRADEWORKER_H
#define MARKET_QT_TRADEWORKER_H


#include "Worker.h"

class TradeWorker : public Worker {
    Q_OBJECT
public:
    ~TradeWorker() {};
    explicit TradeWorker(QObject *parent = nullptr);
public slots:
    void start() override;
};


#endif //MARKET_QT_TRADEWORKER_H
