#ifndef GROUPSEARCH_H
#define GROUPSEARCH_H
#include "inssearch.h"
#include <QVector>
#include <QWidget>
#include "searchargument.h"
class InsSearch;
namespace Ui {
class GroupSearch;
}

class GroupSearch : public QWidget
{
    Q_OBJECT

public:
    explicit GroupSearch(bool final,QWidget *parent = 0);
    ~GroupSearch();
    SearchArgument<QString> *name;
    SearchArgument<int> *id;
    InsSearch *insSearch;
private:
    Ui::GroupSearch *ui;
private slots:
    void on_insSearchButton_toggled(bool checked);
    void on_nameEdit_editingFinished();
    void on_idEdit_editingFinished();
    void on_idType_currentIndexChanged(int index);
    void on_nameType_currentIndexChanged(int index);
};

#endif // GROUPSEARCH_H
