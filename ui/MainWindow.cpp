//
// Created by marinich_v on 04.01.21.
//

#include <QDialog>
#include <QMessageBox>
#include "MainWindow.h"
#include "QMenuBar"
#include "QAction"
#include "MarketManagementContent.h"
#include "../workers/WorkerManager.h"
#include "../workers/TradeWorker.h"
#include <QDebug>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, Qt::Window) {
//    menu = new Menu(this);
    setCentralWidget(new MarketManagementContent(this));
//    setFixedSize(250, 300);
    createMenu();
    workerManager = new WorkerManager();
    workerManager->runWorkerInLoop<TradeWorker>();
}

void MainWindow::createMenu() {
    auto fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(new QAction("New", this));
    fileMenu->addAction(new QAction("Edit", this));
    fileMenu->addAction(new QAction("Exit", this));
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
