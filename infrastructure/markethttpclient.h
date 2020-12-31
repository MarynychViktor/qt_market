#ifndef MARKETHTTPCLIENT_H
#define MARKETHTTPCLIENT_H

#include "httpclient.h"
#include "marketsettings.h"

#include <QString>

#include <infrastructure/models/iteminfo.h>
#include <infrastructure/models/traderesponse.h>



class MarketHttpClient
{
public:
    MarketHttpClient(HttpClient* client)
        : httpClient(client),
          settings(new MarketSettings)
    {};

    ~MarketHttpClient() {
        delete settings;
    };

    void getTrades(std::function<void(QList<TradeResponse*>)> onResponse, function<void(QNetworkReply*)> onError = nullptr);
    void getItemInfo(QString classId, QString instanceId, std::function<void(ItemInfo*)> onResponse, function<void(QNetworkReply*)> onError = nullptr);
    void massSetPriceById(QHash<QString, int> newPrices, std::function<void()> onSuccess, function<void(QNetworkReply*)> onError = nullptr);

    //    public async Task<ItemInfo> GetProductInfo(string classId, string instanceId, string lang = "ru")
//    {
//        string requestUrl = getItemInfoPath(classId, instanceId, lang);
//        return await _networkClient.GetJson<ItemInfo>(requestUrl);
//    }
private:
    HttpClient* httpClient;
    MarketSettings* settings;
    static const QString API_ENDPOINT;
};

#endif // MARKETHTTPCLIENT_H
