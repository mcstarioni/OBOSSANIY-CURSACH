#include "manager.h"
#include "QDebug"
#include "instruments.h"
#include "database.h"
#include "search.h"
Manager::Manager(QObject *parent):
    QObject(parent)
{
    qDebug()<<"manager created";
    database = Database::getInstance();
}
Manager::~Manager()
{

}

Instruments* Manager::getById(int id)
{
    Instruments *ins;
    for(int i = 0; i < database->vectorAll->size(); i++)
    {
        for(int j = 0; j < database->vectorAll->at(i)->size(); j++)
        {
            ins = database->vectorAll->at(i)->at(j);
            if(ins->Id() == id)
            {
                return ins;
            }
        }
    }
    return 0;
}
Group* Manager::getByIdG(int id)
{
    Group *g;
    for(int i = 0; i < database->vectorGroup->size(); i++)
    {
        g = database->vectorGroup->at(i);
        if(g->Id() == id)
        {
            return g;
        }
    }
    return 0;
}

void Manager::includeIns(Instruments* ins, Group* group)
{
    ins->addGroup(group);
    group->addInstrument(ins);
}

void Manager::includeIns(int idIns, int idGroup)
{
    Instruments *ins = getById(idIns);
    Group *g = getByIdG(idGroup);
    if(ins != 0 && g != 0)
    {
        includeIns(ins,g);
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
void Manager::setGroup(int id, QString str)
{
    Group* gr = getByIdG(id);
    if(gr != 0)
    {
        gr->setName(str);
    }
}
QString Manager::getPossibleNameIns(int type)
{
    QString name = Instruments::getTypeName(type);
    switch(type)
    {
    case 0:
        return name + QString::number(Drums::getInstrumentsCount());
    case 1:
        return name + QString::number(Plate::getInstrumentsCount());
    case 2:
        return name + QString::number(Violins::getInstrumentsCount());
    case 3:
        return name + QString::number(EGuitars::getInstrumentsCount());
    case 4:
        return name + QString::number(Synths::getInstrumentsCount());
    case 5:
        return name + QString::number(Organs::getInstrumentsCount());
    default:
        return "WTF?";
    }
}
QString Manager::getTypeName(int type)
{
    return Instruments::getTypeName(type);
}

QVector<QString>* Manager::searchInstruments(SearchArgument<int>* id,
                                             SearchArgument<int>* freq,
                                             SearchArgument<QString>* name,
                                             SearchArgument<int>* classes,
                                             SearchArgument<int>* idGroup,
                                             SearchArgument<QString>* nameGroup)
{
    QVector<QString>* result = new QVector<QString>();
    Instruments *temp;
    qDebug()<<"1";
    for(int i = 0; i < database->vectorAll->size(); i++)
    {
        for(int j = 0; j < database->vectorAll->at(i)->size(); j++)
        {
            temp = database->vectorAll->at(i)->at(j);
            bool fits = false;
            if(checkIns(id,freq,name,classes,temp))
            {
                qDebug()<<"2";
                fits = true;
                if(idGroup != 0 && nameGroup != 0)
                {
                    qDebug()<<"3";
                    QVector<Group*>* groups = temp->getGroups();
                    Group* tempGroup;
                    fits = false;
                    for(int j = 0; j < groups->size(); j++)
                    {
                        tempGroup = groups->at(i);
                        if(checkGroup(idGroup,nameGroup,tempGroup))
                        {
                            fits = true;
                            break;
                        }
                    }
                }
                qDebug()<<"4";
                if(fits)
                {
                    qDebug()<<"fits";
                    result->append(getStringInsRepresentation(temp));
                }
            }
        }
    }
    qDebug()<<"5";
    return result;
}
bool Manager::checkIns(SearchArgument<int>* id,
              SearchArgument<int>* freq,
              SearchArgument<QString>* name,
              SearchArgument<int>* classes,
              Instruments* compared)
{
    return (id->compare(compared->Id()) && freq->compare(compared->getFrequency()) &&
            name->compare(compared->getName()) && classes->compare(compared->Type()));
}

bool Manager::checkGroup(SearchArgument<int>* id,SearchArgument<QString>* name, Group* compared)
{
    return (id->compare(compared->Id()) && name->compare(compared->getName()));
}
QString Manager::getStringInsRepresentation(Instruments* ins)
{
    QString str = QString::number(ins->Id());
    str = "Type: "+ins->getTypeName()+" id: " + str + ", name: " + ins->getName();
    return str;
}
