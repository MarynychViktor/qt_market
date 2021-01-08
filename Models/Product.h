#ifndef PRODUCT_H
#define PRODUCT_H

#include <QJsonObject>
#include <QString>
#include "../Http/MarketHttpClient.h"
#include "Product.h"
#include "../Infrastructure/Models/ItemMassInfoResult.h"

using namespace std;

class Product
{
public:
    QString name;
    QString photo;
    QString classId;
    QString instanceId;
    QString quality;
    double maxAllowedOrderPrice;
    double minAllowedTradePrice;
    bool hasOrder = false;
    bool hasTrade = false;

    static shared_ptr<Product> fromJson(QJsonObject data);
    static shared_ptr<Product> fromItemMassInfo(shared_ptr<ItemMassInfoResult> data);
    QJsonObject toJson();
    QString getCombinedId();

    Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
        : name(name),
          photo(photo),
          classId(classId),
          instanceId(instanceId),
          quality(quality),
          maxAllowedOrderPrice(orderLimit),
          minAllowedTradePrice(sellLimit)
    {}

    Product(const Product& product);
};

#endif // PRODUCT_H
