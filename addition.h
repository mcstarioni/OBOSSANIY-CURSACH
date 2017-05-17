#ifndef ADDITION_H
#define ADDITION_H

#include <QWidget>

namespace Ui {
class Addition;
}

class Addition : public QWidget
{
    Q_OBJECT

public:
    explicit Addition(QWidget *parent = 0);
    ~Addition();

private:
    Ui::Addition *ui;
};

#endif // ADDITION_H
