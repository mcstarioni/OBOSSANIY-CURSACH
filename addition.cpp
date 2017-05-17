#include "addition.h"
#include "ui_addition.h"

Addition::Addition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addition)
{
    ui->setupUi(this);
}

Addition::~Addition()
{
    delete ui;
}
