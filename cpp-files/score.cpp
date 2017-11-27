#include "h-files/score.h"

Score::Score() {
    ammount = 0;

    // Asetetaan scoren perusasetukset sekä annetaan
    // Z-value 1, jotta liikkuu putkien päällä.
    setPlainText(QString::number(ammount));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 27));
    setPos(275, 15);

    setZValue(1);

}

// Kasvattaa scorea yhdellä.
void Score::update() {
    ammount += 0.5;
    setPlainText(QString::number(ammount));
}

int Score::getScore() {
    return ammount;
}


