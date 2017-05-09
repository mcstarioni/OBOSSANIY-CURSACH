#include "mainwindow.h"
#include <QApplication>
#include <instruments.h>
#include <QDebug>
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    //Drumming d(10,20);
    qDebug()<<Instruments::getInstrumentsCount();
    Drum d = new Drum(true);
    Plates* p = new Plates(10);
    qDebug()<<Instruments::getInstrumentsCount();
    delete p;
    qDebug()<<Instruments::getInstrumentsCount();
    return 0;
}
