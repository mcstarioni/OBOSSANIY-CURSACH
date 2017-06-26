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
    change = new Change();
    search = new Search();
    simple = new QWidget();
    addition->hide();
    inclusion->hide();
    remove->hide();
    change->hide();
    search->hide();
    connect(addition,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(inclusion,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(remove,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(change,SIGNAL(cancel()),SLOT(toSimpleView()));
    connect(search,SIGNAL(cancel()),SLOT(toSimpleView()));

    connect(addition,SIGNAL(additionComplete(CheckableForm*,int)),SLOT(on_additionComplete(CheckableForm*,int)));
    connect(inclusion,SIGNAL(complete()),SLOT(on_inclusionComplete()));
    connect(remove,SIGNAL(complete()),SLOT(on_removalComplete()));
    connect(change,SIGNAL(startEdition()),SLOT(on_changeStarted()));
    connect(change,SIGNAL(complete()),SLOT(on_changeComplete()));

    lastWidget = (QWidget*)addition;
    allFormsIns = new QVector<CheckableForm*>();
    allFormsGroup = new QVector<CheckableForm*>();
    toggledIns = new QVector<CheckableForm*>();
    toggledGroup = new QVector<CheckableForm*>();
    lastButton = ui->simpleB;
    ui->actionLayout->addWidget(addition);
    ui->actionLayout->addWidget(inclusion);
    ui->actionLayout->addWidget(remove);
    ui->actionLayout->addWidget(change);
    ui->actionLayout->addWidget(search);
    ui->actionLayout->addWidget(simple);
}

MainForm::~MainForm()
{
    delete toggledIns;
    delete toggledGroup;
    delete allFormsIns;
    delete allFormsGroup;
    delete inclusion;
    delete addition;
    delete remove;
    delete change;
    delete search;
    delete ui;
}
void MainForm::on_inclusionB_clicked()
{
    nextMenuButtonClicked(qobject_cast<QPushButton*>(sender()),inclusion);
    clearToggledVectors();
}

void MainForm::on_addB_clicked()
{
    nextMenuButtonClicked(qobject_cast<QPushButton*>(sender()),addition);
}

void MainForm::on_removeB_clicked()
{
    nextMenuButtonClicked(qobject_cast<QPushButton*>(sender()),remove);
    clearToggledVectors();
}

void MainForm::on_searchB_clicked()
{
    nextMenuButtonClicked(qobject_cast<QPushButton*>(sender()),search);
}

void MainForm::on_changeB_clicked()
{
    nextMenuButtonClicked(qobject_cast<QPushButton*>(sender()),change);
    clearToggledVectors();
}

void MainForm::on_simpleB_clicked()
{
    toSimpleView();
}

void MainForm::toSimpleView()
{
    nextMenuButtonClicked(ui->simpleB,simple);
    setSelectable(false);
}

void MainForm::on_addB_toggled(bool checked)
{
    qDebug()<<"AB_"<<checked;
    if(lastWidget != search)
    {
    showScrollAreas(!checked);
    }
}

void MainForm::on_additionComplete(CheckableForm* form, int type)
{

    connect(form,SIGNAL(toggled(bool)),SLOT(formToggled(bool)));
    if(type == 1)
    {
        ui->scrollIns->layout()->addWidget(form);
        allFormsIns->push_back(form);

    }else
    {
        ui->scrollGroup->layout()->addWidget(form);
        allFormsGroup->push_back(form);
    }
}

void MainForm::setSelectable(bool status)
{
    for(int i = 0; i < allFormsIns->size(); i++)
    {
        allFormsIns->at(i)->setButton(status);
    }
    for(int i = 0; i < allFormsGroup->size(); i++)
    {
        allFormsGroup->at(i)->setButton(status);
    }
}

void MainForm::on_inclusionComplete()
{
    for(int i = 0; i < toggledGroup->size(); i++)
    {
        for(int j = 0; j < toggledIns->size(); j++)
        {
            Manager::getInstance()->includeIns(toggledIns->at(j)->id,toggledGroup->at(i)->id);
        }
    }
    for(int i = 0; i < toggledGroup->size(); i++)
    {
        toggledGroup->at(i)->updateInclusions();
    }
    for(int j = 0; j < toggledIns->size(); j++)
    {
        toggledIns->at(j)->updateInclusions();
    }
    toSimpleView();
}

void MainForm::formToggled(bool toggle)
{
    CheckableForm* form = qobject_cast<CheckableForm*>(sender());
    if(toggle)
    {
        if(form->isInstrument)
        {
            toggledIns->push_back(form);
        }
        else
        {
            toggledGroup->push_back(form);
        }
    }
    else
    {
        if(form->isInstrument)
        {
            if(toggledIns->contains(form))
            {
                toggledIns->removeOne(form);
            }
        }
        else
        {
            if(toggledGroup->contains(form))
            {
                toggledGroup->removeOne(form);
            }
        }
    }
}

void MainForm::on_removalComplete()
{

    for(int i = 0; i < toggledIns->size(); i++)
    {
        CheckableForm* deleted = toggledIns->at(i);
        Manager::getInstance()->removeInstrument(deleted->id);
        allFormsIns->removeOne(deleted);
        delete deleted;
    }
    for(int i = 0; i < toggledGroup->size(); i++)
    {
        CheckableForm* deleted = toggledGroup->at(i);
        Manager::getInstance()->removeGroup(deleted->id);
        allFormsGroup->removeOne(toggledGroup->at(i));
        delete deleted;
    }
    for(int i = 0; i < allFormsIns->size(); i++)
    {
        allFormsIns->at(i)->updateInclusions();
    }
    for(int i = 0; i < allFormsGroup->size(); i++)
    {
        allFormsIns->at(i)->updateInclusions();
    }
    clearToggledVectors();
}

void MainForm::on_changeComplete()
{
    for(int i = 0; i < toggledIns->size(); i++)
    {
        toggledIns->at(i)->change();
    }
    for(int i = 0; i < toggledGroup->size(); i++)
    {
        toggledGroup->at(i)->change();
    }
    clearToggledVectors();
    toSimpleView();
}

void MainForm::on_changeStarted()
{
    for(int i = 0; i < toggledIns->size(); i++)
    {
        toggledIns->at(i)->setEnabled(true);
    }
    for(int i = 0; i < toggledGroup->size(); i++)
    {
        toggledGroup->at(i)->setEnabled(true);
    }
    setSelectable(false);
}

void MainForm::on_searchComplete()
{
//    for(int i = 0; i < toggledIns->size(); i++)
//    {
//        toggledIns->at(i)->setEnabled(true);
//    }
//    for(int i = 0; i < toggledGroup->size(); i++)
//    {
//        toggledGroup->
}

void MainForm::showScrollAreas(bool show)
{
    if(show)
    {
        ui->scrollArea->show();
        ui->scrollArea_2->show();
    }
    else
    {
        ui->scrollArea->hide();
        ui->scrollArea_2->hide();
    }
}

void MainForm::nextMenuButtonClicked(QPushButton* nextMenuButton, QWidget *nextMenu)
{
    nextMenuButton->setChecked(true);
    lastButton->setChecked(false);
    lastButton = nextMenuButton;
    lastWidget->hide();
    lastWidget = nextMenu;
    lastWidget->show();
}

void MainForm::clearToggledVectors()
{
    toggledGroup->clear();
    toggledIns->clear();
}

void MainForm::on_searchB_toggled(bool checked)
{
    qDebug()<<"SB_"<<checked;
    if(lastWidget != addition)
    {
        showScrollAreas(!checked);
    }
}
