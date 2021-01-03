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
    UpdateTradePricesJob* job = new UpdateTradePricesJob;
    try {
        job->run();
    }  catch (std::runtime_error e) {
        qDebug() << "Error " << e.what();
    }  catch (...) {
        qDebug() << "Failed";
        emit error(QString("Trade worker process failed"));
    }

    emit finished();
    delete job;
}
