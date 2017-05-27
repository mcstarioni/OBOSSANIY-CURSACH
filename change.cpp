#include "change.h"
#include "ui_change.h"

Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
}

Change::~Change()
{
    delete ui;
}

void Change::on_changeB_clicked()
{
    emit startEdition();
}

void Change::on_cancelB_clicked()
{
    emit cancel();
}

void Change::on_saveB_clicked()
{
    emit complete();
}
