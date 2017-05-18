#include "inclusion.h"
#include "ui_inclusion.h"

Inclusion::Inclusion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inclusion)
{
    ui->setupUi(this);
}

Inclusion::~Inclusion()
{
    delete ui;
}

void Inclusion::on_cancelB_clicked()
{
    emit cancel();
}

void Inclusion::on_pushButton_clicked()
{
    emit complete();
}
