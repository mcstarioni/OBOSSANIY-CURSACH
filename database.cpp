#include "database.h"
#include "instruments.h"
#include <QVector>
#include "group.h"
Database::Database()
{
    vectorAll = new QVector<QVector<Instruments*>*>();
    vectorDrums = new QVector<Drums*>();
    vectorPlates = new QVector<Plate*>();
    vectorViolins = new QVector<Violins*>();
    vectorGuitars = new QVector<EGuitars*>();
    vectorSynths = new QVector<Synths*>();
    vectorOrgans = new QVector<Organs*>();
    vectorGroup = new QVector<Group*>();
    vectorAll->push_back((QVector<Instruments*>*)vectorDrums);
    vectorAll->push_back((QVector<Instruments*>*)vectorPlates);
    vectorAll->push_back((QVector<Instruments*>*)vectorViolins);
    vectorAll->push_back((QVector<Instruments*>*)vectorGuitars);
    vectorAll->push_back((QVector<Instruments*>*)vectorSynths);
    vectorAll->push_back((QVector<Instruments*>*)vectorOrgans);
}
Database::~Database()
{
    deleteValues<Drums>(vectorDrums);
    deleteValues<Plate>(vectorPlates);
    deleteValues<Violins>(vectorViolins);
    deleteValues<EGuitars>(vectorGuitars);
    deleteValues<Synths>(vectorSynths);
    deleteValues<Organs>(vectorOrgans);
    deleteValues<Group>(vectorGroup);
    delete vectorAll;
}
template <class T>
void Database::deleteValues(QVector<T*>* vec)
{
    for(int i = 0; i < vec->size(); i++)
    {
        T *temp = vec->at(i);
        delete temp;
    }
    delete vec;
}


//Database* Database::instance = new Database();
/*
 *
 *
 * class Band
{

 * using namespace ins;



 * /
*/
