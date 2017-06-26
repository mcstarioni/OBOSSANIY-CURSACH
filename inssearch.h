#ifndef INSSEARCH_H
#define INSSEARCH_H
#include "groupsearch.h"
#include <QWidget>
#include "instruments.h"
#include <QVector>
class GroupSearch;
namespace Ui {
class InsSearch;
}

class InsSearch : public QWidget
{
    Q_OBJECT
public:
    explicit InsSearch(bool final,QWidget *parent = 0);
    ~InsSearch();
    int freqValue;
    int freqType;
    QString nameValue;
    int nameType;
    int idValue;
    int idType;
    GroupSearch* groupSearch;
    int classType;
    int classValue;
    bool isCorrect;
    QVector<Instruments*>* find(QVector<Instruments*>* instruments);
    void parseString(int* searchType, QString* searchValue);
    bool checkConditions(Instruments* ins);
    template<class T>
    bool checkOneCondition(int comparisonType, T value1,T value2);
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_idEdit_editingFinished();
    void on_nameEdit_editingFinished();
    void on_freqEdit_editingFinished();
    void search();
    void on_groupSearchButton_toggled(bool checked);

private:
    Ui::InsSearch *ui;
signals:
    void found(QVector<QString>* result);
};

#endif // INSSEARCH_H
