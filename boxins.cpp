#include "boxins.h"
#include "ui_boxins.h"
#include "manager.h"
#include "drum.h"
#include "plates.h"
#include "violin.h"
#include "eguitar.h"
#include "synth.h"
#include "organ.h"
#include <QDebug>
BoxIns::BoxIns(int i,QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BoxIns),type(i)
{
    qDebug()<<"Created";
    lastClass = 0;
    ui->setupUi(this);
    manager = Manager::getInstance();
    qDebug()<<"Created 1.5";
    connect(manager,SIGNAL(createdIns(int)),SLOT(objectCreated(int)));
    qDebug()<<"Created 2";
}
void BoxIns::setClass()
{
    if(lastClass != 0)
    {
        delete lastClass;
    }
    switch (type) {
    case 0:
        this->setTitle("Барабан");
        lastClass = new Drum;
        ui->classLayout->addWidget(lastClass);
        break;
    case 1:
        setTitle("Тарелки");
        lastClass = new Plates;
        ui->classLayout->addWidget(lastClass);
        break;
    case 2:
        setTitle("Скрипка");
        lastClass = new Violin;
        ui->classLayout->addWidget(lastClass);
        break;
    case 3:
        setTitle("Электрогитара");
        lastClass = new EGuitar;
        ui->classLayout->addWidget(lastClass);
        break;
    case 4:
        setTitle("Синтезатор");
        lastClass = new Synth;
        ui->classLayout->addWidget(lastClass);
        break;
    case 5:
        setTitle("Орган");
        lastClass = new Organ;
        ui->classLayout->addWidget(lastClass);
        break;
    default:
        break;
    }
}

BoxIns::~BoxIns()
{
    delete lastClass;
    delete ui;
}
void BoxIns::createIns()
{
    switch (type) {
    case 0:

        manager->createDrum(ui->freq->text().toInt(),
                            ui->nameEdit->text(),
                            ((Drum*)lastClass)->bpm,
                            ((Drum*)lastClass)->isOpen);
        break;
    case 1:
        manager->createPlate(ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Plates*)lastClass)->bpm,
                             ((Plates*)lastClass)->diameter);
        break;
    case 2:
        manager->createViolin(ui->freq->text().toInt(),
                              ui->nameEdit->text(),
                              ((Violin*)lastClass)->strings,
                              ((Violin*)lastClass)->bow);
        break;
    case 3:
        manager->createGuitar(ui->freq->text().toInt(),
                              ui->nameEdit->text(),
                              ((EGuitar*)lastClass)->strings,
                              ((EGuitar*)lastClass)->pickup);
        break;
    case 4:
        manager->createSynth(ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Synth*)lastClass)->keys,
                             ((Synth*)lastClass)->voices);
        break;
    case 5:
        manager->createOrgan(ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Organ*)lastClass)->keys,
                             ((Organ*)lastClass)->pipes);
        break;
    default:
        break;
    }
}
void BoxIns::classChanged(int i)
{
    type = i;
    setClass();
}
void BoxIns::objectCreated(int id)
{
    qDebug()<<"in signal 1";
    this->id = id;
    ui->labelPlace->addWidget(new QLabel(QString::number(id)));
    qDebug()<<"in signal 2";

}
void BoxIns::addGroup(QString group)
{
    this->ui->groups->addItem(group);
}
void BoxIns::updateIncl()
{
    qDebug()<<"updated 3";
    ui->groups->clear();
    Instruments* ins = manager->getById(id);
    QVector<Group*>* vec = ins->getGroups();
    for(int i = 0; i < vec->size(); i++)
    {
        QString str = QString::number(vec->at(i)->Id());
        str = "id: " + str + ", name: " + vec->at(i)->getName();
        qDebug()<<str;
        ui->groups->addItem(str);
    }
}

