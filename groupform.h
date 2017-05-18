#ifndef GROUPFORM_H
#define GROUPFORM_H
#include "manager.h"
#include <QWidget>

namespace Ui {
class GroupForm;
}

class GroupForm : public QWidget
{
    Q_OBJECT

public:
    explicit GroupForm(QWidget *parent = 0);
    ~GroupForm();
    void createGroup();
    int index;
    Manager* manager;

private:
    Ui::GroupForm *ui;
public slots:
    void createdGroup(int index);

};

#endif // GROUPFORM_H
