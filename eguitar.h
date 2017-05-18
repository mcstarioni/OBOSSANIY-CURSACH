#ifndef EGUITAR_H
#define EGUITAR_H

#include <QWidget>

namespace Ui {
class EGuitar;
}

class EGuitar : public QWidget
{
    Q_OBJECT

public:
    explicit EGuitar(QWidget *parent = 0);
    ~EGuitar();
    int pickup;
    int strings;

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::EGuitar *ui;
};

#endif // EGUITAR_H
