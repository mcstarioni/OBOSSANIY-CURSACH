#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <QString>
#include <QDebug>
#include <QVector>
#include "group.h"

class Group;
class Instruments
{

private:
    int type;
    int id;
    static int instrumentsCount;
    static int lastId;
    QString name;
    int averageFrequency;
    QVector<Group*>* groups;
public:
    int Type();
    int Id();
    Instruments(int arg,int type);
    void setName(QString name);
    QString getName();
    void setFrequency(int arg);
    int getFrequency();
    static int getInstrumentsCount();
    static QString getTypeName(int type);
    QString getTypeName();
    virtual ~Instruments() = 0;
    QVector<Group*>* getGroups();
    void addGroup(Group *b);
    void removeGroup(Group *b);
};

/*
 *
 *  Классы второго уровня наследования, содержашие общие признаки инструментов
 * ----------------------------------------------------------
 *
 */
class Drumming:public Instruments
{
private:
    int beatPerMinute;
public:
    Drumming(int bpm,int freq, int type):Instruments(freq, type),beatPerMinute(bpm) {qDebug()<<"Drumming";}
    int getBPM();
    void setBPM(int bpm);
    virtual bool hasMembrane() = 0;
};

class Stringed:public Instruments
{
private:
    int stringsCount;
protected:
    static const bool potentiometer;
public:
    Stringed(int strings,int freq, int type):Instruments(freq,type),stringsCount(strings){}
    int getStrings();
    void setStrings(int strings);
    virtual bool hasPotentiometer() = 0;
};


class KeyBoarded:public Instruments
{
private:
    int keysCount;
protected:
    static const bool thumbler;
public:
    KeyBoarded(int keys,int freq, int type):Instruments(freq,type),keysCount(keys){}
    int getKeys();
    void setKeys(int keys);
};

/*
 *
 *  Конечные , не абстрактные классы, реализующие Деструктор.
 * ----------------------------------------------------------
 *
 */
class Drums:public Drumming
{
private:
    static int drumsCount;
    const bool open;
    static const bool membrane;
public:
    Drums(bool o = true):Drumming(170,5000,0),open(o){drumsCount++;}
    static int getInstrumentsCount(){return drumsCount;}
    bool isOpen();
    bool hasMembrane();
    ~Drums();
};
class Plate:public Drumming
{
private:
    static int platesCount;
    const int diameter;
    static const bool membrane;
public:
    Plate(int d = 20):Drumming(120,8000,1),diameter(d){platesCount++;}
    static int getInstrumentsCount(){return platesCount;}
    int getDiameter();
    bool hasMembrane();
    ~Plate();
};

class Violins:public Stringed
{
private:
    static int violinsCount;
    int bow;
    static const bool potentiometer;
public:
    Violins(int b = 0):Stringed(4,10000,2),bow(b){violinsCount++;}
    static int getInstrumentsCount(){return violinsCount;}
    int getBow();
    void setBow(int b);
    bool hasPotentiometer();
    ~Violins();
};
class EGuitars:public Stringed
{
private:
    static int eguitarsCount;
    int pickup;
    static const bool potentiometer;
public:
    EGuitars(int p = 0):Stringed(8,9000,3),pickup(p){eguitarsCount++;}
    static int getInstrumentsCount(){return eguitarsCount;}
    int getPickup();
    void setPickup(int p);
    bool hasPotentiometer();
    ~EGuitars();
};

class Synths:public KeyBoarded
{
private:
    static int synthCount;
    int voiceCount;
public:
    Synths(int vc = 10):KeyBoarded(35,18000,4),voiceCount(vc){synthCount++;}
    static int getInstrumentsCount(){return synthCount;}
    int getVoiceCount();
    void setVoiceCount(int voiceCount);
    ~Synths();
};


class Organs:public KeyBoarded
{
private:
    static int organsCount;
    int pipesCount;
public:
    Organs(int pipes = 49):KeyBoarded(49,180000,5),pipesCount(pipes){organsCount++;}
    static int getInstrumentsCount(){return organsCount;}
    int getPipes();
    void setPipes(int pipes);
    ~Organs();
};

#endif // INSTRUMENTS_H
