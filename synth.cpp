#include "synth.h"
#include "ui_synth.h"

Synth::Synth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Synth)
{
    ui->setupUi(this);
}

Synth::~Synth()
{
    delete ui;
}
