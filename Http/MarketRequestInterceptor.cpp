//
// Created by julia on 07.01.2021.
//

#include <QDateTime>
#include <QEventLoop>
#include <QTimer>
#include <Services/Logger.h>
#include <Exceptions/AppException.h>
#include <QElapsedTimer>
#include "MarketRequestInterceptor.h"

QMap<int, int> MarketRequestInterceptor::requestsPerTimeUnit;
QMutex MarketRequestInterceptor::mtx;
QMutex MarketRequestInterceptor::requestMtx;

QByteArray MarketRequestInterceptor::requestWithQuota(function<QByteArray()> handler) {
    requestMtx.lock();

    try {
        ensureQuota();
        auto result = handler();
        requestMtx.unlock();
        return result;
    } catch (AppException& e) {
        requestMtx.unlock();
        throw e;
    }
}


void MarketRequestInterceptor::ensureQuota() {
    mtx.lock();

    auto currentDateTime =  QDateTime::currentDateTime();
    auto timestamp = currentDateTime.toSecsSinceEpoch();
    auto msTimestamp = currentDateTime.toMSecsSinceEpoch();

    if (!requestsPerTimeUnit.contains(timestamp)) {
        requestsPerTimeUnit[timestamp] = 1;
    } else {
        auto requestsPerLastUnit = requestsPerTimeUnit[timestamp];
        if (requestsPerLastUnit == LIMIT_REQUESTS_PER_UNIT) {
            if (requestsPerTimeUnit.keys().length() > 100) {
                requestsPerTimeUnit.clear();
            }

            int delay = 1000 - msTimestamp % 1000;
            Logger::debug(QString("Quota: waiting %1 before next request").arg(delay));

            QEventLoop loop;
            QTimer timer;

            timer.setSingleShot(true);
            QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
            timer.start(delay);

            loop.exec();

            requestsPerTimeUnit[QDateTime::currentDateTime().toSecsSinceEpoch()] = 1;
        } else {
            requestsPerLastUnit++;
            requestsPerTimeUnit[timestamp] = requestsPerLastUnit;
        }
    }

    mtx.unlock();
}

void MarketRequestInterceptor::waitQuotaDelay(int delay) {
    mtx.lock();

    QEventLoop loop;
    QTimer timer;

    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(delay);
    Logger::debug(QString("Delayed request for %1ms").arg(delay));

    loop.exec();

    mtx.unlock();
}
