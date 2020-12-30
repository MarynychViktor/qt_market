#ifndef PRODUCT_H
#define PRODUCT_H

#include <QJsonObject>
#include <QString>
#include <string.h>


class Product
{
public:
    QString name;
    QString photo;
    QString classId;
    QString instanceId;
    QString quality;
    double orderPriceLimit;
    double sellPriceLimit;
    bool hasOrder = false;
    bool hasTrade = false;

    static Product fromJson(QJsonObject data);

    Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
        : name(name),
          photo(photo),
          classId(classId),
          instanceId(instanceId),
          quality(quality),
          orderPriceLimit(orderLimit),
          sellPriceLimit(sellLimit)
    {}
};

#endif // PRODUCT_H
