#ifndef REMOVAL_H
#define REMOVAL_H

#include <QWidget>

namespace Ui {
class removal;
}

class removal : public QWidget
{
    Q_OBJECT

public:
    explicit removal(QWidget *parent = 0);
    ~removal();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::removal *ui;
signals:
    void complete();
    void cancel();

};

#endif // REMOVAL_H
