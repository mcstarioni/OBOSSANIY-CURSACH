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

private:
    Ui::Drum *ui;
};

#endif // DRUM_H
