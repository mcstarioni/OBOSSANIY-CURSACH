#include "checkableform.h"
#include "ui_checkableform.h"
#include "boxins.h"
#include "groupform.h"
CheckableForm::CheckableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckableForm)
{
    ui->setupUi(this);
    isChecked = false;
    id = -1;
}
CheckableForm::~CheckableForm()
{
    delete widget;
    delete ui;
}
void CheckableForm::setWidget(QWidget *w)
{
    widget = w;
    ui->toShow->addWidget(w);
}

void CheckableForm::on_radioButton_toggled(bool checked)
{
    isChecked = checked;
    emit toggled(checked);
}
void CheckableForm::setButton(bool shown)
{
    ui->radioButton->setChecked(false);
    if(shown)
    {
        ui->radioButton->show();
    }
    else
    {
        ui->radioButton->hide();
    }
}
void CheckableForm::setEnabled(bool status)
{
    widget->setEnabled(status);
}
void CheckableForm::updateInclusions()
{
    if(isInstrument)
    {
        ((BoxIns*)widget)->updateIncl();
    }else
    {
        ((GroupForm*)widget)->updateIncl();
    }
}
void CheckableForm::change()
{
    if(isInstrument)
    {
        ((BoxIns*)widget)->change();
    }else
    {
        ((GroupForm*)widget)->change();
    }
}


