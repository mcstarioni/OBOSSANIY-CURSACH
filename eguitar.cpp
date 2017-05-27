#include "eguitar.h"
#include "ui_eguitar.h"

EGuitar::EGuitar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EGuitar)
{
    ui->setupUi(this);
    strings = 0;
    pickup = 0;
}

EGuitar::~EGuitar()
{
    delete ui;
}

void EGuitar::on_spinBox_valueChanged(int arg1)
{
    strings = arg1;
}

void EGuitar::on_comboBox_currentIndexChanged(int index)
{
    pickup = index;
}
