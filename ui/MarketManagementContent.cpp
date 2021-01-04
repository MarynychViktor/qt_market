#include "MarketManagementContent.h"
#include "ui_MarketManagementContent.h"
#include "../models/producttablemodel.h"
#include "../jobs/updatetradepricesjob.h"

MarketManagementContent::MarketManagementContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketManagementContent)
{
    ui->setupUi(this);
    ui->marketManagement->setTabEnabled(0, true);

    setMinimumWidth(1000);
    setMinimumHeight(500);

    trades = new ProductsTableWidget();

    ProductRepository repository;
    auto model = new ProductTableModel();
    model->setProducts(repository.getProducts());
    trades->setModel(model);
    ui->tradesContent->addWidget(trades);

    connect(ui->tradesRefresh, &QPushButton::clicked, [this]() {
        ProductRepository repository;
        auto model = new ProductTableModel();
        model->setProducts(repository.getProducts());
        trades->setModel(model);
    });
}

MarketManagementContent::~MarketManagementContent()
{
    delete ui;
}
