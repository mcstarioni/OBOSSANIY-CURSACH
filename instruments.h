#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <QString>
#include <QDebug>
#include <QVector>
#include "group.h"
enum Bow{mass,orchestral,solo,artistic};
enum Pickup{pzelectric,electromagneic};


class Group;
class Instruments
{

private:
    int id;
    static int instrumentsCount;
    static int lastId;
    QString name;
    int averageFrequency;
    QVector<Group*> *groups;
public:
    Instruments(int arg);
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
    Drumming(int bpm,int freq):Instruments(freq),beatPerMinute(bpm) {qDebug()<<"Drumming";}
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
    Drums(bool o = true):Drumming(170,5000),open(o){qDebug()<<"Drums";}
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
    Plate(int d = 20):Drumming(120,8000),diameter(d){qDebug()<<"Plates";}
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
    Stringed(int strings,int freq):Instruments(freq),stringsCount(strings){}
    int getStrings();
    void setStrings(int strings);
    virtual bool hasPotentiometer() = 0;
};
class Violins:public Stringed
{
private:
    Bow* bow;
    static const bool potentiometer;
public:
    Violins(Bow* b = new Bow(mass)):Stringed(4,10000),bow(b){}
    Bow* getBow();
    void setBow(Bow* bow);
    bool hasPotentiometer();
    ~Violins();
};
class EGuitars:public Stringed
{
private:
    Pickup* pickup;
    static const bool potentiometer;
public:
    EGuitars(Pickup* p = new Pickup(pzelectric)):Stringed(8,9000),pickup(p){}
    Pickup* getPickup();
    void setPickup(Pickup* p);
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
    KeyBoarded(int keys,int freq):Instruments(freq),keysCount(keys){}
    int getKeys();
    void setKeys(int keys);
};
class Synths:public KeyBoarded
{
private:
    int voiceCount;
public:
    Synths(int vc = 10):KeyBoarded(35,18000),voiceCount(vc){}
    int getVoiceCount();
    void setVoiceCount(int voiceCount);
    ~Synths();
};
class Organs:public KeyBoarded
{
private:
    int pipesCount;
public:
    Organs(int pipes = 49):KeyBoarded(49,180000),pipesCount(pipes){}
    int getPipes();
    void setPipes(int pipes);
    ~Organs();
};

#endif // INSTRUMENTS_H
