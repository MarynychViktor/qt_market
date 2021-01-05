#include "MarketManagementContent.h"
#include "ui_MarketManagementContent.h"
#include "../Models/ProductTableModel.h"
#include "../Jobs/UpdateTradePricesJob.h"
#include "../Infrastructure/DI/ServiceLocator.h"

MarketManagementContent::MarketManagementContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketManagementContent)
{
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
    setUpTradesTable();
}

void MarketManagementContent::setUpTradesTable() {
    auto serviceLocator = ServiceLocator::Instance();
    auto repository = serviceLocator->GetService<ProductRepository>();

    trades = new ProductsTableWidget(this);

    auto productModel = new ProductTableModel(repository->getProducts());
    trades->setModel(productModel);
    ui->tradesContent->addWidget(trades);

    connect(ui->tradesRefresh, &QPushButton::clicked, [this, serviceLocator]() {
        auto repository = serviceLocator->GetService<ProductRepository>();
        auto model = new ProductTableModel(repository->getProducts());
        trades->setModel(model);
    });

}

