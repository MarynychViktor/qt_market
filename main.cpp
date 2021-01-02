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

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Menu menu(&app);
    menu.show();

    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started,  worker, &Worker::process);
    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
    QObject::connect(worker, &Worker::finished, thread, &Worker::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);


  return app.exec();
}
