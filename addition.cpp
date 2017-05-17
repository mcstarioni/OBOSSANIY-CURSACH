#include "addition.h"
#include "ui_addition.h"
#include "boxins.h"
#include "groupform.h"

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
        //ui->widget = groupform;
    }
}
