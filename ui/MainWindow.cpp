//
// Created by marinich_v on 04.01.21.
//

#include <QDialog>
#include <QMessageBox>
#include <QMenuBar>
#include <QAction>
#include <QEventLoop>
#include <memory>

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

    // Trade worker setup
//    auto tradeWorker = new TradeWorker();
//    workerManager->runWorkerInLoop<TradeWorker>(tradeWorker);

    // Order worker setup
    auto orderWorker = new OrderWorker();
    workerManager->runWorkerInLoop<OrderWorker>(orderWorker);
}
