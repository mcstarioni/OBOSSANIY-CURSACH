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
    int id;
    Manager* manager;


private:
    Ui::GroupForm *ui;
public slots:
    void createdGroup(int index);
    void updateIncl();
    void change();


};

#endif // GROUPFORM_H
