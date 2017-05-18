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
    QVector<Group*> *groups;
public:
    int Type();
    int Id();
    Instruments(int arg,int type);
    void setName(QString name);
    QString getName();
    void setFrequency(int arg);
    int getFrequency();
    static int getInstrumentsCount();
    virtual ~Instruments() = 0;
    void addGroup(Group *b);
    void removeGroup(Group *b);
};
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
class Drums:public Drumming
{
private:
    const bool open;
    static const bool membrane;
public:
    Drums(bool o = true):Drumming(170,5000,0),open(o){qDebug()<<"Drums";}
    bool isOpen();
    bool hasMembrane();
    ~Drums();
};
class Plate:public Drumming
{
private:
    const int diameter;
    static const bool membrane;
public:
    Plate(int d = 20):Drumming(120,8000,1),diameter(d){qDebug()<<"Plates";}
    int getDiameter();
    bool hasMembrane();
    ~Plate();
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
class Violins:public Stringed
{
private:
    int bow;
    static const bool potentiometer;
public:
    Violins(int b = 0):Stringed(4,10000,1),bow(b){}
    int getBow();
    void setBow(int b);
    bool hasPotentiometer();
    ~Violins();
};
class EGuitars:public Stringed
{
private:
    int pickup;
    static const bool potentiometer;
public:
    EGuitars(int p = 0):Stringed(8,9000,3),pickup(p){}
    int getPickup();
    void setPickup(int p);
    bool hasPotentiometer();
    ~EGuitars();

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
class Synths:public KeyBoarded
{
private:
    int voiceCount;
public:
    Synths(int vc = 10):KeyBoarded(35,18000,4),voiceCount(vc){}
    int getVoiceCount();
    void setVoiceCount(int voiceCount);
    ~Synths();
};
class Organs:public KeyBoarded
{
private:
    int pipesCount;
public:
    Organs(int pipes = 49):KeyBoarded(49,180000,5),pipesCount(pipes){}
    int getPipes();
    void setPipes(int pipes);
    ~Organs();
};

#endif // INSTRUMENTS_H
