#include "manager.h"
#include "QDebug"

Manager::Manager()
{
    n++;
    qDebug()<<n;
}
Manager::~Manager()
{

}
int Manager::n = 0;

