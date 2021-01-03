#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include <QSqlDatabase>


#include <functional>
#include "../../models/product.h"

class ProductRepository
{
public:
    ProductRepository();
    ~ProductRepository();

    QList<Product*> getProducts();
    Product* findByClassAndInstanceIds(QString classId, QString instanceId);
    void addProduct(Product* product);

private:
    void initialize();
    void runQuery(std::function<void(QSqlQuery)> handler);
    QString getConnectionName();
};

#endif // PRODUCTREPOSITORY_H
