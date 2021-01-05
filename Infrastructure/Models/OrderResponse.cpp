//
// Created by marinich_v on 05.01.21.
//

#include <QJsonObject>
#include "OrderResponse.h"

shared_ptr<OrderResponse> OrderResponse::fromJson(QJsonValueRef document) {
    auto rawObject = document.toObject();
        return make_shared<OrderResponse>(
            rawObject["i_classid"].toString(),
            rawObject["i_instanceid"].toString(),
            rawObject["i_market_name"].toString(),
            rawObject["o_state"].toInt(),
            rawObject["o_price"].toInt()
    );
}

OrderResponse::OrderResponse(QString classId, QString instanceId, QString name, int state, int orderPrice)
    : classId( classId), instanceId(instanceId), name(name), state(state), orderPrice(orderPrice)
{
}

shared_ptr<QJsonObject> OrderResponse::toJson() {
    auto orderResponse = new QJsonObject;

    orderResponse->insert("classId", classId);
    orderResponse->insert("instanceId", instanceId);
    orderResponse->insert("name", name);
    orderResponse->insert("state", state);
    orderResponse->insert("orderPrice", orderPrice);

    return shared_ptr<QJsonObject>(orderResponse);
}

bool OrderResponse::isActive()
{
    return state == 0;
}

