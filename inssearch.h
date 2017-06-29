#ifndef INSSEARCH_H
#define INSSEARCH_H
#include "groupsearch.h"
#include <QWidget>
#include "instruments.h"
#include "search.h"
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
    comparison freqType;

    QString nameValue;
    comparison nameType;

    int idValue;
    comparison idType;

    int classValue;
    comparison classType;

    bool isCorrect;

    GroupSearch* groupSearch;

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

    void on_groupSearchButton_toggled(bool checked);

    void on_nameType_currentIndexChanged(int index);

    void on_idType_currentIndexChanged(int index);

    void on_freqType_currentIndexChanged(int index);

private:
    Ui::InsSearch *ui;
};

#endif // INSSEARCH_H
