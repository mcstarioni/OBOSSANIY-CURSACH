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
    explicit BoxIns(QWidget *parent = 0);
    ~BoxIns();

private:
    Ui::BoxIns *ui;
};

#endif // BOXINS_H
