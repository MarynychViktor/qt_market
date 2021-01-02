#include "productrepository.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

ProductRepository::ProductRepository()
{
    initialize();
}

ProductRepository::~ProductRepository()
{
    db.close();
}

QList<Product*> ProductRepository::getProducts()
{
     QSqlQuery query;
     QList<Product*> products;

     query.exec("SELECT * FROM products");
     while(query.next()) {
        products.append(
            new Product(
               query.value(1).toString(),
               query.value(2).toString(),
               query.value(3).toString(),
               query.value(4).toString(),
               query.value(5).toString(),
               query.value(6).toInt(),
               query.value(7).toInt()
            )
        );
     }

     return products;
}

Product *ProductRepository::findByClassAndInstanceIds(QString classId, QString instanceId)
{
    QSqlQuery query;
    Product* product = nullptr;

    query.prepare("SELECT * FROM products WHERE classId = :classId AND instanceId = :instanceId LIMIT 1");
    query.bindValue(":classId", classId);
    query.bindValue(":instanceId", instanceId);

    if (query.next()) {
        product = new Product(
           query.value(1).toString(),
           query.value(2).toString(),
           query.value(3).toString(),
           query.value(4).toString(),
           query.value(5).toString(),
           query.value(6).toInt(),
           query.value(7).toInt()
        );
    }

    return product;
}

void ProductRepository::addProduct(Product *product)
{
    QSqlQuery query;

    query.prepare("INSERT INTO products (name, photo, classId, instanceId, quality, orderLimit, sellLimit) VALUES (:name, :photo, :classId, :instanceId, :quality, :orderLimit, :sellLimit)");
    query.bindValue(":name", product->name);
    query.bindValue(":photo", product->photo);
    query.bindValue(":classId", product->classId);
    query.bindValue(":instanceId", product->instanceId);
    query.bindValue(":quality", product->quality);
    query.bindValue(":orderLimit", product->maxAllowedOrderPrice);
    query.bindValue(":sellLimit", product->minAllowedTradePrice);

    query.exec();
}


void ProductRepository::initialize()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("products.db");

    if (!db.open()) {
        throw db.lastError();
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS products ("
                " id INT PRIMARY KEY NOT NULL,"
                " name TEXT NOT NULL,"
                " photo TEXT NULL,"
                " classId CHAR(255) NOT NULL,"
                " instanceId  CHAR(255) NOT NULL,"
                " quality CHAR(255) NOT NULL,"
                " orderLimit UNSIGNED BIG INT NOT NULL,"
                " sellLimit UNSIGNED BIG INT NOT NULL)"
    );
}

//Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
