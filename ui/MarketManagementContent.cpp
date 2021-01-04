#include "MarketManagementContent.h"
#include "ui_MarketManagementContent.h"
#include "../models/producttablemodel.h"

MarketManagementContent::MarketManagementContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketManagementContent)
{
    ui->setupUi(this);
    ui->marketManagement->setTabEnabled(0, true);

    setMinimumWidth(1000);
    setMinimumHeight(500);

    trades = new ProductsTableWidget();
    QAbstractItemModel *model = new ProductTableModel();
    trades->setModel(model);
    ui->tradesContent->addWidget(trades);
}

MarketManagementContent::~MarketManagementContent()
{
    delete ui;
}
