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
    int actionType;
    Addition* addition;
    Inclusion* inclusion;
    removal* remove;
    Change* change;
    Search* search;
    QWidget* simple;
    QVector<CheckableForm*>* toggledIns;
    QVector<CheckableForm*>* toggledGroup;
    QVector<CheckableForm*>* allFormsIns;
    QVector<CheckableForm*>* allFormsGroup;
    QPushButton *lastButton;
    QWidget *lastWidget;
    void showScrollAreas(bool show);
    void nextMenuButtonClicked(QPushButton* nextMenuButton, QWidget *nextMenu);
    void clearToggledVectors();
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
    void on_simpleB_clicked();
    void on_searchB_toggled(bool checked);
};

#endif // MainForm_H
