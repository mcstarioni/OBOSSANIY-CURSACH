#include "inssearch.h"
#include "ui_inssearch.h"

InsSearch::InsSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsSearch)
{
    ui->setupUi(this);
    type = -1;
    isCorrect = true;
}

InsSearch::~InsSearch()
{
    delete ui;
}

void InsSearch::on_comboBox_currentIndexChanged(int index)
{
    type = index - 1;
}

void InsSearch::on_lineEdit_3_editingFinished()
{
    int searchType;
    QString txt = ui->label_3->text();
    QChar type = txt.at(0);
    searchType = (type == '=')?0:
                ((type == '<')?1:
                ((type == '>')?2:
                 (type == '?')?3:-1));
    if(searchType == -1)
        isCorrect = false;
    txt.
}

void InsSearch::on_lineEdit_2_editingFinished()
{
    int searchType;
    QString txt = ui->label_3->text();
    QChar type = txt.at(0);
    searchType = (type == '=')?0:
                ((type == '<')?1:
                ((type == '>')?2:
                 (type == '?')?3:-1));
    if(searchType == -1)
        isCorrect = false;
}
