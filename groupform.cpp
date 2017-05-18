#include "groupform.h"
#include "ui_groupform.h"
#include "manager.h"
GroupForm::GroupForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupForm)
{
    manager = Manager::getInstance();
    connect(manager,SIGNAL(createdGrp(int)),SLOT(createdGroup(int)) );
    ui->setupUi(this);
}

void GroupForm::createGroup()
{
    manager->createGroup(ui->lineEdit->text());
}

GroupForm::~GroupForm()
{
    delete ui;
}
void GroupForm::createdGroup(int index)
{
    this->index = index;
}
