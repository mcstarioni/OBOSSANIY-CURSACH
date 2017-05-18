#include "checkableform.h"
#include "ui_checkableform.h"
#include "boxins.h"
#include "groupform.h"
CheckableForm::CheckableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckableForm)
{
    ui->setupUi(this);

}
CheckableForm::~CheckableForm()
{
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
    if(shown)
    {
        ui->radioButton->show();
    }
    else
    {
        ui->radioButton->hide();
    }
    ui->radioButton->setChecked(false);
}

void CheckableForm::setEnabled(bool status)
{
    widget->setEnabled(status);
}
void CheckableForm::updateInclusions()
{
    if(isInstrument)
    {
        qDebug()<<"updated 2";
        ((BoxIns*)widget)->updateIncl();
    }else
    {
        qDebug()<<"updated 2";
        ((GroupForm*)widget)->updateIncl();
    }
}


