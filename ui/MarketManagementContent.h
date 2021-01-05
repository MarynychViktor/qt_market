#ifndef MARKETMANAGEMENTCONTENT_H
#define MARKETMANAGEMENTCONTENT_H

#include <QWidget>
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
private:
    Ui::MarketManagementContent *ui;
    ProductsTableWidget *trades;
    ProductsTableWidget *orders;
};

#endif // MARKETMANAGEMENTCONTENT_H
