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
    double uiPrice;
    double minPrice;
    double marketPrice;

    static TradeResponse* fromJson(QJsonValueRef document);
protected:
    TradeResponse();
};

#endif // TRADERESPONSE_H
