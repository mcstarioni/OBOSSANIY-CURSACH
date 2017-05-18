#include "checkableform.h"
#include "ui_checkableform.h"

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
    void toggled(bool status);
    isChecked = checked;
}
void CheckableForm::setButton(bool shown)
{
    if(shown)
        ui->radioButton->show();
    else
        ui->radioButton->hide();
}

void CheckableForm::setEnabled(bool status)
{
    widget->setEnabled(status);
}
