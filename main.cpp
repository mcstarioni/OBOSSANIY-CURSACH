#include "mainform.h"
#include <QApplication>
#include <QDebug>

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

    return a.exec();
}
