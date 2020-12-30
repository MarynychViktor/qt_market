#include "product.h"


Product Product::fromJson(QJsonObject data)
{
    return Product(
        data["name"].toString(),
        data["photo"].toString(),
        data["classId"].toString(),
        data["instanceId"].toString(),
        data["quality"].toString(),
        data["orderLimit"].toDouble(),
        data["sellLimit"].toDouble()
    );
}
