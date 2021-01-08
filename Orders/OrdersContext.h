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
public slots:
    void updateOrderIds(QList<QString> orderIds);

signals:
    void ordersChanged();
};


#endif //MAIN_CPP_ORDERSCONTEXT_H
