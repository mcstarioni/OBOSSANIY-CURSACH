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

void Drum::on_bpm_valueChanged(int arg1)
{
    bpm = arg1;
}

void Drum::on_radioButton_toggled(bool checked)
{
    isOpen = checked;
}
