#ifndef BOXINS_H
#define BOXINS_H
#include "manager.h"
#include <QGroupBox>

namespace Ui {
class BoxIns;
}

class BoxIns : public QGroupBox
{
    Q_OBJECT

public:
    explicit BoxIns(int type,  QWidget *parent = 0);
    int type;
    int id;
    QWidget* lastClass;
    ~BoxIns();
    void setClass();
public slots:
    void createIns();
    void classChanged(int i);
    void objectCreated(int id);
    void addGroup(QString group);
    void updateIncl();
    void change();
private:
    Ui::BoxIns *ui;
    Manager* manager;
};

#endif // BOXINS_H
