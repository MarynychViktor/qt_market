#include "ProductsTableWidget.h"
#include "ui_ProductsTableWidget.h"

#include "../Models/ProductTableModel.h"

#include <QSizePolicy>

ProductsTableWidget::ProductsTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductsTableWidget)
{
    ui->setupUi(this);
    ui->tableView->setSortingEnabled(true);

    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

ProductsTableWidget::~ProductsTableWidget()
{
    delete ui;
}

void ProductsTableWidget::setModel(QAbstractItemModel *model)
{
    ui->tableView->setModel(model);
    QObject::connect(ui->tableView->horizontalHeader(), &QHeaderView::sortIndicatorChanged, ui->tableView, [this](int col, Qt::SortOrder order) {
        ui->tableView->sortByColumn(col, order);
    });
}
