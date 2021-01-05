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
    connect(workerManager.get(), &WorkerManager::stopped, [event, &loop]() {
        Logger::debug("Main window close accepted");
        event->accept();
        loop.exit();
    });

    loop.exec();
}

void MainWindow::setUpWorker()
{
    auto instance = ServiceLocator::Instance();
    workerManager = instance->GetService<WorkerManager>();
    auto tradeWorker = new TradeWorker();
    workerManager->runWorkerInLoop<TradeWorker>(tradeWorker);
}
