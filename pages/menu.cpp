#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QApplication* app, QWidget *parent) :
    QWidget(parent),
    application(app),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    connect(ui->ordersButton, &QPushButton::clicked, [this]() {
        ordersWindow = new OrdersWindow();
        ordersWindow->show();
        connect(ordersWindow, &QObject::destroyed, []() {
           qInfo("Destroyeddd");
        });
    });
    connect(ui->exitButton, &QPushButton::clicked, app, &QApplication::exit);
    setFixedSize(QSize(200, 270));
}

Menu::~Menu()
{
    delete ui;
}

QSize Menu::sizeHint() const {
    return QSize(500, 500);
}

void Menu::closeEvent(QCloseEvent *event) {
    if (ordersWindow != NULL) {
        ordersWindow->close();
    }

    event->accept();
}
