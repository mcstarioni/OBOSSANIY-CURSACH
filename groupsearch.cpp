#include "groupsearch.h"
#include "ui_groupsearch.h"
#include "searchargument.h"
GroupSearch::GroupSearch(bool final,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupSearch)
{
    insSearch = 0;
    ui->setupUi(this);
    if(final)
    {
        ui->insSearchButton->hide();
    }
    name = new SearchArgument<QString>("",notImportant);
    id = new SearchArgument<int>(0,notImportant);
}

GroupSearch::~GroupSearch()
{
    delete ui;
}

void GroupSearch::on_insSearchButton_toggled(bool checked)
{
    if(checked)
    {
        if(insSearch == 0)
        {
            insSearch = new InsSearch(true);
            ui->insAdd->addWidget(insSearch);
        }
        insSearch->show();
    }
    else
    {
        if(insSearch != 0)
        {
            insSearch->hide();
        }
    }
}

void GroupSearch::on_nameEdit_editingFinished()
{
    name->value = ui->nameEdit->text();
}
void GroupSearch::on_idEdit_editingFinished()
{
    bool success;
    int result = ui->idEdit->text().toInt(&success);
    if(success)
    {
        id->value = result;
    }
}

void GroupSearch::on_idType_currentIndexChanged(int index)
{
    id->comparisonType = SearchArgument<int>::getComparisonFromIndex(index);
}

void GroupSearch::on_nameType_currentIndexChanged(int index)
{
    name->comparisonType = SearchArgument<int>::getComparisonFromIndex(index);
}
