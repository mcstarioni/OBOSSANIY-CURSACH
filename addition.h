#ifndef ADDITION_H
#define ADDITION_H
#include "checkableform.h"
#include <QWidget>
#include "boxins.h"
#include "groupform.h"
#include <QPushButton>
namespace Ui {
class Addition;
}

class Addition : public QWidget
{
    Q_OBJECT

public:
    explicit Addition(QWidget *parent = 0);
    BoxIns* insform;
    GroupForm* groupform;
    QPushButton* last;
    ~Addition();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_cancel_clicked();
    void on_accept_clicked();
    void on_createIns_clicked();
    void on_createGroup_clicked();
signals:
    void cancel();
    void additionComplete(CheckableForm *form, int type);

private:
    Ui::Addition *ui;
};

#endif // ADDITION_H
