#ifndef MainForm_H
#define MainForm_H
#include <QWidget>
#include <QPushButton>
#include "addition.h"
#include "inclusion.h"
#include "checkableform.h"
namespace Ui {
class MainForm;
}

class MainForm: public QWidget
{
    Q_OBJECT

private:
    Ui::MainForm* ui;
    QWidget *widgetLast;
    int actionType;
    Addition* addition;
    Inclusion* inclusion;
    QVector<CheckableForm*>* vectorW;
    QVector<CheckableForm*>* vectorG;
    QPushButton *last;
public:

    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
public slots:
private slots:
    void on_inclusionB_clicked();
    void on_addB_clicked();
    void on_removeB_clicked();
    void on_searchB_clicked();
    void on_changeB_clicked();
    void toSimpleView();
    void on_addB_toggled(bool checked);
    void on_additionComplete(CheckableForm* form, int type);
    void setSelectable(bool);
};

#endif // MainForm_H
