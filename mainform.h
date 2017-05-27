#ifndef MainForm_H
#define MainForm_H
#include <QWidget>
#include <QPushButton>
#include "addition.h"
#include "inclusion.h"
#include "removal.h"
#include "change.h"
#include "search.h"
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
    removal* remove;
    Change* change;
    Search* search;
    QVector<CheckableForm*>* toggledW;
    QVector<CheckableForm*>* toggledG;
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
    void on_inclusionComplete();
    void on_removalComplete();
    void on_changeComplete();
    void on_changeStarted();
    void on_searchComplete();
    void setSelectable(bool);
    void formToggled(bool toggled);
    void on_pushButton_clicked();
};

#endif // MainForm_H
