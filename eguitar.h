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

private:
    Ui::EGuitar *ui;
};

#endif // EGUITAR_H
