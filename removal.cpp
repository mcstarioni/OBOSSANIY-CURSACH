#include "removal.h"
#include "ui_removal.h"

removal::removal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removal)
{
    ui->setupUi(this);
}

removal::~removal()
{
    delete ui;
}

void removal::on_pushButton_2_clicked()
{
    emit cancel();
}

void removal::on_pushButton_clicked()
{
    emit complete();
}
