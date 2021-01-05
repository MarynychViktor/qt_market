#include "TradeResponse.h"
#include <QJsonValueRef>
#include <QJsonValue>
#include <QJsonObject>

using namespace std;

TradeResponse::TradeResponse()
{

}

bool TradeResponse::isOnSale()
{
    return uiStatus == "1";
}

shared_ptr<TradeResponse> TradeResponse::fromJson(QJsonValueRef document)
{
    auto obj = document.toObject();
    auto trade = make_shared<TradeResponse>(TradeResponse());

    trade->uiid = obj["ui_id"].toString();
    trade->classId = obj["i_classid"].toString();
    trade->instanceId = obj["i_instanceid"].toString();
    trade->name = obj["i_name"].toString();
    trade->marketName = obj["i_market_name"].toString();
    trade->uiStatus = obj["ui_status"].toString();
    trade->uiPrice = obj["ui_price"].toString().toDouble();
    trade->minPrice = obj["min_price"].toString().toDouble();
    trade->marketPrice = obj["i_market_price"].toString().toDouble();

    return trade;
}
