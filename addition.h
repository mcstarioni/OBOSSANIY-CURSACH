#ifndef ADDITION_H
#define ADDITION_H

#include <QWidget>
#include "boxins.h"
#include "groupform.h"
namespace Ui {
class Addition;
}

class Addition : public QWidget
{
    Q_OBJECT

public:
    explicit Addition(QWidget *parent = 0);
    bool addPressed;
    BoxIns* insform;
    GroupForm* groupform;
    ~Addition();

private slots:
    void on_createIns_toggled(bool checked);

    void on_createGroup_toggled(bool checked);

private:
    Ui::Addition *ui;
};

#endif // ADDITION_H
