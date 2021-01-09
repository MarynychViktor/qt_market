#include <Services/Logger.h>

#include <memory>
#include "MarketManagementContent.h"
#include "ui_MarketManagementContent.h"
#include "../Models/ProductTableModel.h"
#include "../Jobs/UpdateTradePricesJob.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include <QThread>
#include <Orders/OrdersContext.h>

MarketManagementContent::MarketManagementContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketManagementContent)
{
    productManager = ServiceLocator::Instance()->GetService<ProductManager>();

    ui->setupUi(this);
    ui->marketManagement->setTabEnabled(0, true);

    setMinimumWidth(1000);
    setMinimumHeight(500);
    setUp();
}

MarketManagementContent::~MarketManagementContent()
{
    delete ui;
}

void MarketManagementContent::setUp()
{
    setUpOrdersTable();
    setUpTradesTable();
}

void MarketManagementContent::setUpTradesTable() {
    auto serviceLocator = ServiceLocator::Instance();
    auto repository = serviceLocator->GetService<ProductRepository>();
    auto context = serviceLocator->GetService<TradesContext>();

    trades = new ProductsTableWidget(this);

    auto productModel = new ProductTableModel(QList<shared_ptr<Product>>());
    trades->setModel(productModel);
    ui->tradesContent->addWidget(trades);

    connect(ui->tradesRefresh, &QPushButton::clicked, [this, serviceLocator]() {
        auto repository = serviceLocator->GetService<ProductManager>();
        auto model = new ProductTableModel(repository->getProducts());
        trades->setModel(model);
    });

    connect(context.get(), &TradesContext::tradesChanged, [this, context]() {
        auto model = new ProductTableModel(context->snapshot);
        trades->setModel(model);
    });
}


void MarketManagementContent::setUpOrdersTable() {
    auto serviceLocator = ServiceLocator::Instance();
    auto repository = serviceLocator->GetService<ProductRepository>();
    auto context = serviceLocator->GetService<OrdersContext>();

    orders = new ProductsTableWidget(this);

    auto productModel = new ProductTableModel(QList<shared_ptr<Product>>());
    orders->setModel(productModel);
    ui->ordersContent->addWidget(orders);

    connect(ui->ordersRefresh, &QPushButton::clicked, [this, serviceLocator]() {
        auto repository = serviceLocator->GetService<ProductRepository>();
        auto model = new ProductTableModel(repository->getProducts());
        orders->setModel(model);
    });

    connect(context.get(), &OrdersContext::ordersChanged, [this, context]() {
        auto model = new ProductTableModel(context->snapshot);
        orders->setModel(model);
    });

//    connect(context.get(), &OrdersContext::ordersAdded, [this, context, serviceLocator](QList<QString> productIds) {
//        auto repository = serviceLocator->GetService<ProductManager>();
//        orders->model->addProducts(repository->getProductsByIds(productIds));
//    });
}

