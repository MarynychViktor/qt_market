//
// Created by marinich_v on 04.01.21.
//

#include <QDialog>
#include <QMessageBox>
#include <QMenuBar>
#include <QAction>
#include <QEventLoop>
#include <memory>
#include <Orders/OrdersContext.h>

#include "MainWindow.h"
#include "MarketManagementContent.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include "../workers/OrderWorker.h"

using namespace std;

// TODO: refactor trash
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, Qt::Window)
{
    setCentralWidget(new MarketManagementContent(this));
    setUpWorker();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QEventLoop loop;
    workerManager->stop();

    Logger::debug("Main window close requested");
    QMessageBox messageBox;
//    messageBox.setStandardButtons(nullptr);
    messageBox.setWindowTitle("Info");
    messageBox.setText("Stopping running workers");
    messageBox.show();
    connect(workerManager.get(), &WorkerManager::stopped, [event, &loop, &messageBox]() {
        Logger::debug("Main window close accepted");
        messageBox.hide();
        event->accept();
        loop.exit();
    });

    loop.exec();
}

void MainWindow::setUpWorker()
{
    auto instance = ServiceLocator::Instance();
    workerManager = instance->GetService<WorkerManager>();
    productManager = instance->GetService<ProductManager>();
    auto tradesContext = instance->GetService<TradesContext>();
    auto ordersContext = instance->GetService<OrdersContext>();

    auto tradeWorker = new TradeWorker();
    auto orderWorker = new OrderWorker();

    //     Trade worker setup
    connect(tradeWorker, &TradeWorker::tradesChanged, tradesContext.get(), &TradesContext::updateTradeIds);

    auto tradeThread = new QThread;
    tradeWorker->moveToThread(tradeThread);
    QObject::connect(tradeThread, &QThread::started, [this, tradeWorker]() {
        tradeWorker->start();
    });

    QObject::connect(tradeWorker, &TradeWorker::finished, [this, orderWorker, tradeWorker]() {
        if (workerManager->isStopRequested) {
            Logger::debug("Worker stop requested");
            emit tradeWorker->quit();
        } else {
            orderWorker->start();
        }
    });

    QObject::connect(tradeWorker, &TradeWorker::quit, tradeThread, &QThread::quit);
    QObject::connect(tradeThread, &QThread::finished, tradeWorker, &TradeWorker::deleteLater);
    QObject::connect(tradeThread, &QThread::finished, tradeThread, &QThread::deleteLater);
    //****

    // Order worker setup
    connect(orderWorker, &OrderWorker::ordersChanged, ordersContext.get(), &OrdersContext::updateOrderIds);

    auto orderThread = new QThread;
    orderWorker->moveToThread(orderThread);
    QObject::connect(orderThread, &QThread::started, [this, orderWorker]() {
//        orderWorker->start();
    });

    QObject::connect(orderWorker, &OrderWorker::finished, [this, tradeWorker, orderWorker]() {
        if (workerManager->isStopRequested) {
            Logger::debug("Worker stop requested");
            emit orderWorker->quit();
        } else {
            tradeWorker->start();
        }
    });

    QObject::connect(orderWorker, &OrderWorker::quit, orderThread, &QThread::quit);
    QObject::connect(orderThread, &QThread::finished, orderWorker, &OrderWorker::deleteLater);
    QObject::connect(orderThread, &QThread::finished, orderThread, &QThread::deleteLater);

    orderThread->start();

    //*****
    tradeThread->start();
}
