#include "plates.h"
#include "ui_plates.h"

Plates::Plates(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plates)
{
    ui->setupUi(this);
}

Plates::~Plates()
{
    delete ui;
}

void Plates::on_spinBox_valueChanged(int arg1)
{
    bpm = arg1;
}

void Plates::on_diamTitle_valueChanged(int arg1)
{
    diameter = arg1;
}
