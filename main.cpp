#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QNetworkReply>
#include <Trades/TradesContext.h>
#include <Orders/OrdersContext.h>


#include "pages/menu.h"
#include "ui/MainWindow.h"
#include "Infrastructure/DI/ServiceLocator.h"
#include "Models/Product.h"
using namespace std;

void registerServices();
int main(int argc, char **argv)
{

    // TODO: review shared pointers instead of raw
    // !!!!
    QApplication app(argc, argv);
    qRegisterMetaType<QList<QString>>();
    registerServices();

    MainWindow mainWindow;
    mainWindow.show();

//    productRepository = make_shared<ProductRepository>(ProductRepository());

  return app.exec();
}

void registerServices()
{
    auto serviceLocator = ServiceLocator::Instance();

    serviceLocator->Register<TradesContext>(make_shared<TradesContext>());
    serviceLocator->Register<OrdersContext>(make_shared<OrdersContext>());
    serviceLocator->Register<ProductRepository>(make_shared<ProductRepository>());
    serviceLocator->Register<ProductManager>(make_shared<ProductManager>(serviceLocator->GetService<ProductRepository>()));
    serviceLocator->Register<WorkerManager>(make_shared<WorkerManager>());
    serviceLocator->Register<MarketSettings>(make_shared<MarketSettings>());
    serviceLocator->Register<SyncHttpClient>([]() { return make_shared<SyncHttpClient>(); });
    serviceLocator->Register<MarketHttpClient>([serviceLocator]() {
        return make_shared<MarketHttpClient>(
                serviceLocator->GetService<SyncHttpClient>(),
                serviceLocator->GetService<MarketSettings>()
            );
    });
}