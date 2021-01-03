#include "productrepository.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QJsonDocument>

ProductRepository::ProductRepository()
{
    initialize();
}

ProductRepository::~ProductRepository()
{
}

QList<Product*> ProductRepository::getProducts()
{
     QList<Product*> products;

     runQuery([&products](QSqlQuery query) {
         query.exec("SELECT * FROM products");
         while(query.next()) {
             qDebug() << "Append product";
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

         qDebug() << "LAst insert id" <<  query.lastInsertId();
         qDebug() << "LAst error id" <<  query.lastError();
     });

     return products;
}

Product *ProductRepository::findByClassAndInstanceIds(QString classId, QString instanceId)
{
    Product* product = nullptr;

    runQuery([&product, &classId, &instanceId](QSqlQuery query) {
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
    });

    return product;
}

void ProductRepository::addProduct(Product *product)
{
   runQuery([&product](QSqlQuery query) {
       query.prepare("INSERT INTO products (name, photo, classId, instanceId, quality, orderLimit, sellLimit)"
" VALUES (:name, :photo, :classId, :instanceId, :quality, :orderLimit, :sellLimit)");
       query.bindValue(":name", product->name);
       query.bindValue(":photo", product->photo);
       query.bindValue(":classId", product->classId);
       query.bindValue(":instanceId", product->instanceId);
       query.bindValue(":quality", product->quality);
       query.bindValue(":orderLimit", product->maxAllowedOrderPrice);
       query.bindValue(":sellLimit", product->minAllowedTradePrice);

       query.exec();
       qDebug() << "addProduct LAst insert id" <<  query.lastInsertId();
       qDebug() << "addProduct LAst error id" <<  query.lastError() << product->name;
   });
}


void ProductRepository::initialize()
{
    runQuery([](QSqlQuery query) {
        query.exec("CREATE TABLE IF NOT EXISTS products ("
                    " id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                    " name TEXT NOT NULL,"
                    " photo TEXT NULL,"
                    " classId CHAR(255) NOT NULL,"
                    " instanceId  CHAR(255) NOT NULL,"
                    " quality CHAR(255) NOT NULL,"
                    " orderLimit UNSIGNED BIG INT NOT NULL,"
                    " sellLimit UNSIGNED BIG INT NOT NULL)");

        qDebug() << "LAst insert id" <<  query.lastInsertId();
        qDebug() << "LAst error id" <<  query.lastError();
    });
}

void ProductRepository::runQuery(std::function<void(QSqlQuery query)> handler)
{
     QString name;
    {
        int retry = 0;
        name = getConnectionName();

        while (QSqlDatabase::contains(name)) {
            if (retry > 3) {
                throw "Failed to resolve connection name";
            }

            name = getConnectionName();
            retry ++;
        }

        auto db = QSqlDatabase::addDatabase("QSQLITE", name);
        db.setDatabaseName("products.db");

        if (!db.open()) {
            qDebug() << "Open db";
            throw db.lastError();
        };
        handler(QSqlQuery(db));
    }

    QSqlDatabase::removeDatabase(name);
}

QString ProductRepository::getConnectionName()
{
    std::time_t t = std::time(0);
    return QString::number(t) + QString("_") + QString::number(rand() % 1000);
}

//Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
