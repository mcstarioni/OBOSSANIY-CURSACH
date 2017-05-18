#include "mainform.h"
#include "ui_mainform.h"
#include <QVector>
#include "addition.h"
#include "inclusion.h"
#include "manager.h"
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    addition = new Addition;
    inclusion = new Inclusion;
    remove = new removal();
    addition->hide();
    inclusion->hide();
    remove->hide();
    connect(addition,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(inclusion,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(remove,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(addition,SIGNAL(additionComplete(CheckableForm*,int)),SLOT(on_additionComplete(CheckableForm*,int)));
    connect(inclusion,SIGNAL(complete()),SLOT(on_inclusionComplete()));
    connect(remove,SIGNAL(complete()),SLOT(on_removalComplete()));
    widgetLast = (QWidget*)addition;
    vectorW = new QVector<CheckableForm*>();
    vectorG = new QVector<CheckableForm*>();
    toggledW = new QVector<CheckableForm*>();
    toggledG = new QVector<CheckableForm*>();
    last = ui->pushButton;
    ui->actionLayout->addWidget(addition);
    ui->actionLayout->addWidget(inclusion);
    ui->actionLayout->addWidget(remove);
}

MainForm::~MainForm()
{
    delete toggledW;
    delete toggledG;
    delete vectorW;
    delete vectorG;
    delete inclusion;
    delete addition;
    delete remove;
    delete ui;
}
void MainForm::on_inclusionB_clicked()
{

    last->setChecked(false);
    ui->inclusionB->setChecked(true);
    widgetLast->hide();
    inclusion->show();
    setSelectable(true);
    last = ui->inclusionB;
    widgetLast = inclusion;

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
    widgetLast = addition;
}

void MainForm::on_removeB_clicked()
{

    last->setChecked(false);
    ui->removeB->setChecked(true);
    widgetLast->hide();
    remove->show();
    setSelectable(true);
    last = ui->removeB;
    widgetLast = remove;
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
    last = ui->pushButton;
    setSelectable(false);
    widgetLast->hide();
}

void MainForm::on_addB_toggled(bool checked)
{
    if(!checked)
    {
        //toSimpleView();
        ui->scrollArea->show();
        ui->scrollArea_2->show();
    }
}
void MainForm::on_additionComplete(CheckableForm* form, int type)
{
    connect(form,SIGNAL(toggled(bool)),SLOT(formToggled(bool)));
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
void MainForm::on_inclusionComplete()
{
    for(int i = 0; i < toggledG->size(); i++)
    {
        for(int j = 0; j < toggledW->size(); j++)
        {
            Manager::getInstance()->includeIns(toggledW->at(j)->id,toggledG->at(i)->id);
        }
    }
    for(int i = 0; i < toggledG->size(); i++)
    {
        qDebug()<<"updated";
        toggledG->at(i)->updateInclusions();
    }
    for(int j = 0; j < toggledW->size(); j++)
    {
        qDebug()<<"updated";
        toggledW->at(j)->updateInclusions();
    }
    toggledG->clear();
    toggledW->clear();
    toSimpleView();
}


void MainForm::formToggled(bool toggle)
{
    CheckableForm* form = qobject_cast<CheckableForm*>(sender());
    if(toggle)
    {
        if(form->isInstrument)
        {
            toggledW->push_back(form);
        }
        else
        {
            toggledG->push_back(form);
        }
    }
    else
    {
        if(form->isInstrument)
        {
            if(toggledW->contains(form))
            {
                toggledW->removeOne(form);
            }
        }
        else
        {
            if(toggledG->contains(form))
            {
                toggledG->removeOne(form);
            }
        }
    }
}

void MainForm::on_pushButton_clicked()
{
    toSimpleView();
}
void MainForm::on_removalComplete()
{
    for(int i = 0; i < toggledW->size(); i++)
    {
        Manager::getInstance()->removeInstrument(toggledW->at(i)->id);
        vectorW->removeOne(toggledW->at(i));
        delete toggledW->at(i);
    }
    for(int i = 0; i < toggledG->size(); i++)
    {
        Manager::getInstance()->removeGroup(toggledG->at(i)->id);
        vectorG->removeOne(toggledG->at(i));
        delete toggledG->at(i);
    }
    for(int i = 0; i < vectorW->size(); i++)
    {
        vectorW->at(i)->updateInclusions();
    }
    for(int i = 0; i < vectorG->size(); i++)
    {
        vectorW->at(i)->updateInclusions();
    }
}

