//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_WORKERMANAGER_H
#define MARKET_QT_WORKERMANAGER_H


#include <QObject>
#include "Worker.h"
#include "TradeWorker.h"
using namespace std;

class WorkerManager  : public QObject
{
    Q_OBJECT;
public:
    WorkerManager(QObject *parent = nullptr);

    template<class W>
    void runWorkerInLoop() {
        if (!is_base_of<Worker, W>()) {
            throw runtime_error("Template class should be base of Worker");
        }

        auto thread = new QThread;
        auto worker = new W;
        worker->moveToThread(thread);

        // SOMETHING WRONG HERE
        QObject::connect(thread, &QThread::started, worker, &Worker::start);

        QObject::connect(worker, &Worker::finished,  [this, &worker]() {
            if (isStopRequested) {
                stopWorker(worker);
                emit worker->quit();
            } else {
                worker->start();
            }
        });

        QObject::connect(worker, &Worker::quit, thread, &QThread::quit);
        QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
        QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }

signals:
    void stopped();

public slots:
    void stop();

private:
    QList<Worker*> activeWorkers;
    bool isStopRequested = false;

    void startWorker(Worker* worker);
    void stopWorker(Worker* worker);
};




#endif //MARKET_QT_WORKERMANAGER_H
