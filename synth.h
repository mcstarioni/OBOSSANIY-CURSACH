#ifndef SYNTH_H
#define SYNTH_H

#include <QWidget>

namespace Ui {
class Synth;
}

class Synth : public QWidget
{
    Q_OBJECT

public:
    explicit Synth(QWidget *parent = 0);
    ~Synth();
    int keys;
    int voices;

private slots:
    void on_keysCount_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::Synth *ui;
};

#endif // SYNTH_H
