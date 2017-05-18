#ifndef DRUM_H
#define DRUM_H

#include <QWidget>

namespace Ui {
class Drum;
}

class Drum : public QWidget
{
    Q_OBJECT

public:
    explicit Drum(QWidget *parent = 0);
    ~Drum();
    bool isOpen;
    int bpm;
    Ui::Drum *ui;
private slots:
    void on_bpm_valueChanged(int arg1);
    void on_radioButton_toggled(bool checked);
};

#endif // DRUM_H
