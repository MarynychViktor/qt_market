#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTableView>
#include <QNetworkReply>
#include <form.h>
#include <QJsonDocument>
#include <QThread>

#include <pages/menu.h>

#include <infrastructure/httpclient.h>
#include <infrastructure/markethttpclient.h>

#include <workers/worker.h>

#include <infrastructure/repositories/productrepository.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Menu menu(&app);
    menu.show();

    bool shouldExit = false;
    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started,  worker, &Worker::process);
//    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
//    QObject::connect(worker, &Worker::finished, [&shouldExit, &worker]() {
//        if (!shouldExit) {
//            qDebug() << "Worker started again";
//            worker->process();
//        } else {
//            qDebug() << "Worker not started";
//        }
//    });
    QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();

    QObject::connect(&app, &QApplication::aboutToQuit, [&thread, &shouldExit]() {
        thread->quit();
        shouldExit = true;
        qDebug() << "Worker close requested again";
    });

  return app.exec();
}
