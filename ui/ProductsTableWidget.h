#ifndef ORDERSWINDOW_H
#define ORDERSWINDOW_H

#include <QAbstractItemModel>
#include <QWidget>
#include <Models/ProductTableModel.h>

namespace Ui {
class ProductsTableWidget;
}

class ProductsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductsTableWidget(QWidget *parent = nullptr);
    void setModel(ProductTableModel *model);
    ProductTableModel *model;
    ~ProductsTableWidget();

private:
    Ui::ProductsTableWidget *ui;
};

#endif // ORDERSWINDOW_H
