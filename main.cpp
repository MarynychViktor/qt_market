#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QNetworkReply>


#include "pages/menu.h"
#include "ui/MainWindow.h"
#include "Infrastructure/DI/ServiceLocator.h"

void registerServices();
int main(int argc, char **argv)
{

    // TODO: review shared pointers instead of raw
    // !!!!
    QApplication app(argc, argv);
    registerServices();

    MainWindow mainWindow;
    mainWindow.show();

//    productRepository = make_shared<ProductRepository>(ProductRepository());

  return app.exec();
}

void registerServices()
{
    auto serviceLocator = ServiceLocator::Instance();

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