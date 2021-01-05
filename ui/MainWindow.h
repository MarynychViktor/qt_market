//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_MAINWINDOW_H
#define MARKET_QT_MAINWINDOW_H


#include <QMainWindow>
#include "../pages/menu.h"
#include "../workers/WorkerManager.h"
#include "../Services/ProductManager.h"

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);

private:
    shared_ptr<WorkerManager> workerManager;

    void closeEvent(QCloseEvent *event) override;
    void setUpWorker();
};


#endif //MARKET_QT_MAINWINDOW_H
