#include "groupform.h"
#include "ui_groupform.h"

GroupForm::GroupForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupForm)
{
    ui->setupUi(this);
}

GroupForm::~GroupForm()
{
    delete ui;
}
