#include "instruments.h"
#include <QDebug>
int Instruments::instrumentsCount = 0;
int Instruments::lastId = 0;
Instruments::Instruments(int freq)
{
    this->averageFrequency = freq;
    this->id = Instruments::lastId++;
    Instruments::instrumentsCount++;
    qDebug()<<"Instrument "<<this->id<<" created";
}
Instruments::~Instruments()
{
    qDebug()<<"Instrument "<<this->id<<" destroyed";
    Instruments::instrumentsCount--;
}
int Instruments::getFrequency(){return this->averageFrequency;}
void Instruments::setFrequency(int arg){this->averageFrequency = arg;}
int Instruments::getInstrumentsCount(){return Instruments::instrumentsCount;}
void Instruments::setName(QString name){this->name = name;}
QString Instruments::getName(){return this->name;}

int Drumming::getBPM(){return this->beatPerMinute;}
void Drumming::setBPM(int bpm){this->beatPerMinute = bpm;}

const bool Drum::membrane = true;
bool Drum::isOpen(){return this->open;}
bool Drum::hasMembrane(){return Drum::membrane;}
Drum::~Drum(){}

const bool Plates::membrane = false;
int Plates::getDiameter(){return this->diameter;}
bool Plates::hasMembrane(){return Plates::membrane;}
Plates::~Plates(){}

int Stringed::getStrings(){return this->stringsCount;}
void Stringed::setStrings(int strings){this->stringsCount = strings;}

const bool Violin::potentiometer = false;
Bow* Violin::getBow(){return this->bow;}
void Violin::setBow(Bow *bow){this->bow = bow;}
bool Violin::hasPotentiometer(){return this->potentiometer;}
Violin::~Violin(){}

const bool EGuitar::potentiometer = true;
Pickup* EGuitar::getPickup(){return this->pickup;}
void EGuitar::setPickup(Pickup *p){this->pickup = pickup;}
bool EGuitar::hasPotentiometer(){return this->potentiometer;}
EGuitar::~EGuitar(){}




