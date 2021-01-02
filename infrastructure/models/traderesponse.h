#ifndef TRADERESPONSE_H
#define TRADERESPONSE_H

#include <QJsonDocument>
#include <QString>



class TradeResponse
{
public:
    QString uiid;
    QString classId;
    QString instanceId;
    QString name;
    QString marketName;
    QString uiStatus;
    int uiPrice;
    int minPrice;
    int marketPrice;

    static TradeResponse* fromJson(QJsonValueRef document);
    bool isOnSale();
protected:
    TradeResponse();
};

#endif // TRADERESPONSE_H
