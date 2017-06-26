#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T00:20:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    instruments.cpp \
    manager.cpp \
    database.cpp \
    boxins.cpp \
    mainform.cpp \
    drum.cpp \
    plates.cpp \
    violin.cpp \
    group.cpp \
    eguitar.cpp \
    synth.cpp \
    organ.cpp \
    groupform.cpp \
    checkableform.cpp \
    addition.cpp \
    inclusion.cpp \
    removal.cpp \
    change.cpp \
    search.cpp \
    inssearch.cpp \
    groupsearch.cpp

HEADERS  += \
    instruments.h \
    manager.h \
    database.h \
    boxins.h \
    mainform.h \
    drum.h \
    plates.h \
    violin.h \
    group.h \
    eguitar.h \
    synth.h \
    organ.h \
    groupform.h \
    checkableform.h \
    addition.h \
    inclusion.h \
    removal.h \
    change.h \
    search.h \
    inssearch.h \
    groupsearch.h

FORMS    += \
    mainform.ui \
    boxins.ui \
    drum.ui \
    plates.ui \
    violin.ui \
    eguitar.ui \
    synth.ui \
    organ.ui \
    groupform.ui \
    checkableform.ui \
    addition.ui \
    inclusion.ui \
    removal.ui \
    change.ui \
    search.ui \
    inssearch.ui \
    groupsearch.ui
