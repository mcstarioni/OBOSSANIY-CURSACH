#include "eguitar.h"
#include "ui_eguitar.h"

EGuitar::EGuitar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EGuitar)
{
    ui->setupUi(this);
}

EGuitar::~EGuitar()
{
    delete ui;
}
