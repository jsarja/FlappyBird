#include "h-files/pipes.h"
#include "h-files/game.h"
#include "h-files/bird.h"

#include <QDebug>

extern Game* newGame;

pipes::pipes() {
    // Putket liikkuvat 50ms välein
    ajastin = new QTimer();
    connect(ajastin,SIGNAL(timeout()),this,SLOT(move()));
    ajastin->start(50);

    counted = false;


    QTimer* Timer2 = new QTimer();
    connect(Timer2,SIGNAL(timeout()),this,SLOT(unpauseTimer()));
    Timer2->start(1);

}

void pipes::move() {
    setPos(x()-12, y());

    if (newGame->ended) {
        ajastin->stop();
    }

    //Törmääkö pelaaja.
    QList<QGraphicsItem *> tormaykset = collidingItems();
    for(int i = 0; i < tormaykset.size(); ++i) {
        if(typeid(*(tormaykset[i])) == typeid(Bird)) {
            // Aloitetaan alusta.
            newGame->gameOver();
//            newGame->ended = true;
        }
    }

    //Aloitetaan alusta myös, jos pelaaja menee ruudusta ulos.
    if (newGame->player->y() > 741 || newGame->player->y() < 0) {
        newGame->gameOver();
//        newGame->ended = true;
    }

    // Päivitetään score, jos putki ohittaa pelaajan.
    if(x() < -25) {
        if(!counted) {
            newGame->score->update();
            counted = true;
         }
    }

    // Poistetaan putki jos ollaan ulkona kuvasta.
    if(x() < -150) {
        scene()->removeItem(this);
        delete this;
        counted = false;
    }

    // Poistetaan putki myös, jos peli on loppunut.
    if(!newGame->player->GameStarted) {
        scene()->removeItem(this);
        delete this;
    }
}

void pipes::unpauseTimer() {
    if(newGame->unpaused) {
        ajastin->start(50);
        newGame->unpaused = false;
    }
}
