#ifndef CHECKABLEFORM_H
#define CHECKABLEFORM_H

#include <QWidget>

namespace Ui {
class CheckableForm;
}

class CheckableForm : public QWidget
{
    Q_OBJECT

public:
    explicit CheckableForm(QWidget *parent = 0);
    ~CheckableForm();
    bool isInstrument;
    int id;
    QWidget* widget;
    void setWidget(QWidget* w);
private slots:
    void on_radioButton_clicked();
public slots:
    void setButton(bool);
    void setEnabled(bool);
    void updateInclusions();
    void change();
signals:
    void toggled(bool status);
private:
    Ui::CheckableForm *ui;
};

#endif // CHECKABLEFORM_H
