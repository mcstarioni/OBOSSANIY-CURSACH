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
    ui->widget = w;
}

void CheckableForm::on_radioButton_toggled(bool checked)
{
    isChecked = checked;
}
void CheckableForm::changeButton()
{
    if(ui->radioButton->isHidden())
    {
        ui->radioButton->show();
    }
    else
    {
        ui->radioButton->hide();
    }
}
void CheckableForm::changeEnabled()
{
    if(ui->widget->isEnabled())
    {
        ui->widget->setEnabled(false);
    }
    else
    {
        ui->widget->setEnabled(true);
    }
}
