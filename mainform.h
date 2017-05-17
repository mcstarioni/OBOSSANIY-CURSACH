#ifndef MainForm_H
#define MainForm_H
#include <QWidget>
#include <QPushButton>
#include "addition.h"
namespace Ui {
class MainForm;
}

class MainForm: public QWidget
{
    Q_OBJECT

private:
    Ui::MainForm* ui;
    QWidget *widgetLast;
    Addition* addition;
    //QVector<QWidget*>* vectorW;
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
};

#endif // MainForm_H
