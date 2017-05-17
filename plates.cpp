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
