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
