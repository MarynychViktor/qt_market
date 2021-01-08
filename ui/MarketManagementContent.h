#ifndef MARKETMANAGEMENTCONTENT_H
#define MARKETMANAGEMENTCONTENT_H

#include <QWidget>
#include <Trades/TradesContext.h>
#include <Services/ProductManager.h>
#include "ProductsTableWidget.h"

namespace Ui {
class MarketManagementContent;
}

class MarketManagementContent : public QWidget
{
Q_OBJECT
public:
    explicit MarketManagementContent(QWidget *parent = nullptr);
    ~MarketManagementContent();

    void setUp();
    void setUpTradesTable();
    void setUpOrdersTable();
private:
    Ui::MarketManagementContent *ui;
    ProductsTableWidget *trades;
    ProductsTableWidget *orders;
    shared_ptr<ProductManager> productManager;
};

#endif // MARKETMANAGEMENTCONTENT_H
