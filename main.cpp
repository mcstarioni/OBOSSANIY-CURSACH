#include "mainform.h"
#include <QApplication>
#include <instruments.h>
#include <QDebug>
#include "manager.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    /*
    MainWindow w;
    w.show();
    return a.exec();*/
    //Drumming d(10,20);
//    qDebug()<<Instruments::getInstrumentsCount();
//    Drum* d = new Drum(true);
//    Plates* p = new Plates(10);
//    qDebug()<<Instruments::getInstrumentsCount();
//    delete d;
//    delete p;
//    qDebug()<<Instruments::getInstrumentsCount();
    //Manager* manager = Manager::getInstance();
    //Manager* manager2 = Manager::getInstance();
    MainForm form;
    form.show();
    Drums *drum = new Drums();
    QVector<Drums*>* drums = new QVector<Drums*>();
    drums->push_back(drum);
    QVector<Instruments*>* ins= (QVector<Instruments*>*)drums;
    qDebug()<<ins->at(0)->Id();
    delete drum;
    drum = 0;
    delete drum;
    delete ins;
    return a.exec();
}
