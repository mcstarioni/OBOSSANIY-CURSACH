#ifndef VIOLIN_H
#define VIOLIN_H

#include <QWidget>

namespace Ui {
class Violin;
}

class Violin : public QWidget
{
    Q_OBJECT

public:
    explicit Violin(QWidget *parent = 0);
    int bow;
    int strings;
    ~Violin();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Violin *ui;
};

#endif // VIOLIN_H
