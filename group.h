#ifndef GROUP_H
#define GROUP_H

#include <instruments.h>
#include <QVector>
#include <QString>
class Instruments;
class Group
{
private:
    int id;
    static int groupCount;
    static int lastId;
    QString name;
    QVector<Instruments*> *orchestra;
public:
    int Id();
    void setName(QString n);
    QString getName();
    void addInstrument(Instruments *i);
    void removeInstrument(Instruments *i);
    QVector<Instruments*>* getInstruments();
    Group();
    ~Group();
};

#endif // GROUP_H
