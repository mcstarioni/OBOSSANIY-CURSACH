#ifndef SEARCH_H
#define SEARCH_H
#include "inssearch.h"
#include "groupsearch.h"
#include <QWidget>

namespace Ui {
class Search;
}

enum Comparison{moreThan,lessThan,equal,notImportant};
class Search : public QWidget
{
    Q_OBJECT

public:    
    template <typename T>
    class SearchArgument
    {
    public:
        T value;
        Comparison comparisonType;
        SearchArgument(T comparableValue, Comparison type);
        bool compare(T comparedValue);
    };
    explicit Search(QWidget *parent = 0);
    ~Search();
    int searchType;
    QWidget* searched;
    InsSearch* ins;
    GroupSearch* gr;
    static Comparison getComparisonFromIndex(int index);
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
