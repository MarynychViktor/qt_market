//
// Created by julia on 07.01.2021.
//

#ifndef MARKET_QT_MARKETREQUESTINTERCEPTOR_H
#define MARKET_QT_MARKETREQUESTINTERCEPTOR_H

#include <mutex>
#include <QMap>
#include <QMutex>

using namespace std;

const int LIMIT_REQUESTS_PER_UNIT = 2;

class MarketRequestInterceptor {
public:
    static void ensureQuota();
    static void waitQuotaDelay(int delay);

private:
    static QMutex mtx;
    static QMap<int, int> requestsPerTimeUnit;
};


#endif //MARKET_QT_MARKETREQUESTINTERCEPTOR_H
