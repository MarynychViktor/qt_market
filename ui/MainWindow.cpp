//
// Created by marinich_v on 04.01.21.
//

#include <QDialog>
#include <QMessageBox>
#include "MainWindow.h"
#include "QMenuBar"
#include "QAction"
#include "MarketManagementContent.h"
#include <QEventLoop>
#include <memory>
#include "../workers/WorkerManager.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent, Qt::Window)
{
    productRepository = make_shared<ProductRepository>(ProductRepository());
    marketClient = make_shared<MarketHttpClient>(MarketHttpClient());
    productManager = make_shared<ProductManager>(productRepository, marketClient);

    setCentralWidget(new MarketManagementContent(this));

    workerManager = new WorkerManager();
    auto tradeWorker = new TradeWorker();
    workerManager->runWorkerInLoop<TradeWorker>();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QEventLoop loop;
    workerManager->stop();

    qDebug() << "Close event fired";
    connect(workerManager, &WorkerManager::stopped, [event, &loop]() {
        qDebug() << "Close accepted";
       event->accept();
       loop.exit();
    });

    loop.exec();
}
