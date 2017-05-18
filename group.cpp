#include "group.h"

int Group::groupCount = 0;
int Group::lastId = 0;
Group::Group()
{
    id = Group::lastId++;
    Group::groupCount++;
}
void Group::addInstrument(Instruments *i)
{
    if(!orchestra->contains(i))
        orchestra->push_back(i);
}

void Group::removeInstrument(Instruments *i)
{
    orchestra->removeOne(i);
}

QVector<Instruments*>* Group::getInstruments()
{
    return orchestra;
}
void Group::setName(QString n)
{
    name = n;
}

QString Group::getName()
{
    return name;
}
Group::~Group()
{
    Group::groupCount--;
    for(int i = 0; i < orchestra->size(); i++)
    {
        orchestra->at(i)->removeGroup(this);
    }
}
int Group::Id(){return id;}
