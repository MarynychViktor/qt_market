//
// Created by marinich_v on 04.01.21.
//

#include "WorkerManager.h"
#include "../Services/Logger.h"
#include <QDebug>

using namespace std;

WorkerManager::WorkerManager(QObject *parent)
    : QObject(parent)
{
}

void WorkerManager::stop()
{
    isStopRequested = true;
    emit stopRequested();
}

void WorkerManager::startWorker(Worker *worker)
{
    activeWorkers.append(worker);
}

void WorkerManager::stopWorker(Worker *worker)
{
    bool removed = false;

    for (int i = 0; i < activeWorkers.length(); i++) {
       if (worker == activeWorkers.at(i)) {
           activeWorkers.removeAt(i);
           removed = true;
           break;
       }
    }

    if (activeWorkers.isEmpty()) {
        Logger::debug("Worker manager stopped");
        emit stopped();
    }
}

