#ifndef MANAGER_H
#define MANAGER_H
#include "instruments.h"
#include <QString>
#include "database.h"
#include <QObject>

class Manager: public QObject
{
    Q_OBJECT

private:

    Manager(QObject *parent = 0);
    ~Manager();
    Database *database;
public:

    Instruments* getById(int id);
    Group* getByIdG(int id);
    void includeIns(Instruments* ins, Group* group);
    void includeIns(int idIns, int idGroup);
    //void removeInstrument(int id);
    void createDrum(int af, QString name, int bpm,bool open);
    void createPlate(int af, QString name, int bpm,int diameter);
    void createViolin(int af, QString name,int strings, int bowType);
    void createGuitar(int af, QString name,int strings, int pickupType);
    void createSynth(int af, QString name,int keys, int voices);
    void createOrgan(int af, QString name,int keys, int pipes);
    void createGroup(QString name);

    void setDrum(int id, int af, QString name, int bpm,bool open,Instruments *ins = 0);
    void setPlate(int id,int af, QString name, int bpm,int diameter,Instruments *ins = 0);
    void setViolin(int id,int af, QString name,int strings, int bowType,Instruments *ins = 0);
    void setGuitar(int id,int af, QString name,int strings, int pickupType,Instruments *ins = 0);
    void setSynth(int id,int af, QString name,int keys, int voices,Instruments *ins = 0);
    void setOrgan(int id,int af, QString name,int keys, int pipes,Instruments *ins = 0);
    //void setGroup(QString name);

    static Manager* getInstance()
    {
        static Manager instance;
        return &instance;
    }
signals:
    void createdIns(int id);
    void createdGrp(int id);
};

#endif // MANAGER_H
