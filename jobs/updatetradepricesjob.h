#ifndef UPDATETRADEPRICESJOB_H
#define UPDATETRADEPRICESJOB_H

//#include "../infrastructure/markethttpclient.h"
//#include "../infrastructure/repositories/productrepository.h"


#include "../infrastructure/repositories/productrepository.h"
#include "../markethttpclient.h"

using namespace std;

class UpdateTradePricesJob
{
public:
    UpdateTradePricesJob();
    ~UpdateTradePricesJob();
    MarketHttpClient* marketClient;
    ProductRepository * repository;

    void run();
};

#endif // UPDATETRADEPRICESJOB_H
