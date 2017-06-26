#include "groupsearch.h"
#include "ui_groupsearch.h"

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
}

GroupSearch::~GroupSearch()
{
    delete ui;
}

void GroupSearch::on_insSearchButton_toggled(bool checked)
{
//    if(checked)
//    {
//        if(groupSearch == 0)
//        {
//            groupSearch = new GroupSearch(true);
//            ui->groupAdd->addWidget(groupSearch);
//        }
//        groupSearch->show();
//    }
//    else
//    {
//        if(groupSearch != 0)
//        {
//            groupSearch->hide();
//        }
//    }
}

void GroupSearch::on_nameEdit_editingFinished()
{

}
void GroupSearch::on_idEdit_editingFinished()
{

}
void GroupSearch::search()
{

}
void GroupSearch::parseString(int *searchType, QString* searchValue)
{
    QChar type = searchValue->at(0);
    *searchType = (type == '=')?0:
                ((type == '<')?1:
                ((type == '>')?2:
                 (type == '?')?3:-1));
    if(*searchType == -1)
    {
        return;
    }
    *searchValue = searchValue->right(1);
}
