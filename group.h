#ifndef GROUP_H
#define GROUP_H

#include <instruments.h>
#include <QVector>
#include <QString>
class Instruments;
class Group
{
private:
    QString name;
    QVector<Instruments*> *orchestra;
public:
    void setName(QString n);
    QString getName();
    void addInstrument(Instruments *i);
    void removeInstrument(Instruments *i);
    QVector<Instruments*>* getInstruments();
    Group();
    ~Group();
};

#endif // GROUP_H
