#ifndef MARKETHTTPCLIENT_H
#define MARKETHTTPCLIENT_H

#include "HttpClient.h"
#include "../Infrastructure/MarketSettings.h"
#include "../Infrastructure/Models/TradeResponse.h"
#include "../Infrastructure/Models/ItemMassInfoResult.h"
#include "../Infrastructure/Models/ItemInfo.h"
#include "../Infrastructure/Models/OrderResponse.h"

#include <QString>

using namespace std;

class MarketHttpClient
{
public:
    MarketHttpClient(shared_ptr<SyncHttpClient> client, shared_ptr<MarketSettings> settings)
        : httpClient(client),
          settings(settings)
    {};

    ~MarketHttpClient() {};

    QList<shared_ptr<TradeResponse>> getTrades();
    QList<shared_ptr<OrderResponse>> getOrders();

    QList<shared_ptr<ItemMassInfoResult>> getMassInfo(const QList<QString>& combinedIds);
    shared_ptr<ItemInfo> getItemInfo(const QString& classId, const QString& instanceId);
    void massSetPriceById(QHash<QString, int> newPrices);
    void updateOrder(QString classId, QString instanceId, int price);
private:
    shared_ptr<SyncHttpClient> httpClient;
    shared_ptr<MarketSettings> settings;
    static const QString API_ENDPOINT;
};

#endif // MARKETHTTPCLIENT_H
