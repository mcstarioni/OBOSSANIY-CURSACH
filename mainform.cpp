#include "mainform.h"
#include "ui_mainform.h"
#include <QVector>
#include <addition.h>
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    addition = new Addition;
    widgetLast = (QWidget*)addition;
//    this->vectorW = new QVector<QWidget*>();
    last = ui->addB;
    ui->actionLayout->addWidget(addition);
}

MainForm::~MainForm()
{
    delete addition;
    delete ui;
}
void MainForm::on_inclusionB_clicked()
{
    last->setChecked(false);
    ui->inclusionB->setChecked(true);
    widgetLast->hide();
    last = ui->inclusionB;
}

void MainForm::on_addB_clicked()
{
    last->setChecked(false);
    ui->addB->setChecked(true);
    widgetLast->hide();
    addition->show();
    last = ui->addB;
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
