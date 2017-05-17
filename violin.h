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
    ~Violin();

private:
    Ui::Violin *ui;
};

#endif // VIOLIN_H
