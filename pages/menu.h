#ifndef MENU_H
#define MENU_H

#include "../ui/ProductsTableWidget.h"

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    ~Menu();

//    QApplication* application;
//    OrdersWindow* ordersWindow;

protected:
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::Menu *ui;
};

#endif // MENU_H
