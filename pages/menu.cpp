#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QApplication* app, QWidget *parent) :
    QWidget(parent),
    application(app),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, app, &QApplication::exit);
    setFixedSize(QSize(300, 500));
}

Menu::~Menu()
{
    delete ui;
}

QSize Menu::sizeHint() const {
    return QSize(500, 500);
}
