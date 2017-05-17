#ifndef ORGAN_H
#define ORGAN_H

#include <QWidget>

namespace Ui {
class Organ;
}

class Organ : public QWidget
{
    Q_OBJECT

public:
    explicit Organ(QWidget *parent = 0);
    ~Organ();

private:
    Ui::Organ *ui;
};

#endif // ORGAN_H
