#ifndef ORDERSWINDOW_H
#define ORDERSWINDOW_H

#include <QAbstractItemModel>
#include <QWidget>

namespace Ui {
class OrdersWindow;
}

class OrdersWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OrdersWindow(QWidget *parent = nullptr);
    void setModel(QAbstractItemModel *model);
    ~OrdersWindow();

private:
    Ui::OrdersWindow *ui;
};

#endif // ORDERSWINDOW_H
