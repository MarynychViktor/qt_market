//
// Created by marinich_v on 04.01.21.
//

#include <QDialog>
#include <QMessageBox>
#include "MainWindow.h"
#include "QMenuBar"
#include "QAction"
#include "MarketManagementContent.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include <QEventLoop>
#include <memory>

using namespace std;
// TODO: refactor trash
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent, Qt::Window)
{
//    productRepository = make_shared<ProductRepository>(ProductRepository());
//    marketClient = make_shared<MarketHttpClient>(MarketHttpClient());
//    productManager = make_shared<ProductManager>(productRepository, marketClient);

    setCentralWidget(new MarketManagementContent(this));
    setUpWorker();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QEventLoop loop;
    workerManager->stop();

    qDebug() << "Close event fired";
    connect(workerManager.get(), &WorkerManager::stopped, [event, &loop]() {
        qDebug() << "Close accepted";
       event->accept();
       loop.exit();
    });

    loop.exec();
}

void MainWindow::setUpWorker() {
    auto instance = ServiceLocator::Instance();

    workerManager = instance->GetService<WorkerManager>();
    auto tradeWorker = new TradeWorker();
    workerManager->runWorkerInLoop<TradeWorker>(tradeWorker);
}
