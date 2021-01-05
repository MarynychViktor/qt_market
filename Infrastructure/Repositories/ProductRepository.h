#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include <QSqlDatabase>


#include <functional>
#include "../../Models/Product.h"

using namespace std;

class ProductRepository
{
public:
    ProductRepository();
    ~ProductRepository();

    QList<shared_ptr<Product>> getProducts();
    shared_ptr<Product> findByClassAndInstanceIds(QString classId, QString instanceId);
    void addProduct(shared_ptr<Product> product);
    void updateMaxAllowedOrderPrice(shared_ptr<Product> product, int newPrice);
    void updateMinAllowedTradePrice(shared_ptr<Product> product, int newPrice);

private:
    void initialize();
    void runQuery(const std::function<void(QSqlQuery)>& handler);
    QString getConnectionName();
};

#endif // PRODUCTREPOSITORY_H
