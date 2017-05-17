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
    ~Plates();

private:
    Ui::Plates *ui;
};

#endif // PLATES_H
