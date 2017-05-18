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
    int pipes;
    int keys;

private slots:
    void on_keysCount_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::Organ *ui;
};

#endif // ORGAN_H
