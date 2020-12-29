#include "orderswindow.h"
#include "ui_orderswindow.h"

OrdersWindow::OrdersWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrdersWindow)
{
    ui->setupUi(this);
    ui->tableView->setSortingEnabled(true);
}

OrdersWindow::~OrdersWindow()
{
    delete ui;
}

void OrdersWindow::setModel(QAbstractItemModel *model)
{
    ui->tableView->setModel(model);
    QObject::connect(ui->tableView->horizontalHeader(), &QHeaderView::sortIndicatorChanged, ui->tableView, [this](int col, Qt::SortOrder order) {
        ui->tableView->sortByColumn(col, order);
    });
}
