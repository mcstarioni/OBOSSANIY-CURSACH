#include "boxins.h"
#include "ui_boxins.h"
#include "manager.h"
#include "drum.h"
#include "plates.h"
#include "violin.h"
#include "eguitar.h"
#include "synth.h"
#include "organ.h"
BoxIns::BoxIns(int i,QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BoxIns),index(i)
{
    ui->setupUi(this);
//    switch (index) {
//    case 1:
//        ui->finalClass = new Drum;
//        break;
//    case 2:
//        ui->finalClass = new Plates;
//        break;
//    case 3:
//        ui->finalClass = new Violin;
//        break;
//    case 4:
//        ui->finalClass = new EGuitar;
//        break;
//    case 5:
//        ui->finalClass = new Synth;
//        break;
//    case 6:
//        ui->finalClass = new Organ;
//        break;
//    default:
//        break;
//    }
}

BoxIns::~BoxIns()
{
    delete ui;
}
void BoxIns::createIns()
{
    switch (index) {
    case 1:
        break;\
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
}
