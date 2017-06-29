#include "inssearch.h"
#include "ui_inssearch.h"

InsSearch::InsSearch(bool final,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsSearch)
{
    groupSearch = 0;
    ui->setupUi(this);
    freq = new Search::SearchArgument<int>(0,notImportant);
    id = new Search::SearchArgument<int>(0,notImportant);
    name = new Search::SearchArgument<QString>("",notImportant);
    classes = new Search::SearchArgument<int>(0,notImportant);
    if(final)
    {
        ui->groupSearchButton->hide();
    }
    inputCorrect
}

InsSearch::~InsSearch()
{
    delete ui;
}

void InsSearch::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
        classes.comparisonType = notImportant;
    else
        classes.comparisonType = equal;
    classes.value = index - 1;
}

void InsSearch::on_idEdit_editingFinished()
{
    int result = ui->idEdit->text().toInt();
    if()
    id.value =
}

void InsSearch::on_nameEdit_editingFinished()
{
    nameValue = ui->nameEdit->text();
    parseString(&nameType,&nameValue);
    if(nameType == -1)
        isCorrect = false;
}

void InsSearch::on_freqEdit_editingFinished()
{

}

void InsSearch::search()
{

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
        groupSearch->show();
    }
    else
    {
        qDebug()<<"toggled cancel";
        if(groupSearch != 0)
        {
            groupSearch->hide();
        }
    }
}

void InsSearch::on_nameType_currentIndexChanged(int index)
{
    nameType = Search::getComparisonFromIndex(index);
}

void InsSearch::on_idType_currentIndexChanged(int index)
{
    idType = Search::getComparisonFromIndex(index);
}

void InsSearch::on_freqType_currentIndexChanged(int index)
{
    freqType = Search::getComparisonFromIndex(index);
}
