#ifndef CHECKABLEFORM_H
#define CHECKABLEFORM_H

#include <QWidget>

namespace Ui {
class CheckableForm;
}

class CheckableForm : public QWidget
{
    Q_OBJECT

public:
    explicit CheckableForm(QWidget *parent = 0);
    ~CheckableForm();

private:
    Ui::CheckableForm *ui;
};

#endif // CHECKABLEFORM_H
