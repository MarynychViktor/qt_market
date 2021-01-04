#ifndef MARKETHTTPCLIENT_H
#define MARKETHTTPCLIENT_H

#include "httpclient.h"
#include "marketsettings.h"
#include "models/traderesponse.h"
#include "models/itemmassinforesult.h"
#include "models/iteminfo.h"

#include <QString>


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
    QList<ItemMassInfoResult*> getMassInfo(const QList<QString>& combinedIds);
    ItemInfo* getItemInfo(const QString& classId, const QString& instanceId);
    void massSetPriceById(QHash<QString, int> newPrices);
private:
    SyncHttpClient* httpClient;
    MarketSettings* settings;
    static const QString API_ENDPOINT;
};

#endif // MARKETHTTPCLIENT_H
