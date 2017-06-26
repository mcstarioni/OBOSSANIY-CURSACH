#ifndef SEARCH_H
#define SEARCH_H
#include "inssearch.h"
#include "groupsearch.h"
#include <QWidget>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    int searchType;
    QWidget* searched;
    InsSearch* ins;
    GroupSearch* gr;
private slots:
    void on_insButton_toggled(bool checked);
    void on_groupButton_toggled(bool checked);
    void on_searchButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::Search *ui;
signals:
    void cancel();
};

#endif // SEARCH_H
