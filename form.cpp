#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->pushButton2, &QPushButton::clicked, []() {
        qInfo("Button 1 clicked");
    });
}

Form::~Form()
{
    delete ui;
}

