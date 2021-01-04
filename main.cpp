#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTableView>
#include <QNetworkReply>
#include "form.h"
#include <QJsonDocument>
#include <QThread>

#include "pages/menu.h"
#include "workers/Worker.h"
#include "ui/MainWindow.h"


int main(int argc, char **argv)
{
    // TODO: review shared pointers instead of raw
    // !!!!
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();


//    Menu menu(&app);
//    menu.show();
//
//    bool shouldExit = false;
//    QThread* thread = new QThread;
//    Worker* worker = new Worker();
//    worker->moveToThread(thread);
//
//    QObject::connect(thread, &QThread::started,  worker, &Worker::start);
////    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
////    QObject::connect(worker, &Worker::finished, [&shouldExit, &worker]() {
////        if (!shouldExit) {
////            qDebug() << "Worker started again";
////            worker->start();
////        } else {
////            qDebug() << "Worker not started";
////        }
////    });
//    QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
//    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
//
//    thread->start();
//
//    QObject::connect(&app, &QApplication::aboutToQuit, [&thread, &shouldExit]() {
//        thread->quit();
//        shouldExit = true;
//        qDebug() << "Worker close requested again";
//    });

  return app.exec();
}
