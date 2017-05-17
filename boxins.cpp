#include "boxins.h"
#include "ui_boxins.h"

BoxIns::BoxIns(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BoxIns)
{
    ui->setupUi(this);
}

BoxIns::~BoxIns()
{
    delete ui;
}
