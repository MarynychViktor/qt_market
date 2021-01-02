#ifndef PRODUCT_H
#define PRODUCT_H

#include <QJsonObject>
#include <QString>
#include <string.h>

#include <infrastructure/models/itemmassinforesult.h>


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

    static Product* fromJson(QJsonObject data);
    static Product* fromItemMassInfo(ItemMassInfoResult* data);

    Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
        : name(name),
          photo(photo),
          classId(classId),
          instanceId(instanceId),
          quality(quality),
          maxAllowedOrderPrice(orderLimit),
          minAllowedTradePrice(sellLimit)
    {}
};

#endif // PRODUCT_H
