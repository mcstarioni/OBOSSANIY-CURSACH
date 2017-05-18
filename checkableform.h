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
    bool isChecked;
    bool isInstrument;
    int id;
    QWidget* widget;
    void setWidget(QWidget* w);
private slots:
    void on_radioButton_toggled(bool checked);
public slots:
    void setButton(bool);
    void setEnabled(bool);
signals:
    void toggled(bool status);
private:
    Ui::CheckableForm *ui;
};

#endif // CHECKABLEFORM_H
