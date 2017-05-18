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
    id = index;
}
void GroupForm::updateIncl()
{
    qDebug()<<"updated 3";
    ui->listWidget->clear();
    Group *group = Manager::getInstance()->getByIdG(id);
    QVector<Instruments*>* vec = group->getInstruments();
    for(int i = 0; i < vec->size(); i++)
    {
        QString str = QString::number(vec->at(i)->Id());
        str = "Type: "+vec->at(i)->getTypeName()+" id: " + str + ", name: " + vec->at(i)->getName();
        qDebug()<<str;
        ui->listWidget->addItem(str);
    }
}
