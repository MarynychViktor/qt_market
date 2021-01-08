//
// Created by julia on 08.01.2021.
//

#ifndef MAIN_CPP_TRADESCONTEXT_H
#define MAIN_CPP_TRADESCONTEXT_H

#include <QObject>
#include "../Models/Product.h"

using namespace  std;

class TradesContext : public QObject {
    Q_OBJECT
public:
    TradesContext(QObject* parent = nullptr);
    QList<shared_ptr<Product>> snapshot;
public slots:
    void updateTradeIds(QList<QString> tradeIds);

signals:
    void tradesChanged();
};


#endif //MAIN_CPP_TRADESCONTEXT_H
