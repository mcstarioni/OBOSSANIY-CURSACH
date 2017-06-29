#include "search.h"
#include "ui_search.h"
#include "groupsearch.h"
Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ins = 0;
    gr = 0;
    searched = 0;
    searchType = -1;
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_insButton_toggled(bool checked)
{
    if(checked)
    {
        ui->groupButton->setChecked(false);
        searchType = 0;
        if(gr != 0)
        {
            gr->hide();
        }
        if(ins == 0)
        {
            ins = new InsSearch(false);
            ui->searchMenuLayout->addWidget(ins);
        }
        ins->show();
    }
    else
    {
        if(ins != 0)
        {
            ins->hide();
        }
    }
}

void Search::on_groupButton_toggled(bool checked)
{
    if(checked)
    {
        ui->insButton->setChecked(false);
        searchType = 1;
        if(ins != 0)
        {
            ins->hide();
        }
        if(gr == 0)
        {
            gr = new GroupSearch(false);
            ui->searchMenuLayout->addWidget(gr);
        }
        gr->show();
    }
    else
    {
        if(gr != 0)
        {
            gr->hide();
        }
    }
}

void Search::on_searchButton_clicked()
{

}

void Search::on_pushButton_clicked()
{
    emit cancel();
}

