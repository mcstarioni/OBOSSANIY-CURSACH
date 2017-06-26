#ifndef GROUPSEARCH_H
#define GROUPSEARCH_H
#include "inssearch.h"
#include <QVector>
#include <QWidget>
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
    QString nameValue;
    int nameType;
    int idValue;
    int idType;
    InsSearch* insSearch;
    void parseString(int *searchType, QString* searchValue);
private:
    Ui::GroupSearch *ui;
private slots:
    void on_insSearchButton_toggled(bool checked);
    void on_nameEdit_editingFinished();
    void on_idEdit_editingFinished();
    void search();
signals:
    void found(QVector<QString>* result);
};

#endif // GROUPSEARCH_H
