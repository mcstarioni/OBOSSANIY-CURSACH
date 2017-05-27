#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = 0);
    ~Change();

private slots:
    void on_changeB_clicked();

    void on_cancelB_clicked();

    void on_saveB_clicked();

private:
    Ui::Change *ui;
signals:
    complete();
    cancel();
    startEdition();
};

#endif // CHANGE_H
