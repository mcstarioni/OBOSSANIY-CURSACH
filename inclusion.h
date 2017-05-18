#ifndef INCLUSION_H
#define INCLUSION_H

#include <QWidget>

namespace Ui {
class Inclusion;
}

class Inclusion : public QWidget
{
    Q_OBJECT

public:
    explicit Inclusion(QWidget *parent = 0);
    ~Inclusion();

private:
    Ui::Inclusion *ui;
signals:
    void cancel();
private slots:
    void on_cancelB_clicked();
    void on_pushButton_clicked();
};

#endif // INCLUSION_H
