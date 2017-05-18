#include "addition.h"
#include "ui_addition.h"
#include "boxins.h"
#include "groupform.h"
#include "checkableform.h"
#include <QDebug>
Addition::Addition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addition)
{
    ui->setupUi(this);
    insform = 0;
    groupform = 0;
    addPressed = false;
}

Addition::~Addition()
{
    delete groupform;
    delete insform;
    delete ui;
}

void Addition::on_createIns_toggled(bool checked)
{
    if(checked)
    {
        if(groupform != 0)
        {
            groupform->hide();
        }
        ui->createGroup->setChecked(false);
        if(insform == 0)
        {
            insform = new BoxIns(ui->comboBox->currentIndex());
            ui->additionLayout->addWidget(insform);
            qDebug()<<"togled";
        }
        insform->show();
    }
}

void Addition::on_createGroup_toggled(bool checked)
{
    if(checked)
    {
        if(insform != 0)
        {
            insform->hide();
        }
        ui->createIns->setChecked(false);
        if(groupform == 0)
        {
            groupform = new GroupForm();
            ui->additionLayout->addWidget(groupform);

        }
        groupform->show();
    }
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
    qDebug()<<"inAccept 1";
    int type = 1;
    CheckableForm *form = new CheckableForm();
    if(insform !=0 && insform->isHidden() == false)
    {
        qDebug()<<"inAccept 2";
        insform->createIns();
        form->setWidget(insform);
        form->id = insform->id;
        form->isInstrument = true;
        insform = 0;
        qDebug()<<"inAccept 3";

    }
    else
    {
        if(groupform != 0 && groupform->isHidden() == false)
        {
            groupform->createGroup();
            form->setWidget(groupform);
            form->id = groupform->index;
            form->isInstrument = false;
            groupform = 0;
            type = 2;
        }
    }
    form->setEnabled(false);
    form->setButton(false);
    qDebug()<<"inAccept 4";
    emit additionComplete(form, type);
}
