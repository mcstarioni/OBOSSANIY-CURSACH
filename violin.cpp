#include "violin.h"
#include "ui_violin.h"

Violin::Violin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Violin)
{
    ui->setupUi(this);
}

Violin::~Violin()
{
    delete ui;
}

void Violin::on_spinBox_valueChanged(int arg1)
{
    strings = arg1;
}

void Violin::on_comboBox_currentIndexChanged(int index)
{
    bow = index;
}
