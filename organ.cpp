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
