#ifndef PLATES_H
#define PLATES_H

#include <QWidget>

namespace Ui {
class Plates;
}

class Plates : public QWidget
{
    Q_OBJECT

public:
    explicit Plates(QWidget *parent = 0);
    int bpm;
    int diameter;
    ~Plates();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_diamTitle_valueChanged(int arg1);

private:
    Ui::Plates *ui;
};

#endif // PLATES_H
