#include "mainform.h"
#include "ui_mainform.h"
#include <QVector>
#include "addition.h"
#include "inclusion.h"
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    addition = new Addition;
    inclusion = new Inclusion;
    addition->hide();
    inclusion->hide();
    connect(addition,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(inclusion,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(addition,SIGNAL(additionComplete(CheckableForm*,int)),SLOT(on_additionComplete(CheckableForm*,int)));
    widgetLast = (QWidget*)addition;
    vectorW = new QVector<CheckableForm*>();
    vectorG = new QVector<CheckableForm*>();
    last = ui->addB;
    ui->actionLayout->addWidget(addition);
}

MainForm::~MainForm()
{
    delete inclusion;
    delete addition;
    delete ui;
}
void MainForm::on_inclusionB_clicked()
{

    last->setChecked(false);
    ui->inclusionB->setChecked(true);
    widgetLast->hide();
    inclusion->show();
    last = ui->inclusionB;

}

void MainForm::on_addB_clicked()
{
    last->setChecked(false);
    ui->addB->setChecked(true);
    widgetLast->hide();
    addition->show();
    last = ui->addB;
    ui->scrollArea->hide();
    ui->scrollArea_2->hide();
}

void MainForm::on_removeB_clicked()
{

    last->setChecked(false);
    ui->removeB->setChecked(true);
    widgetLast->hide();
    last = ui->removeB;
}

void MainForm::on_searchB_clicked()
{
    last->setChecked(false);
    ui->searchB->setChecked(true);
    widgetLast->hide();
    last = ui->searchB;
}

void MainForm::on_changeB_clicked()
{
    last->setChecked(false);
    ui->changeB->setChecked(true);
    widgetLast->hide();
    last = ui->changeB;
}
void MainForm::toSimpleView()
{
    last->setChecked(false);
    widgetLast->hide();
}

void MainForm::on_addB_toggled(bool checked)
{
    if(!checked)
    {
        ui->scrollArea->show();
        ui->scrollArea_2->show();
    }
}
void MainForm::on_additionComplete(CheckableForm* form, int type)
{

    if(type == 1)
    {
        ui->scrollW->layout()->addWidget(form);
        vectorW->push_back(form);

    }else
    {
        ui->scrollG->layout()->addWidget(form);
        vectorG->push_back(form);
    }
}
void MainForm::setSelectable(bool status)
{
    for(int i = 0; i < vectorW->size(); i++)
    {
        vectorW->at(i)->setButton(status);
    }
    for(int i = 0; i < vectorG->size(); i++)
    {
        vectorG->at(i)->setButton(status);
    }
}

