#include "drum.h"
#include "ui_drum.h"

Drum::Drum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Drum)
{
    ui->setupUi(this);
}

Drum::~Drum()
{
    delete ui;
}
