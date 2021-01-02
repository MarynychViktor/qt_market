#include "worker.h"

#include <jobs/updatetradepricesjob.h>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::~Worker()
{

}

void Worker::process()
{
    UpdateTradePricesJob job;
    try {
        job.run();
        emit finished();
    }  catch (...) {
        emit error(QString("Trade worker process failed"));
        emit finished();
    }

}
