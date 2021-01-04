/********************************************************************************
** Form generated from reading UI file 'MarketManagementContent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKETMANAGEMENTCONTENT_H
#define UI_MARKETMANAGEMENTCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MarketManagementContent
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *marketManagement;
    QWidget *ordersTab;
    QHBoxLayout *ordersLayout;
    QVBoxLayout *ordersContent;
    QWidget *tradesTab;
    QHBoxLayout *tradesTab_2;
    QVBoxLayout *tradesContent;

    void setupUi(QWidget *MarketManagementContent)
    {
        if (MarketManagementContent->objectName().isEmpty())
            MarketManagementContent->setObjectName(QString::fromUtf8("MarketManagementContent"));
        MarketManagementContent->resize(400, 300);
        verticalLayout = new QVBoxLayout(MarketManagementContent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        marketManagement = new QTabWidget(MarketManagementContent);
        marketManagement->setObjectName(QString::fromUtf8("marketManagement"));
        ordersTab = new QWidget();
        ordersTab->setObjectName(QString::fromUtf8("ordersTab"));
        ordersLayout = new QHBoxLayout(ordersTab);
        ordersLayout->setObjectName(QString::fromUtf8("ordersLayout"));
        ordersContent = new QVBoxLayout();
        ordersContent->setObjectName(QString::fromUtf8("ordersContent"));

        ordersLayout->addLayout(ordersContent);

        marketManagement->addTab(ordersTab, QString());
        tradesTab = new QWidget();
        tradesTab->setObjectName(QString::fromUtf8("tradesTab"));
        tradesTab_2 = new QHBoxLayout(tradesTab);
        tradesTab_2->setObjectName(QString::fromUtf8("tradesTab_2"));
        tradesContent = new QVBoxLayout();
        tradesContent->setObjectName(QString::fromUtf8("tradesContent"));

        tradesTab_2->addLayout(tradesContent);

        marketManagement->addTab(tradesTab, QString());

        verticalLayout->addWidget(marketManagement);


        retranslateUi(MarketManagementContent);

        marketManagement->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MarketManagementContent);
    } // setupUi

    void retranslateUi(QWidget *MarketManagementContent)
    {
        MarketManagementContent->setWindowTitle(QCoreApplication::translate("MarketManagementContent", "Form", nullptr));
        marketManagement->setTabText(marketManagement->indexOf(ordersTab), QCoreApplication::translate("MarketManagementContent", "Orders", nullptr));
        marketManagement->setTabText(marketManagement->indexOf(tradesTab), QCoreApplication::translate("MarketManagementContent", "Trades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MarketManagementContent: public Ui_MarketManagementContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKETMANAGEMENTCONTENT_H
