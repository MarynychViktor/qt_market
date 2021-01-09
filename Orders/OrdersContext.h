//
// Created by julia on 08.01.2021.
//

#ifndef MAIN_CPP_ORDERSCONTEXT_H
#define MAIN_CPP_ORDERSCONTEXT_H


#include <QObject>
#include "../Models/Product.h"

class OrdersContext : public QObject {
Q_OBJECT
public:
    OrdersContext(QObject* parent = nullptr);
    QList<shared_ptr<Product>> snapshot;
    QList<QString> snapshotIds;
public slots:
    void updateOrderIds(QList<QString> orderIds);
    void updateSnapshot(const QList<shared_ptr<Product>>& products);

signals:
    void ordersChanged();
    void ordersAdded(QList<QString> orderIds);
    void ordersRemoved(QList<QString> orderIds);
};


#endif //MAIN_CPP_ORDERSCONTEXT_H
