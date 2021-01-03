#include "product.h"
#include "../consts.h"


Product* Product::fromJson(QJsonObject data)
{
    return new Product(
        data["name"].toString(),
        data["photo"].toString(),
        data["classId"].toString(),
        data["instanceId"].toString(),
        data["quality"].toString(),
        data["orderLimit"].toDouble(),
        data["sellLimit"].toDouble()
            );
}

Product* Product::fromItemMassInfo(ItemMassInfoResult* data)
{
    return new Product(data->name, data->photo, data->classId, data->instanceId, data->quality, DEFAULT_ORDER_PRICE, DEFAULT_TRADE_PRICE);
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
