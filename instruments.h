#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <QString>
#include <QDebug>
enum Bow{mass,orchestral,solo,artistic};
enum Pickup{pzelectric,electromagneic};
class Instruments
{
private:
    int id;
    static int instrumentsCount;
    static int lastId;
    QString name;
    int averageFrequency;
public:
    Instruments(int arg);
    void setName(QString name);
    QString getName();
    void setFrequency(int arg);
    int getFrequency();
    static int getInstrumentsCount();
    virtual ~Instruments() = 0;
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
class Drum:public Drumming
{
private:
    const bool open;
    static const bool membrane;
public:
    Drum(bool o = true):Drumming(170,5000),open(o){qDebug()<<"Drum";}
    bool isOpen();
    bool hasMembrane();
    ~Drum();
};
class Plates:public Drumming
{
private:
    const int diameter;
    static const bool membrane;
public:
    Plates(int d = 20):Drumming(120,8000),diameter(d){qDebug()<<"Plates";}
    int getDiameter();
    bool hasMembrane();
    ~Plates();
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
    bool hasPotentiometer();
};
class Violin:public Stringed
{
private:
    Bow* bow;
public:
    Violin(Bow* b = new Bow(mass)):Stringed(4,10000),bow(b){}
    Bow* getBow();
    void setBow(Bow* bow);
    ~Violin();
};
class EGuitar:public Stringed
{
private:
    Pickup* pickup;
public:
    EGuitar(Pickup* p = new Pickup(pzelectric)):Stringed(8,9000),pickup(p){}
    Pickup* getPickup();
    void setPickup(Pickup* p);
    ~EGuitar();

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
class Synth:public KeyBoarded
{
private:
    int voiceCount;
public:
    Synth(int vc = 10):KeyBoarded(35,18000),voiceCount(vc){}
    int getVoiceCount();
    void setVoiceCount(int voiceCount);
    ~Synth();
};
class Organ:public KeyBoarded
{
private:
    int pipesCount;
public:
    Organ(int pipes = 49):KeyBoarded(49,180000),pipesCount(pipes){}
    int getPipes();
    void setPipes(int pipes);
    ~Organ();
};

#endif // INSTRUMENTS_H
