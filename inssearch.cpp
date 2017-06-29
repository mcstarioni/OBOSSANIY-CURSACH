#include "inssearch.h"
#include "ui_inssearch.h"

InsSearch::InsSearch(bool final,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsSearch)
{
    groupSearch = 0;
    ui->setupUi(this);
    isCorrect = true;
    classValue = -1;
    classType = 3;
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
        classType = 3;
    else
        classType = 0;
    classValue = index - 1;
}

void InsSearch::on_idEdit_editingFinished()
{
    QString temp = ui->idEdit->text();
    parseString(&idType,&temp);
    if(idType == -1)
        isCorrect = false;
    idValue = temp.toInt(&isCorrect);
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
    QString temp = ui->freqEdit->text();
    parseString(&freqType,&temp);
    if(freqType == -1)
        isCorrect = false;
    freqValue = temp.toInt(&isCorrect);

}

void InsSearch::search()
{

}
QVector<Instruments*>* InsSearch::find(QVector<Instruments*>* instruments)
{
    QVector<Instruments*>* result = new QVector<Instruments*>();
    for(int i = 0; i < instruments->size(); i++)
    {
        if(checkConditions(instruments->at(i)))
        {
            result->push_back(instruments->at(i));
        }
    }
    return result;
}
void InsSearch::parseString(int *searchType, QString* searchValue)
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
    *searchValue = searchValue->right(searchValue->length()-1);

}
bool InsSearch::checkConditions(Instruments* ins)
{
    return (checkOneCondition(idType,ins->Id(),idValue) &&
            checkOneCondition(freqType,ins->getFrequency(),freqValue) &&
            checkOneCondition(nameType,ins->getName(),nameValue) &&
            checkOneCondition(classType,ins->Type(),classValue)
            );
}
template <class T>
bool InsSearch::checkOneCondition(enum comparisonType, T value1,T value2)
{
    switch(comparisonType)
    {
        case 0:
        {
            return (value1 == value2);
        }
        case 1:
        {
            return (value1 < value2);
        }
        case 2:
        {
            return (value1 > value2);
        }
        case 3:
        {
            return true;
        }
        case -1:
        {
            return false;
        }
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
