#include "Product.h"
#include "../consts.h"


shared_ptr<Product> Product::fromJson(QJsonObject data)
{
    return make_shared<Product>(
        data["name"].toString(),
        data["photo"].toString(),
        data["classId"].toString(),
        data["instanceId"].toString(),
        data["quality"].toString(),
        data["orderLimit"].toDouble(),
        data["sellLimit"].toDouble()
        );
}

shared_ptr<Product> Product::fromItemMassInfo(shared_ptr<ItemMassInfoResult> data)
{
    return make_shared<Product>(data->name, data->photo, data->classId, data->instanceId, data->quality, DEFAULT_ORDER_PRICE, DEFAULT_TRADE_PRICE);
}

QJsonObject Product::toJson()
{
    QJsonObject object;
    object.insert("name", name);
    object.insert("photo", photo);
    object.insert("classId", classId);
    object.insert("instanceId", instanceId);
    object.insert("maxAllowedOrderPrice", maxAllowedOrderPrice);
    object.insert("minAllowedTradePrice", minAllowedTradePrice);

    return object;
}

QString Product::getCombinedId() {
    return classId + "_" + instanceId;
}

Product::Product(const Product& product): name(QString::fromStdString(product.name.toStdString())),
                                          photo(QString::fromStdString(product.photo.toStdString())),
                                          classId(QString::fromStdString(product.classId.toStdString())),
                                          instanceId(QString::fromStdString(product.instanceId.toStdString())),
                                          quality(QString::fromStdString(product.quality.toStdString())),
                                          maxAllowedOrderPrice(product.maxAllowedOrderPrice),
                                          minAllowedTradePrice(product.minAllowedTradePrice)
{
}
