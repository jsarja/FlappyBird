#include "h-files/spawner.h"
#include "h-files/game.h"

extern Game* newGame;

const int SPACE = 189;
const int PIPELENGTH = 443;

Spawner::Spawner() {

    // Spawnataan tolppia
    ajastin = new QTimer();
    connect(ajastin,SIGNAL(timeout()),this,SLOT(addPipes()));
    ajastin->start(2000);

    // Tarkkaillaan pelin alkamista.
    QTimer* timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(deleteMsg()));
    timer2->start(10);
}

void Spawner::addPipes() {
        if(newGame->player->GameStarted) {

            // Arvotaan kuinka pitkä osa yläpylväästä jää piiloon.
            int random = (rand() % 256) + 100;

            // Määritetään pisteet joihin ylä- ja alapylväät tulee sijoittaa.
            int pipeUpY = -random;
            int pipeDownY = pipeUpY + PIPELENGTH + SPACE;


            pipes* pipeDown = new pipes();
            pipeDown->setZValue(-1);
            pipeDown->setPixmap(QPixmap(":/images/Images/pipeDown1"));
            pipeDown->setPos(468,pipeDownY);
            newGame->scene->addItem(pipeDown);

            pipes* pipeUp = new pipes();
            pipeUp->setZValue(-1);
            pipeUp->setPixmap(QPixmap(":/images/Images/pipeUp1"));
            pipeUp->setPos(468,pipeUpY);
            newGame->scene->addItem(pipeUp);
        }
}

void Spawner::deleteMsg() {
    if(newGame->player->GameStarted) {
        newGame->scene->removeItem(newGame->guideText);
    }
}
