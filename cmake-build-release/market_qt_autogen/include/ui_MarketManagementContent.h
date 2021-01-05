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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *tradesWrapper;
    QHBoxLayout *tradesHeader;
    QPushButton *tradesRefresh;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *tradesContent;

    void setupUi(QWidget *MarketManagementContent)
    {
        if (MarketManagementContent->objectName().isEmpty())
            MarketManagementContent->setObjectName(QString::fromUtf8("MarketManagementContent"));
        MarketManagementContent->resize(993, 766);
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
        tradesWrapper = new QVBoxLayout();
        tradesWrapper->setSpacing(6);
        tradesWrapper->setObjectName(QString::fromUtf8("tradesWrapper"));
        tradesWrapper->setSizeConstraint(QLayout::SetDefaultConstraint);
        tradesHeader = new QHBoxLayout();
        tradesHeader->setSpacing(0);
        tradesHeader->setObjectName(QString::fromUtf8("tradesHeader"));
        tradesHeader->setSizeConstraint(QLayout::SetDefaultConstraint);
        tradesRefresh = new QPushButton(tradesTab);
        tradesRefresh->setObjectName(QString::fromUtf8("tradesRefresh"));

        tradesHeader->addWidget(tradesRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tradesHeader->addItem(horizontalSpacer);


        tradesWrapper->addLayout(tradesHeader);

        tradesContent = new QVBoxLayout();
        tradesContent->setSpacing(10);
        tradesContent->setObjectName(QString::fromUtf8("tradesContent"));
        tradesContent->setSizeConstraint(QLayout::SetDefaultConstraint);

        tradesWrapper->addLayout(tradesContent);

        tradesWrapper->setStretch(0, 1);
        tradesWrapper->setStretch(1, 25);

        tradesTab_2->addLayout(tradesWrapper);

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
        tradesRefresh->setText(QCoreApplication::translate("MarketManagementContent", "Refresh", nullptr));
        marketManagement->setTabText(marketManagement->indexOf(tradesTab), QCoreApplication::translate("MarketManagementContent", "Trades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MarketManagementContent: public Ui_MarketManagementContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKETMANAGEMENTCONTENT_H
