/********************************************************************************
** Form generated from reading UI file 'orderswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSWINDOW_H
#define UI_ORDERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrdersWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *OrdersWindow)
    {
        if (OrdersWindow->objectName().isEmpty())
            OrdersWindow->setObjectName(QString::fromUtf8("OrdersWindow"));
        OrdersWindow->resize(658, 505);
        verticalLayout = new QVBoxLayout(OrdersWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(OrdersWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(OrdersWindow);

        QMetaObject::connectSlotsByName(OrdersWindow);
    } // setupUi

    void retranslateUi(QWidget *OrdersWindow)
    {
        OrdersWindow->setWindowTitle(QCoreApplication::translate("OrdersWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrdersWindow: public Ui_OrdersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSWINDOW_H
