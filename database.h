#ifndef DATABASE_H
#define DATABASE_H
#include "instruments.h"
#include <QVector>
    #include "group.h"
class Database
{
public:
    QVector<QVector<Instruments*>*>* vectorAll;
    QVector<Drums*>* vectorDrums;
    QVector<Plate*>* vectorPlates;
    QVector<Violins*>* vectorViolins;
    QVector<EGuitars*>* vectorGuitars;
    QVector<Synths*>* vectorSynths;
    QVector<Organs*>* vectorOrgans;
    QVector<Group*>* vectorGroup;
    Database();
    ~Database();
    template <class T>
    void deleteValues(QVector<T*>* vec);
    static Database* getInstance()
    {
        static Database instance;
        return &instance;
    }
};

#endif // DATABASE_H
