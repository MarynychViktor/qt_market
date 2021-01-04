//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_MAINWINDOW_H
#define MARKET_QT_MAINWINDOW_H


#include <QMainWindow>
#include "../pages/menu.h"
#include "../workers/WorkerManager.h"

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);

private:
    Menu* menu;
    WorkerManager* workerManager;

    void createMenu();
    void closeEvent(QCloseEvent *event) override;
};


#endif //MARKET_QT_MAINWINDOW_H
