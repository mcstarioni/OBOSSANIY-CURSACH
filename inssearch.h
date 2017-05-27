#ifndef INSSEARCH_H
#define INSSEARCH_H

#include <QWidget>

namespace Ui {
class InsSearch;
}

class InsSearch : public QWidget
{
    Q_OBJECT

public:
    explicit InsSearch(QWidget *parent = 0);
    ~InsSearch();
    int type;
    bool isCorrect;
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::InsSearch *ui;
};

#endif // INSSEARCH_H
