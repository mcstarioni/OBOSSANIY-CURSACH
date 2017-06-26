#include "groupsearch.h"
#include "ui_groupsearch.h"

GroupSearch::GroupSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupSearch)
{
    ui->setupUi(this);
}

GroupSearch::~GroupSearch()
{
    delete ui;
}
