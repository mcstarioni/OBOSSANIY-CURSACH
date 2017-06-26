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
    ui(new Ui::BoxIns)
{
    type = i;
    lastClass = 0;
    ui->setupUi(this);
    manager = Manager::getInstance();
    connect(manager,SIGNAL(createdIns(int)),SLOT(objectCreated(int)));
    setClass();
}
void BoxIns::setClass()
{
    if(lastClass != 0)
    {
        delete lastClass;
    }
    switch (type)
    {
    case 0:
        lastClass = new Drum;
        break;
    case 1:
        lastClass = new Plates;
        break;
    case 2:
        lastClass = new Violin;
        break;
    case 3:
        lastClass = new EGuitar;
        break;
    case 4:
        lastClass = new Synth;
        break;
    case 5:
        lastClass = new Organ;
        break;
    default:
        return;
    }
    QString insTypeName = manager->getTypeName(type);
    setTitle(insTypeName);
    ui->nameEdit->setText(manager->getPossibleNameIns(type));
    ui->classLayout->addWidget(lastClass);
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

    this->id = id;
    QLabel* label = ui->idLabel;
    label->setText(QString::number(id));
}

void BoxIns::addGroup(QString group)
{
    this->ui->groups->addItem(group);
}

void BoxIns::updateIncl()
{
    ui->groups->clear();
    Instruments* ins = manager->getById(id);
    QVector<Group*>* vec = ins->getGroups();
    qDebug()<<ins->getName()<<" "<<vec->size();
    for(int i = 0; i < vec->size(); i++)
    {
        QString str = QString::number(vec->at(i)->Id());
        str = "id: " + str + ", name: " + vec->at(i)->getName();
        qDebug()<<str;
        ui->groups->addItem(str);
    }
}

void BoxIns::change()
{
    switch (type) {
    case 0:

        manager->setDrum(id,ui->freq->text().toInt(),
                            ui->nameEdit->text(),
                            ((Drum*)lastClass)->bpm,
                            ((Drum*)lastClass)->isOpen);
        break;
    case 1:
        manager->setPlate(id,ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Plates*)lastClass)->bpm,
                             ((Plates*)lastClass)->diameter);
        break;
    case 2:
        manager->setViolin(id,ui->freq->text().toInt(),
                              ui->nameEdit->text(),
                              ((Violin*)lastClass)->strings,
                              ((Violin*)lastClass)->bow);
        break;
    case 3:
        manager->setGuitar(id,ui->freq->text().toInt(),
                              ui->nameEdit->text(),
                              ((EGuitar*)lastClass)->strings,
                              ((EGuitar*)lastClass)->pickup);
        break;
    case 4:
        manager->setSynth(id,ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Synth*)lastClass)->keys,
                             ((Synth*)lastClass)->voices);
        break;
    case 5:
        manager->setOrgan(id,ui->freq->text().toInt(),
                             ui->nameEdit->text(),
                             ((Organ*)lastClass)->keys,
                             ((Organ*)lastClass)->pipes);
        break;
    default:
        break;
    }
    this->setEnabled(false);
}
