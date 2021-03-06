#ifndef INSSEARCH_H
#define INSSEARCH_H
#include "groupsearch.h"
#include <QWidget>
#include "instruments.h"
#include "searchargument.h"
#include <QVector>

class GroupSearch;
namespace Ui {
class InsSearch;
}

class InsSearch : public QWidget
{
    Q_OBJECT
public:
    explicit InsSearch(bool final,QWidget *parent = 0);
    ~InsSearch();
    SearchArgument<int> *freq;
    SearchArgument<int> *id;
    SearchArgument<QString> *name;
    SearchArgument<int> *classes;
    GroupSearch* groupSearch;
    bool inputCorrect;
    bool hasGroupSearch;
private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_idEdit_editingFinished();

    void on_nameEdit_editingFinished();

    void on_freqEdit_editingFinished();

    void on_groupSearchButton_toggled(bool checked);

    void on_nameType_currentIndexChanged(int index);

    void on_idType_currentIndexChanged(int index);

    void on_freqType_currentIndexChanged(int index);

private:
    Ui::InsSearch *ui;
};

#endif // INSSEARCH_H
