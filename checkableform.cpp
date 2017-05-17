#include "checkableform.h"
#include "ui_checkableform.h"

CheckableForm::CheckableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckableForm)
{
    ui->setupUi(this);
}

CheckableForm::~CheckableForm()
{
    delete ui;
}
