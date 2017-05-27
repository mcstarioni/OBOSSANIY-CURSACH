#include "mainform.h"
#include <QApplication>
#include <QDebug>
#include "manager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm form;
    form.show();
    return a.exec();
//    Manager* m = Manager::getInstance();
//    m->createDrum(0,"I1",0,false);
//    m->createDrum(0,"I2",0,false);
//    m->createDrum(0,"I3",0,false);
//    m->createDrum(0,"I4",0,false);
//    m->createGroup("1");
//    m->includeIns(0,0);
//    m->includeIns(1,0);
//    m->includeIns(2,0);
//    m->includeIns(3,0);
//    m->createGroup("2");
//    m->createGuitar(0,"I5",0,0);
//    m->createGuitar(0,"I6",0,0);
//    m->createGuitar(0,"I7",0,0);
//    m->includeIns(4,1);
//    m->includeIns(5,1);
//    m->includeIns(6,0);
//    return 0;
}
