#include "addition.h"
#include "ui_addition.h"
#include "boxins.h"
#include "groupform.h"
#include "checkableform.h"
#include <QDebug>
#include <QPushButton>
Addition::Addition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addition)
{
    ui->setupUi(this);
    insform = 0;
    groupform = 0;
    last = ui->createIns;
}

Addition::~Addition()
{
    delete groupform;
    delete insform;
    delete ui;
}
void Addition::on_comboBox_currentIndexChanged(int index)
{
    if(insform !=0 && ui->createIns->isChecked() == true)
    {
        insform->classChanged(index);
    }
}

void Addition::on_cancel_clicked()
{
    emit cancel();
}

void Addition::on_accept_clicked()
{

    int type = 1;
    CheckableForm *form = new CheckableForm();
    if(insform !=0 && insform->isHidden() == false)
    {
        insform->createIns();
        form->setWidget(insform);
        form->id = insform->id;
        form->isInstrument = true;
        insform = 0;
    }
    else
    {
        if(groupform != 0 && groupform->isHidden() == false)
        {
            groupform->createGroup();
            form->setWidget(groupform);
            form->id = groupform->id;
            form->isInstrument = false;
            groupform = 0;
            type = 2;
        }else
        {
            return;
        }
    }
    form->setEnabled(false);
    form->setButton(false);
    emit additionComplete(form, type);
}

void Addition::on_createIns_clicked()
{
    last->setChecked(false);
    last = ui->createIns;
    last->setChecked(true);
    if(groupform != 0)
    {
        groupform->hide();
    }
    if(insform == 0)
    {

        insform = new BoxIns(ui->comboBox->currentIndex());
        qDebug()<<"New InsForm "<<insform;
        ui->additionLayout->addWidget(insform);
    }
    insform->show();
}

void Addition::on_createGroup_clicked()
{
    last->setChecked(false);
    last = ui->createGroup;
    last->setChecked(true);
    if(insform != 0)
    {
        insform->hide();
    }
    if(groupform == 0)
    {
        groupform = new GroupForm();
        qDebug()<<"New groupform "<<insform;
        ui->additionLayout->addWidget(groupform);
    }
    groupform->show();
}
