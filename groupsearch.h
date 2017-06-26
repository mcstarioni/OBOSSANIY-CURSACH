#ifndef GROUPSEARCH_H
#define GROUPSEARCH_H

#include <QWidget>

namespace Ui {
class GroupSearch;
}

class GroupSearch : public QWidget
{
    Q_OBJECT

public:
    explicit GroupSearch(QWidget *parent = 0);
    ~GroupSearch();

private:
    Ui::GroupSearch *ui;
};

#endif // GROUPSEARCH_H
