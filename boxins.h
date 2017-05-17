#ifndef BOXINS_H
#define BOXINS_H

#include <QGroupBox>

namespace Ui {
class BoxIns;
}

class BoxIns : public QGroupBox
{
    Q_OBJECT

public:
    explicit BoxIns(int index,QWidget *parent = 0);
    int index;
    ~BoxIns();
public slots:
    void createIns();

private:
    Ui::BoxIns *ui;
};

#endif // BOXINS_H
