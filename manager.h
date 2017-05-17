#ifndef MANAGER_H
#define MANAGER_H
#include "instruments.h"

class Manager
{
private:
    Manager();
    ~Manager();
public:
    static int n;
    static void add(Instruments* instr);
    static void remove(Instruments* instr);
    static Manager* getInstance()
    {
        static Manager instance;
        return &instance;
    }
};

#endif // MANAGER_H
