//
// Created by marinich_v on 04.01.21.
//

#include "TradeWorker.h"
#include <QDebug>

void TradeWorker::start() {
    emit started();

//    auto job = make_shared<UpdateTradePricesJob>();
//    try {
//        job->run();
//    }  catch (runtime_error& e) {
//        qDebug() << "Error " << e.what();
//    }  catch (...) {
//        qDebug() << "Failed";
//        emit error(QString("Trade worker start failed"));
//    }

    emit finished();
}

TradeWorker::TradeWorker(QObject *parent)
    : Worker(parent)
{
}

