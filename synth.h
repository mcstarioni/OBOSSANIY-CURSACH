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

private:
    Ui::Synth *ui;
};

#endif // SYNTH_H
