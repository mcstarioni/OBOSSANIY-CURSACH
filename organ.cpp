#include "organ.h"
#include "ui_organ.h"

Organ::Organ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Organ)
{
    ui->setupUi(this);
}

Organ::~Organ()
{
    delete ui;
}

void Organ::on_keysCount_valueChanged(int arg1)
{
    keys = arg1;
}

void Organ::on_spinBox_2_valueChanged(int arg1)
{
    pipes = arg1;
}
