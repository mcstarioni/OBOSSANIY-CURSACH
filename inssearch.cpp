#include "inssearch.h"
#include "ui_inssearch.h"
#include "searchargument.h"
InsSearch::InsSearch(bool final,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsSearch)
{
    groupSearch = 0;
    ui->setupUi(this);
    freq = new SearchArgument<int>(0,notImportant);
    id = new SearchArgument<int>(0,notImportant);
    name = new SearchArgument<QString>("",notImportant);
    classes = new SearchArgument<int>(0,notImportant);
    if(final)
    {
        ui->groupSearchButton->hide();
    }
}

InsSearch::~InsSearch()
{
    delete ui;
}

void InsSearch::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
        classes->comparisonType = notImportant;
    else
        classes->comparisonType = equal;
    classes->value = index - 1;
}

void InsSearch::on_idEdit_editingFinished()
{
    bool success;
    int result = ui->idEdit->text().toInt(&success);
    if(success)
    {
        id->value = result;
    }
}

void InsSearch::on_nameEdit_editingFinished()
{
    name->value = ui->nameEdit->text();
}

void InsSearch::on_freqEdit_editingFinished()
{
    bool success;
    int result = ui->freqEdit->text().toInt(&success);
    if(success)
    {
        freq->value = result;
    }
}

void InsSearch::on_groupSearchButton_toggled(bool checked)
{
    qDebug()<<"clicked"<<checked;
    if(checked)
    {
        qDebug()<<"Ok1";
        if(groupSearch == 0)
        {
            groupSearch = new GroupSearch(true);
            ui->groupAdd->addWidget(groupSearch);
            qDebug()<<"Ok2";
        }
        hasGroupSearch = true;
        groupSearch->show();
    }
    else
    {
        qDebug()<<"toggled cancel";
        if(groupSearch != 0)
        {
            hasGroupSearch = false;
            groupSearch->hide();
        }
    }
}

void InsSearch::on_nameType_currentIndexChanged(int index)
{
    name->comparisonType = SearchArgument<int>::getComparisonFromIndex(index);
}

void InsSearch::on_idType_currentIndexChanged(int index)
{
    id->comparisonType = SearchArgument<int>::getComparisonFromIndex(index);
}

void InsSearch::on_freqType_currentIndexChanged(int index)
{
    freq->comparisonType = SearchArgument<int>::getComparisonFromIndex(index);
}
