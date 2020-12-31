#include "traderesponse.h"
#include <QJsonValueRef>
#include <QJsonValue>
#include <QJsonObject>

using namespace std;

TradeResponse::TradeResponse()
{

}

TradeResponse* TradeResponse::fromJson(QJsonValueRef document)
{
    auto obj = document.toObject();
    auto trade = new TradeResponse();

    trade->uiid = obj["ui_id"].toString();
    trade->classId = obj["i_classid"].toString();
    trade->instanceId = obj["i_instanceid"].toString();
    trade->name = obj["i_name"].toString();
    trade->marketName = obj["i_market_name"].toString();
    trade->uiStatus = obj["ui_status"].toString();
    trade->uiPrice = obj["ui_price"].toDouble();
    trade->minPrice = obj["min_price"].toDouble();
    trade->marketPrice = obj["i_market_price"].toDouble();

    return trade;
}
