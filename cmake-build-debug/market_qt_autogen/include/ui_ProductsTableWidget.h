/********************************************************************************
** Form generated from reading UI file 'ProductsTableWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSTABLEWIDGET_H
#define UI_PRODUCTSTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductsTableWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *ProductsTableWidget)
    {
        if (ProductsTableWidget->objectName().isEmpty())
            ProductsTableWidget->setObjectName(QString::fromUtf8("ProductsTableWidget"));
        ProductsTableWidget->resize(658, 505);
        verticalLayout = new QVBoxLayout(ProductsTableWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(ProductsTableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(ProductsTableWidget);

        QMetaObject::connectSlotsByName(ProductsTableWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductsTableWidget)
    {
        ProductsTableWidget->setWindowTitle(QCoreApplication::translate("ProductsTableWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductsTableWidget: public Ui_ProductsTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSTABLEWIDGET_H
