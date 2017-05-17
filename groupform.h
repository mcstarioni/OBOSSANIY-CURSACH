#ifndef GROUPFORM_H
#define GROUPFORM_H

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

private:
    Ui::GroupForm *ui;
};

#endif // GROUPFORM_H
