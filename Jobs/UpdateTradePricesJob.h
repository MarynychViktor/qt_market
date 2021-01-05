#ifndef UPDATETRADEPRICESJOB_H
#define UPDATETRADEPRICESJOB_H


#include "../Infrastructure/Repositories/ProductRepository.h"
#include "../Http/MarketHttpClient.h"

using namespace std;

class UpdateTradePricesJob
{
public:
    UpdateTradePricesJob(shared_ptr<MarketHttpClient> client, shared_ptr<ProductRepository> repository);
    ~UpdateTradePricesJob();
    shared_ptr<MarketHttpClient> marketClient;
    shared_ptr<ProductRepository> repository;

    void run();
};

#endif // UPDATETRADEPRICESJOB_H
