#ifndef DATABASE_H
#define DATABASE_H
#include "instruments.h"
#include "group.h"
class Database
{
private:
    QVector<Instruments*>* vectorInst;
    QVector<Group*>* vectorGroup;
    Database();
    ~Database();
public:
    static Database* getInstance()
    {
        static Database instance;
        return &instance;
    }
};

#endif // DATABASE_H
