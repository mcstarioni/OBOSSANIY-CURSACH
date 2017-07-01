#include "search.h"
#include "ui_search.h"
#include "groupsearch.h"
#include "manager.h"
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
    qDebug()<<"searchType = "<<searchType;
    QVector<QString>* result = 0;
    if(searchType == 0)
    {
        qDebug()<<"1";
        if(ins->hasGroupSearch)
        {
            result = Manager::getInstance()->searchInstruments(ins->id,
                                      ins->freq,
                                      ins->name,
                                      ins->classes,
                                      ins->groupSearch->id,
                                      ins->groupSearch->name);
        }
        else
        {
            qDebug()<<"2";
            result = Manager::getInstance()->searchInstruments(ins->id,
                                      ins->freq,
                                      ins->name,
                                      ins->classes);
        }
    }else
    {
        if(searchType == 1)
        {

        }else
        {

        }
    }
    if(result != 0)
    {
        qDebug()<<"3";
        for(int i = 0; i < result->size(); i++)
        {
            QString temp = result->at(i);
            ui->listWidget->addItem(temp);
        }
    }
}

void Search::on_pushButton_clicked()
{
    emit cancel();
}

