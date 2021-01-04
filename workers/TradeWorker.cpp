//
// Created by marinich_v on 04.01.21.
//

#include "TradeWorker.h"
#include "../jobs/updatetradepricesjob.h"

void TradeWorker::start() {
    emit started(this);

    UpdateTradePricesJob* job = new UpdateTradePricesJob;
    try {
        job->run();
    }  catch (std::runtime_error e) {
        qDebug() << "Error " << e.what();
    }  catch (...) {
        qDebug() << "Failed";
        emit error(QString("Trade worker start failed"));
    }

    emit finished(this);
    delete job;
}

TradeWorker::TradeWorker(QObject *parent) : Worker(parent) {}

