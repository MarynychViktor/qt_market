#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include <QSqlDatabase>

#include <models/product.h>

class ProductRepository
{
public:
    ProductRepository();
    ~ProductRepository();
    QSqlDatabase db;

    QList<Product*> getProducts();
    Product* findByClassAndInstanceIds(QString classId, QString instanceId);
    void addProduct(Product* product);

private:
    void initialize();
};

#endif // PRODUCTREPOSITORY_H
