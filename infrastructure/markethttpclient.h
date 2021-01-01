#ifndef MARKETHTTPCLIENT_H
#define MARKETHTTPCLIENT_H

#include "httpclient.h"
#include "marketsettings.h"

#include <QString>

#include <infrastructure/models/iteminfo.h>
#include <infrastructure/models/itemmassinforesult.h>
#include <infrastructure/models/traderesponse.h>

#include <math.h>

class MarketHttpClient
{
public:
    MarketHttpClient()
        : httpClient(new SyncHttpClient()),
          settings(new MarketSettings)
    {};

    ~MarketHttpClient() {
        delete settings;
    };

    QList<TradeResponse*> getTrades();
    QList<ItemMassInfoResult*> getMassInfo(QList<QString> combinedIds);
    ItemInfo* getItemInfo(QString classId, QString instanceId);
    void massSetPriceById(QHash<QString, int> newPrices);

    //    public async Task<ItemInfo> GetProductInfo(string classId, string instanceId, string lang = "ru")
//    {
//        string requestUrl = getItemInfoPath(classId, instanceId, lang);
//        return await _networkClient.GetJson<ItemInfo>(requestUrl);
//    }
private:
    SyncHttpClient* httpClient;
    MarketSettings* settings;
    static const QString API_ENDPOINT;
};

#endif // MARKETHTTPCLIENT_H
