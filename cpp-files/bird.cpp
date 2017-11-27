#include "h-files/bird.h"

Bird::Bird() {
    // Asetetaan linnun kuva ja sijainti.
    setPixmap(QPixmap(":/images/Images/Bird"));
    setPos(75,290);

    // Alustetaan kuvitteellinen x-koordinaatti.
    imagine_x = 0;

    // Peli alkaa vasta, kun painetaan space, joten
    // GameStarted alustetaan falseksi.
    GameStarted = false;

    // Pelaaja liikkuu 40ms välein
    ajastin = new QTimer();
    connect(ajastin,SIGNAL(timeout()),this,SLOT(move()));
    ajastin->start(50);

    spawn = new Spawner();
}

// Spacella imagine_x nollataan, jolloin mennään paraabelin "alkuun".
void Bird::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space) {
        imagine_x = 0;
        // Merkataan myös, että peli on aloitettu ja
        // ja lintu voi liikkua.
        GameStarted = true;
    }
}

// Linnun y-koordinaatti liikkuu paraabelin y = x^2 - 7.2x mukaisesti.
void Bird::move() {
    // Jos peli on aloitettu hoidetaan liikuttaminen.
    if(GameStarted) {
        imagine_x = imagine_x + 1;
        double newY = y() + pow(0.90*imagine_x, 2) - 7.2 * imagine_x;
        setPos(x(), newY);
    }
}
