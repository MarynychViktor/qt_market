#ifndef ORDERRESPONSE_H
#define ORDERRESPONSE_H

#include <QJsonDocument>
#include <QString>

using namespace std;

class OrderResponse
{
public:
    QString classId;
    QString instanceId;
    QString name;
    int state;
    int orderPrice;

    OrderResponse(QString classId, QString instanceId, QString name, int state, int orderPrice);
    static shared_ptr<OrderResponse> fromJson(QJsonValueRef document);
    shared_ptr<QJsonObject> toJson();

    bool isActive();
protected:
};

#endif // ORDERRESPONSE_H

