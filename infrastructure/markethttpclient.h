#ifndef MARKETHTTPCLIENT_H
#define MARKETHTTPCLIENT_H

#include "httpclient.h"
#include "marketsettings.h"

#include <QString>

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

    void getTrades(std::function<void(QList<TradeResponse*>)> onTrades, QString lang = "ru");
private:
    HttpClient* httpClient;
    MarketSettings* settings;
    static const QString API_ENDPOINT;
};

#endif // MARKETHTTPCLIENT_H
