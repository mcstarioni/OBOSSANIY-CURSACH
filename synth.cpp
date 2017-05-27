#include "synth.h"
#include "ui_synth.h"

Synth::Synth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Synth)
{
    ui->setupUi(this);
    voices = 0;
    keys = 0;
}

Synth::~Synth()
{
    delete ui;
}

void Synth::on_keysCount_valueChanged(int arg1)
{
    keys = arg1;
}

void Synth::on_spinBox_2_valueChanged(int arg1)
{
    voices = arg1;
}
