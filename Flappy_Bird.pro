#-------------------------------------------------
#
# Project created by QtCreator 2017-06-10T09:32:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flappy_Bird
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


SOURCES += cpp-files/main.cpp \
    cpp-files/game.cpp \
    cpp-files/bird.cpp \
    cpp-files/pipes.cpp \
    cpp-files/spawner.cpp \
    cpp-files/score.cpp

HEADERS  += \
    h-files/game.h \
    h-files/bird.h \
    h-files/pipes.h \
    h-files/spawner.h \
    h-files/score.h

RESOURCES += \
    res.qrc
