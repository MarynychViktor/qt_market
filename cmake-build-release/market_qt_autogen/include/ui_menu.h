/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *ordersButton;
    QPushButton *pushButton;
    QPushButton *exitButton;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(305, 411);
        verticalLayout_2 = new QVBoxLayout(Menu);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 150));
        label->setMaximumSize(QSize(16777215, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/csgo-wallpaper.jpg")));
        label->setScaledContents(true);

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ordersButton = new QPushButton(Menu);
        ordersButton->setObjectName(QString::fromUtf8("ordersButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/shopping-bag-svg"), QSize(), QIcon::Normal, QIcon::Off);
        ordersButton->setIcon(icon);

        verticalLayout->addWidget(ordersButton);

        pushButton = new QPushButton(Menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/trading.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        verticalLayout->addWidget(pushButton);

        exitButton = new QPushButton(Menu);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/logout.svg"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon2);

        verticalLayout->addWidget(exitButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        label->setText(QString());
        ordersButton->setText(QCoreApplication::translate("Menu", "Orders", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "Trades", nullptr));
        exitButton->setText(QCoreApplication::translate("Menu", "Exit     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
