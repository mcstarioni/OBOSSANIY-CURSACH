#include "manager.h"
#include "QDebug"
#include "instruments.h"
#include "database.h"
Manager::Manager(QObject *parent):
    QObject(parent)
{
    qDebug()<<"manager created";
    database = Database::getInstance();
    qDebug()<<"manager created";

}
Manager::~Manager()
{
}
Instruments* Manager::getById(int id)
{
    qDebug()<<"I 1";
    Instruments *ins;
    for(int i = 0; i < database->vectorAll->size(); i++)
    {
        qDebug()<<"I 2";
        for(int j = 0; j < database->vectorAll->at(i)->size(); j++)
        {
            qDebug()<<"I 3";
            ins = database->vectorAll->at(i)->at(j);
            if(ins->Id() == id)
            {
                qDebug()<<"found 4"<<id;
                return ins;
            }
        }
    }
    return 0;
}
Group* Manager::getByIdG(int id)
{
    Group *g;
    qDebug()<<"G 1";
    for(int i = 0; i < database->vectorGroup->size(); i++)
    {
        qDebug()<<"G 2";
        g = database->vectorGroup->at(i);
        if(g->Id() == id)
        {
            qDebug()<<"found 3";
            return g;
        }
    }
    return 0;
}

void Manager::includeIns(Instruments* ins, Group* group)
{
    qDebug()<<"include 1 1";
    ins->addGroup(group);
    qDebug()<<"include 1 2";
    group->addInstrument(ins);
    qDebug()<<"include 1 2";


}

void Manager::includeIns(int idIns, int idGroup)
{
    qDebug()<<idIns<<" "<<idGroup;
    Instruments *ins = getById(idIns);
    Group *g = getByIdG(idGroup);
    if(ins != 0 && g != 0)
    {
        qDebug()<<"include 1";
        includeIns(ins,g);
        qDebug()<<"include 2";

    }
}
void Manager::removeInstrument(Instruments* ins)
{
   switch(ins->Type())
   {
   case 0:
       database->vectorDrums->removeOne((Drums*)ins);
       break;
   case 1:
       database->vectorPlates->removeOne((Plate*)ins);
       break;
   case 2:
       database->vectorViolins->removeOne((Violins*)ins);
       break;
   case 3:
       database->vectorGuitars->removeOne((EGuitars*)ins);
       break;
   case 4:
       database->vectorSynths->removeOne((Synths*)ins);
       break;
   case 5:
       database->vectorOrgans->removeOne((Organs*)ins);
       break;
   default:
       return;
   }
}

void Manager::removeGroup(Group *gr)
{
    database->vectorGroup->removeOne(gr);
}

void Manager::removeInstrument(int idIns)
{
    removeInstrument(getById(idIns));
}

void Manager::removeGroup(int idGroup)
{
    removeGroup(getByIdG(idGroup));
}

void Manager::createGroup(QString name)
{
    Group *group = new Group();
    group->setName(name);
    database->vectorGroup->push_back(group);
    emit createdGrp(group->Id());
}

void Manager::createDrum(int af, QString name, int bpm,bool open)
{
    Drums* drum = new Drums(open);
    setDrum(drum->Id(),af,name,bpm,open,drum);
    database->vectorDrums->push_back(drum);
    qDebug()<<"drum creation";
    emit createdIns(drum->Id());
}

void Manager::createPlate(int af, QString name, int bpm,int diameter)
{
    Plate* plates = new Plate(diameter);
    setPlate(plates->Id(),af,name,bpm,diameter,plates);
    database->vectorPlates->push_back(plates);
    emit createdIns(plates->Id());
}

void Manager::createViolin(int af, QString name,int strings, int bowType)
{
    Violins* violins = new Violins(bowType);
    setViolin(violins->Id(),af,name,strings,bowType,violins);
    database->vectorViolins->push_back(violins);
    emit createdIns(violins->Id());
}

void Manager::createGuitar(int af, QString name,int strings, int pickupType)
{
    EGuitars* guitar = new EGuitars(pickupType);
    setGuitar(guitar->Id(),af,name,strings,pickupType,guitar);
    database->vectorGuitars->push_back(guitar);
    emit createdIns(guitar->Id());
}

void Manager::createSynth(int af, QString name,int keys, int voices)
{
    Synths* synths = new Synths();
    setSynth(synths->Id(),af,name,keys,voices,synths);
    database->vectorSynths->push_back(synths);
    emit createdIns(synths->Id());
}

void Manager::createOrgan(int af, QString name,int keys, int pipes)
{
    Organs* organs = new Organs();
    setSynth(organs->Id(),af,name,keys,pipes,organs);
    database->vectorOrgans->push_back(organs);
    emit createdIns(organs->Id());
}

void Manager::setDrum(int id, int af, QString name, int bpm,bool open,Instruments *ins)
{
    qDebug()<<"drum set 1";
    Drums *drum;
    if(ins != 0)
    {
        drum = (Drums*)ins;
    }else
    {
        drum = (Drums*)getById(id);
    }
    if(drum != 0)
    {
        drum->setFrequency(af);
        drum->setName(name);
        drum->setBPM(bpm);
    }
    qDebug()<<"drum set 2";
}

void Manager::setPlate(int id,int af, QString name, int bpm,int diameter,Instruments *ins)
{
    Plate *plate;
    if(ins != 0)
    {
        plate = (Plate*)ins;
    }else
    {
        plate = (Plate*)getById(id);
    }
    if(plate != 0)
    {
        plate->setFrequency(af);
        plate->setName(name);
        plate->setBPM(bpm);
    }
}

void Manager::setViolin(int id,int af, QString name,int strings, int bowType,Instruments *ins)
{
    Violins *violins;
    if(ins != 0)
    {
        violins = (Violins*)ins;
    }else
    {
        violins = (Violins*)getById(id);
    }
    if(violins != 0)
    {
        violins->setFrequency(af);
        violins->setName(name);
        violins->setStrings(strings);
        violins->setBow(bowType);
    }
}

void Manager::setGuitar(int id,int af, QString name,int strings, int pickupType,Instruments *ins)
{
    EGuitars *violins;
    if(ins != 0)
    {
        violins = (EGuitars*)ins;
    }else
    {
        violins = (EGuitars*)getById(id);
    }
    if(violins != 0)
    {
        violins->setFrequency(af);
        violins->setName(name);
        violins->setStrings(strings);
        violins->setPickup(pickupType);
    }
}

void Manager::setSynth(int id,int af, QString name,int keys, int voices,Instruments *ins)
{
    Synths *t;
    if(ins != 0)
    {
        t = (Synths*)ins;
    }else
    {
        t = (Synths*)getById(id);
    }
    if(t != 0)
    {
        t->setFrequency(af);
        t->setName(name);
        t->setKeys(keys);
        t->setVoiceCount(voices);
    }
}

void Manager::setOrgan(int id,int af, QString name,int keys, int pipes,Instruments *ins)
{
    Organs *t;
    if(ins != 0)
    {
        t = (Organs*)ins;
    }else
    {
        t = (Organs*)getById(id);
    }
    if(t != 0)
    {
        t->setFrequency(af);
        t->setName(name);
        t->setKeys(keys);
        t->setPipes(pipes);
    }
}





