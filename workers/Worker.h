#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr) {};
    ~Worker() {};

public slots:
    virtual void start() {};
signals:
    void started();
    void finished();
    void quit();
    void error(QString err);
};

#endif // WORKER_H
