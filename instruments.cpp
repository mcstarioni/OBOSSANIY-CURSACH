#include "instruments.h"
#include "group.h"
#include <QDebug>
#include <QVector>

int Instruments::instrumentsCount = 0;
int Instruments::lastId = 0;
int Drums::drumsCount = 0;
int Plate::platesCount = 0;
int Violins::violinsCount = 0;
int EGuitars::eguitarsCount = 0;
int Synths::synthCount = 0;
int Organs::organsCount = 0;

Instruments::Instruments(int freq,int type)
{
    this->type = type;
    this->averageFrequency = freq;
    this->id = Instruments::lastId++;
    Instruments::instrumentsCount++;
    this->groups = new QVector<Group*>();
    qDebug()<<"Instrument "<<this->id<<" created";
}
Instruments::~Instruments()
{
    qDebug()<<"Instrument "<<this->id<<" destroyed";
    for(int i = 0; i < groups->size(); i++)
    {
        groups->at(i)->removeInstrument(this);
    }
    delete groups;
    Instruments::instrumentsCount--;
}
int Instruments::getFrequency(){return this->averageFrequency;}
void Instruments::setFrequency(int arg){this->averageFrequency = arg;}
int Instruments::getInstrumentsCount(){return Instruments::instrumentsCount;}
void Instruments::setName(QString name){this->name = name;}
QString Instruments::getName(){return this->name;}
void Instruments::addGroup(Group *b){
    if(!groups->contains(b))
        this->groups->push_back(b);}
void Instruments::removeGroup(Group *b){this->groups->removeOne(b);}
int Instruments::Id(){return this->id;}
int Instruments::Type(){return type;}
QVector<Group*>* Instruments::getGroups(){return groups;}
QString Instruments::getTypeName()
{
    return Instruments::getTypeName(this->type);
}
QString Instruments::getTypeName(int type)
{
    switch(type)
    {
    case 0:
        return "Drum";
    case 1:
        return "Plate";
    case 2:
        return "Violin";
    case 3:
        return "EGuitar";
    case 4:
        return "Synth";
    case 5:
        return "Organ";
    default:
        return "WTF?";
    }
}
int Drumming::getBPM(){return this->beatPerMinute;}
void Drumming::setBPM(int bpm){this->beatPerMinute = bpm;}

const bool Drums::membrane = true;
bool Drums::isOpen(){return this->open;}
bool Drums::hasMembrane(){return Drums::membrane;}
Drums::~Drums(){}

const bool Plate::membrane = false;
int Plate::getDiameter(){return this->diameter;}
bool Plate::hasMembrane(){return Plate::membrane;}
Plate::~Plate(){}

int Stringed::getStrings(){return this->stringsCount;}
void Stringed::setStrings(int strings){this->stringsCount = strings;}

const bool Violins::potentiometer = false;
int Violins::getBow(){return this->bow;}
void Violins::setBow(int bow){this->bow = bow;}
bool Violins::hasPotentiometer(){return this->potentiometer;}
Violins::~Violins(){}

const bool EGuitars::potentiometer = true;
int EGuitars::getPickup(){return this->pickup;}
void EGuitars::setPickup(int p){this->pickup = p;}
bool EGuitars::hasPotentiometer(){return this->potentiometer;}
EGuitars::~EGuitars(){}

int KeyBoarded::getKeys(){return this->keysCount;}
void KeyBoarded::setKeys(int keys){this->keysCount = keys;}

int Synths::getVoiceCount(){return this->voiceCount;}
void Synths::setVoiceCount(int voiceCount){this->voiceCount = voiceCount;}
Synths::~Synths(){}

int Organs::getPipes(){return this->pipesCount;}
void Organs::setPipes(int pipes){this->pipesCount = pipes;}
Organs::~Organs(){}


