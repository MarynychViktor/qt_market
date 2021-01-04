//
// Created by marinich_v on 04.01.21.
//

#include "WorkerManager.h"
#include <QDebug>

using namespace std;

WorkerManager::WorkerManager(QObject *parent) : QObject(parent) {
}

void WorkerManager::stop() {
    isStopRequested = true;
}

void WorkerManager::startWorker(Worker *worker) {
    activeWorkers.append(worker);
}

void WorkerManager::stopWorker(Worker *worker) {
    bool removed = false;

    for (int i = 0; i < activeWorkers.length(); i++) {
       if (worker == activeWorkers.at(i)) {
           activeWorkers.removeAt(i);
           removed = true;
           break;
       }
    }

    if (activeWorkers.isEmpty()) {
        qDebug() << "Worker manager stopped";
        emit stopped();
    }
}

