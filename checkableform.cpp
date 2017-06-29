#include "checkableform.h"
#include "ui_checkableform.h"
#include "boxins.h"
#include "groupform.h"
CheckableForm::CheckableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckableForm)
{
    ui->setupUi(this);
    setButton(false);
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
void CheckableForm::setButton(bool shown)
{

    ui->selectionButton->setChecked(false);
    if(shown)
    {
        ui->selectionButton->show();
    }
    else
    {
        ui->selectionButton->hide();
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

void CheckableForm::on_selectionButton_clicked()
{
    emit toggled(ui->selectionButton->isChecked());
}
